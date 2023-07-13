/********************************************************************************
** Form generated from reading UI file 'addinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINFO_H
#define UI_ADDINFO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddInfo
{
public:
    QPushButton *Reset;
    QPushButton *WriteOk;
    QPushButton *AddNew;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_6;
    QDateEdit *dateEdit_7;
    QDateEdit *dateEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;

    void setupUi(QWidget *AddInfo)
    {
        if (AddInfo->objectName().isEmpty())
            AddInfo->setObjectName("AddInfo");
        AddInfo->resize(631, 312);
        QIcon icon;
        icon.addFile(QString::fromUtf8("file/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddInfo->setWindowIcon(icon);
        Reset = new QPushButton(AddInfo);
        Reset->setObjectName("Reset");
        Reset->setGeometry(QRect(110, 220, 92, 29));
        Reset->setAutoDefault(true);
        WriteOk = new QPushButton(AddInfo);
        WriteOk->setObjectName("WriteOk");
        WriteOk->setGeometry(QRect(350, 220, 92, 29));
        WriteOk->setAutoDefault(true);
        AddNew = new QPushButton(AddInfo);
        AddNew->setObjectName("AddNew");
        AddNew->setGeometry(QRect(230, 220, 92, 29));
        AddNew->setAutoDefault(true);
        layoutWidget = new QWidget(AddInfo);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(100, 20, 173, 165));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEdit_1 = new QLineEdit(layoutWidget);
        lineEdit_1->setObjectName("lineEdit_1");

        verticalLayout_4->addWidget(lineEdit_1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout_4->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");

        verticalLayout_4->addWidget(lineEdit_3);

        comboBox_4 = new QComboBox(layoutWidget);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");

        verticalLayout_4->addWidget(comboBox_4);

        comboBox_5 = new QComboBox(layoutWidget);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");

        verticalLayout_4->addWidget(comboBox_5);

        layoutWidget1 = new QWidget(AddInfo);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(410, 20, 173, 165));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_6 = new QComboBox(layoutWidget1);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName("comboBox_6");

        verticalLayout->addWidget(comboBox_6);

        dateEdit_7 = new QDateEdit(layoutWidget1);
        dateEdit_7->setObjectName("dateEdit_7");
        dateEdit_7->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));

        verticalLayout->addWidget(dateEdit_7);

        dateEdit_8 = new QDateEdit(layoutWidget1);
        dateEdit_8->setObjectName("dateEdit_8");
        dateEdit_8->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));

        verticalLayout->addWidget(dateEdit_8);

        lineEdit_9 = new QLineEdit(layoutWidget1);
        lineEdit_9->setObjectName("lineEdit_9");

        verticalLayout->addWidget(lineEdit_9);

        lineEdit_10 = new QLineEdit(layoutWidget1);
        lineEdit_10->setObjectName("lineEdit_10");

        verticalLayout->addWidget(lineEdit_10);

        layoutWidget2 = new QWidget(AddInfo);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(320, 20, 91, 161));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName("label_6");

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName("label_7");

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName("label_8");

        verticalLayout_2->addWidget(label_8);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName("label_9");

        verticalLayout_2->addWidget(label_9);

        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName("label_10");

        verticalLayout_2->addWidget(label_10);

        layoutWidget3 = new QWidget(AddInfo);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 20, 91, 161));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(layoutWidget3);
        label_1->setObjectName("label_1");

        verticalLayout_3->addWidget(label_1);

        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName("label_4");

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        label = new QLabel(AddInfo);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 270, 461, 20));

        retranslateUi(AddInfo);

        QMetaObject::connectSlotsByName(AddInfo);
    } // setupUi

    void retranslateUi(QWidget *AddInfo)
    {
        AddInfo->setWindowTitle(QCoreApplication::translate("AddInfo", "Form", nullptr));
        Reset->setText(QCoreApplication::translate("AddInfo", "\351\207\215\347\275\256", nullptr));
        WriteOk->setText(QCoreApplication::translate("AddInfo", "\347\241\256\345\256\232\345\271\266\350\277\224\345\233\236", nullptr));
        AddNew->setText(QCoreApplication::translate("AddInfo", "\347\273\247\347\273\255\346\267\273\345\212\240", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("AddInfo", "\346\230\257", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("AddInfo", "\345\220\246", nullptr));

        comboBox_5->setItemText(0, QCoreApplication::translate("AddInfo", "\346\230\257", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("AddInfo", "\345\220\246", nullptr));

        comboBox_6->setItemText(0, QCoreApplication::translate("AddInfo", "\346\230\257", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("AddInfo", "\345\220\246", nullptr));

        label_6->setText(QCoreApplication::translate("AddInfo", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("AddInfo", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("AddInfo", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("AddInfo", "TextLabel", nullptr));
        label_10->setText(QCoreApplication::translate("AddInfo", "TextLabel", nullptr));
        label_1->setText(QCoreApplication::translate("AddInfo", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("AddInfo", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("AddInfo", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("AddInfo", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("AddInfo", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("AddInfo", "\346\263\250\357\274\232\345\234\250\346\267\273\345\212\240\345\256\214\350\256\276\345\244\207\345\220\216\357\274\214\350\257\267\347\202\271\345\207\273\344\270\273\351\241\265\351\235\242\347\232\204\345\210\267\346\226\260\346\214\211\351\222\256\345\206\215\344\277\235\345\255\230\357\274\214\351\230\262\346\255\242\345\207\272\351\224\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddInfo: public Ui_AddInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINFO_H
