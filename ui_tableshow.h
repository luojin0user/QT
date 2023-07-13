/********************************************************************************
** Form generated from reading UI file 'tableshow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLESHOW_H
#define UI_TABLESHOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableShow
{
public:
    QLabel *label;
    QPushButton *back;
    QTableWidget *table_output;
    QPushButton *tablePush;
    QPushButton *ButtonAddNew;
    QLabel *outputLabel;
    QLabel *label_2;
    QLabel *ItemLabel;
    QPushButton *DeleteRow;
    QGroupBox *groupBox;
    QRadioButton *edit_enable;
    QRadioButton *edit_disable;
    QPushButton *saveAll;
    QLineEdit *searchInput;
    QLabel *label_3;
    QPushButton *startSearch;
    QPushButton *searchReset;
    QPushButton *startRT;
    QPushButton *stopRT;
    QGroupBox *badMessageGroup;
    QRadioButton *startBadMessage;
    QRadioButton *stopBadMessage;
    QLabel *label_4;
    QLabel *data_time;

    void setupUi(QWidget *TableShow)
    {
        if (TableShow->objectName().isEmpty())
            TableShow->setObjectName("TableShow");
        TableShow->resize(1206, 556);
        QIcon icon;
        icon.addFile(QString::fromUtf8("file/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        TableShow->setWindowIcon(icon);
        TableShow->setAutoFillBackground(true);
        TableShow->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(TableShow);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 80, 30));
        back = new QPushButton(TableShow);
        back->setObjectName("back");
        back->setGeometry(QRect(30, 50, 92, 29));
        back->setAutoDefault(true);
        table_output = new QTableWidget(TableShow);
        table_output->setObjectName("table_output");
        table_output->setGeometry(QRect(10, 140, 1181, 391));
        tablePush = new QPushButton(TableShow);
        tablePush->setObjectName("tablePush");
        tablePush->setGeometry(QRect(30, 90, 92, 29));
        tablePush->setAutoDefault(true);
        ButtonAddNew = new QPushButton(TableShow);
        ButtonAddNew->setObjectName("ButtonAddNew");
        ButtonAddNew->setGeometry(QRect(140, 50, 92, 29));
        ButtonAddNew->setAutoDefault(true);
        outputLabel = new QLabel(TableShow);
        outputLabel->setObjectName("outputLabel");
        outputLabel->setGeometry(QRect(90, 10, 151, 30));
        label_2 = new QLabel(TableShow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(900, 110, 69, 20));
        ItemLabel = new QLabel(TableShow);
        ItemLabel->setObjectName("ItemLabel");
        ItemLabel->setGeometry(QRect(980, 110, 181, 20));
        DeleteRow = new QPushButton(TableShow);
        DeleteRow->setObjectName("DeleteRow");
        DeleteRow->setGeometry(QRect(140, 90, 92, 29));
        DeleteRow->setAutoDefault(true);
        groupBox = new QGroupBox(TableShow);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(610, 50, 120, 71));
        edit_enable = new QRadioButton(groupBox);
        edit_enable->setObjectName("edit_enable");
        edit_enable->setGeometry(QRect(10, 30, 41, 24));
        edit_disable = new QRadioButton(groupBox);
        edit_disable->setObjectName("edit_disable");
        edit_disable->setGeometry(QRect(60, 30, 41, 24));
        edit_disable->setChecked(true);
        saveAll = new QPushButton(TableShow);
        saveAll->setObjectName("saveAll");
        saveAll->setGeometry(QRect(240, 90, 92, 29));
        saveAll->setAutoDefault(true);
        searchInput = new QLineEdit(TableShow);
        searchInput->setObjectName("searchInput");
        searchInput->setGeometry(QRect(290, 50, 113, 25));
        searchInput->setTabletTracking(true);
        label_3 = new QLabel(TableShow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(250, 50, 41, 20));
        startSearch = new QPushButton(TableShow);
        startSearch->setObjectName("startSearch");
        startSearch->setGeometry(QRect(410, 50, 92, 29));
        startSearch->setAutoDefault(true);
        searchReset = new QPushButton(TableShow);
        searchReset->setObjectName("searchReset");
        searchReset->setGeometry(QRect(510, 50, 92, 29));
        searchReset->setAutoDefault(true);
        startRT = new QPushButton(TableShow);
        startRT->setObjectName("startRT");
        startRT->setGeometry(QRect(340, 90, 92, 29));
        startRT->setAutoDefault(true);
        stopRT = new QPushButton(TableShow);
        stopRT->setObjectName("stopRT");
        stopRT->setGeometry(QRect(440, 90, 101, 31));
        stopRT->setAutoDefault(true);
        badMessageGroup = new QGroupBox(TableShow);
        badMessageGroup->setObjectName("badMessageGroup");
        badMessageGroup->setGeometry(QRect(740, 50, 141, 71));
        startBadMessage = new QRadioButton(badMessageGroup);
        startBadMessage->setObjectName("startBadMessage");
        startBadMessage->setGeometry(QRect(10, 30, 41, 24));
        stopBadMessage = new QRadioButton(badMessageGroup);
        stopBadMessage->setObjectName("stopBadMessage");
        stopBadMessage->setGeometry(QRect(70, 30, 41, 24));
        stopBadMessage->setChecked(true);
        label_4 = new QLabel(TableShow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(900, 20, 71, 20));
        data_time = new QLabel(TableShow);
        data_time->setObjectName("data_time");
        data_time->setGeometry(QRect(970, 20, 191, 20));

        retranslateUi(TableShow);

        QMetaObject::connectSlotsByName(TableShow);
    } // setupUi

    void retranslateUi(QWidget *TableShow)
    {
        TableShow->setWindowTitle(QCoreApplication::translate("TableShow", "Form", nullptr));
        label->setText(QCoreApplication::translate("TableShow", "\345\275\223\345\211\215\345\212\237\350\203\275\357\274\232", nullptr));
        back->setText(QCoreApplication::translate("TableShow", "\350\277\224\345\233\236", nullptr));
        tablePush->setText(QCoreApplication::translate("TableShow", "\345\210\267\346\226\260", nullptr));
        ButtonAddNew->setText(QCoreApplication::translate("TableShow", "\346\267\273\345\212\240\350\256\276\345\244\207", nullptr));
        outputLabel->setText(QCoreApplication::translate("TableShow", "\346\227\240", nullptr));
        label_2->setText(QCoreApplication::translate("TableShow", "\345\275\223\345\211\215\345\206\205\345\256\271\357\274\232", nullptr));
        ItemLabel->setText(QCoreApplication::translate("TableShow", "\346\227\240", nullptr));
        DeleteRow->setText(QCoreApplication::translate("TableShow", "\345\210\240\351\231\244", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TableShow", "\346\230\257\345\220\246\345\274\200\345\220\257\347\274\226\350\276\221", nullptr));
        edit_enable->setText(QCoreApplication::translate("TableShow", "\346\230\257", nullptr));
        edit_disable->setText(QCoreApplication::translate("TableShow", "\345\220\246", nullptr));
        saveAll->setText(QCoreApplication::translate("TableShow", "\344\277\235\345\255\230", nullptr));
        label_3->setText(QCoreApplication::translate("TableShow", "\346\220\234\347\264\242\357\274\232", nullptr));
        startSearch->setText(QCoreApplication::translate("TableShow", "\347\241\256\345\256\232", nullptr));
        searchReset->setText(QCoreApplication::translate("TableShow", "\351\207\215\347\275\256", nullptr));
        startRT->setText(QCoreApplication::translate("TableShow", "\345\256\236\346\227\266\350\276\223\345\207\272", nullptr));
        stopRT->setText(QCoreApplication::translate("TableShow", "\345\201\234\346\255\242\345\256\236\346\227\266\350\276\223\345\207\272", nullptr));
        badMessageGroup->setTitle(QCoreApplication::translate("TableShow", "\346\230\257\345\220\246\345\274\200\345\220\257\346\215\237\345\235\217\345\274\271\347\252\227", nullptr));
        startBadMessage->setText(QCoreApplication::translate("TableShow", "\346\230\257", nullptr));
        stopBadMessage->setText(QCoreApplication::translate("TableShow", "\345\220\246", nullptr));
        label_4->setText(QCoreApplication::translate("TableShow", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
        data_time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TableShow: public Ui_TableShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLESHOW_H
