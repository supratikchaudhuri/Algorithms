#include<bits/stdc++.h>
#include <fstream>
#include"preprocessing.h"
#include"hashmap.h"
using namespace std;

void getWord(string &s);


int main() {
    HashMap map;

    cout<< "Choose file to read: ";
    string fileName; cin >> fileName;
    fileName = "alice.txt";
    readFileAndPutInMap(fileName, map);


    int input;
    while(1) {
        cout<<"\n\nChoose Operation: \n"
        "1.Search word\n2. List all keys\n3. Insert word\n4. Delete Word\n"
        "5. Increase word count\n6. Get word's hash\n7. Get map size\n"
        "8. Get map collisions and longest chain length\n"
        "9. Get chain length counts\n0. Press to exit\n";
        cin >> input;
        string s;

        switch (input) {
            
            case 1: {
                getWord(s);
                int count = map.find(s);
                if(count == 0)
                    cout<< s <<" not found in the map. Count = 0";
                else    
                    cout<< "word found !   " << s << " word count = " << count << endl;  
                break;
            }
            case 2: {
                vector<string> all_words = map.list_all_keys();
                cout<<"Keys: "<<all_words.size()<<endl;
                cout<<"\nWORD\t\tCOUNT"<<"\t\tHASH\n";
                // for(string w: all_words) {
                //     cout<<w<<"\t\t"<<map.find(w)<<"\t\t"<<map.getHash(w)<<endl;
                // }
                for(string w: all_words)
                    cout<<w<<" ";
                break;
            }
            case 3: {
                getWord(s);
                int c = map.find(s);
                map.insert(s, c+1);
                cout<< "Word inserted successfully!";
                break;
            }
            case 4: {
                getWord(s);
                map.remove(s);
                cout<<"Number deleted!";
                break;
            }
            case 5: {
                getWord(s);
                int new_count = map.increase(s);
                
                if(new_count)
                    cout<< "Count increased successfully!\n Updated count = "<< new_count;
                else    
                    cout<<s<< " doesn't exists in the map";
                break;
            }
            case 6: {
                getWord(s);
                cout<< "Hash: "<< map.getHash(s);
                break;
            }
            case 7: {
                cout<<"Map size = "<<map.size;
                break;
            }
            case 8: {
                cout<<"Map collisions= "<<map.collisions<<" Longest chain length= "<<(map.size ? max(map.longest_chain, 1) : 0);
                break;
            }
            case 9: {
                auto lenMap = map.chainLengthCount();
                cout<<"LENGHT\tCOUNT\n";
                for(auto it: lenMap)
                    cout<<it.first<<"\t"<<it.second<<endl;
                break;
            }
            case 0:
                exit(0);
            default:
                break;
        }
    }

    return 0;
}


void getWord(string &s) {
    cout << "Enter word: ";
    cin >> s;
    s = to_lower(s);
}