#include <iostream>
#include <stack>
using namespace std;
 

struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 

void inorderIterative(Node* root)
{
    
    stack<Node*> stack;
    Node* curr = root;
    while (!stack.empty() || curr != nullptr)
    {
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
 
            curr = curr->right;
        }
    }
}
 
int main()
{

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(4);

    
 
    inorderIterative(root);
 
    return 0;
}
