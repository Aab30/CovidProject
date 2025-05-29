#include "loginscreen.h"
#include "doctormenu.h"
#include "patientmenu.h"


LoginScreen::LoginScreen(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	m_patients = CsvLoader::loadPersons("Data/patient.csv", "patient");
	m_doctors = CsvLoader::loadPersons("Data/doctor.csv", "doctor");
}

void LoginScreen::on_loginButton_clicked() {
	QString username = ui.emailEdit->text();
	QString password = ui.passwordEdit->text();
	
	if (!ui.doctorButton->isChecked() && !ui.patientButton->isChecked()) {
		QMessageBox::warning(this, "Login failed", "You must check one of the boxes");
		return;
	}

	else if (ui.doctorButton->isChecked()) {
		for (const auto& person : m_doctors) {
			if (person->getEmail() == username.toStdString() && person->getPassword() == password.toStdString()) {
				DoctorMenu* doctorMenu = new DoctorMenu();
				doctorMenu->setAttribute(Qt::WA_DeleteOnClose);
				doctorMenu->show();
				this->close();
				return;
			}
		}
	}

	else if (ui.patientButton->isChecked()) {
		for (const auto& person : m_patients) {
			if (person->getEmail() == username.toStdString() && person->getPassword() == password.toStdString()) {
				PatientMenu* patientmenu = new PatientMenu();
				patientmenu->show();
				this->close();
				return;
			}
		}
	}
	
	
	QMessageBox::warning(this, "Login failed", "Wrong username or password");
	
}

