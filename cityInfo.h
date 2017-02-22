#ifndef __cityInfo_H__
#define __cityInfo_H__

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class cityInfo {
protected:

	string  dataCity[10][6];// change to 1000

public:
	
	string getDataCity(int i);
	string printMsg(bool beGin);
	string getNameCity(int i);
	int findCity(string keyWord);
	int findEnd();

	void readFile();
	void writeFile();
	void listCities();
	void deleteCity(int currCitLoc);
	void displayCity(int currCitLoc);
	void addNewCity(int currCitLoc);
};

#endif
