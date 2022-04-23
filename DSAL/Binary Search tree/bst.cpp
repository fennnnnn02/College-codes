#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class BST;

class Node{
    private:
    int data;
    Node*left,*right;
    public:
    Node();
    friend class BST;
};

Node::Node(){
    left = NULL;
    right = NULL;
}

class BST{

    private:
    Node*root=NULL;

    public:
    BST();
    // BST Operations and Traversals
    void Insert();
    void Traverse();
    void Delete();
    void Delete1(Node*child,Node*loc);
    void DisplayLevel();
    void DisplayLeaf();
    Node* Search(int key);
    void MirrorTree(Node*t);
    int HeightTree(Node*t);

    // Get root
    Node* getRoot();
};

BST::BST(){
    root=NULL;
}

void BST::Insert(){
    
    int key;
    cout<<"Enter value of the node: ";
    cin>>key;
    Node* temp, *new1;
    new1 = new Node();
    new1->data = key;
    if(root == NULL)
			root = new1;
		else{
			temp = root;
			check:
			if(new1->data <= temp->data){
				if(temp->left != NULL){
					temp = temp->left;
					goto check;
				}
				else{
					temp->left = new1;
				}
			}
			else if(new1->data > temp->data){
				if(temp->right != NULL){
					temp = temp->right;
					goto check;
                	}
				else{
					temp->right = new1;
				}
            }
        }
}

void BST::Traverse(){
    stack<Node*> stack;
    Node* curr = root;
    if(root==NULL) return;
    while (!stack.empty() or curr != NULL)
    {   
        if (curr !=NULL)
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

void BST::MirrorTree(Node*t){
    Node* temp;
    if(t){
        temp = t->left;
        t->left = t->right;
        t->right = temp;
        MirrorTree(t->left);
        MirrorTree(t->right);
    }
    else return;
}

Node* BST::Search(int key){
   
    Node* curr = root,*temp=NULL;
    check:
    if(curr==NULL) {
        cout<<"Key not found"<<endl;
        return NULL;
    }
    else {
        if(curr!=NULL and curr->data>key){
            temp = curr;
            curr = curr->left;
            goto check;
        }
        else if(curr!=NULL and curr->data<key){
            temp = curr;
            curr = curr->right;
            goto check;
        }
        if(curr!=NULL and curr->data==key) {
            cout<<"Key found"<<endl;
            return temp;
        }
        
    }
}

void BST::Delete(){
    int key;
    cout<<"Enter node to delete: ";
    cin>>key;
    Node* par = Search(key);
    Node* loc;
    // Find location
    if(par==NULL) loc = root;
    else if(par->left!=NULL and key==par->left->data) loc = par->left;
    else if (par->right!=NULL and key==par->right->data) loc = par->right;
    else return;

    if(loc->left!=NULL and loc->right!=NULL){
        Node* ptr2 = loc->right;
        Node* ptr1 = loc;
        while(ptr2->left!=NULL){
            ptr1 = ptr2;
            ptr2 = ptr2->left;
        }
        if(ptr1!=loc){    
        loc->data = ptr2->data;
        Delete1(ptr1,ptr2);
        }
        else{
            loc->data = ptr2->data;
            Delete1(ptr1,ptr2);
        }

    }

    else{
        Delete1(par,loc);
    }
}

void BST::Delete1(Node*par,Node*loc){
    Node*child;
    if(loc->left==NULL and loc->right == NULL) child = NULL;
        else if(loc->left!=NULL) child = loc->left;
        else child = loc->right;
        if(par!=NULL){
            if(loc==par->left) par->left = child;
            else par->right = child;
            delete loc;
            loc = NULL;
        }
        else{
            // location is root
            if(root->left) {
                child = root->left;
                delete root;
                root = child;
            }
            else if(root->right){
                child = root->right;
                delete root;
                root = child;
            }
            else{
                delete root;
                root = NULL;
            }
        }
}

Node*BST:: getRoot(){
    return root;
}

void BST::DisplayLeaf(){
    stack<Node*> s;
    if(root==NULL) return;
    s.push(root);
    while(!s.empty()){
        Node* curr = s.top();
        s.pop();
        if(curr->left) s.push(curr->left);
        if(curr->right) s.push(curr->right);
        if(!curr->left and !curr->right) {
            cout<<curr->data<<" ";
        }
    }
}

void BST::DisplayLevel(){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        cout<<q.front()->data<<" ";
        if(q.front()->left) q.push(q.front()->left);
        if(q.front()->right) q.push(q.front()->right);
        q.pop();
    }
}

int BST::HeightTree(Node *t)
{
	int hleft, hright;
	if(t == NULL)
		return 0;
	else
	{
		hleft = HeightTree(t->left) + 1;
		hright = HeightTree(t->right) + 1;
	}
	return max(hleft,hright);
}

int main(){
    BST t;
    int ch;
    while(true){
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"1. Insert element in BST"<<endl;
        cout<<"2. Delete element in BST "<<endl;
        cout<<"3. Traverse and Display "<<endl;
        cout<<"4. Search element "<<endl;
        cout<<"5. Mirror Tree "<<endl;
        cout<<"6. Height of Tree"<<endl;
        cout<<"7. Display BST Level wise"<<endl;
        cout<<"8. Display leaf"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"Enter command: ";
        cin>>ch;
        switch(ch){
            case 1:
            t.Insert();
            break;
            case 2:
            t.Delete();
            break;
            case 3:
            t.Traverse();
            cout<<endl;
            break;
            case 4:
            int key;
            cout<<"Enter element to find: ";
            cin>>key;
            t.Search(key);
            break;
            case 5:
            t.MirrorTree(t.getRoot());
            t.Traverse();
            break;
            case 6:
            cout<<"Height of the tree is: "<<t.HeightTree(t.getRoot());
            cout<<endl;
            break;
            case 7:
            t.DisplayLevel();
            cout<<endl;
            break;
            case 8:
            t.DisplayLeaf();
            cout<<endl;
            break;
            case 9:
            cout<<"Exited Successfully"<<endl;
            exit(0);
        }
    }
    return 0;
}


/* 

Output

-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST 
3. Traverse and Display 
4. Search element 
5. Mirror Tree 
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 1
Enter value of the node: 4
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST 
3. Traverse and Display 
4. Search element 
5. Mirror Tree 
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 1
Enter value of the node: 2
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 1
Enter value of the node: 6
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 1
Enter value of the node: 1
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 1
Enter value of the node: 3
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 1
Enter value of the node: 5
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 1
Enter value of the node: 7
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 3
1 2 3 4 5 6 7 
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 2
Enter node to delete: 7
Key found
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 3
1 2 3 4 5 6 
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 2
Enter node to delete: 3
Key found
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 3
1 2 4 5 6 
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 5
6 5 4 2 1 -------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 6
Height of the tree is: 3
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 7
4 6 2 5 1 
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 8
1 5 
-------------------------------------------------------
1. Insert element in BST
2. Delete element in BST
3. Traverse and Display
4. Search element
5. Mirror Tree
6. Height of Tree
7. Display BST Level wise
8. Display leaf
9. Exit
-------------------------------------------------------
Enter command: 9
Exited Successfully

*/