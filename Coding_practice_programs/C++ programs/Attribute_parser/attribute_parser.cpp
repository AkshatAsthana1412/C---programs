#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
// #include <string>
using namespace std;


vector<string> tag_stack;
map<string, string> attrs;

void insert_attr(string &attr, string &value){
    string res = "";
    for(string &tag: tag_stack){
        tag.push_back('.');
        res += tag;
    }
    res.pop_back();
    res += "~" + attr;
    attrs[res] = value;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i){
        // cin >> tag; this takes in the entire line as input at once, and hence we can't
        //             break the input into tag, attr and value, thus it's wrong
        // if (tag[1] == '/') //closing tag
        //     tag_stack.pop_back();

        char ch; cin >> ch; //break the string by taking in '<' first
        if (cin.peek() == '/'){ //closing tag peek() checks the input stream without
                                //actually consuming the input. i.e. without storing
                                //it in a variable in the program.
            string temp; 
            cin >> temp; //we have "tag>" in temp now.
            tag_stack.pop_back();
        }

        else{
            string tag;
            cin >> tag;
            if (tag.back() == '>'){ //no attributes
                tag.pop_back(); //remove '>' from the back of tag
                tag_stack.push_back(tag);
            }
            else{
                tag_stack.push_back(tag);
                for(;;){
                    string attr, eq, value;
                    cin >> attr >> eq >> value;
                    if(value.back() == '>'){
                        value.pop_back(); //delete '>' from the back
                        value.pop_back(); //delet " from the back
                        value = value.substr(1);
                        insert_attr(attr, value);
                        break;
                    }
                    else{
                        value.pop_back();
                        value = value.substr(1);
                        insert_attr(attr, value);
                    }
                }
            }
        }
    }  

    for (int i = 0; i < q; ++i){
        string qr;
        cin >> qr;
        if (attrs.find(qr) != attrs.end()){
            cout << attrs[qr] << endl;
        }
        else{
            cout << "Not Found!" << endl;
        }
    }
    return 0;
}



// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <map>
// using namespace std;

// vector<string> tag_stack;
// map<string, string> attrs;
    

// void insert_attr(string & name, string & val) {
//     string full;
//     for(string & str : tag_stack)
//         full += str + ".";
//     full.pop_back();
//     full += "~" + name;
//     attrs[full] = val;
    
// }

// int main() {
//     int n, q;
//     cin >> n >> q;
    
//     for(int i = 0; i < n; ++i) {
//         char c; cin >> c;
//         if(cin.peek() == '/') { // close
//             string cn; cin >> cn;
//             tag_stack.pop_back();
//         }
//         else { //open'
//             string name;
//             cin >> name;
//             if(name.back() == '>') { //no attrs
//                 name.pop_back();
//                 tag_stack.push_back(name);
//             }
//             else {
//                 tag_stack.push_back(name);
                 
//                 for(;;) { 
//                     string attr_name, attr_val, eq;
//                     cin >> attr_name >> eq >> attr_val;
//                     if(attr_val.back() == '>') { //last attr
//                         attr_val.pop_back();
//                         attr_val.pop_back();
//                         attr_val = attr_val.substr(1);
//                         insert_attr(attr_name, attr_val);
//                         break;
//                     }
//                     else {
//                         attr_val.pop_back();
//                         attr_val = attr_val.substr(1);
//                         insert_attr(attr_name, attr_val);
//                     }
//                 }
//             }
                
//         }
//     }
    
//     for(int i = 0; i < q; ++i) {
//         string quer;
//         cin >> quer;
//         if(attrs.find(quer) != attrs.end())
//             cout << attrs[quer] << endl;
//         else 
//             cout << "Not Found!" << endl;
//     }
    
    
//     return 0;
// }