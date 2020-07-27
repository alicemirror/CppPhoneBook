/**
	\file globals.h
	\brief Global definitions
	
	\note These definitions are only for testing purposes and are not needed
	to use the PhoneBook class, as well as should not be included in any
	application using the class.
	
*/

#define VERSION "0.1"
#define BUILD "26"

//! The number of available commands
#define NUM_COMMANDS 9
//! The commands list sown on help
std::string helpCommands[] = { 
	"<a> Add a new Entry",
	"<d> Delete an Entry",
	"<1> List all entries ordered by Name",
	"<2> List all entries ordered by Surname",
	"<n> Search entries by Name",	
	"<s> Search entries by Surname",
	"<p> Populate (again!)",
	"<x> Exit",
	"<?> This list of commands"
	};

// ----------------------------- Commands
#define ADD_ENTRY 'a'
#define DELETE_ENTRY 'd'
#define ENTRIES_BY_NAME '1'
#define ENTRIES_BY_SURNAME '2'
#define SEARCH_BY_NAME 'n'
#define SEARCH_BY_SURNAME 's'
#define POPULATE_AGAIN 'p'
#define EXIT 'x'
#define HELP '?'

// ----------------------------- Messages
#define WRONG_COMMAND "Command not recognized. Type '?' for help"
#define SURNAME_ENTRIES "Address Book ordered by surname"
#define NAME_ENTRIES "Address Book ordered by name"
#define DELETE "Delete the selected entry"
#define ADD "Add a new entry"
#define SEARCH_SURNAME "Search entries by surname"
#define SEARCH_NAME "Search entries by name"
