
#include <bits/stdc++.h>
using namespace std;


struct Student{
    int rollno;
    string name;
    float sgpa;
};

class division{
    private:
    Student s[10];
    public:
    int n;
    public:
        void input();
        void display();
        void lsearch();
        void bsearch();
        void ins_sort();
        void bubble_sort();
        void selection_sort();
        void quick_sort(int low,int high);
}SE11;

void division::input(){
    cout<<"Enter value of n"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter name rollno. and sgpa: ";
        cin>>s[i].name>>s[i].rollno>>s[i].sgpa;
        cout<<endl;
    }
}

void division::display(){
    for(int i=0;i<n;i++){
        cout<<s[i].name<<" "<<s[i].rollno<<" "<<s[i].sgpa<<endl;
    }
}

void division::lsearch(){
    int k;
    cout<<"Enter roll no to find"<<endl;
    cin>>k;
    int i=0;
    for( i=0;i<n;i++){
        if(s[i].rollno==k) {
            cout<<s[i].name<<endl;
            break;
        }
    }
    if(i==n) cout<<"Not found"<<endl;
}

void division::bsearch(){
    string key;
    cout<<"Enter name to find"<<endl;
    cin>>key;
    int high = n-1;
    int low = 0;
    int mid = n/2;
    while(low<=high){
        int x = key.compare(s[mid].name);
        if(x==0){
            cout<<s[mid].rollno<<endl;
            break;
        }
        else if(x<0){
            high = mid-1;
        }
        else if(x>0){
            low = mid +1;
        }
        mid = (high + low)/2;
    }
    if(low>high) cout<<"not found"<<endl;
}

void division::ins_sort(){
    for(int i=1;i<n;i++){
        int j=i-1;
        Student temp = s[i];
        while(j>=0 and s[j].name>temp.name){
            s[j+1]=s[j];
            j--;
        }
        s[j+1]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<s[i].name<<" ";
        cout<<s[i].rollno<<" ";
        cout<<s[i].sgpa<<" "<<endl;
    }
}

void division::bubble_sort(){
    for(int i = 0 ; i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(s[j].rollno>s[j+1].rollno){
                Student temp=s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<s[i].name<<" ";
        cout<<s[i].rollno<<" ";
        cout<<s[i].sgpa<<" "<<endl;
    }
    
}

void division::selection_sort(){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(s[j].name<s[i].name){
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout<<s[i].name<<" ";
        cout<<s[i].rollno<<" ";
        cout<<s[i].sgpa<<" "<<endl;
    }
}

void division::quick_sort(int low,int high){
    if(low<=high){
    int pivot = s[low].sgpa;
    int i = low+1;
    int j = high;
    while(i<j){
        while(s[i].sgpa<pivot and i<=high) i++;
        while(s[j].sgpa>pivot and j>=low) j--;
        if(i<j){
            Student tempt = s[i];
            s[i] = s[j];
            s[j] = tempt;
            i++;
            j--;
        }
    }
    if(s[low].sgpa>=s[j].sgpa) {
        Student temp = s[low];
        s[low] = s[j];
        s[j] = temp;
    }
    quick_sort(low,j-1);
    quick_sort(j+1,high);
}
}

int main() {
   
   
   while(1){
       cout<<" 1. Input ";
       cout<<" 2. Display ";
       cout<<" 3. Lsearch ";
       cout<<" 4. Bsearch ";
       cout<<" 5. Insertion Sort ";
       cout<<" 6. Bubble Sort ";
       cout<<" 7. Selection Sort ";
       cout<<" 8. Quick Sort ";
       cout<<" 9. Exit "<<endl;
   
       int ch;
       cout<<"Enter command"<<endl;
       cin>>ch;
       switch (ch){
           case 1: 
           SE11.input();
           break;
           case 2:
           SE11.display();
           break;
           case 3:
           SE11.lsearch();
           break;
           case 4:
           SE11.bsearch();
           break;
           case 5:
           SE11.ins_sort();
           break;
           case 6:
           SE11.bubble_sort();
           break;
           case 7:
           SE11.selection_sort();
           break;
           case 8:
           SE11.quick_sort(0,SE11.n-1);
           break;
           case 9:
           exit(0);
       }
       cout<<endl;
   }
    return 0;
}


/*

Output

 1. Input  2. Display  3. Lsearch  4. Bsearch  5. Insertion Sort  6. Bubble Sort  7. Selection Sort  8. Quick Sort  9. Exit 
Enter command
1
Enter value of n
3
Enter name rollno. and sgpa: Parth 12 9

Enter name rollno. and sgpa: Akshay 36 9.3

Enter name rollno. and sgpa: Yash 22 8


 1. Input  2. Display  3. Lsearch  4. Bsearch  5. Insertion Sort  6. Bubble Sort  7. Selection Sort  8. Quick Sort  9. Exit 
Enter command
2
Parth 12 9
Akshay 36 9.3
Yash 22 8

 1. Input  2. Display  3. Lsearch  4. Bsearch  5. Insertion Sort  6. Bubble Sort  7. Selection Sort  8. Quick Sort  9. Exit 
Enter command
3
Enter roll no to find
12
Parth

 1. Input  2. Display  3. Lsearch  4. Bsearch  5. Insertion Sort  6. Bubble Sort  7. Selection Sort  8. Quick Sort  9. Exit
Enter command
3
Enter roll no to find
12
Parth

 1. Input  2. Display  3. Lsearch  4. Bsearch  5. Insertion Sort  6. Bubble Sort  7. Selection Sort  8. Quick Sort  9. Exit
Enter command
5
Akshay 36 9.3 
Parth 12 9
Yash 22 8

 1. Input  2. Display  3. Lsearch  4. Bsearch  5. Insertion Sort  6. Bubble Sort  7. Selection Sort  8. Quick Sort  9. Exit     n Sort  6. Bubble Sort  7. Selection Sort  8. Quick Sort  
9. Exit
Enter command
6
Parth 12 9
Yash 22 8
Akshay 36 9.3                                                  

 1. Input  2. Display  3. Lsearch  4. Bsearch  5. Insertion Sort  6. Bubble Sort  7. Selection Sort  8. Quick Sort  
9. Exit
Enter command
7
Akshay 36 9.3                                                 
Parth 12 9
Yash 22 8

 1. Input  2. Display  3. Lsearch  4. Bsearch  5. Insertion Sort  6. Bubble Sort  7. Selection Sort  8. Quick Sort  9. Exit     n Sort  6. Bubble Sort  7. Selection Sort  8. Quick Sort  
9. Exit
Enter command
8

 1. Input  2. Display  3. Lsearch  4. Bsearch  5. Insertion Sort  6. Bubble Sort  7. Selection Sort  8. Quick Sort  n Sort  6. Bubble Sort  7. Selection Sort  8. Quick Sort  9. Exit     
9. Exit
Enter command
2                                                         
Yash 22 8
Akshay 36 9.3
Parth 12 9

 1. Input  2. Display  3. Lsearch  4. Bsearch  5. Insertion Sort  6. Bubble Sort  7. Selection Sort  8. Quick Sort  
9. Exit
Enter command
9

Exited successfully

*/
