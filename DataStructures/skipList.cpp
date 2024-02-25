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
    int size;
    Skiplist() {
        head = new Node(INT_MIN, NULL, NULL);
        size = 0;
    }

    pair<bool, vector<string>> search(int target) {
        Node* p = head;
        vector<string> operations;

        while(p) {
            while(p->next && p->next->val <= target) {
                p = p->next;
                operations.push_back("RIGHT");
            }
            if(p->val == target)
                return {true, operations};
            p = p->down;
            operations.push_back("DOWN");
        }
        return {false, {}};
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
            head = new Node(INT_MIN, new Node(num, NULL, downNode), head);
        }
        size++;
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
                size--;
            }
            
            p = p->down;
        }
        return found;
    }

    void printSkiplist() {
        Node* p = head;

        while(p) {
            Node* downNode = p->down;

            // move to next node because start is a dummy node
            p = p->next;
            for(; p != NULL; p = p->next) {
                cout<<p->val<<"  ";
            }
            cout<<"\n";

            p = downNode;
        }
    }

};

int main() {
    Skiplist sl;
    unordered_set<int> set;
    int input; 
    while(1) {
        cout<< "\n\nChoose Skiplist operation: \n1. Insert\n2. Search\n3. Delete\n4. Print Skiplist\n5. Quit\n\nOperation: ";
        
        cin >> input;

        switch (input) {
            int n;
            case 1: {
                cout<< "Enter number to add: ";
                cin >> n;
                auto found = sl.search(n);
                if(found.first)
                    cout<<"\n Number already exits!\n";
                else {
                    sl.add(n);
                    cout<<"\n Number added successfully!\n";
                }
                break;
            }
            case 2: {
                cout<< "Enter Number to search: ";
                cin >> n;
                auto res = sl.search(n);

                if(!res.first)
                    cout<<"Item NOT Found\n";
                else {
                    cout<<"Item found in list in "<<res.second.size()<<"/"<<sl.size<<  " operations\n";
                    cout<< "OPERATIONS: \n";
                    for(string op : res.second)
                        cout<<op<<" -> ";  
                }
                break;
            }
            case 3: {
                cout<<"Enter number to delete: ";
                cin >> n;
                cout<< (sl.erase(n) ? "Number deleted successfully!\n" : "Number doesn't exists!\n");
                break;
            }
            case 4: {
                sl.printSkiplist();
                break;
            }
            case 5:
                exit(0);
            default:
                break;
        }
    }

    return 0;
}
