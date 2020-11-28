#include <iostream>
//fstream header contains ifstream class, ofstream class and fstream class
#include <fstream>
#include <vector>
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

int main(){
    string file_path;
    cout << "Input the file path:\n";
    cin >> file_path;
    for (string line: getLines(file_path))
        cout << line << endl;
    return 0;
}