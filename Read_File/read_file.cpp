#include <iostream>
//fstream header contains ifstream class, ofstream class and fstream class
#include <fstream>
#include <vector>
#include "read_file.h"
using namespace std;

vector <string> getLines(string file_path){
    vector <string> lines;
    ifstream fin;
    //open file
    fin.open(file_path);
    //traverse through the file
    string line;
    while (!fin.eof()){
        getline(fin, line);
        //push line into the vector
        lines.push_back(line);
    }
    fin.close();
    return lines;
}
