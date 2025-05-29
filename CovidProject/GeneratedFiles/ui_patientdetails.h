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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_PatientDetails
{
public:
    QTableView *patientdetailsView;

    void setupUi(QDialog *PatientDetails)
    {
        if (PatientDetails->objectName().isEmpty())
            PatientDetails->setObjectName(QString::fromUtf8("PatientDetails"));
        PatientDetails->resize(400, 300);
        patientdetailsView = new QTableView(PatientDetails);
        patientdetailsView->setObjectName(QString::fromUtf8("patientdetailsView"));
        patientdetailsView->setGeometry(QRect(25, 21, 351, 261));

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
