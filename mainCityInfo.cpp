#include <iostream>
#include <string>
#include <cstdlib>
#include "cityInfo.h"
#include "cityInfo.h"
using namespace std;
//***********************************************************
//*                                                         *
//* Wirtten by Michael Revilla 1/28/2017                    *
//* Project 2: City Info - Non-linear Data Structures       *
//*                                                         *
//***********************************************************
void printHelp() {
	cout << "Here is the list of commands!" << endl;
	cout << "Exit -- Exits the Program." << endl;
	cout << "Add -- Adds a city to the list of cities." << endl;
	cout << "List -- List all of the cities. " << endl;
	cout << "Next -- List the next city in the list." << endl;
	cout << "Previous -- List the previous city in the list." << endl;
	cout << "Delete -- Deletes the current city." << endl;
	cout << "First -- Takes you to first city in list." << endl;
	cout << "Last -- Takes you to last city in list." << endl;
	cout << "Search -- Search for city by name." << endl;
	cout << "Current -- Displays current city in list." << endl;
}

int main(int argCount, char *argValues[]) {
	cityInfo citAray;
	citAray.readFile();
	string inPut = "";
	string temp = "";
	int cityNum = 0;
	int currCitLoc = 0; // Current city in list
	bool beGin = true;

	while (inPut != "Exit") {
		inPut = citAray.printMsg(beGin);
		int end = citAray.findEnd();
		beGin = false;
		if (inPut == "Help") {
			printHelp();
		}else if (inPut == "Add") {
			citAray.addNewCity(currCitLoc);
		}else if(inPut == "List"){
			citAray.listCities();
		}else if (inPut == "Next") {
			if (currCitLoc==end) {
				cout << "You are at the end of the list." << endl;
			}else {
				currCitLoc++;
			}
			citAray.displayCity(currCitLoc);
		}else if (inPut == "Previous") {
			if (currCitLoc == 0) {
				cout << "You are at the beign of the list." << endl;
			}else {
				currCitLoc--;	
			}
			citAray.displayCity(currCitLoc);
		}else if (inPut == "Delete") {
			string nameCity = "";
			nameCity = citAray.getNameCity(currCitLoc);
			cout << "Are you sure you want to delete " << nameCity << " from the list?" << endl;
			cout << "Enter 'YES' for yes or enter 'NO' for no." << endl;
			cin >> temp;
			if (temp == "YES") {
				citAray.deleteCity(currCitLoc);
				cout << nameCity << " has been deleted from the list." << endl;
			}else {
				cout << nameCity << " will not be deleted from the list." << endl;
			}
		}else if (inPut == "First") {
			citAray.displayCity(0);
			currCitLoc = 0;
		}else if (inPut == "Last") {
			citAray.displayCity(end);
			currCitLoc = end;
		}else if (inPut == "Search") {
			cout << "Please type in the name of the city or the name of the State/country your city is in: ";
			cin >> temp;
			cityNum = citAray.findCity(temp);
			if (cityNum == -1) {
				cout << "Sorry there is no city with that name in this database! " << endl;
			}else {
				//do nothing
			}
		}else if (inPut == "Current") {
			citAray.displayCity(currCitLoc);
		}else if (inPut == "Exit") {
			//do nothing the loop will break and program will close!
		}else {
			cout << "That was not a vaild command!!" << endl;
			cout << "Type 'Help' for list of commands!" << endl;
		}
	}
	citAray.writeFile();
	return EXIT_SUCCESS;
}
