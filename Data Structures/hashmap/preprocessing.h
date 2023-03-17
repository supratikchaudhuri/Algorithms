#include<bits/stdc++.h>
#include <fstream>
using namespace  std;


string to_lower(string s) {
    string res = "";

    for(char c : s)
        res += tolower(c);
    
    return res;
}

void replaceNoAlphaAndUpperCaseChars(string &s) {
    for(char &c : s)
        if(!isalpha(c)) 
            c = ' ';
        else    
            c = tolower(c);
}

template <typename T>
void readFileAndPutInMap(string fileName, T &map) {
    string str;
    ifstream MyFile(fileName);

    while (getline(MyFile, str)) {
        replaceNoAlphaAndUpperCaseChars(str);

        istringstream iss(str);
        string word;
        
        if(str.length() == 0) continue;

        while(iss >> word) {
            int c = map.find(word);
            map.insert(word, c+1);
        }
    }

    MyFile.close();

}