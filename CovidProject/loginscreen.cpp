#include "loginscreen.h"
#include "doctormenu.h"
#include "patientmenu.h"
#include "error_handling.h"


LoginScreen::LoginScreen(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	ErrorType error;
	auto all_persons = CsvLoader::LoadAllPersons("Data/persons.csv", error);
	ErrorHandling::ReportError(error, "LoginScreen - Constructor");
	m_patients = CsvLoader::FilterPatients(all_persons, error);
	ErrorHandling::ReportError(error, "LoginScreen - Constructor");
	m_doctors = CsvLoader::FilterDoctors(all_persons, error);
	ErrorHandling::ReportError(error, "LoginScreen - Constructor");
}

void LoginScreen::on_loginButton_clicked() {
	QString username = ui.emailEdit->text();
	QString password = ui.passwordEdit->text();
	
	if (!ui.doctorButton->isChecked() && !ui.patientButton->isChecked()) {
		QMessageBox::warning(this, "Login failed", "You must check one of the boxes");
		return;
	}

	else if (ui.doctorButton->isChecked()) {
		for (const auto& doctor : m_doctors) {
			if (doctor->getEmail() == username.toStdString() && doctor->getPassword() == password.toStdString()) {
				DoctorMenu* doctormenu = new DoctorMenu();
				doctormenu->setAttribute(Qt::WA_DeleteOnClose);
				doctormenu->show();
				this->close();
				return;
			}
		}
	}

	else if (ui.patientButton->isChecked()) {
		for (const auto& patient: m_patients) {
			if (patient->getEmail() == username.toStdString() && patient->getPassword() == password.toStdString()) {
				PatientMenu* patientmenu = new PatientMenu();
				patientmenu->show();
				this->close();
				return;
			}
		}
	}
	
	
	QMessageBox::warning(this, "Login failed", "Wrong username or password");
	
}

LoginScreen::~LoginScreen() {
}
