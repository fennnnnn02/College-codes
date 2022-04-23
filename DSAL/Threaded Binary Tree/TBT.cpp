#include <bits/stdc++.h>

using namespace std;

class Node{
    private:
    bool lb,rb;
    int data;
    Node* left,*right;
    public:
    Node();
    friend class TBT;
};

Node::Node(){
    lb=rb=0;
    left = right = NULL;
    data =0;
}

class TBT{
    Node* header;
    Node* root;
    public:
    TBT();
    void create_tbt();
    void create_root(int a);
    void create_node(int a);
    void inorder();
    void preorder();
};

TBT::TBT(){
    header->rb = 1;
    header->right = header;
    header->left = header;
}

void TBT::create_root(int a){
    root = new Node();
    root->data = a;
    header->left = root;
    header->lb = 1;
    root->left = header;
    root->right = header;
}

void TBT::create_node(int a){
    Node* node = new Node();
    node->data = a;
    Node*curr = root;
    while(true){
        if(node->data<curr->data and curr->lb==1){
            curr = curr->left;
        }
        else if(node->data>curr->data and curr->rb==1) curr = curr->right;
        else break;
    }
    if(node->data<curr->data){
        curr->lb = 1;
        node->left = curr->left;
        curr->left = node;
        node->right = curr;
    }
    else{
        curr->rb = 1;
        node->right = curr->right;
        curr->right = node;
        node->left = curr;
    }

}

void TBT::create_tbt(){
    int n;
    cout<<"Enter total nodes: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter value of node "<<i+1<<": ";
        cin>>a[i];
        if(i==0){
            create_root(a[i]);
        }
        else{
            create_node(a[i]);
        }
    }

}

void TBT::inorder(){
    Node *curr = root;
    bool val = true;
    while(curr!=header){
        while(curr->lb and val) curr = curr->left;
        if(curr->rb) {
            curr = curr->right;
            val = true;
        }
        else {
            cout<<curr->data<<" ";
            curr = curr->right;
            if(curr->rb and curr->right !=header){
                cout<<curr->data<<" ";   
                curr = curr->right;
                val = true;
            }
            else{
                val = false;
            }
        }
    }
    cout<<endl;
}

void TBT::preorder(){
    Node* curr = root;
    
    bool val = root->data;
    while(curr!=header){
        while(curr->lb and val){
            cout<<curr->data<<" ";
            curr = curr->left;
        }
        if(val) cout<<curr->data<<" ";
        if(curr->rb) {
            curr = curr->right;
            val = true;
        }
        else{
            curr=curr->right;
            val = false;
        }
    }
    cout<<endl;
}

int main(){
    TBT t;
    int ch;
    while(true){
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"1. Create Threaded Binary Tree"<<endl;
        cout<<"2. Inorder Traversal "<<endl;
        cout<<"3. Preorder Traversal "<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"Enter command: ";
        cin>>ch;
        switch(ch){
            case 1:
            t.create_tbt();
            break;
            case 2:
            t.inorder();
            cout<<"-------------------------------------------------------"<<endl;
            break;
            case 3:
            t.preorder();
            cout<<"-------------------------------------------------------"<<endl;
            break;
            case 4:
            cout<<"Exited Successfully"<<endl;
            exit(0);
        }
    }

}

/*

Output

-------------------------------------------------------
1. Create Threaded Binary Tree
2. Inorder Traversal 
3. Preorder Traversal 
4. Exit
-------------------------------------------------------
Enter command: 1
Enter total nodes: 9
Enter value of node 1: 6
Enter value of node 2: 3
Enter value of node 3: 8
Enter value of node 4: 1
Enter value of node 5: 5
Enter value of node 6: 7
Enter value of node 7: 11
Enter value of node 8: 9
Enter value of node 9: 13
-------------------------------------------------------
1. Create Threaded Binary Tree
2. Inorder Traversal 
3. Preorder Traversal 
4. Exit
-------------------------------------------------------
Enter command: 2
1 3 5 6 7 8 9 11 13
-------------------------------------------------------
-------------------------------------------------------
1. Create Threaded Binary Tree
2. Inorder Traversal 
3. Preorder Traversal 
4. Exit
-------------------------------------------------------
Enter command: 3
6 3 1 5 8 7 11 9 13 
-------------------------------------------------------
-------------------------------------------------------
1. Create Threaded Binary Tree
2. Inorder Traversal
3. Preorder Traversal
4. Exit
-------------------------------------------------------
Enter command: 4

Exited Successfully

*/