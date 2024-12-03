/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QLineEdit *LineEditIP;
    QPushButton *ButtonTestConnect;
    QSlider *slider2;
    QPushButton *ButtonSend6;
    QLabel *label_11;
    QSlider *slider6;
    QSlider *slider3;
    QPushButton *ButtonSend2;
    QLabel *label_8;
    QDoubleSpinBox *spinBox3;
    QPushButton *ButtonSend1;
    QPushButton *ButtonConnect;
    QTextBrowser *textBrowser;
    QLabel *label_6;
    QLabel *label_4;
    QDoubleSpinBox *spinBox2;
    QLabel *label_7;
    QLabel *label_10;
    QPushButton *ButtonSend4;
    QLabel *label;
    QPushButton *ButtonSend3;
    QLabel *label_5;
    QDoubleSpinBox *spinBox1;
    QDoubleSpinBox *spinBox5;
    QLineEdit *LineEditPORT;
    QPushButton *ButtonDisconnect;
    QDoubleSpinBox *spinBox4;
    QSlider *slider1;
    QSlider *slider4;
    QPushButton *ButtonSTOP;
    QLabel *label_9;
    QDoubleSpinBox *spinBox6;
    QSlider *slider5;
    QLabel *label_2;
    QPushButton *ButtonSend5;
    QPushButton *ButtonQuit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1137, 771);
        MainWindow->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 270, 71, 41));
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        LineEditIP = new QLineEdit(centralwidget);
        LineEditIP->setObjectName(QString::fromUtf8("LineEditIP"));
        LineEditIP->setGeometry(QRect(680, 300, 171, 41));
        ButtonTestConnect = new QPushButton(centralwidget);
        ButtonTestConnect->setObjectName(QString::fromUtf8("ButtonTestConnect"));
        ButtonTestConnect->setGeometry(QRect(940, 350, 93, 28));
        slider2 = new QSlider(centralwidget);
        slider2->setObjectName(QString::fromUtf8("slider2"));
        slider2->setGeometry(QRect(120, 330, 261, 22));
        slider2->setMaximum(180);
        slider2->setOrientation(Qt::Horizontal);
        slider2->setTickPosition(QSlider::TicksBothSides);
        ButtonSend6 = new QPushButton(centralwidget);
        ButtonSend6->setObjectName(QString::fromUtf8("ButtonSend6"));
        ButtonSend6->setGeometry(QRect(490, 530, 93, 28));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(750, 430, 191, 31));
        label_11->setAlignment(Qt::AlignCenter);
        slider6 = new QSlider(centralwidget);
        slider6->setObjectName(QString::fromUtf8("slider6"));
        slider6->setGeometry(QRect(120, 530, 261, 22));
        slider6->setMaximum(180);
        slider6->setOrientation(Qt::Horizontal);
        slider6->setTickPosition(QSlider::TicksBothSides);
        slider3 = new QSlider(centralwidget);
        slider3->setObjectName(QString::fromUtf8("slider3"));
        slider3->setGeometry(QRect(120, 380, 261, 22));
        slider3->setMaximum(180);
        slider3->setOrientation(Qt::Horizontal);
        slider3->setTickPosition(QSlider::TicksBothSides);
        ButtonSend2 = new QPushButton(centralwidget);
        ButtonSend2->setObjectName(QString::fromUtf8("ButtonSend2"));
        ButtonSend2->setGeometry(QRect(490, 330, 93, 28));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 520, 71, 41));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);
        spinBox3 = new QDoubleSpinBox(centralwidget);
        spinBox3->setObjectName(QString::fromUtf8("spinBox3"));
        spinBox3->setGeometry(QRect(401, 380, 81, 22));
        spinBox3->setMaximum(180.000000000000000);
        spinBox3->setSingleStep(0.100000000000000);
        ButtonSend1 = new QPushButton(centralwidget);
        ButtonSend1->setObjectName(QString::fromUtf8("ButtonSend1"));
        ButtonSend1->setGeometry(QRect(490, 280, 93, 28));
        ButtonConnect = new QPushButton(centralwidget);
        ButtonConnect->setObjectName(QString::fromUtf8("ButtonConnect"));
        ButtonConnect->setGeometry(QRect(940, 270, 93, 28));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(660, 480, 391, 192));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 420, 71, 41));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 320, 71, 41));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        spinBox2 = new QDoubleSpinBox(centralwidget);
        spinBox2->setObjectName(QString::fromUtf8("spinBox2"));
        spinBox2->setGeometry(QRect(401, 330, 81, 22));
        spinBox2->setMaximum(180.000000000000000);
        spinBox2->setSingleStep(0.100000000000000);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 470, 71, 41));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(750, 220, 191, 31));
        label_10->setAlignment(Qt::AlignCenter);
        ButtonSend4 = new QPushButton(centralwidget);
        ButtonSend4->setObjectName(QString::fromUtf8("ButtonSend4"));
        ButtonSend4->setGeometry(QRect(490, 430, 93, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 60, 471, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\255\227\351\255\20235\345\217\267-\347\273\217\345\205\270\351\233\205\351\273\221"));
        font1.setPointSize(36);
        label->setFont(font1);
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);
        ButtonSend3 = new QPushButton(centralwidget);
        ButtonSend3->setObjectName(QString::fromUtf8("ButtonSend3"));
        ButtonSend3->setGeometry(QRect(490, 380, 93, 28));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 370, 71, 41));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        spinBox1 = new QDoubleSpinBox(centralwidget);
        spinBox1->setObjectName(QString::fromUtf8("spinBox1"));
        spinBox1->setGeometry(QRect(401, 280, 81, 22));
        spinBox1->setMaximum(180.000000000000000);
        spinBox1->setSingleStep(0.100000000000000);
        spinBox5 = new QDoubleSpinBox(centralwidget);
        spinBox5->setObjectName(QString::fromUtf8("spinBox5"));
        spinBox5->setGeometry(QRect(401, 480, 81, 22));
        spinBox5->setMaximum(180.000000000000000);
        spinBox5->setSingleStep(0.100000000000000);
        LineEditPORT = new QLineEdit(centralwidget);
        LineEditPORT->setObjectName(QString::fromUtf8("LineEditPORT"));
        LineEditPORT->setGeometry(QRect(860, 300, 71, 41));
        ButtonDisconnect = new QPushButton(centralwidget);
        ButtonDisconnect->setObjectName(QString::fromUtf8("ButtonDisconnect"));
        ButtonDisconnect->setGeometry(QRect(940, 310, 93, 28));
        spinBox4 = new QDoubleSpinBox(centralwidget);
        spinBox4->setObjectName(QString::fromUtf8("spinBox4"));
        spinBox4->setGeometry(QRect(401, 430, 81, 22));
        spinBox4->setMaximum(180.000000000000000);
        spinBox4->setSingleStep(0.100000000000000);
        slider1 = new QSlider(centralwidget);
        slider1->setObjectName(QString::fromUtf8("slider1"));
        slider1->setGeometry(QRect(120, 280, 261, 22));
        slider1->setMaximum(180);
        slider1->setOrientation(Qt::Horizontal);
        slider1->setTickPosition(QSlider::TicksBothSides);
        slider4 = new QSlider(centralwidget);
        slider4->setObjectName(QString::fromUtf8("slider4"));
        slider4->setGeometry(QRect(120, 430, 261, 22));
        slider4->setMaximum(180);
        slider4->setOrientation(Qt::Horizontal);
        slider4->setTickPosition(QSlider::TicksBothSides);
        ButtonSTOP = new QPushButton(centralwidget);
        ButtonSTOP->setObjectName(QString::fromUtf8("ButtonSTOP"));
        ButtonSTOP->setEnabled(false);
        ButtonSTOP->setGeometry(QRect(210, 580, 191, 91));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        ButtonSTOP->setFont(font2);
        ButtonSTOP->setCursor(QCursor(Qt::PointingHandCursor));
        ButtonSTOP->setFlat(false);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(230, 220, 191, 31));
        label_9->setAlignment(Qt::AlignCenter);
        spinBox6 = new QDoubleSpinBox(centralwidget);
        spinBox6->setObjectName(QString::fromUtf8("spinBox6"));
        spinBox6->setGeometry(QRect(401, 530, 81, 22));
        spinBox6->setMaximum(180.000000000000000);
        spinBox6->setSingleStep(0.100000000000000);
        slider5 = new QSlider(centralwidget);
        slider5->setObjectName(QString::fromUtf8("slider5"));
        slider5->setGeometry(QRect(120, 480, 261, 22));
        slider5->setMaximum(180);
        slider5->setOrientation(Qt::Horizontal);
        slider5->setTickPosition(QSlider::TicksBothSides);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(870, 0, 261, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Consolas"));
        font3.setPointSize(10);
        label_2->setFont(font3);
        ButtonSend5 = new QPushButton(centralwidget);
        ButtonSend5->setObjectName(QString::fromUtf8("ButtonSend5"));
        ButtonSend5->setGeometry(QRect(490, 480, 93, 28));
        ButtonQuit = new QPushButton(centralwidget);
        ButtonQuit->setObjectName(QString::fromUtf8("ButtonQuit"));
        ButtonQuit->setGeometry(QRect(800, 360, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", "MainWindow"));
        label_3->setText(QCoreApplication::translate("MainWindow", "1\350\275\264", nullptr));
        LineEditIP->setText(QCoreApplication::translate("MainWindow", "192.168.221.162", nullptr));
        ButtonTestConnect->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\350\277\236\346\216\245", nullptr));
        ButtonSend6->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\346\216\247\345\210\266\345\217\260\350\276\223\345\207\272\351\235\242\346\235\277", nullptr));
        ButtonSend2->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "6\350\275\264", nullptr));
        ButtonSend1->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250", nullptr));
        ButtonConnect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "4\350\275\264", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "2\350\275\264", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "5\350\275\264", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\351\235\242\346\235\277", nullptr));
        ButtonSend4->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\242\260\350\207\202\346\216\247\345\210\266\344\270\255\345\277\203", nullptr));
        ButtonSend3->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "3\350\275\264", nullptr));
        LineEditPORT->setText(QCoreApplication::translate("MainWindow", "6657", nullptr));
        ButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200", nullptr));
        ButtonSTOP->setText(QCoreApplication::translate("MainWindow", "\347\264\247\346\200\245\344\270\255\346\226\255", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\350\247\222\345\272\246\346\216\247\345\210\266\351\235\242\346\235\277", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "v0.1 Alpha Designed by\357\274\232RoyZ", nullptr));
        ButtonSend5->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250", nullptr));
        ButtonQuit->setText(QCoreApplication::translate("MainWindow", "QUIT!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
