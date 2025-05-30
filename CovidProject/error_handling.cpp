#include "error_handling.h"
#include "QDebug"

void ErrorHandling::ReportError(ErrorType _error, const QString& _context) {
	QString message;
	switch (_error) {
	case ErrorType::No_Error:
		return;
	case ErrorType::Wrong_Type:
		message = "Wrong type";
		break;
	case  ErrorType::Wrong_Input:
		message = "Wrong input";
		break;
	case ErrorType::File_Open_Failed:
		message = "Couldnt open file";
		break;
	case ErrorType::Wrong_Amount_Of_Parameters:
		message = "Not the right amount of parameters";
		break;
	case ErrorType::Invalid_Cast:
		message = "Cast Failed";
		break;
	}
	qCritical() << "[" << _context << "]" << message;
}
