/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *price_info;
    QLabel *price;
    QPushButton *dele;
    QTableView *tableView2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(1278, 596);
        price_info = new QLabel(Form);
        price_info->setObjectName(QString::fromUtf8("price_info"));
        price_info->setGeometry(QRect(420, 390, 300, 35));
        price_info->setStyleSheet(QString::fromUtf8("font: 30pt \"MS Shell Dlg 2\";\n"
"color:rgb(170, 0, 0) ;"));
        price_info->setAlignment(Qt::AlignCenter);
        price = new QLabel(Form);
        price->setObjectName(QString::fromUtf8("price"));
        price->setGeometry(QRect(780, 390, 150, 35));
        price->setStyleSheet(QString::fromUtf8("font: 30pt \"MS Shell Dlg 2\";\n"
"color:rgb(170, 0, 0) ;"));
        price->setAlignment(Qt::AlignCenter);
        dele = new QPushButton(Form);
        dele->setObjectName(QString::fromUtf8("dele"));
        dele->setGeometry(QRect(820, 210, 200, 60));
        dele->setStyleSheet(QString::fromUtf8("font: 24pt \"MS Shell Dlg 2\";"));
        tableView2 = new QTableView(Form);
        tableView2->setObjectName(QString::fromUtf8("tableView2"));
        tableView2->setGeometry(QRect(220, 40, 500, 300));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        price_info->setText(QApplication::translate("Form", "TOTAL PR\304\260CE", nullptr));
        price->setText(QString());
        dele->setText(QApplication::translate("Form", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
