#include "person.h"
#include <iostream>
#include <utility>

person::person() = default;

person::person(string phoneNumber,
               string address,
               string name) {
    this->phoneNumber = move(phoneNumber);
    this->address = move(address);
    this->name = move(name);
}

void person::toString() const {
    cout
        << "Phone number: " << phoneNumber
        << ", address: "
        << address
        << ", person name: "
        << name
        << endl;
}
