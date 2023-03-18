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
    const static int MAXSIZE = 30;
    const static int mult = 12582917;
    Node* map[MAXSIZE] = {};
    
    int hash (string s) {
        long key = 0;

        for(int i = 0; i < s.length(); i++) {
            if(!isalpha(s[i]))
                key -= pow(s[0], 3);
            key += ((int)s[i] + (i+2)*(i+3)*(i*i)*s[i] * 1009L) ;
        }

        return (int)(key * mult % MAXSIZE);
    }

    // int hash (string s) {
    //     uint64_t hash = 0x811c9dc5;
    //     uint64_t prime = 0x1000193;

    //     for(int i = 0; i < s.size(); ++i) {
    //         hash *= s[i] * s[i] * prime;
    //         hash += (hash << 10);
    //         hash ^= (hash >> 6);
    //     }
    //     hash += (hash << 3);
    //     hash ^= (hash >> 11);
    //     hash += (hash << 15);

    //     return hash * prime % MAXSIZE;
    // }

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