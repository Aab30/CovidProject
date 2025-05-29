#pragma once

#include <vector>
#include <qsharedpointer.h>
#include <Person.h>

class CsvLoader {
public:
	static std::vector<std::unique_ptr<Person>> loadPersons(const std::string& _filepath, const std::string& _doctor_or_patient);
};
