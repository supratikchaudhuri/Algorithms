#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next, *down;

    Node(int val, Node* next, Node* down) {
        this->val = val;
        this->next = next;
        this->down = down;
    }
};

class Skiplist {
    Node* head;
public:
    Skiplist() {
        head = new Node(-1, NULL, NULL);
    }
    
    bool search(int target) {
        Node* p = head;

        while(p) {
            while(p->next && p->next->val <= target)
                p = p->next;
            if(p->val == target)
                return true;
            p = p->down;
        }
        return false;
    }
    
    void add(int num) {
        vector<Node*>insertPoints;
        Node *p = head;
        while(p) {
            while(p->next && p->next->val < num) 
                p = p->next;
            insertPoints.push_back(p);
            p = p->down;
        }
        
        Node* downNode = NULL;
        bool insertUp = true;
        while(insertUp && insertPoints.size()) {
            Node *ins = insertPoints.back(); 
            insertPoints.pop_back();
            
            ins->next = new Node(num, ins->next , downNode);
            downNode = ins->next;
            
            insertUp = (rand() & 1) == 0;
        }
        if(insertUp) {
            head = new Node(-1, new Node(num, NULL, downNode), head);
        }
    }
    
    bool erase(int n) {
        Node* p = head;
        bool found = false;
        while(p) {
            while(p->next && p->next->val < n) 
                p = p->next;

            if(p->next && p->next->val == n) {
                found = true;
                p->next = p->next->next;
            }
            
            p = p->down;
        }
        return found;
    }
};

int main() {
    Skiplist sl;
    unordered_set<int> set;
    int input; 
    while(1) {
        cout<< "\n\nChoose Skiplist operation: \n1. Insert\n2. Search\n3. Delete\n4. Quit\n";
        
        cin >> input;

        switch (input) {
            int n;
        case 1:
            cout<< "Enter number to add: ";
            cin >> n;
            sl.add(n);
            cout<<"\n Number added successfully!\n";
            break;
        case 2:
            cout<< "Enter Number to search: ";
            cin >> n;
            cout<< "Number " <<(sl.search(n) == true ? "" : "NOT" )<< " found\n";
            break;
        case 3: 
            cout<<"Enter number to delete: ";
            cin >> n;
            cout<< (sl.erase(n) ? "Number deleted successfully!\n" : "Number doesn't exists!\n");
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}

// g++ -std=c++11 <filename>