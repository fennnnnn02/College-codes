#include <bits/stdc++.h>

using namespace std;

class dLL;

class Node{
    private:
    int data;
    Node* prev;
    Node* next;
    Node(){
        prev = NULL;
        next = NULL;
    }
    friend class dLL;
};

class dLL{
    Node *start;
    Node *last;
    public:
    dLL(){
        start = NULL;
        last = NULL;
    }
    void ins_at_end();
    void ins_at_start();
    void ins_at_any();
    void del_at_start();
    void del_at_end();
    void del_at_any();
    void traverse_start();
    void traverse_end();
};

void dLL::ins_at_end(){
    Node *temp = new Node();
    int val;
    cout<<"Enter val: ";
    cin>>val;
    temp->data = val;
    if(start == NULL){
        start = temp;
        last = temp;
    }
    else{
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

void dLL::ins_at_start(){
    int val;
    cout<<"Enter val: ";
    cin>>val;
    Node* temp = new Node();
    temp->data = val;
    if(start == NULL){
        start = temp;
        last = temp;
    }
    else{
        start->prev = temp;
        temp->next = start;
        start = temp;
    }
}

void dLL::ins_at_any(){
    int pos,val;
    cout<<"Enter pos: ";
    cin>>pos;
    if(start == NULL) ins_at_end();
    else if(pos==0){
        cout<<"Enter value: ";
        cin>>val;
        Node*temp = new Node();
        temp->data = val;
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
    else{
        cout<<"Enter value: ";
        cin>>val;
        Node *p = start;
        Node *temp = new Node;
        temp->data = val;
        int count = 0;
        while(count<pos-1 and p!=NULL){
            p = p->next;
            count++;
        }
        temp->next = p->next;
        p->next = temp;
        temp->prev = p;
        p->next->prev = temp;
    }
}

void dLL::traverse_start(){
    Node*p = start;
    if(start == NULL) cout<<"Empty"<<endl;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}

void dLL::traverse_end(){
    Node*p = last;
    if(start == NULL) cout<<"Empty"<<endl;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->prev;
    } 
}

int main(){
    
    dLL ll1;
    while(1){
        int ch;
        cout<<endl;
        cout<<"1.at end, 2.at begin, 3.at any, 4.traverse end 5. traverse 6.  7. del at start 8. del at any 9. Exit"<<endl;
        cout<<"Enter command: ";
        cin>>ch;
        switch(ch){
            case 1:
                ll1.ins_at_end();
                break;
            case 2:
                ll1.ins_at_start();
                break;
            case 3:
                ll1.ins_at_any();
                break;
            case 5:
                ll1.traverse_start();
                break;
            case 4:
                ll1.traverse_end();
                break;
            // case 6:
            //     ll1.del_at_end();
            //     break;
            // case 7:
            //     ll1.del_at_start();
            //     break;
            // case 8:
            //     ll1.del_at_any();
            //     break;
            case 9:
                exit(0);
        }
    }
    return 0;
}