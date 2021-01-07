// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
 
// Node of the binary tree
struct node {
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
 
// Function that returns true if a pair
// with given sum exists in the given BSTs
bool existsPair(node* root1, node* root2, int x)
{
    // node *cur1 = root1, *cur2 = root2;
    // stack<node*> s1, s2;
    // bool done1 = false, done2 = false;
    // int val1 = 0, val2 = 0;

    // while(1) {
    //     while(!done1) {
    //         if(cur1){
    //             s1.push(cur1);
    //             cur1 = cur1->left;
    //         }
    //         else {
    //             if(s1.empty())
    //                 done1 = true;
    //             else {
    //                 cur1 = s1.top(); s1.pop();
    //                 val1 = cur1->data;
    //                 cur1 = cur1->right;
    //                 done1 = true;
    //             }
    //         }
    //     }

    //     while(!done2) {
    //         if(cur2){
    //             s2.push(cur2);
    //             cur2 = cur2->right;
    //         }
    //         else {
    //             if(s2.empty())
    //                 done2 = true;
    //             else {
    //                 cur2 = s2.top(); s2.pop();
    //                 val2 = cur2->data;
    //                 cur2 = cur2->left;
    //                 done2 = true;
    //             }
    //         }
    //     }
    //     cout<<val1<<"  "<<val2<<endl;

    //     if(val1 + val2 == x) return true;
    //     else if(val1 + val2 < x){
    //         if(val1 < val2)
    //             done1 = false;
    //         else
    //             done2 = false;
    //     }
    //     else{
    //         if(val1 < val2)
    //             done2 = false;
    //         else
    //             done1 = false;
    //     }
        
    //     if(!cur1 and s1.empty() || !cur2 and s2.empty()) return false;
    
    
    
    // Stack to store nodes for forward and backward
	// iterator
    stack<node *> it1, it2;

	// Initializing forward iterator
	node* c = root1;
	while (c != NULL)
		it1.push(c), c = c->left;

	// Initializing backward iterator
	c = root2;
	while (c != NULL)
		it2.push(c), c = c->right;

	// Two pointer technique
	while (it1.size() and it2.size()) {

		// To store the value of the nodes
		// current iterators are pointing to
		int v1 = it1.top()->data, v2 = it2.top()->data;
        cout<<v1<<"  "<<v2<<endl;
		// If found a valid pair
		if (v1 + v2 == x)
			return true;

		// Moving forward iterator
		if (v1 + v2 < x) {
			c = it1.top()->right;
			it1.pop();
			while (c != NULL)
				it1.push(c), c = c->left;
		}

		// Moving backward iterator
		else {
			c = it2.top()->left;
			it2.pop();
			while (c != NULL)
				it2.push(c), c = c->right;
		}
	}

	// If no such pair found
	return false;

}
 
// Driver code
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
 
    int x = 16;
 
    if (existsPair(root1, root2, x))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}