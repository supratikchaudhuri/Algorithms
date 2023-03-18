#include<bits/stdc++.h>
#include <fstream>
using namespace  std;


string to_lower(string s) {
    string res = "";
    int i = 0, j= s.length()-1; 
    while(s[i] == '\'') i++;
    while(s[j] == '\'') j--;

    for(; i <= j; i++) {
        char &c = s[i];
        if(isalpha(c)) res += tolower(c);
    }
    // cout<<res<<endl;
    return res.length() >= 1 ? res : "";
}

void replaceNoAlphaAndUpperCaseChars(string &s) {
    
    for(int i = 0; i < s.length(); i++) {
        char &c = s[i];

        if(c == '\'')
            continue;
        else if(!isalpha(c)) 
            c = ' ';
        else    
            c = tolower(c);
    }
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
            word = to_lower(word);
            if(word.length() == 0) continue;
            int c = map.find(word);
            map.insert(word, c+1);
        }
    }

    MyFile.close();

}