#include<bits/stdc++.h>
using namespace std;

const string RED = "red";
const string BLACK = "black";

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

    void insertFixUp(Node* cur) {
        Node* u;
        cout<<"fixing "<<cur->val<<endl;
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
        if(!node)
            return;

        inOrder(node->left);
        cout<<node->val<<" ";
        inOrder(node->right);
    }

    Node* minimum(Node* node) {
        if(!node)
            return NULL;

        if(!node->left && !node->right)
            return node;
        
        return minimum(node->left);
    }

    Node* maximum(Node* node) {
        if(!node)
            return NULL;

        if(!node->left && !node->right)
            return node;
    
        return maximum(node->right);
    }

    Node* search(Node* node, int target) {
        if(!node)
            return NULL;

        if(node->val == target) 
            return node;
        else if(node->val > target) 
            return search(node->left, target);
        else    
            return search(node->right, target);
    }

    Node* predecessor(Node* node, int key) {
        Node* cur = search(root, key);
        if(!cur)
            return NULL;
        
        if(cur->right)
            return maximum(cur->right);
        else    
            return maximum(cur->left);        
    }

    Node* successor(int key) {
        Node* cur = search(root, key);
        if(!cur)
            return NULL;
        
        if(cur->left)
            return minimum(cur->left);
        else    
            return minimum(cur->right);     
    }

    int height(Node* root) {
        Node* cur = root;

        if(cur == TNULL)
            return 0;

        return 1 + max(height(cur->left), height(cur->right));
        
    }

    void printTree() {
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
            cout<<endl;
        }
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

};

int main() {
    // vector<int> A = {4,3,6,1,77,23,87,38,424,-123,-645};
    // vector<int> A = {4,3,6,1,77};
    vector<int> A = {-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8};
    RedBlackTree bst;
    
    for(auto i : A)
        bst.insert(i);
    

    bst.printTree();
    cout<<bst.height(bst.root);

    return 0;
}