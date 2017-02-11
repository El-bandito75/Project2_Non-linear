#include <iostream>
#include <string>
#include <cstdlib>
#include "cityInfo.h"
#include "cityInfo.h"
using namespace std;


int main(int argCount, char *argValues[]) {
	cityInfo citAray;

	citAray.readFile();
	string temp = citAray.getDataCity(1);

	cout << temp << endl;




	citAray.writeFile();
	return EXIT_SUCCESS;
}
