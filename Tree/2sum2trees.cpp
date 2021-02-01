#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
 

bool existsPair(node* root1, node* root2, int x) {
    stack<node *> it1, it2;
 
    node* c = root1;
    while (c != NULL)
        it1.push(c), c = c->left;
 
    c = root2;
    while (c != NULL)
        it2.push(c), c = c->right;
 
    while (it1.size() and it2.size()) {
        int v1 = it1.top()->data, v2 = it2.top()->data;
 
        if (v1 + v2 == x)
            return true;
 
        if (v1 + v2 < x) {
            c = it1.top()->right;
            it1.pop();
            while (c != NULL)
                it1.push(c), c = c->left;
        }
 
        else {
            c = it2.top()->left;
            it2.pop();
            while (c != NULL)
                it2.push(c), c = c->right;
        }
    }
 
    return false;
}
 
int main()
{
 
    // First BST
    node* root1 = new node(11);
    root1->right = new node(15);
 
    // Second BST
    node* root2 = new node(5);
    root2->left = new node(3);
    root2->right = new node(7);
    root2->left->left = new node(2);
    root2->left->right = new node(4);
    root2->right->left = new node(6);
    root2->right->right = new node(8);
 
    int x = 23;
 
    if (existsPair(root1, root2, x))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}