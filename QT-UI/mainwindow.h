#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QSlider>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QTextBrowser>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT  // 必须包含 Q_OBJECT 宏，以支持 Qt 的信号与槽机制

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 角度控制槽函数
    void onSliderValueChanged(int value);    // 滑块更新角度
    void onSendAngleClicked();               // 发送角度指令

    // 连接面板槽函数
    void onConnectClicked();                 // 连接服务器
    void onDisconnectClicked();              // 断开连接
    void onTestConnectionClicked();          // 测试连接
    void onQuitClicked();                    // quit!!!

    // 网络数据处理
    void onSocketConnected();
    void onSocketDisconnected();
    void onSocketError(QAbstractSocket::SocketError socketError);
    void onSocketReadyRead();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;

    // 辅助方法
    void logMessage(const QString &message); // 控制台日志输出
};

#endif // MAINWINDOW_H
