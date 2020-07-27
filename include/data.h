/**
	\file data.h
	\brief Test data filled on program startup
	
	\page data_page Hardcoded Data
	
	The hardcoded data are only for testing and
	are not needed by the PhoneBook class for running.
	
	It is expected that the content of the data will be used by the main
	application. When the application starts this initial set of data are filled
	to show the features of the class. The test application also include the
	command \e p \e to duplicate the data demonstrating the synonims support
	of the PhoneBook class.
	
	\section improvements Improvements 
	A possible improvement, that need to remove the limitations of working only
	with std:: libraries is providing this file in a Json format. The abiity
	to import Json data set can also be implemented in a future version of the
	class to populate the data vector externally.
	
	\note The phone number field is present in all the array elements but is
	an optional filed (weird, what is a phonebook entry without the phone n?).
	If the phone number is not present, it is requested a '--' string instead.
*/

//! The maximum number of entries statically defined
#define MAX_ENTRIES 14

/**
	The entries statically defined in this two dimensional array will be
	used to populate a first dataset.
*/
const char* fields[MAX_ENTRIES][3] = { { "Mario", "Rossi", "625487859" },
									{ "Gino", "Rossignolo", "49858596" },
									{ "Pino", "Rossino", "625487859" },
									{ "Stefania", "Lupano", "032565855" },
									{ "Antonio", "Taricone", "78485963" },
									{ "Stefano", "Tresti", "09265855" },
									{ "Carlo", "Dimaio", "68528546" },
									{ "Davide", "Gelli", "585548669" },
									{ "Marialuisa", "Pintus", "362945878" },
									{ "Daverio", "Corradi", "78598485" },
									{ "Chiara", "Zurzolo", "785998575" },
									{ "Lorenzina", "Celidonio", "3395998575" },
									{ "Davico", "Carrisi", "999633858" },
									{ "Daniele", "Delpiero", "001425886952" } };