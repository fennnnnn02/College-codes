# include <iostream>

using namespace std;

class heap{
    private:
    int n;
    int *tree;
    public:
    void inp();
    void ins(int n,int item);
    void del();
    void heapsort();
    void display();
};

void heap::ins(int n,int item){
   
    int par;
    int ptr = n ;
    while(ptr>0){
        par = (ptr-1)/2;
        if(item<= tree[par]){
            tree[ptr] = item;
            return;
        }
        else{
            tree[ptr] = tree[par];
            ptr = par;
        }
    }
    tree[ptr] = item;
}

void heap::del(){
    int item = tree[0];
    cout<<item<<" ";
    int last = tree[n-1];
    n=n-1;
    int ptr=0,left=1,right=2;
    while(right<=n){
        if(last>=tree[left] and last>=tree[right]){
            tree[ptr] = last;
            return;
        }
        else if(tree[right]<=tree[left]){
            tree[ptr] = tree[left];
            ptr = left;
        }
        else{
            tree[ptr] = tree[right];
            ptr = right;
        }
        left = ptr*2+1;
        right = ptr*2+2;
    }
    if(left == n-1 and last<tree[left]){
        cout<<"found"<<endl;
        tree[ptr] = tree[left];
        ptr = left;
    }
    tree[ptr] = last;
}

void heap::inp(){
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Enter no of elements: ";
    cin>>n;
    tree = new int[n];
    for(int i=0;i<n;i++){
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"Enter element "<<i+1<<": ";
        cin>>tree[i];
    }
}

void heap::heapsort(){
    for(int i=0;i<=n-1;i++){
        ins(i,tree[i]);
    }
    while(n>0){
        del();
    }
    cout<<endl;
}

int main(){

    heap h;
    int ch;
    while(true){
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"1. Input Array"<<endl;
        cout<<"2. Sort "<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"Enter command: ";
        cin>>ch;
        switch(ch){
            case 1:
            h.inp();
            break;
            case 2:
            cout<<"-------------------------------------------------------"<<endl;
            h.heapsort();
            break;
            case 3:
            cout<<"Exited Successfully"<<endl;
            exit(0);
        }
    }
    return 0;
}

/*

Output

-------------------------------------------------------
1. Input Array
2. Sort 
3. Exit
-------------------------------------------------------
Enter command: 1
-------------------------------------------------------
Enter no of elements: 5
-------------------------------------------------------
Enter element 1: 5
-------------------------------------------------------
Enter element 2: 2
-------------------------------------------------------
Enter element 3: 8
-------------------------------------------------------
Enter element 4: 3
-------------------------------------------------------
Enter element 5: 7
-------------------------------------------------------
1. Input Array
2. Sort 
3. Exit
-------------------------------------------------------
Enter command: 2
-------------------------------------------------------
8 7 5 3 2 
-------------------------------------------------------
1. Input Array
2. Sort 
3. Exit
-------------------------------------------------------
Enter command: 3
Exited Successfully

*/