/********************************************************************************
** Form generated from reading UI file 'patientdetails.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTDETAILS_H
#define UI_PATIENTDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_PatientDetails
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QTableView *patientdetailsView;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *PatientDetails)
    {
        if (PatientDetails->objectName().isEmpty())
            PatientDetails->setObjectName(QString::fromUtf8("PatientDetails"));
        PatientDetails->resize(540, 432);
        PatientDetails->setMinimumSize(QSize(300, 400));
        gridLayout = new QGridLayout(PatientDetails);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        patientdetailsView = new QTableView(PatientDetails);
        patientdetailsView->setObjectName(QString::fromUtf8("patientdetailsView"));
        QFont font;
        font.setFamily(QString::fromUtf8("Menlo"));
        patientdetailsView->setFont(font);

        gridLayout->addWidget(patientdetailsView, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        retranslateUi(PatientDetails);

        QMetaObject::connectSlotsByName(PatientDetails);
    } // setupUi

    void retranslateUi(QDialog *PatientDetails)
    {
        PatientDetails->setWindowTitle(QApplication::translate("PatientDetails", "Patient details", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientDetails: public Ui_PatientDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTDETAILS_H
