#pragma once
#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "core/factory.h"

//单例模式
Factory* Factory::privateFactory = new (std::nothrow) Factory;

int main(int argc, char *argv[])
{ 
    /*加载core*/
    Factory::GetInstance()->read_from_file();   //读文件
    Factory::GetInstance()->write_RTfile(); //重新写入RT文件
    Factory::GetInstance()->read_RTfile();  //读取RT文件

    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "cppProjectNew_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.setWindowTitle("工厂设备管理系统");
    w.show();

    return a.exec();
}
