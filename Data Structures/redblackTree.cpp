#include<bits/stdc++.h>
using namespace std;

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
    Node* root;
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

    void insertFixUp(Node* node) {

    }

    public:
    RedBlackTree() {
        TNULL = new Node(-1, NULL, NULL, NULL, "black");
        root = TNULL;
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

    void printTree(Node* node) {
        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                auto cur = q.front(); q.pop();
                cout<<cur->val<<" ("<<cur->color<<")\t";

                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            cout<<endl;
        }
    }

    void insert(int key) {
        Node* new_node = new Node(key, NULL, NULL, NULL, "red");
        Node* cur = root, *prev = NULL;

        if(!cur) {
            this->root = new_node;
            root->color = "black";
            return;
        } 

        while(cur) {
            prev = cur;

            if(key < cur->val)
                cur = cur->left;
            else    
                cur = cur->right;
        }

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



    return 0;
}