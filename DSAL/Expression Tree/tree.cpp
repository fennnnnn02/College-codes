#include <bits/stdc++.h>
#include <iostream>
#include "stacks.cpp"

using namespace std;

class Tree;

class NodeTree{
    char data;
    NodeTree*left,*right;
    public:
    NodeTree();
    friend class Tree;
};

NodeTree::NodeTree(){
    left = NULL;
    right = NULL;
}

class Tree{
    NodeTree*root;
    string postfix,prefix,infix;
    public:
    NodeTree* create_tree();
    void rec_inorder(NodeTree *cnode);
    void rec_preorder(NodeTree *cnode);
    void rec_postorder(NodeTree *cnode);
    void it_inorder();
    void it_postorder();
    void it_preorder();
};

NodeTree* Tree::create_tree(){
    cout<<"Enter postfix expression: ";
    string postfix;
    cin>>postfix;
    Stack <NodeTree*> s;
    for(int i=0;i<postfix.length();i++){
        if(isalpha(postfix[i])){
            NodeTree *temp = new NodeTree();
            temp->data = postfix[i];
            s.push(temp);
        }
        else{
            NodeTree *t1 = new NodeTree();
            t1->data = postfix[i];
            t1->right = s.peek();
            s.pop();
            t1->left = s.peek();
            s.pop();
            s.push(t1);
        }
    }
    root = s.peek();
    s.pop();
    return root;
}

void Tree::rec_inorder(NodeTree * cnode){
    if(cnode){
        rec_inorder(cnode->left);
        cout<<" "<<cnode->data;
        rec_inorder(cnode->right);
    }
}

void Tree::rec_preorder(NodeTree * cnode){
    if(cnode){
        cout<<" "<<cnode->data;
        rec_preorder(cnode->left);
        rec_preorder(cnode->right);
    }
}

void Tree:: rec_postorder(NodeTree* cnode){
    if(cnode){
        rec_postorder(cnode->left);
        rec_postorder(cnode->right);
        cout<<" "<<cnode->data;
    }
}

void Tree:: it_inorder(){
    NodeTree* curr = root;
    Stack<NodeTree*> stack;
    while (!stack.isempty() || curr != NULL){
        if (curr != NULL)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            curr = stack.peek();
            stack.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

void Tree:: it_preorder(){
    Stack<NodeTree*> stack;
    NodeTree* curr = root;
    if(curr == NULL){
        return;
    }
    else{
        stack.push(curr);
        while(!stack.isempty()){
            curr = stack.peek();
            stack.pop();
            cout<<curr->data<<" ";
            if(curr->right!=NULL) stack.push(curr->right);
            if(curr->left!=NULL){
                stack.push(curr->left);
            }
        }
    }
}

void Tree:: it_postorder(){
    NodeTree* curr = root;
    NodeTree* temp;
    Stack<NodeTree*> s;
    while(curr!=NULL || !s.isempty()){
        if(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        else{
            temp = s.peek()->right;
            if(temp==NULL){
                temp = s.peek();
                s.pop();
                postfix = postfix + temp->data;
                while(!s.isempty() and temp==s.peek()->right){
                    temp = s.peek();
                    s.pop();
                    postfix = postfix + temp->data;
                }
            }
            else curr = temp;
        }
    }
    cout<<postfix<<endl;
}

int main(){
    Tree t;
    NodeTree *p;
    int c;
    while(true){
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"1. Create Tree"<<endl;
        cout<<"2. Recursive Inorder Traversal "<<endl;
        cout<<"3. Recursive Preorder Traversal "<<endl;
        cout<<"4. Recursive Postorder Traversal "<<endl;
        cout<<"5. Iterative Inorder Traversal "<<endl;
        cout<<"6. Iterative Preorder Traversal"<<endl;
        cout<<"7. Iterative Postorder Traversal"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"Enter command: ";
        cin>>c;
        switch(c){
            case 1:
            p = t.create_tree();
            break;
            case 2:
            t.rec_inorder(p);
            cout<<endl;
            break;
            case 3:
            t.rec_preorder(p);
            cout<<endl;
            break;
            case 4:
            t.rec_postorder(p);
            cout<<endl;
            break;
            case 5:
            t.it_inorder();
            cout<<endl;
            break;
            case 6:
            t.it_preorder();
            cout<<endl;
            break;
            case 7:
            t.it_postorder();
            cout<<endl;
            break;
            case 8:
            cout<<"Exited Successfully"<<endl;
            exit(0);
        }
    }
}

/*

Output

-------------------------------------------------------
1. Create Tree
2. Recursive Inorder Traversal
3. Recursive Preorder Traversal
4. Recursive Postorder Traversal
5. Iterative Inorder Traversal
6. Iterative Preorder Traversal
7. Iterative Postorder Traversal
8. Exit
-------------------------------------------------------
Enter command: 1
Enter postfix expression: abc+*
-------------------------------------------------------
1. Create Tree
2. Recursive Inorder Traversal
3. Recursive Preorder Traversal
4. Recursive Postorder Traversal
5. Iterative Inorder Traversal
6. Iterative Preorder Traversal
7. Iterative Postorder Traversal
8. Exit
-------------------------------------------------------
Enter command: 2
 a * b + c
-------------------------------------------------------
1. Create Tree
2. Recursive Inorder Traversal
3. Recursive Preorder Traversal
4. Recursive Postorder Traversal
5. Iterative Inorder Traversal
6. Iterative Preorder Traversal
7. Iterative Postorder Traversal
8. Exit
-------------------------------------------------------
Enter command: 3
 * a + b c
-------------------------------------------------------
1. Create Tree
2. Recursive Inorder Traversal
3. Recursive Preorder Traversal
4. Recursive Postorder Traversal
5. Iterative Inorder Traversal
6. Iterative Preorder Traversal
7. Iterative Postorder Traversal
8. Exit
-------------------------------------------------------
Enter command: 4
 a b c + *
-------------------------------------------------------
1. Create Tree
2. Recursive Inorder Traversal 
3. Recursive Preorder Traversal 
4. Recursive Postorder Traversal 
5. Iterative Inorder Traversal
6. Iterative Preorder Traversal
7. Iterative Postorder Traversal
8. Exit
-------------------------------------------------------
Enter command: 5
a * b + c 
-------------------------------------------------------
1. Create Tree
2. Recursive Inorder Traversal
3. Recursive Preorder Traversal
4. Recursive Postorder Traversal
5. Iterative Inorder Traversal
6. Iterative Preorder Traversal
7. Iterative Postorder Traversal
8. Exit
-------------------------------------------------------
Enter command: 6
* a + b c 
-------------------------------------------------------
1. Create Tree
2. Recursive Inorder Traversal
3. Recursive Preorder Traversal
4. Recursive Postorder Traversal
5. Iterative Inorder Traversal
6. Iterative Preorder Traversal
7. Iterative Postorder Traversal
8. Exit
-------------------------------------------------------
Enter command: 7
abc+*

-------------------------------------------------------
1. Create Tree
2. Recursive Inorder Traversal
3. Recursive Preorder Traversal
4. Recursive Postorder Traversal
5. Iterative Inorder Traversal
6. Iterative Preorder Traversal
7. Iterative Postorder Traversal
8. Exit
-------------------------------------------------------
Enter command: 8

Exited Successfully

*/