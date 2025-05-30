#pragma once

#include <vector>
#include <qsharedpointer.h>
#include <memory>
#include <functional>
#include <string>
#include "person.h"
#include "data_types.h"

// Forward declarations
class Doctor;
class Patient;

class CsvLoader {
public:

	// New type-based methods
	static std::vector<std::unique_ptr<Person>> LoadAllPersons(const std::string& _filepath, ErrorType& _error);
	static std::vector<std::unique_ptr<Doctor>> FilterDoctors(const std::vector<std::unique_ptr<Person>>& _persons, ErrorType& _error);
	static std::vector<std::unique_ptr<Patient>> FilterPatients(const std::vector<std::unique_ptr<Person>>& _persons, ErrorType& _error);

private:
	static std::unique_ptr<Person> createPersonFromData(const std::vector<std::string>& _data, ErrorType& _error);
};
