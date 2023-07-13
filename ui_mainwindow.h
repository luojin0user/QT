/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *user;
    QPushButton *LargeShow;
    QPushButton *SmallShow;
    QPushButton *RTbutton;
    QPushButton *close;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 400);
        QIcon icon;
        icon.addFile(QString::fromUtf8("file/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        user = new QPushButton(centralwidget);
        user->setObjectName("user");
        user->setAutoDefault(false);

        gridLayout->addWidget(user, 0, 1, 1, 1);

        LargeShow = new QPushButton(centralwidget);
        LargeShow->setObjectName("LargeShow");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        LargeShow->setFont(font);
        LargeShow->setAutoDefault(true);

        gridLayout->addWidget(LargeShow, 1, 0, 1, 1);

        SmallShow = new QPushButton(centralwidget);
        SmallShow->setObjectName("SmallShow");
        SmallShow->setFont(font);
        SmallShow->setAutoDefault(true);

        gridLayout->addWidget(SmallShow, 2, 0, 1, 1);

        RTbutton = new QPushButton(centralwidget);
        RTbutton->setObjectName("RTbutton");
        RTbutton->setFont(font);
        RTbutton->setAutoDefault(true);

        gridLayout->addWidget(RTbutton, 3, 0, 1, 1);

        close = new QPushButton(centralwidget);
        close->setObjectName("close");
        close->setFont(font);
        close->setAutoDefault(true);

        gridLayout->addWidget(close, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        user->setText(QCoreApplication::translate("MainWindow", "\350\275\257\344\273\266\350\257\264\346\230\216", nullptr));
        LargeShow->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\207\272\347\224\237\344\272\247\350\256\276\345\244\207", nullptr));
        SmallShow->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\207\272\345\205\266\344\273\226\350\256\276\345\244\207", nullptr));
        RTbutton->setText(QCoreApplication::translate("MainWindow", "\345\256\236\346\227\266\346\230\276\347\244\272", nullptr));
        close->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
