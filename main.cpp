/**
	\file main.cpp
	\brief Main application
	
	the main application is used to test the features of the PhoneBook class
	and uses a set of stored information pre-loaded when the appication starts.
	
	\version 0.1
	\author Enrico Migino <enrico.miglino@gmail.com>
	\date July 2020
	
	\todo Add a command to delete all the dataset
*/

#include <iostream>
#include <string>
#include "include/phonebook.h"
#include "include/data.h"
#include "include/globals.h"

using namespace std;

// Undef below to remove the debug messages
#undef _DEBUG

/**
	Shows the applicaiton information
*/
void help() {
	cout << "---------------------------------" << endl;
	cout << "Phonebook v. " << VERSION << " (build " << BUILD << ")" << endl;
	cout << "---------------------------------" << endl;
	for(int j = 0; j < NUM_COMMANDS; j++) {
		cout << helpCommands[j] << endl;
	}
	cout << "---------------------------------" << endl << endl;
}

/**
	Populate the phonebook with an initial set of hardcoded data
*/
void populate(PhoneBook* pb) {
	//! Temporary entry header used for input fields.
	EntryHeader t_entry;

	for(int j = 0; j < MAX_ENTRIES; j++) {

		t_entry.name = fields[j][0];
		t_entry.surname = fields[j][1];
		t_entry.phone = fields[j][2];

		pb->addEntry(&t_entry);
		
		#ifdef _DEBUG
		cout << "DEB: " << "Populate() " << fields[j][0] << " " <<
		fields[j][1] << endl;
		#endif
	}
}

//! Get an input from the cin
string getInput(string comment) {
	string in;
	
	cout << comment << " (no spaces)?>";
	cin >> in;
	
	return in;
}

string inputKey(void) {
	string kk;
	kk = getInput("Insert the search keyword");
	
	return kk;
}

//! Get the fields for a new insertion
void inputAllFields(EntryHeader *fields) {
	fields->name = getInput("Name");
	fields->surname = getInput("Surname");
	fields->phone = getInput("Phone, or '--' if not available");
}

/**
	Input an id for an entry. Generic function used for data retrieval and 
	deletion.
	
	\return The ID value
*/
int inputId() {
	int id;

	cout << "Add a valid phonebook entry ID" << endl;
	cin >> id;
	
	return id;
}

//! Main application, class testing
int main(int argc, char **argv) {
	//! Flag set to extir from the applicaiton
	//! maybe useful if some final check should che done
	//! before the program closes.
	bool exiting = false;
	//! Temporary entry header used for input fields.
	EntryHeader t_entry;
	//! PhoneBook class instance
	PhoneBook myPhoneBook;

	
	// Any parameter passed to the program just shows the help info
	if(argc > 1) {
		help();
	}

	// Populate the dataset and show the menu
	populate(&myPhoneBook);
	help();

	// Application loop
	while(!exiting) {
		char cmd;
		
		cout << "?>";
		cin >> cmd;
		
		switch(cmd) {
		case ADD_ENTRY:
			cout << ADD << endl;
			inputAllFields(&t_entry);
			myPhoneBook.addEntry(&t_entry);
				break;
		case DELETE_ENTRY: {
			int delId; ///< Id of the element to delete
			string searchKey; ///< Key searching the element to delete
			
			// Search for the key
			searchKey = myPhoneBook.toL(inputKey());
			delId = myPhoneBook.searchForDelete(searchKey);
			
			if(delId < 0) {
				cout << "No entry found!" << endl;
			} else {
				// ask for confirmation to delete the entry
				myPhoneBook.getEntry(delId, &t_entry);
				cout << "Confirm for deleting " << t_entry.name << 
				" " << t_entry.surname << " " << t_entry.phone << 
				" ? (y/n) ";
				string confirm;
				cin >> confirm;
				if(myPhoneBook.toL(confirm)[0] == char('y')) {
					myPhoneBook.deleteEntry(delId);
					cout << " Deleted" << endl;
				} else {
					cout << "Deletion aborted" << endl;
					}
				}
			}
			break;
		case ENTRIES_BY_NAME: {
			cout << NAME_ENTRIES << endl;
			//! Local entries list
			vector<int> myEntries;
			// Get the ordered list of IDs
			myPhoneBook.getOrderedId(&myEntries, ORDER_NAME);
			// Retrieve the data following the list order
			for(unsigned int j = 0; j < myEntries.size(); j++) {
				myPhoneBook.getEntry(myEntries.at(j), &t_entry);
				cout << j + 1 << ") " << t_entry.name << " " << t_entry.surname <<
				" " << t_entry.phone << endl;
				}
			}
			break;
		case ENTRIES_BY_SURNAME: {
			cout << SURNAME_ENTRIES << endl;
			//! Local entries list
			vector<int> myEntries;
			// Get the ordered list of IDs
			myPhoneBook.getOrderedId(&myEntries, ORDER_SURNAME);
			// Retrieve the data following the list order
			for(unsigned int j = 0; j < myEntries.size(); j++) {
				myPhoneBook.getEntry(myEntries.at(j), &t_entry);
				cout << j + 1 << ") " << t_entry.surname << " " << t_entry.name <<
				" " << t_entry.phone << endl;
				}
			}
			break;
		case SEARCH_BY_NAME: {
			cout << SEARCH_NAME << endl;
			//! Local entries list
			vector<int> myEntries;
			// Input the search key
			string sKey = myPhoneBook.toL(inputKey());
			// Get the ordered list of IDs
			myPhoneBook.searchForId(sKey, &myEntries, ORDER_NAME);
			// Retrieve the data following the list order
			for(unsigned int j = 0; j < myEntries.size(); j++) {
				myPhoneBook.getEntry(myEntries.at(j), &t_entry);
				cout << j + 1 << ") " << t_entry.name << " " << t_entry.surname <<
				" " << t_entry.phone << endl;
				}
			}
			break;
		case SEARCH_BY_SURNAME: {
			cout << SEARCH_SURNAME << endl;
			//! Local entries list
			vector<int> myEntries;
			// Input the search key
			string sKey = myPhoneBook.toL(inputKey());
			// Get the ordered list of IDs
			myPhoneBook.searchForId(sKey, &myEntries, ORDER_SURNAME);
			// Retrieve the data following the list order
			for(unsigned int j = 0; j < myEntries.size(); j++) {
				myPhoneBook.getEntry(myEntries.at(j), &t_entry);
				cout << j + 1 << ") " << t_entry.surname << " " << t_entry.name <<
				" " << t_entry.phone << endl;
				}
			}
			break;
		case POPULATE_AGAIN:
			populate(&myPhoneBook);
			break;
		case EXIT:
			exiting = true;
			break;
		case HELP:
			help();
			break;
		default:
			cout << WRONG_COMMAND << endl;
		}
	}
	
	return 0;
}
