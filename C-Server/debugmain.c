#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 6657

// 向客户端发送响应
void send_response(int client_fd, const char *message) {
    ssize_t len = strlen(message);
    if (write(client_fd, message, len) != len) {
        perror("发送响应失败");
    }
}

// 解析接收到的指令并打印角度信息
void process_command(int client_fd, const unsigned char *buffer, ssize_t len) {
    if (len < 3) {
        printf("指令数据不完整\n");
        return;
    }

    // 如果接收到 "TEST" 指令
    if (strncmp((char *)buffer, "TEST", 4) == 0) {
        printf("收到 TEST 指令\n");

        // 向客户端发送响应
        send_response(client_fd, "测试指令收到\n");
        return;
    }

    // 检查包头
    if (buffer[0] != 0xAA) {
        printf("无效的包头\n");
        return;
    }

    // 指令类型（第二个字节，轴号）
    unsigned char axis = buffer[1];
    if (axis > 5) {
        printf("无效的轴号\n");
        return;
    }

    // 角度数据（第三个字节）
    unsigned char angle = buffer[2];

    // 打印指令内容
    printf("收到控制面板指令：\n");
    printf("包头: 0xAA\n");
    printf("轴编号: %d\n", axis);  // 轴编号从0开始
    printf("角度: %d°\n", angle);

    // 向客户端发送确认消息
    char response[256];
    snprintf(response, sizeof(response), "指令已收到：轴 %d 的角度设置为 %d°", axis + 1, angle);  // 客户端显示1~6的轴号
    send_response(client_fd, response);
}

// 监听并接收控制面板指令
void listen_and_debug() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[1024];
    ssize_t len;

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
            // 处理并打印接收到的角度控制指令
            process_command(client_fd, (unsigned char *)buffer, len);
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
}

int main() {
    listen_and_debug();
    return 0;
}
