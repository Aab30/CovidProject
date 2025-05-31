/********************************************************************************
** Form generated from reading UI file 'covidtest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COVIDTEST_H
#define UI_COVIDTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CovidTest
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CovidTest)
    {
        if (CovidTest->objectName().isEmpty())
            CovidTest->setObjectName(QString::fromUtf8("CovidTest"));
        CovidTest->resize(600, 700);
        QFont font;
        font.setFamily(QString::fromUtf8("Menlo"));
        CovidTest->setFont(font);
        centralwidget = new QWidget(CovidTest);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CovidTest->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CovidTest);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 24));
        CovidTest->setMenuBar(menubar);
        statusbar = new QStatusBar(CovidTest);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CovidTest->setStatusBar(statusbar);

        retranslateUi(CovidTest);

        QMetaObject::connectSlotsByName(CovidTest);
    } // setupUi

    void retranslateUi(QMainWindow *CovidTest)
    {
        CovidTest->setWindowTitle(QApplication::translate("CovidTest", "COVID-19 Scan Analysis", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CovidTest: public Ui_CovidTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COVIDTEST_H
