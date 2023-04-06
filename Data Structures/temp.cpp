#include<bits/stdc++.h>
using namespace std;

template<typename T>
T getInput(T n) {
    cin >> n;
    return n;
}

struct Node {
    int val;
    int degree;
    Node *parent;
    Node *sibling;
    Node *child;

    Node(int x) : val(x) {}
};

class BinomialHeap {
private:
    Node* head;

    void linkBinomialTrees(Node* x, Node* y) {
        y->parent = x;
        y->sibling = x->child;
        x->child = y;
        x->degree += 1;
    }

    Node* reverseList(Node* head) {
        if(!head)
            return NULL;
        
        Node *prev = NULL, * cur = head;

        while(cur) {
            cur->parent = NULL;
            Node* temp = cur->sibling;
            cur->sibling = prev;
            prev = cur;
            cur = temp;
        }
        
        return prev;
    }

public:
    BinomialHeap() {
        head = nullptr;
    }

    Node* getHead() { return head; }

    void setHead(Node* head) { this->head = head; }

    Node* getMinimum() {
		// traverse all the roots and find compare
		Node* cur = head;
		Node* minPtr = nullptr;

		while (cur != nullptr) {
			if (minPtr == NULL || cur->val < minPtr->val) 
				minPtr = cur;
			
			cur = cur->sibling;
		}

		return minPtr;
	}

    void insert(int key) {
        if(head == NULL) {
            setHead(new Node(key));
        }
        else {
            Node* node = new Node(key);
            BinomialHeap h2;
            h2.setHead(new Node(key));
            merge(h2);
        }
	}

    // void merge(BinomialHeap h2) {return;}

    void merge(BinomialHeap h2) {
        Node* cur1 = getHead();
        Node* cur2 = h2.getHead();
        Node* cur3 = NULL, *temp = NULL;

        if(cur1 == NULL) {
            setHead(cur2);
            return;
        }

        if(cur2 == NULL) {
            return;
        }

        if(cur1->degree <= cur2->degree) {
			cur3 = cur1;
			cur1 = cur1->sibling;
		} else {
			cur3 = cur2;
			cur2 = cur2->sibling;
		}

		temp = cur3;
        
        // union of heap roots in asc order of degree
        while(cur1 && cur2) {
            if (cur1->degree <= cur2->degree) {
				cur3->sibling = cur1;
				cur1 = cur1->sibling;
			} else {
				cur3->sibling = cur2;
				cur2 = cur2->sibling;
			}

			cur3 = cur3->sibling;
        }

        if(cur1 != nullptr) {
            cur3->sibling = cur1;
        }

        if(cur2 != nullptr) {
            cur3->sibling = cur2;
        }
		
        //merge trees with same degrees
        cur3 = temp;
        Node *prev = nullptr, *next = cur3->sibling;

        while(next) {
            if ((cur3->degree != next->degree )|| (next->sibling != nullptr && cur3->degree == next->sibling->degree)) {
				prev = cur3;
				cur3 = next;
			}
            else {
                if(cur3->val <= next->val) {
                    cur3->sibling = next->sibling;
                    linkBinomialTrees(cur3, next);
                }
                else {
                    if(prev == NULL)
                        temp = next;
                    else    
                        prev->sibling = next;
                    
                    linkBinomialTrees(next, cur3);
                    cur3 = next;
                }
            }

            next = cur3->sibling;
        }

        this->head = temp;
    }

    Node* extractMin() {
        if(head == NULL) 
            return NULL;

        BinomialHeap h2;
        Node *minNode = head, *cur = head, *prev = NULL;
        Node *minChild, *minPrev = NULL;

        while(cur) {
            if(cur->val < minNode->val) {
                minPrev = prev;
                minNode = cur;
            }
            prev = cur;
            cur = cur->sibling;
        }

        minChild = minNode->child;
        minChild = reverseList(minChild);
        Node* p = minChild;
        
        h2.setHead(minChild);
        
        //minNode not is not first root
        if(minPrev != NULL) {
            minPrev->sibling = minNode->sibling;
        }
        else {  //first root is minNode
            setHead(minNode->sibling);
        }

        merge(h2);
        return minNode;
    }

