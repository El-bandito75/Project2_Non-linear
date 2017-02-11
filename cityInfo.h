#ifndef __cityInfo_H__
#define __cityInfo_H__

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class cityInfo {
protected:
	string  name;
	string  stateProv;  // get rid of these
	string  country;    // only need dataCity
	string  log;
	string  lat;
	string  pop; 
	string  dataCity[10][6];// change to 1000

public:
	
	string getName();
	void setName();
	
	void setDataCity();
	string getDataCity(int i);

	void readFile();
	void writeFile();
};

#endif
