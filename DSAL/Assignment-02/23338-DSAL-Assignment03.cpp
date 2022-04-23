#include <bits/stdc++.h>

using namespace std;

struct Student{
    string name;
    int rollno;
    int sgpa;
};

class Queue{ 
        Student *s;
        int r,f,n;
    public:
        Queue();
        Student input();
        void insert(Student item);
        void del();
        bool isempty();
        bool isfull();
        void display();

}SE11;

Queue::Queue(){
    r = -1;
    f = -1;
    cout<<"Enter n"<<endl;
    cin>>n;
    s = new Student[n];
}

Student Queue::input(){
    Student a;
    cout<<"Enter name, roll no, sgpa "<<endl;
    cin>>a.name>>a.rollno>>a.sgpa;
    return a;
}

void Queue::insert(Student item){
    // linear queue
    // if(r<9){
    //     if(f ==-1) f++;
    //     r = r + 1;
    //     s[r] = item;
    // }
    // else cout<<"Overload"<<endl;

    // circular queue
    if(isfull()) cout<<"Overflow"<<endl;
    else {
        if(r==-1) {
            f++;
        }
        r = (r+1)%n;
        s[r] = item;
    }
}

void Queue::del(){
    // linear queue
    // if(SE11.isempty()) cout<<"Empty"<<endl;
    // else f++;

    // circular queue
    if(isempty()) cout<<"Empty"<<endl;
    else{
        if(f==r){
            f=-1;
            r=-1;
        }
        else f = (f+1)%n;
    }
}

bool Queue::isempty(){
    // if(f==r+1 or f==-1) return true;
    if(f==-1) return true;
    else return false;
}

bool Queue::isfull(){
    if((r+1)%n==f) return true;
    else return false;
}

void Queue::display(){
    if(isempty()) cout<<"Empty"<<endl;
    else {
            int i=f;
            for( i; i!=r;i=(i+1)%n){
                cout<<s[i].name<<" "<<s[i].rollno<<" "<<s[i].sgpa<<endl;
            }
            cout<<s[i].name<<" "<<s[i].rollno<<" "<<s[i].sgpa<<endl;
    }
}

int main(){

    while(1){
        cout<<"1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit"<<endl;
        int ch;
        cout<<"Enter command"<<endl;
        cin>>ch;
    
        switch(ch){
            case 1:
            SE11.insert(SE11.input());
            break;
            case 2:
            SE11.del();
            break;
            case 3:
            cout<<SE11.isempty();
            break;
            case 4:
            cout<<SE11.isfull();
            break;
            case 5:
            SE11.display();
            break;
            case 6:
            exit(0);

        }
    }

    return 0;
}

/*

Enter n
5
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
1
Enter name, roll no, sgpa 
A 13 8
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
1
Enter name, roll no, sgpa 
B 12 7
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
1
Enter name, roll no, sgpa 
C 34 9
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
5
A 13 8
B 12 7
C 34 9
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
1
Enter name, roll no, sgpa 
D 6 8
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
1
Enter name, roll no, sgpa 
E 8 5
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
1
Enter name, roll no, sgpa 
F 1 5
Overflow
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
5
A 13 8
B 12 7
C 34 9
D 6 8
E 8 5
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
2
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
5
B 12 7
C 34 9
D 6 8
E 8 5
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
1
Enter name, roll no, sgpa 
F 11 6
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
5
B 12 7
C 34 9
D 6 8
E 8 5
F 11 6
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
4
1
1.Insert 2.Del 3.IsEmpty 4.Is Full 5.Display 6.Exit
Enter command
6

*/