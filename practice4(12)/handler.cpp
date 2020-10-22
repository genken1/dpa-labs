#include "handler.h"

handler::handler(const string &filename) {
    this->filename = filename;
}

void handler::dataInFile(vector<person> &data, string &fName) {
    ofstream fout(fName);

    for (int i = 0; i < data.size(); i++) {
        fout
                << data.at(i).phoneNumber << ' '
                << data.at(i).address << ' '
                << data.at(i).name << ' ';

        if (i != data.size() - 1) {
            fout << endl;
        }
    }

    fout.close();
}

void handler::initTestData() {
    vector<person> data;
    person p1 = person("88005553535", "Moscow", "name1");
    person p2 = person("89370684587", "Rome", "name2");
    person p3 = person("89370684587", "Rome", "name3");
    person p4 = person("89617986541", "Volgograd", "name4");
    person p5 = person("79815632189", "Saratov", "name5");
    data.push_back(p1);
    data.push_back(p2);
    data.push_back(p3);
    data.push_back(p4);
    data.push_back(p5);
    dataInFile(data, filename);
}

void handler::dataOutFile(vector<person> &data) {
    ifstream fin;
    fin.open(filename);

    if (fin.is_open()) {
        data.clear();
        person p;
        string phoneNumber;

        while (fin.good()) {
            getline(fin, phoneNumber, ' ');

            if (phoneNumber.empty() || phoneNumber == "\n") {
                break;
            } else if (!data.empty()) {
                phoneNumber.erase(0, 1);
            }

            p.phoneNumber = phoneNumber;
            getline(fin, p.address, ' ');
            getline(fin, p.name, ' ');

            data.push_back(p);
        }
    } else {
        cout << "Could not open the file " << filename << endl;
    }

    fin.close();
}

bool handler::delElementByKey(char smb) {
    vector<person> data;
    dataOutFile(data);
    int size = data.size();
    for (int i = 0; i < size; ++i) {
        if (smb == data[i].phoneNumber[0]){
            for (int j = i; j < data.size()-1; j++) {
                data[j] = data[j+1];
            }
            data.pop_back();
            i--;
            size--;
        }
    }
    dataInFile(data, filename);
    return size==data.size();
}

void handler::printSortData(string number) {
    vector<string> newData;
    vector<person> data;
    dataOutFile(data);
    for (int i = 0; i < data.size(); ++i) {
        if (number == data[i].phoneNumber.substr(0, 3)){
           newData.push_back(data[i].name);
        }
    }
    ofstream fout("sortFile");
    for (int i = 0; i < newData.size(); i++) {
        fout<< newData.at(i);
        if (i != newData.size() - 1) {
            fout << endl;
        }
    }
    fout.close();
    ifstream fin;
    fin.open("sortFile");
    string line;
    if (fin.is_open())
    {
        while (! fin.eof() )
        {
            getline (fin, line);
            cout << line << endl;
        }
        fin.close();
    } else {
        cout << "Could not open the file " << filename << endl;
    }
    fin.close();
}

void handler::printFileData() {
    vector<person> data;
    dataOutFile(data);

    if (data.empty()) {
        cout << "File is empty" << endl;
    }

    for (int i = 0; i < data.size(); i++) {
        data.at(i).toString();
    }
}
