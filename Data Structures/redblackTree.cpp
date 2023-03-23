#include<bits/stdc++.h>
using namespace std;

const static string RED = "RED";
const static string BLACK = "BLACK";

template<typename T>
T getInput(T n) {
    cin >> n;
    return n;
}

struct Node {
    int val;
    Node *parent;
    Node *left;
    Node *right;
    string color;

    Node(int val, Node* parent, Node* left, Node* right, string color) {
        this->val = val;
        this->parent = parent;
        this->left = left;
        this->right = right;
        this->color = color;
    }
};

class RedBlackTree {
    private:
    Node* TNULL;

    void insertFixUp(Node* cur) {
        Node* u;
        
        while(cur->parent->color == RED) {
            if(cur->parent == cur->parent->parent->left) {
                u = cur->parent->parent->right;

                if(u->color == RED) {
                    u->color = BLACK;
                    cur->parent->color = BLACK;
                    cur->parent->parent->color = RED;
                    cur = cur->parent->parent;
                }
                else {
                    if(cur == cur->parent->right) {
                        cur = cur->parent;
                        leftRotate(cur);
                    }
                    cur->parent->color = BLACK;
                    cur->parent->parent->color = RED;
                    rightRotate(cur->parent->parent);
                }
            }
            else {
                u = cur->parent->parent->left;

                if(u->color == RED) {
                    u->color = BLACK;
                    cur->parent->color = BLACK;
                    cur->parent->parent->color = RED;
                    cur = cur->parent->parent;
                }
                else {
                    if(cur == cur->parent->left) {
                        cur = cur->parent;
                        rightRotate(cur);
                    }
                    cur->parent->color = BLACK;
                    cur->parent->parent->color = RED;
                    leftRotate(cur->parent->parent);
                }
            }
            if(cur == root)
                break;
        }

        root->color = BLACK;
        return;
    }

    public:
     Node* root;

    RedBlackTree() {
        TNULL = new Node(INT_MIN, NULL, NULL, NULL, BLACK);
        root = NULL;
    }

    void inOrder(Node* node) {
        if(node == NULL || node == TNULL)
            return;


        inOrder(node->left);
        cout<<node->val<<" ";
        inOrder(node->right);
    }

    Node* minimum(Node* node) {
        if(!node)
            return NULL;

        if(node->left == TNULL && node->right == TNULL)
            return node;
        
        return minimum(node->left);
    }

    Node* maximum(Node* node) {
        if(!node)
            return NULL;

        if(node->left == TNULL && node->right == TNULL)
            return node;
    
        return maximum(node->right);
    }

    Node* search(Node* node, int target) {
        if(node == NULL || node == TNULL)
            return NULL;

        if(node->val == target) 
            return node;
        else if(node->val > target) 
            return search(node->left, target);
        else    
            return search(node->right, target);
    }

    Node* predecessor(int key, Node* cur, Node* pred) {
        if(cur == NULL || cur == TNULL)
            return pred;

        if(cur->val == key) {
            if(cur->left != TNULL) {
                return maximum(cur->left);
            }
        }
        else if(cur->val > key) 
            return predecessor(key, cur->left, pred);
        else {
            pred = cur;
            return predecessor(key, cur->right, pred);
        }

        return pred;
    }

    Node* successor(int key, Node* cur, Node* succ) {
        if(cur == NULL)
            return succ;
        
        if(cur->val == key) {
            if(cur->right != TNULL)
                return minimum(cur->right);
        }
        else if(cur->val > key) {
            succ = cur;
            return successor(key, cur->left, succ);
        }
        else    
            return successor(key, cur->right, succ);
        
        return succ;
    }

    int height(Node* root) {
        Node* cur = root;

        if(cur == TNULL)
            return 0;

        return 1 + max(height(cur->left), height(cur->right));
        
    }

    void printTree() {
        if(!root) return;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                auto cur = q.front(); q.pop();
                if(cur == TNULL) {
                    cout<< "X "<<" ("<<cur->color<<")\t";
                }
                else {
                    cout<<cur->val<<" ("<<cur->color<<")\t";
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            cout<<endl<<endl;
        }
    }

    void leftRotate(Node* x) {
        Node* y = x->right;
        
        x->right = y->left;
        if (y->left != TNULL) 
            y->left->parent = x;
        
        y->parent = x->parent;

        if (x->parent == NULL) 
            this->root = y;
        else if (x == x->parent->left) 
            x->parent->left = y;
        else 
            x->parent->right = y;
        
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* x) {
        Node* y = x->left;
        
        x->left = y->right;
        if (y->right != TNULL) 
            y->right->parent = x;
        
        y->parent = x->parent;

        if (x->parent == NULL) 
            this->root = y;
        else if (x == x->parent->right) 
            x->parent->right = y;
        else 
            x->parent->left = y;
        
        y->right = x;
        x->parent = y;
    }

