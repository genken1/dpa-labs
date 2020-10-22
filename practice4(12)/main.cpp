#include <iostream>
#include "handler.h"

int main() {
    string filename = "person.txt";
    handler handler(filename);
    handler.initTestData();

    cout << "File content:" << endl;
    handler.printFileData();

    cout << endl << "After delete person data:" << endl;
    handler.delElementByKey('7');
    handler.printFileData();

    cout << endl << "After sort by first three number:" << endl;
    handler.printSortData("893");

    return 0;
}
