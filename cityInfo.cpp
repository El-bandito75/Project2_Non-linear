#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "cityInfo.h"

using namespace std;
//***********************************************************
//*                                                         *
//* Wirtten by Michael Revilla 1/28/2017                    *
//* Project 2: City Info - Non-linear Data Structures       *
//*                                                         *
//***********************************************************

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

	//**this is for testing**
	//cout << "--------" << endl;
	//cout << dataCity[0][0] << endl;
	//cout << dataCity[1][0] << endl;
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


