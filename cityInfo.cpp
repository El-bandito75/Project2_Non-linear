#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "cityInfo.h"

using namespace std;


void cityInfo::readFile() {
	ifstream file("text.txt");
	string curInfo;
	int plcHold = 0;//place holder
	int numOfCity = 0;//number of city

	while (file >> curInfo) {
		if (curInfo == "~~~~~~~") { 	// a line of seven '~' spilt the different cities
			plcHold = 0;
			numOfCity = numOfCity + 1;
		}
		else {
			dataCity[numOfCity][plcHold] = curInfo;
			plcHold++;
		}
	}
}

void cityInfo::writeFile() {
	ofstream myWrite;
	myWrite.open("text.txt");
	int numOfCity = 0;

	while ((dataCity[numOfCity][0].empty()) == false) {
		for (int i = 0; i < 6; i++) {
			myWrite << dataCity[numOfCity][i] << endl;
		}
		myWrite << "~~~~~~~" << endl; // there are seven of these'`' that serpate the cities 
		numOfCity++;
	}
	myWrite.close();
}

string cityInfo::getDataCity(int i) {
	string info = "";
	for (int j = 0; j < 6; j++) {
		info = info + dataCity[i][j];
		info = info + '\n';
	}
	return info;
}

string cityInfo::printMsg(bool beGin) {
	string in = "";
	if (beGin == true) {
		cout << "Welcome to the City Database!" << endl;
		cout << "Enter 'Help' to get list of commands" << endl;
		cout << ": ";
	}else {
		cout << ": ";
	}
	
	cin >> in;
	return in; 
}
string cityInfo::getNameCity(int i) {
	return dataCity[i][0];
}

int cityInfo::findCity(string keyWord) {
	int numOfCity = 0;
	int temp = 0;
	bool isFound = false;

		while ((dataCity[numOfCity][0].empty()) == false) {
			for (int i = 0; i < 6; i++) {
				if (dataCity[numOfCity][i] == keyWord) {
					displayCity(numOfCity);
					isFound = true;
				}
			}
			numOfCity++;
		}
		if (isFound == false) {
			return -1;
		}
		return 0;
}

void cityInfo::listCities() {
	int numOfCity = 0;
	while ((dataCity[numOfCity][0].empty()) == false) {
		for (int i = 0; i < 6; i++) {
			cout << dataCity[numOfCity][i] << endl;
		}
		cout << "-------------------------" << endl;
		numOfCity++;
	}
}

void cityInfo::addNewCity(int currCitLoc) {
	string newCity = "", name = "", state = "", conty = "", log = "", lan = "", pop = "";
	int endOfList = 0;

	cout << "Please enter the following info." << endl;
	cout << "Name of city: ";
	cin >> name;
	cout << "State/Province: ";
	cin >> state;
	cout << "Country: ";
	cin >> conty;
	cout << "Longitude: ";
	cin >> log;
	cout << "Latitude: ";
	cin >> lan;
	cout << "Population: ";
	cin >> pop;

	while (newCity != "CUR" && newCity != "END") {
		cout << "Do you want to add new city in the current spot or at the end?" << endl;
		cout << "Enter 'CUR' for current spot or 'END' for end." << endl;
		cout << ": ";
		cin >> newCity;
		endOfList = findEnd();
		endOfList++;
		if (newCity == "CUR") {
			while (endOfList> currCitLoc) {
				for (int i = 0; i < 6; i++) {
					dataCity[endOfList][i] = dataCity[endOfList-1][i];
				}
				endOfList--;
			}
			dataCity[currCitLoc][0] = name;
			dataCity[currCitLoc][1] = state;
			dataCity[currCitLoc][2] = conty;
			dataCity[currCitLoc][3] = log;
			dataCity[currCitLoc][4] = lan;
			dataCity[currCitLoc][5] = pop;
			cout << name << " has been entered to the list" << endl;
			break;
		}else if (newCity == "END") { 
			dataCity[endOfList][0] = name;
			dataCity[endOfList][1] = state;
			dataCity[endOfList][2] = conty;
			dataCity[endOfList][3] = log;
			dataCity[endOfList][4] = lan;
			dataCity[endOfList][5] = pop;
			cout << name << " has been entered to the list at the end" << endl;
			break;
		}else {
			cout << "Please enter 'CUR' or 'END'." << endl;
			// do nothing
		}
	}
}
int cityInfo::findEnd() {
	int numOfCity = 0;
	while ((dataCity[numOfCity][0].empty()) == false) {
		for (int i = 0; i < 6; i++) {
		}
		numOfCity++;
	}
	return numOfCity-1;
}
void cityInfo::displayCity(int currCitLoc) {
	for (int i = 0; i < 6; i++) {
		cout << dataCity[currCitLoc][i] << endl;
	}
	cout << "-------------------------" << endl;
}
void cityInfo::deleteCity(int currCitLoc){
	while ((dataCity[currCitLoc][0].empty()) == false) {
		for (int i = 0; i < 6; i++) {
			dataCity[currCitLoc][i] = dataCity[currCitLoc + 1][i];
		}
		currCitLoc++;
	}
}
