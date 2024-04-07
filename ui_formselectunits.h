/********************************************************************************
** Form generated from reading UI file 'formselectunits.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSELECTUNITS_H
#define UI_FORMSELECTUNITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSelectUnits
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *FormSelectUnits)
    {
        if (FormSelectUnits->objectName().isEmpty())
            FormSelectUnits->setObjectName("FormSelectUnits");
        FormSelectUnits->resize(399, 353);
        FormSelectUnits->setMinimumSize(QSize(100, 100));
        FormSelectUnits->setStyleSheet(QString::fromUtf8("image: url(:/polFlag.png);"));
        gridLayout = new QGridLayout(FormSelectUnits);
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(FormSelectUnits);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);


        retranslateUi(FormSelectUnits);

        QMetaObject::connectSlotsByName(FormSelectUnits);
    } // setupUi

    void retranslateUi(QWidget *FormSelectUnits)
    {
        FormSelectUnits->setWindowTitle(QCoreApplication::translate("FormSelectUnits", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("FormSelectUnits", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormSelectUnits: public Ui_FormSelectUnits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSELECTUNITS_H
