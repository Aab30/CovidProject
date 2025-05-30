#include <fstream>
#include <string>
#include "csvloader.h"
#include <sstream>
#include "doctor.h"
#include "patient.h"
#include <iostream>
#include <functional>


// New type-based implementation
std::vector<std::unique_ptr<Person>> CsvLoader::LoadAllPersons(const std::string& _filepath, ErrorType& _error) {
	std::vector<std::unique_ptr<Person>> persons;
	std::ifstream file(_filepath);

	_error = ErrorType::No_Error;

	if (!file.is_open()) {
		_error = ErrorType::File_Open_Failed;
		return persons;
	}

	std::string line;
	std::getline(file, line); // Skip header

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::vector<std::string> fields;
		std::string field;

		while (std::getline(ss, field, ';')) { // Using semicolon separator
			fields.push_back(field);
		}

		if (auto person = createPersonFromData(fields, _error)) {
			persons.push_back(std::move(person));
		}
	}

	return persons;
}

std::unique_ptr<Person> CsvLoader::createPersonFromData(const std::vector<std::string>& _data, ErrorType& _error) {

	_error = ErrorType::No_Error;

	if (_data.size() < 6) {
		_error = ErrorType::Wrong_Amount_Of_Parameters;
		return nullptr;
	}

	const std::string& type = _data[0];

	if (type == "Doctor") {
		if (_data.size() < 7) return nullptr;
		// type;name;surname;password;phoneNumber;email;specialization;positive;last_test_date
		return std::make_unique<Doctor>(
			_data[1], _data[2], _data[3], _data[4], _data[5], _data[6]
			);
	}
	else if (type == "Patient") {
		if (_data.size() < 9) return nullptr;
		// type;name;surname;password;phoneNumber;email;specialization;positive;last_test_date
		bool isPositive = (_data[7] == "true");
		return std::make_unique<Patient>(
			_data[1], _data[2], _data[3], _data[4], _data[5], isPositive, _data[8]
			);
	}
	else {
		_error = ErrorType::Wrong_Type;
		return nullptr;
	}
}

std::vector<std::unique_ptr<Doctor>> CsvLoader::FilterDoctors(const std::vector<std::unique_ptr<Person>>& _persons, ErrorType& _error) {
	std::vector<std::unique_ptr<Doctor>> doctors;
	_error = ErrorType::No_Error;

	for (const auto& person : _persons) {
		if (Doctor* doctor = dynamic_cast<Doctor*>(person.get())) {
			// Create a copy of the doctor
			doctors.push_back(std::make_unique<Doctor>(
				doctor->getName(),
				doctor->getSurname(),
				doctor->getPassword(),
				doctor->getPhoneNumber(),
				doctor->getEmail(),
				doctor->getSpecialization()
				));
		}
		else {
			_error = ErrorType::Invalid_Cast;
		}
	}

	return doctors;
}

std::vector<std::unique_ptr<Patient>> CsvLoader::FilterPatients(const std::vector<std::unique_ptr<Person>>& _persons, ErrorType& _error) {
	std::vector<std::unique_ptr<Patient>> patients;
	_error = ErrorType::No_Error;

	for (const auto& person : _persons) {
		if (Patient* patient = dynamic_cast<Patient*>(person.get())) {
			// Create a copy of the patient
			patients.push_back(std::make_unique<Patient>(
				patient->getName(),
				patient->getSurname(),
				patient->getPassword(),
				patient->getPhoneNumber(),
				patient->getEmail(),
				patient->isPositive(),
				patient->getLastTestDate()
				));
		}
		else {
			_error = ErrorType::Invalid_Cast;
		}
	}

	return patients;
}
