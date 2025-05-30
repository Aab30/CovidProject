#include <fstream>
#include <string>
#include "csvloader.h"
#include <sstream>
#include <doctor.h>
#include <patient.h>

std::vector<std::unique_ptr<Person>> CsvLoader::LoadPersons(const std::string& _filepath, const std::string& _doctor_or_patient) {
	std::vector<std::unique_ptr<Person>> people;
	std::ifstream file_stream_read;
	file_stream_read.open(_filepath);
	std::string line;
	if (file_stream_read.is_open()) {
		std::getline(file_stream_read, line); //This puts the header of the csv file in line so it is skipped
		while (std::getline(file_stream_read, line)) {
			std::stringstream line_read(line);
			std::vector<std::string> parameters;
			std::string parameter;
			while (std::getline(line_read, parameter, ';')) {
				parameters.push_back(parameter);
			}
			if (_doctor_or_patient == "doctor") {
				//Doctor CSV structure: name,surname,password,phoneNumber,email,speciliazisiton
				people.push_back(std::make_unique<Doctor>(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], parameters[5]));
			}

			else if (_doctor_or_patient == "patient") {
				//Patient CSV structure: name,surname,password,phoneNumber,email,positive,last_test_date
				bool isPositive = (parameters[5] == "true"); //Van string naar bool
				people.push_back(std::make_unique<Patient>(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], isPositive, parameters[6]));
			}

			else {
				//error verkeerde input
			}
		}
	}
	else {
		//error file niet geopend
	}
	return people;
}

void CsvLoader::SavePatients(const std::vector<std::unique_ptr<Person>>& _patients, const std::string&& _filepath) {
	std::ofstream file_stream;
	file_stream.open(_filepath);
	if (file_stream.is_open())
	{
		//header
		file_stream << "Name;Surname;Password;Phonenumber;Email;Positive;Last_test_date" << std::endl;
		for (const auto& p : _patients) {
			const Patient* patient = dynamic_cast<const Patient*>(p.get());
			if (patient) {
				file_stream << patient->getName() << ";"
					<< patient->getSurname() << ";"
					<< patient->getPassword() << ";"
					<< patient->getPhoneNumber() << ";"
					<< patient->getEmail() << ";"
					<< (patient->isPositive() ? "true" : "false") << ";"
					<< patient->getLastTestDate() << ";"
					<< std::endl;
			}
		}
		file_stream.close();
	}
}

