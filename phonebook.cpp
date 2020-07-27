/**
	\file phonebook.cpp
	\brief PhoneBook class
	
	Definition of the PhoneBook class methods.
	
*/

#include "include/phonebook.h"

using namespace std;

PhoneBook::PhoneBook(void) {
	cleanDataSet();
}

void PhoneBook::cleanDataSet() {
	dataIdCounter = 0;
	byName.clear();
	bySurname.clear();
	dataEntries.clear();
}

int PhoneBook::addEntry(EntryHeader *entry) {
	// Update the entry with the unique id
	entry->id = ++dataIdCounter;
	// Add the new entry to the end of the vector
	dataEntries.push_back(*entry);

	// Update the maps. As the new entry has been added to the end of the vector
	// The position id of the new element coresponds to the size-1 of the vector
	int mapIdx = dataEntries.size() - 1;	
	string keyName = toL(entry->name + '@' + to_string(dataIdCounter));
	string keySurname = toL(entry->surname + '@' + to_string(dataIdCounter));
	
	byName.emplace(make_pair(keyName, mapIdx));
	bySurname.emplace(make_pair(keySurname, mapIdx));
	
#ifdef _CLASS_DEBUG
	cout << "CLASS: EntryHeader* " << keyName << " " << 
			keySurname << " " << " " << entry->phone << 
			" " << entry->id << " " << mapIdx << endl;
#endif
	return 0;
}

string PhoneBook::toL(string uc) {
	string lc = uc;
	
	transform(uc.begin(), uc.end(), lc.begin(), ::tolower);
	
	return lc;
}

#ifdef _CLASS_DEBUG
void PhoneBook::dumpMapByName() {
	cout << "CLASS: dumpMapByName" << endl;
	for(map<string, int>::iterator it = byName.begin(); 
		it != byName.end(); ++it) {
	  cout << it->first << " " << it->second << "\n";
	}
}
void PhoneBook::dumpMapBySurname() {
	cout << "CLASS: dumpMapByName" << endl;
	for(map<string, int>::iterator it = bySurname.begin(); 
		it != bySurname.end(); ++it) {
	  cout << it->first << " " << it->second << "\n";
	}
}
#endif

int PhoneBook::deleteEntry(int id) {
	
	// Delete the vector to the corresponding position
	dataEntries.erase(dataEntries.begin() + id);
	
	// and remap the indexes
	remapIndexes();
	
	return 0;
	
}

void PhoneBook::remapIndexes() {
	byName.clear();
	bySurname.clear();
	
	for(unsigned int j = 0; j < dataEntries.size(); j++) {
		string keyName = toL(dataEntries.at(j).name + 
			'@' + to_string(dataEntries.at(j).id));
		string keySurname = toL(dataEntries.at(j).surname + 
			'@' + 
			to_string(dataEntries.at(j).id));
		
		byName.emplace(make_pair(keyName, j));
		bySurname.emplace(make_pair(keySurname, j));
	}
}

int PhoneBook::searchForDelete(string key) {
	int foundId = -1;
	
	// Search for the first occurrence, if any
	auto mapResult = bySurname.lower_bound(key);
	if(mapResult != bySurname.end() ) {
		string kFound = mapResult->first;
		if(kFound.substr(0, key.size()).compare(key) == 0) {
			foundId = mapResult->second;
		}		
	}
	return foundId; // Not found
}

int PhoneBook::searchForId(string key, vector<int> *list, int orderType) {
	switch(orderType) {
	case ORDER_NAME: {
		auto kFound = byName.lower_bound(key);
		if(kFound != byName.end()) {
			for (map<string, int>::iterator it = kFound; it != byName.end(); it++) {
				string mapKey = it->first;
				if(mapKey.substr(0, key.size()).compare(key) != 0) {
					break;
					}
				list->push_back(it->second);
				}
			}
		}
		break;
	case ORDER_SURNAME: {
		auto kFound = bySurname.lower_bound(key);
		if(kFound != bySurname.end()) {
			for (map<string, int>::iterator it = kFound; it != bySurname.end(); it++) {
				string mapKey = it->first;
				if(mapKey.substr(0, key.size()).compare(key) != 0) {
					break;
					}
				list->push_back(it->second);
				}
			}
		}
		break;
	}
	return 0;
}

void PhoneBook::getOrderedId(vector<int> *list, int orderType) {
	switch(orderType) {
	case ORDER_NAME:
		// Iterate the whole map
		for(map<string, int>::iterator it = byName.begin(); 
			it != byName.end(); ++it) {
			// Update the list with the data index
			list->push_back(it->second);
			}
		break;
	case ORDER_SURNAME:
		// Iterate the whole map
		for(map<string, int>::iterator it = bySurname.begin(); 
			it != bySurname.end(); ++it) {
			// Update the list with the data index
			list->push_back(it->second);
			}
		break;
	}
}

int PhoneBook::getEntry(int id, EntryHeader *entry) {
	entry->name = dataEntries.at(id).name;
	entry->surname = dataEntries.at(id).surname;
	entry->phone = dataEntries.at(id).phone;

	return 0;
}