    Node* search(Node* head, int key) {
        if(head == NULL)
            return NULL;
        
        Node* cur = head, *res = NULL;

        if(cur->val == key)
            return cur;
        
        if(cur->child && res == NULL)
            res = search(cur->child, key);
        if(cur->sibling && res == NULL)
            res = search(cur->sibling, key);

        return res;
    }

    int decreaseKey(int i, int j) {
        Node* p = search(getHead(), i);
        if(p == NULL)
            return 0;

        p->val = j;

        while(p->parent && p->parent->val > p->val) { 
            swap(p->parent->val, p->val);
            p = p->parent;
        }

        return 1;
    }

    int remove(int key) {
        Node* p = search(getHead(), key);

        if(p == NULL)
            return 0;

        decreaseKey(key, INT_MIN);
        extractMin();
        return 1;
    }

    void printHeap() {
		Node* curPtr = head;
        int n = 0;
		while (curPtr != nullptr) {
			cout<<"Heap #"<<n+1<<" degree: "<<curPtr->degree<<endl;
			cout<<"There are "<<pow(2, curPtr->degree)<<" nodes in this tree"<<endl;
			cout<<"The level order traversal is: "<<endl;
			queue<pair<Node*, Node*>> q;
			q.push({curPtr, NULL});
			while (!q.empty()) {
				int s = q.size();

                while(s--) {
                    auto p =  q.front(); q.pop();
                    cout<<p.first->val<<" ("<<(p.second != NULL ? to_string(p.second->val) : "Root" )<<")\t";

                    if(p.first->child) {
                        Node* child = p.first->child;
                        while(child) {
                            q.push({child, p.first});
                            child = child->sibling;
                        }
                    }
                }
                cout<<endl;
			}
			cout<<endl<<endl;
			curPtr = curPtr->sibling;
            n++;
		}
	}

};

int main() {

    
    BinomialHeap heap;

    int input;
    while(1) {
        cout<<"\n\n\nChoose operation on Binomial Heap: \n"
            "0. Print Binomial heap\n"
            "1. Insert element\n"
            "2. Find minimum element\n"
            "3. Extract minimum element\n"
            "4. Delete element\n"
            "5. Decrese key\n"
            "6. Build Heap\n"
            "Input: ";
        cin >> input;

        switch (input) {
            int n;
            case 0: {
                cout<<"\n\n--------------------------------\n\n";
                heap.printHeap();
                cout<<"\n\n--------------------------------\n\n";
                break;
            }
            case 1: {
                cout<<"Enter number to insert: ";
                n = getInput(n);
                heap.insert(n);
                break;
            }
            case 2 : {
                Node* res = heap.getMinimum();
                if(res)
                    cout<<"Minimum element: "<<res->val<<endl;
                else    
                    cout<<"Heap is empty!\n";
                break;
            }
            case 3: {
                Node* res = heap.extractMin();
                if(res)
                    cout<<"Element extracted: "<<res->val<<endl;
                else
                    cout<<"Heap is empty!\n";
                break;
            }
            case 4: {
                cout<<"Enter element to delete: ";
                n = getInput(n);
                int flag = heap.remove(n);
                if(flag)
                    cout<< "Element deleted successfully!"<<endl;
                else 
                    cout<<"Element doesn't exists."<<endl;
                break;
            }
            case 5: {
                cout<<"Enter element to decrese: ";
                n = getInput(n);
                cout<<"Enter new value after change: ";
                int key = getInput(n);
                int flag = heap.decreaseKey(n, key);
                if(flag)
                    cout<< "Element decreased successfully!"<<endl;
                else 
                    cout<<"Element doesn't exists."<<endl;
                break;
            }
            case 6: {
                int k;
                
                cout<<"Enter number of nodes: "; cin >> k;
                vector<int> A(k) ;
                cout<<"Enter "<<k<<" node values: \n";
                for(int i = 0; i < k; i++) {
                    cin>>A[i];
                    heap.insert(A[i]);
                }
                break;
            }
            default: {
                exit(0);
            }
        }
    }
    return 0;
}