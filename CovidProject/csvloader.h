#pragma once

#include <vector>
#include <qsharedpointer.h>
#include <Person.h>

class CsvLoader {
public:
	static std::vector<std::unique_ptr<Person>> LoadPersons(const std::string& _filepath, const std::string& _doctor_or_patient);
	static void SavePatients(const std::vector<std::unique_ptr<Person>>& _patients, const std::string&& _filepath);
};
