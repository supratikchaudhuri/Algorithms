#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode *child[26];
    bool eow; 
};

struct TrieNode* getNode() {
    TrieNode *node = new TrieNode;
    node->eow = false;
    
    for(int i = 0; i < 26; i++) {
        node->child[i] = NULL;
    }
    return node;
}

void insert(TrieNode *root, string word) {
    TrieNode *it = root;

    for(char c : word) {
        if(!it->child[c-'a'])
            it->child[c-'a'] = getNode();
        it = it->child[c-'a'];
    }
    it->eow = true;
}

bool search(TrieNode *root, string word) {
    TrieNode *it = root;

    for(char ch : word) {
        if(!it->child[ch-'a'])
            return false;
        it = it->child[ch-'a'];
    }
    return (it != NULL && it->eow == true);
}

bool startsWith(TrieNode *root, string prefix) {
    TrieNode* it = root;
    
    for(char ch : prefix) {
        if(!it->child[ch-'a'])
            return false;
        it = it->child[ch-'a'];
    }
    return true;
}

int main() {
    string words[] = { "the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero", "heroplane" };
    int n = sizeof(words) / sizeof(words[0]);

    TrieNode *root = getNode(); 

    for(int i = 0; i < n; i++) {
        insert(root, words[i]);
    }

    search(root, "ani")? cout << "Yes\n" : 
                         cout << "No\n"; 
    search(root, "any")? cout << "Yes\n" : 
                           cout << "No\n";
    startsWith(root, "hero") ? cout<< "YES\n" : cout<< "NO\n";
    startsWith(root, "herro") ? cout<< "YES\n" : cout<< "NO\n";

    // remove(root, "heroplane");
    search(root, "hero") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}