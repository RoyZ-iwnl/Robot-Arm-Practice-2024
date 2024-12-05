#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define PORT 6657
#define SERIAL_PORT "/dev/ttyUSB0"  // 串口设备地址

// 打开串口
int open_serial_port(const char *port) {
    int fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("无法打开串口");
        exit(1);
    }
    return fd;
}

// 配置串口
void configure_serial_port(int fd) {
    struct termios options;
    tcgetattr(fd, &options);

    // 设置波特率
    cfsetispeed(&options, B115200);  // 接收波特率
    cfsetospeed(&options, B115200);  // 发送波特率

    // 设置数据位、停止位、无校验
    options.c_cflag &= ~PARENB;      // 无校验
    options.c_cflag &= ~CSTOPB;      // 1个停止位
    options.c_cflag &= ~CSIZE;       // 清除数据位大小
    options.c_cflag |= CS8;          // 8个数据位

    options.c_cflag |= CLOCAL | CREAD; // 启动接收器

    // 禁用软件流控
    options.c_iflag &= ~(IXON | IXOFF | IXANY);

    // 设置串口选项
    tcsetattr(fd, TCSANOW, &options);
}

// 向STM32发送指令
void send_to_stm32(int serial_fd, const unsigned char *buffer, ssize_t len) {
    if (write(serial_fd, buffer, len) != len) {
        perror("写入串口失败");
    }
}

// 从STM32接收数据
ssize_t read_from_stm32(int serial_fd, unsigned char *buffer, size_t size) {
    return read(serial_fd, buffer, size);
}

// 向客户端发送响应
void send_response(int client_fd, const char *message) {
    ssize_t len = strlen(message);
    if (write(client_fd, message, len) != len) {
        perror("发送响应失败");
    }
}

// 原有指令数组（用于处理0xBB协议转化）
void Reset(int fd) {
    unsigned char BUF[6][3] = 
    {
        {0xaa,0x01,0x5A},
        {0xaa,0x02,0x5A},
        {0xaa,0x03,0x5A},
        {0xaa,0x00,0x5A},
        {0xaa,0x04,0x5A},
        {0xaa,0x05,0x5A},
    };
    for(int i = 0;i < 4;i++) {
        write(fd,BUF[i],3);
        usleep(500000);
    }
}

void Left(int fd) {
    unsigned char BUF[5][3] = 
    {
        {0xaa,0x00,0x00},
        {0xaa,0x01,0x38},
        {0xaa,0x02,0x0c},
        {0xaa,0x03,0x14},
        {0xaa,0x05,0x63},
    };
    for(int i = 0;i < 5;i++) {
        write(fd,BUF[i],3);
        usleep(500000);
    }
}

void Right(int fd) {
    unsigned char BUF[5][3] = 
    {
        {0xaa,0x00,0xB4},    // 底座右转
        {0xaa,0x01,0x38},
        {0xaa,0x02,0x0c},
        {0xaa,0x03,0x14},
        {0xaa,0x05,0x63},
    };
    for(int i = 0;i < 5;i++) {
        write(fd,BUF[i],3);
        usleep(500000);
    }
}

void Scrach(int fd) {
    unsigned char BUF[2][3] = 
    {
        {0xaa,0x04,0x3c},    // 夹子张开
        {0xaa,0x04,0x82},    // 夹子夹紧
    };
    for(int i = 0;i < 2;i++) {
        write(fd,BUF[i],3);
        usleep(500000);
    }
}

void Push(int fd) {
    unsigned char BUF[1][3] = 
    {
        {0xaa,0x04,0x3c},    // 夹子张开
    };
    for(int i = 0;i < 1;i++) {
        write(fd,BUF[i],3);
        usleep(500000);
    }
}

// 处理接收到的指令（支持0xBB协议和0xAA协议）
void process_command(int client_fd, int serial_fd, const unsigned char *buffer, ssize_t len) {
    if (len < 2) {
        printf("指令数据不完整\n");
        return;
    }

    // 处理0xAA协议
    if (buffer[0] == 0xAA) {
        unsigned char axis = buffer[1];
        unsigned char angle = buffer[2];
        
        // 打印指令内容
        printf("收到控制面板指令（0xAA协议）：\n");
        printf("包头: 0xAA\n");
        printf("轴编号: %d\n", axis + 1);
        printf("角度: %d°\n", angle);

        // 向STM32发送控制命令
        unsigned char stm32_command[3] = {0xAA, axis, angle};
        send_to_stm32(serial_fd, stm32_command, sizeof(stm32_command));

        // 向客户端发送确认消息
        char response[256];
        snprintf(response, sizeof(response), "指令已收到：轴 %d 的角度设置为 %d°", axis + 1, angle);
        send_response(client_fd, response);
    }

    // 处理0xBB协议
    else if (buffer[0] == 0xBB) {
    unsigned char command_type = buffer[1];


        // 根据不同的command_type调用对应的动作
        switch (command_type) {
            case 0x00:  // 全部角度为5A
                Reset(serial_fd);
                break;
            case 0x01:  // 左转
                Left(serial_fd);
                break;
            case 0x02:  // 右转
                Right(serial_fd);
                break;
            case 0x03:  // 抓
                Scrach(serial_fd);
                break;
            case 0x04:  // 放
                Push(serial_fd);
                break;
            default:
                printf("未知的命令类型 0x%02X\n", command_type);
                return;
        }

        // 向客户端发送响应
        send_response(client_fd, "0xBB命令已执行\n");
    } else {
        printf("无效的包头\n");
    }
}

// 监听并接收控制面板指令
void listen_and_debug() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[1024];
    ssize_t len;

    // 打开并配置串口
    int serial_fd = open_serial_port(SERIAL_PORT);
    configure_serial_port(serial_fd);

    // 创建TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("创建socket失败");
        exit(1);
    }

    // 设置端口可重用
    int reuse = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
        perror("设置端口可重用失败");
        close(server_fd);
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // 监听所有可用的网络接口
    server_addr.sin_port = htons(PORT);

    // 绑定socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("绑定端口失败");
        close(server_fd);
        exit(1);
    }

    // 监听端口
    if (listen(server_fd, 10) == -1) {
        perror("监听端口失败");
        close(server_fd);
        exit(1);
    }

    printf("网络调试程序已启动，监听端口 %d...\n", PORT);

    while (1) {
        // 接受客户端连接
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len)) == -1) {
            perror("接受连接失败");
            continue;
        }
        printf("客户端已连接\n");

        // 读取客户端数据
        while ((len = read(client_fd, buffer, sizeof(buffer))) > 0) {
            buffer[len] = '\0';  // 确保字符串结束

            // 如果接收到quit指令，退出程序
            if (strncmp((char *)buffer, "quit", 4) == 0) {
                printf("收到quit指令，关闭程序...\n");
                send_response(client_fd, "中转程序已关闭");
                close(client_fd);
                close(serial_fd);
                close(server_fd);
                return;  // 退出程序
            }

            // 处理并打印接收到的角度控制指令
            process_command(client_fd, serial_fd, (unsigned char *)buffer, len);
        }

        if (len == 0) {
            printf("客户端已断开连接\n");
        } else if (len < 0) {
            perror("读取数据失败");
        }

        // 关闭客户端连接
        close(client_fd);
    }

    // 关闭服务器socket
    close(server_fd);
    close(serial_fd);
}

int main() {
    listen_and_debug();
    return 0;
}