    void insert(int key) {
        Node* new_node = new Node(key, NULL, TNULL, TNULL, RED);
        Node* cur = root, *prev = NULL;

        if(!cur) {
            this->root = new_node;
            root->color = BLACK;
            return;
        } 

        while(cur != TNULL) {
            prev = cur;

            if(key < cur->val)
                cur = cur->left;
            else    
                cur = cur->right;
        }

        if(prev->val == key)
            return;

        new_node->parent = prev;
        if(prev->val > key)
            prev->left = new_node;
        else    
            prev->right = new_node;

        if(new_node->parent->parent == NULL)
            return;

        insertFixUp(new_node);
    }

    Node* remove(Node* node, int key) {
        if(node == NULL || node == TNULL)
            return NULL;

        if(node->val > key)
            node->left = remove(node->left, key);
        else if(node->val < key)
            node->right = remove(node->right, key);
        else {
            if(node->left == TNULL && node->right == TNULL)
                return TNULL;
            
            if(node->left == TNULL || node->right == TNULL)
                return node->left != TNULL ? node->left : node->right;
            
            Node* temp = minimum(node->right);
            temp->left = node->left;
            // cout<<node->val<<" "<<temp->val<<"\n";
            return node->right;
        }
        return node;
    }

};

int main() {
    // vector<int> A = {4,3,6,1,77,23,87,38,424,123,645};
    // vector<int> A = {4,3,6,1,77};
    // vector<int> A = {-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8};
    vector<int> A = {5,10,15,20};
    RedBlackTree bst;
    
    for(auto i : A)
        bst.insert(i);

    while(1) {
        cout<<"\n\n---------MENU-------\n"
            "1.Sort items\n"
            "2. Print Tree\n"
            "3. Search Item\n"
            "4. Find minimum\n"
            "5. Find maximum\n"
            "6. find Predecessor\n"
            "7. Find Successor\n"
            "8. Insert element\n"
            "9. Delete element\n"
            "10. Left Rotate\n"
            "11. Right Rotate\n"
            "12. Tree Height\n"
            "Choose operation: ";

        int input; cin >> input;
        switch(input) {
            int n;
            case 1: {
                bst.inOrder(bst.root);
                break;
            }
            case 2: {
                bst.printTree();
                cout<<"Tree height = "<<bst.height(bst.root);
                break;
            }
            case 3: {
                cout<< "Enter element to search: ";
                n = getInput(n);
                auto res = bst.search(bst.root, n);
                if(res) 
                    cout<< "Node found! Node Color: "<<res->color;
                else    
                    cout<<"Element not found!";
                break;
            }
            case 4: {
                auto res = bst.minimum(bst.root);
                if(res) cout<<"Minimum = "<<res->val;
                else cout<<"Tree is empty";
                break;
            }
            case 5: {
                auto res = bst.maximum(bst.root);
                if(res) cout<<"Maximum = "<<res->val;
                else cout<<"Tree is empty";
                break;
            }
            case 6: {
                cout<<"Enter element: ";
                n = getInput(n);
                auto res = bst.predecessor(n, bst.root, nullptr);
                if(res) cout<<"Predecessor of "<<n<<" = "<<res->val;
                else cout<<"No predecessor for "<<n;
                break;
            }
            case 7: {
                cout<<"Enter element: ";
                n = getInput(n);
                auto res = bst.successor(n, bst.root, nullptr);
                if(res) cout<<"Successor of "<<n<<" = "<<res->val;
                else cout<<"No successor for "<<n;
                break;
            }
            case 8: {
                cout<< "Enter element to insert: ";
                n = getInput(n);
                bst.insert(n);
                bst.printTree();
                cout<<"Tree height = "<<bst.height(bst.root);
                break;
            }
            case 9: {
                cout<< "Enter element to delete: ";
                n = getInput(n);
                bst.root = bst.remove(bst.root, n);
                bst.printTree();
                cout<<"Tree height = "<<bst.height(bst.root);
                break;
            }
            case 10: {
                bst.leftRotate(bst.root);
                bst.printTree();
                cout<<"Tree height = "<<bst.height(bst.root);
                break;
            }
            case 11: {
                bst.rightRotate(bst.root);
                bst.printTree();
                cout<<"Tree height = "<<bst.height(bst.root);
                break;
            }
            case 12: {
                cout<<"Tree height = "<<bst.height(bst.root);
            }
            default:
                exit(0);
        }
    }

    return 0;
}