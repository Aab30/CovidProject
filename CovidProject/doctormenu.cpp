#include "doctormenu.h"
#include "patientlist.h"

DoctorMenu::DoctorMenu(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
}

void DoctorMenu::on_patientlistButton_clicked() {
	PatientList* patientlist = new PatientList();
	patientlist->show();

}
void DoctorMenu::on_covidtestButton_clicked() {

}

void DoctorMenu::on_signoffButton_clicked() {

}

