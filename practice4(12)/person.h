#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class person {
public:
	person();

	person(string phoneNumber,
           string address,
           string name
	);

	string phoneNumber;
	string address;
	string name;

	void toString() const;
};


#endif //PERSON_H
