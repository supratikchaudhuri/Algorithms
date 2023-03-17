#include<bits/stdc++.h>
#include <fstream>
using namespace std;

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
        int key = 0;

        for(int i = 0; i < s.length(); i++) {
            if(!isalpha(s[i]))
                continue;
            key += ((int)s[i] + (i+1)*(i+1));
        }
        // cout<<s<<"\t -->"<<(int)((long)key * mult % MAXSIZE)<<endl;
        return (int)((long)key * mult % MAXSIZE);
    }

    public:
    void remove(string key) {
        int h = hash(key);
        Node* node = map[h];

        if(!node) return;

        if(node->key == key) {
            map[h] = node->next;
            delete node;
        } 
        else for(; node && node->next; node = node->next) {
            if(node->next->key == key) {
                Node* temp = node->next;
                node->next = node->next->next;
                delete temp;
            }
        }
    }


    
    void insert(string key, int count) {
        int h = hash(key);
        remove(key);

        map[h] = new Node(key, count, map[h]);
    }


    void increase(string key) {
        int h = hash(key);
        Node* node = map[h];

        // increase count if key found, or else do nothing
        for(; node != NULL; node = node->next) {
            if(node->key == key) {
                node->count++;
                return;
            }
        }
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

};

int main() {
    // string str = "hello my name is name of what is my name is th hello .";
    HashMap map;

    string str;

    ifstream MyFile("alice.txt");

    while (getline(MyFile, str)) {
        
        istringstream iss(str);
        string word;
        if(str.length() == 0) continue;

        while(iss >> word) {
            int c = map.find(word);
            map.insert(word, c+1);
        }
    }

    vector<string> all_words = map.list_all_keys();
    for(string w: all_words) {
        cout<<w<<"\t"<<map.find(w)<<endl;
    }

    MyFile.close();
    return 0;
}
