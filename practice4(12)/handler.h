#ifndef HANDLER_H
#define HANDLER_H
#include <iostream>
#include <fstream>
#include <vector>
#include "person.h"

using namespace std;

class handler {
public:
	explicit handler(const string& filename);

	bool delElementByKey(char smb);

	void printSortData(string number);

	void printFileData();

	void initTestData();

private:
	string filename;

	void dataInFile(vector<person> &data, string &filename);

	void dataOutFile(vector<person> &data);
};

#endif //HANDLER_H
