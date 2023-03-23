#include<bits/stdc++.h>
using namespace std;

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

    int remove(int key) {
        if(head == NULL)
            return 0;

        return 1;
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

    void printHeap() {
		Node* curPtr = head;
        int n = 0;
		while (curPtr != nullptr) {
			cout<<"B"<<n<<" degree: "<<curPtr->degree<<endl;
			cout<<"There are "<<pow(2, curPtr->degree)<<" nodes in this tree"<<endl;
			cout<<"The level order traversal is: "<<endl;
			queue<Node*> q;
			q.push(curPtr);
			while (!q.empty()) {
				int s = q.size();

                while(s--) {
                    Node* p =  q.front(); q.pop();
                    cout<<p->val<<" ";

                    if(p->child) {
                        Node* child = p->child;
                        while(child) {
                            q.push(child);
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

    vector<int> A = {1,2,3,4,5,6,7};
    BinomialHeap h;

    for(int i : A)
        h.insert(i);

    h.printHeap();
    // cout<<h.getMinimum()->val;

    cout<<"Deleted: "<<h.extractMin()->val<<endl<<endl;
    h.printHeap();

    h.insert(100);
    h.printHeap();

    return 0;
}