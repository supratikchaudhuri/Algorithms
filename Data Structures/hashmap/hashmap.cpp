#include<bits/stdc++.h>
#include <fstream>
#include"preprocessing.h"
using namespace std;

void getWord(string &s);

struct Node {
    string key;
    int count;
    Node* next;

    Node(string key, int count, Node* next) {
        this->key = key;
        this->count = count;
        this->next = next;
    }
};

class HashMap {
    const static int MAXSIZE = 1000;
    const static int mult = 12582917;
    Node* map[MAXSIZE] = {};
    
    int hash (string s) {
        long key = 0;

        for(int i = 0; i < s.length(); i++) {
            if(!isalpha(s[i]))
                continue;
            key += ((int)s[i] + (i+2)*(i+3)*(i*i)*s[i]) ;
            // key += ((int)s[i] + (i+1)*(i+1));
        }

        return (int)(key * mult % MAXSIZE);
    }

    public:
    int size = 0;
    int collisions = 0;
    int longest_chain = 0;

    int getHash(string word) {
        return hash(word);
    }

    void remove(string key) {
        int h = hash(key);
        Node* node = map[h];

        if(!node) return;

        if(node->key == key) {
            map[h] = node->next;
            size--;
            delete node;
        } 
        else for(; node && node->next; node = node->next) {
            if(node->next->key == key) {
                Node* temp = node->next;
                node->next = node->next->next;
                delete temp;
                size--;
            }
        }
    }


    
    void insert(string key, int count) {
        int h = hash(key);
        remove(key);

        if(map[h] != NULL) {
            collisions++;
            Node *p = map[h];

            for(int chainLen = 0; p != NULL; p = p->next)
                longest_chain = max(longest_chain, ++chainLen);
        }

        map[h] = new Node(key, count, map[h]);
        size++;
    }


    int increase(string key) {
        int h = hash(key);
        Node* node = map[h];

        // increase count if key found, or else do nothing
        for(; node != NULL; node = node->next) {
            if(node->key == key) {
                node->count++;
                return node->count;
            }
        }
        return 0;
    }

    int find(string key) {
        int h = hash(key);
        Node* node = map[h];

        if(node == NULL)
            return 0;

        for(; node != NULL; node = node->next) {
            if(node->key == key)
                return node->count;
        }
        return 0;
    }

    vector<string> list_all_keys() {
        vector<string> words;
        for(int i = 0; i < MAXSIZE; i++) {
            Node * node = map[i];

            for(; node != NULL; node = node->next) 
                words.push_back(node->key);
        }
        return words;
    } 

    unordered_map<int, int> chainLengthCount() {
        unordered_map<int, int> res;
        
        for(int i = 0, len = 0; i < MAXSIZE; i++, len = 0) {
            Node* p = map[i];
            if(!p) continue;

            for(; p != NULL; p = p->next) 
                len++;
    
            res[len]++;
        }
        return res;
    }

};

int main() {
    HashMap map;

    cout<< "Choose file to read: ";
    string fileName; cin >> fileName;
    fileName = "alice.txt";
    readFileAndPutInMap(fileName, map);


    int input;
    while(1) {
        cout<<"\n\nChoose Operation: \n"
        "1.Search word\n2. List all keys\n3. Insert word\n"
        "4. Increase word count\n5. Get word's hash\n6. Get map size\n"
        "7. Get map collisions and longest chain length\n"
        "8. Get chain length counts\n";
        cin >> input;
        string s;

        switch (input) {
            
            case 1: {
                getWord(s);
                int count = map.find(s);
                if(count == 0)
                    cout<< s <<" not found in the map. Count = 0";
                else    
                    cout<< "word found !   " << s << "'s count = " << count << endl;  
                break;
            }
            case 2: {
                vector<string> all_words = map.list_all_keys();
                cout<<"\nWORD\t\tCOUNT"<<"\t\tHASH\n";
                for(string w: all_words) {
                    cout<<w<<"\t\t"<<map.find(w)<<"\t\t"<<map.getHash(w)<<endl;
                }
                break;
            }
            case 3: {
                getWord(s);
                int c = map.find(s);
                map.insert(s, c+1);
                break;
            }
            case 4: {
                getWord(s);
                int new_count = map.increase(s);
                
                if(new_count)
                    cout<< "Count increased successfully!\n Updated count = "<< new_count;
                else    
                    cout<<s<< " doesn't exists in the map";
                break;
            }
            case 5: {
                getWord(s);
                cout<< "Hash: "<< map.getHash(s);
                break;
            }
            case 6: {
                cout<<"Map size = "<<map.size;
                break;
            }
            case 7: {
                cout<<"Map collisions= "<<map.collisions<<" Longest chain length= "<<(map.size ? max(map.longest_chain, 1) : 0);
                break;
            }
            case 8: {
                auto lenMap = map.chainLengthCount();
                cout<<"LENGHT\tCOUNT\n";
                for(auto it: lenMap)
                    cout<<it.first<<"\t"<<it.second<<endl;
                break;
            }
            case 10:
                exit(1);
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