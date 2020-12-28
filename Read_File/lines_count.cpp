#include <iostream>
#include "read_file.h"
#include <vector>
using namespace std;
//returns the count of lines in the file 'file_path'
int lines_count(string file_path){
    vector<string> lines = getLines(file_path);
    return lines.size();
}

int main(){
    string file_path;
    cout << "enter the file path:\n";
    cin >> file_path;
    cout << "the number of lines in " << file_path << "is: " << lines_count(file_path);
    return 0;
}