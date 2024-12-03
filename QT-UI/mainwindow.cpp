#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), socket(new QTcpSocket(this)) {
    ui->setupUi(this);
    this->setWindowTitle("机械臂控制中心 By:RoyZ v0.1 Alpha");

    // 1. 角度控制面板：滑块与 SpinBox 联动
    for (int i = 0; i < 6; ++i) {
        QSlider *slider = findChild<QSlider*>(QString("slider%1").arg(i+1));
        QDoubleSpinBox *spinBox = findChild<QDoubleSpinBox*>(QString("spinBox%1").arg(i+1));
        QPushButton *button = findChild<QPushButton*>(QString("ButtonSend%1").arg(i+1));

        // 滑条范围
        slider->setRange(0, 180);

        // 数值输入行显示范围
        spinBox->setRange(0, 180);

        // 滑块更新 SpinBox
        connect(slider, &QSlider::valueChanged, spinBox, &QDoubleSpinBox::setValue);

        // SpinBox 更新滑块
        connect(spinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [slider](double value) {
            slider->setValue(static_cast<int>(value));
        });

        // 初始化
        spinBox->setValue(slider->value());

        // 点击按钮发送指令
        connect(button, &QPushButton::clicked, this, &MainWindow::onSendAngleClicked);
    }

    // 2. 连接面板：连接、断开、测试、QUIT按钮
    connect(ui->ButtonConnect, &QPushButton::clicked, this, &MainWindow::onConnectClicked);
    connect(ui->ButtonDisconnect, &QPushButton::clicked, this, &MainWindow::onDisconnectClicked);
    connect(ui->ButtonTestConnect, &QPushButton::clicked, this, &MainWindow::onTestConnectionClicked);
    connect(ui->ButtonQuit, &QPushButton::clicked, this, &MainWindow::onQuitClicked);

    // 3. 网络连接信号
    connect(socket, &QTcpSocket::connected, this, &MainWindow::onSocketConnected);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::onSocketDisconnected);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::onSocketReadyRead);
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error), this, &MainWindow::onSocketError);
}

MainWindow::~MainWindow() {
    delete ui;
}

// 角度控制：滑条更新角度
void MainWindow::onSliderValueChanged(int value) {
    QSlider *slider = qobject_cast<QSlider*>(sender());
    int axis = slider->objectName().right(1).toInt() - 1; // 获取轴编号
    QDoubleSpinBox *spinBox = findChild<QDoubleSpinBox*>(QString("spinBox%1").arg(axis+1));
    spinBox->setValue(static_cast<double>(value));  // 更新 SpinBox
}

// 角度控制：发送指令
void MainWindow::onSendAngleClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    int axis = button->objectName().right(1).toInt() - 1; // 获取轴编号
    QDoubleSpinBox *spinBox = findChild<QDoubleSpinBox*>(QString("spinBox%1").arg(axis+1));

    double angle = spinBox->value();
    QByteArray command;
    command.append(0xAA); // 包头
    command.append(0x01); // 指令类型（设置角度）
    command.append(axis); // 轴编号
    command.append(static_cast<int>(angle) & 0xFF); // 角度数据（示例：简单发送整数部分）

    if (socket->isOpen()) {
        socket->write(command);
        logMessage(QString("发送轴 %1 的角度：%2°").arg(axis+1).arg(angle));
    } else {
        logMessage("发送失败：未连接到服务器");
    }
}

// 连接面板：连接服务器
void MainWindow::onConnectClicked() {
    QString ip = ui->LineEditIP->text();
    quint16 port = ui->LineEditPORT->text().toUShort();
    socket->connectToHost(ip, port);
    logMessage("尝试连接到服务器...");
}

// 连接面板：断开连接
void MainWindow::onDisconnectClicked() {
    socket->disconnectFromHost();
    logMessage("断开连接...");
}

// 连接面板：测试连接
void MainWindow::onTestConnectionClicked() {
    if (socket->isOpen()) {
        QByteArray testMessage = "TEST";
        socket->write(testMessage);
        logMessage("发送测试连接指令...");
    } else {
        logMessage("测试失败：未连接到服务器");
    }
}

// 连接面板：QUIT
void MainWindow::onQuitClicked() {
    if (socket->isOpen()) {
        QByteArray quitMessage = "quit";
        socket->write(quitMessage);
        logMessage("发送QUIT指令...");
    } else {
        logMessage("发送失败：未连接到服务器");
    }
}

// 网络事件：连接成功
void MainWindow::onSocketConnected() {
    logMessage("成功连接到服务器");
}

// 网络事件：断开连接
void MainWindow::onSocketDisconnected() {
    logMessage("已断开连接");
}


// 网络事件：错误处理
void MainWindow::onSocketError(QAbstractSocket::SocketError socketError) {
    logMessage("连接错误：" + socket->errorString());
}

// 网络事件：读取服务器返回数据
void MainWindow::onSocketReadyRead() {
    QByteArray data = socket->readAll();
    logMessage("收到服务器数据：" + QString(data));
}

// 日志输出
void MainWindow::logMessage(const QString &message) {
    ui->textBrowser->append(message);
}
