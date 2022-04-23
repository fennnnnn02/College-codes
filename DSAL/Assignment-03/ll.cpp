#include <bits/stdc++.h>

using namespace std;

class Linked_list;

class Node{
    private:
    int data;
    Node *next;
    public:
    Node(){
        next = NULL;
    }
    friend class Linked_list;
};

class Linked_list{
    Node *start;
    Node *last;
    public:
    Linked_list(){
            start = NULL;
            last = NULL;
        }
    void insert_at_end();
    void insert_at_begin();
    void insert_at_any();
    void insert_in_sorted();
    void traverse();
    void del_at_end();
    void del_at_any();
    void del_at_start();
};

void Linked_list::insert_at_end(){
    int val;
    cout<<"Enter value: ";
    cin>>val;
    Node *temp = new Node;
    temp->data = val;
    if(start==NULL){
        start = temp;
        last = temp;
        
    }
    else{
        last->next = temp;
        last = temp;
    }
    temp->next = NULL; // check
    
}

void Linked_list:: traverse(){
    Node *p = start;
     cout<<endl;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;

}

void Linked_list::insert_at_begin(){
    int val;
    cout<<"Enter value: ";
    cin>>val;
    Node *temp = new Node;
    temp->data = val;
    if(start == NULL){
        start = temp;
        last = temp;
    }
    else{
        temp->next = start;
        start = temp;
    }
}

void Linked_list::insert_at_any(){
    int val,pos;
    cout<<"Enter pos: ";
    cin>>pos;
    
    if(start==NULL){
       insert_at_end();
    }
    else if(pos ==0){
        cout<<"Enter value: ";
        cin>>val;
        Node*temp = new Node;
        temp->data = val;
        temp->next = start;
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
    }

}

void Linked_list::insert_in_sorted(){
    Node *p = start;
    Node *temp = new Node;
    int val;
    cout<<"Enter value: ";
    cin>>val;
    temp->data = val;
    if(temp->data < p->data or start == NULL){
        temp->next = p;
        start = temp;
        return;
    }
    while(p->next!=NULL){
        if(val<=(p->next)->data and val>(p)->data){
            temp->next = p->next;
            p->next = temp;
            return;
        }
        p = p->next;
    }
    last->next = temp;
    last = temp;
}

void Linked_list::del_at_end(){
    if(start == NULL) cout<<"Already Empty"<<endl;
    else if(start->next==NULL){
        delete start;
        start = NULL;
        last = NULL;
    }
    else{
        Node *p = start;
        while(p->next!=last) p = p->next;
        p->next = NULL;
        delete last;
        last = p;
    }
}

void Linked_list::del_at_start(){
    if(start==NULL) cout<<"Underflow"<<endl;
    else if(start->next==NULL){
        delete start;
        start=NULL;
        last = NULL;
    }
    else{
        Node *p = start;
        start = start->next;
        delete p;
        p = NULL;
    }
}

void Linked_list::del_at_any(){
    int pos;
    cout<<"Enter pos: ";
    cin>>pos;
    if(pos==0) del_at_start();
    else{
        Node  *p = start;
        Node *q;
        int c=0;
        while(c!=pos) {
            c++;
            q = p;
            p=p->next;
        }
        if(p==last){
            delete p;
            p = NULL;
            last = q;
            last->next = NULL;
        }
        else{
            q->next = p->next;
            delete p;
            p=NULL;
        }
    }
}

int main(){

    Linked_list ll1;

    while(1){
        int ch;
        cout<<endl;
        cout<<"1.at end, 2.at begin, 3.at any, 4.in sorted 5. traverse 6. del at end 7. del at start 8. del at any 9. Exit"<<endl;
        cout<<"Enter command: ";
        cin>>ch;
        switch(ch){
            case 1:
                ll1.insert_at_end();
                break;
            case 2:
                ll1.insert_at_begin();
                break;
            case 3:
                ll1.insert_at_any();
                break;
            case 5:
                ll1.traverse();
                break;
            case 4:
                ll1.insert_in_sorted();
                break;
            case 6:
                ll1.del_at_end();
                break;
            case 7:
                ll1.del_at_start();
                break;
            case 8:
                ll1.del_at_any();
                break;
            case 9:
                exit(0);
        }
    }

    return 0;
}