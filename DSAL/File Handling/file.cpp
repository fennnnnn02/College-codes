#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<fstream>

using namespace std;

class Student{
    private:
    int roll;
    string name;
    string address;
    int div;
    int count;
    public:
    Student();
    void create();
    void addStudent();
    void display();
    int search();
    void del();
    void update();
};

Student::Student(){
    count=1;
}

void Student::create(){
    fstream f("new.txt");
    f<<"------------------------------------------------------------------------\n";
    f<<"Title - Student Database\n";
    f<<"------------------------------------------------------------------------\n";
    f<<"Srno.\t\tName\t\tRollno.\t\tDivision\t\tAddress\n";
    f<<"------------------------------------------------------------------------\n";
    f.close();
}

void Student::addStudent(){
    ofstream f("new.txt",ios::out | ios::app);
    char a = 'y';
    while(a=='y' or a=='Y'){ 
        cout<<"Enter name, rollno, division and address in order: ";
        cin>>name;
        cin>>roll;
        cin>>div;
        cin>>address;
        f<<count<<"\t\t\t"<<name<<"\t\t\t"<<roll<<"\t\t\t"<<div<<"\t\t\t"<<address<<"\n";
        count++;
        cout<<"Do you want to enter another record? (y/n): ";
        cin>>a;
    }
    f.close();
}

void Student::display(){
    fstream file;
    string word;
	file.open("new.txt", ios::in);
	if (!file) {
		cout << "No such file";
	}
	else {
		while (getline(file,word)){
                cout << word<<endl; ;
            }

	}
	file.close();
}

int Student::search(){
    ifstream fin;
	fin.open("new.txt");
    string word;
	if(fin.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	string search;
	cout << "Please enter a name: ";
	cin  >> search;
	bool isFound;
    int c=0;
	while(!fin.eof())
	{
		string temp = "";
		getline(fin,temp);
        stringstream iss(temp);
        iss>>word;
        if(isdigit(word[0])){c = stoi(word);}
        while(iss>>word){
            if(word==search){
                isFound=true;
                break;
            }
        }

		if(isFound)
		{
			cout << "Record found "<<endl;
            return c;
            break;
		}

	}

	if(fin.eof()&&(!isFound))
	{
		cout << "Name not found!\n";
	}

	fin.close();
    return c;
}

void Student::del(){
    int c = search();
    int cbar=0;
    ifstream fin;
	fin.open("new.txt");
    fstream f("del.txt",ios::out | ios::app);
    string word;
    while(!fin.eof())
	{
		string temp = "";
		getline(fin,temp);
        stringstream iss(temp);
        iss>>word;
            if(isdigit(word[0])){
                cbar = stoi(word);
            }
            if(cbar!=c){
                f<<temp<<"\n";
            }
    }
    // f.close();
    // fin.close();
    //remove("new.txt");
    //rename("del.txt", "new.txt");
}

void Student::update(){
    int c = search();
    int cbar=0;
    ifstream fin;
	fin.open("new.txt");
    fstream f("update.txt",ios::out | ios::app);
    string word;

    int rollno,division;
    string add;

    cout<<"Enter new rollno: ";
    cin>>rollno;
    cout<<"Enter new division: ";
    cin>>division;
    cout<<"Enter new address: ";
    cin>>add;

    while(!fin.eof())
	{
		string temp = "";
		getline(fin,temp);
        stringstream iss(temp);
        iss>>word;
            if(isdigit(word[0])){
                cbar = stoi(word);
            }

            if(cbar!=c){
                f<<temp<<"\n";
            }
            if(cbar==c){
                iss>>word;
                f<<c<<"\t\t\t"<<word<<"\t\t\t"<<rollno<<"\t\t\t"<<division<<"\t\t\t"<<add<<"\n";
            }
            
    }
    f.close();
    fin.close();
     remove("new.txt");
     rename("update.txt", "new.txt");
}


int main(){
    Student s;
    s.create();
    s.addStudent();
    s.update();
    // int c;
    // while(true){
    //     cout<<"-------------------------------------------------------"<<endl;
    //     cout<<"1. Add Student to file"<<endl;
    //     cout<<"2. Delete Student "<<endl;
    //     cout<<"3. Update records by name "<<endl;
    //     cout<<"4. Search Record "<<endl;
    //     cout<<"5. Display Records "<<endl;
    //     cout<<"6. Exit"<<endl;
    //     cout<<"-------------------------------------------------------"<<endl;
    //     cout<<"Enter command: ";
    //     cin>>c;
    //     switch(c){
    //         case 1:
    //         s.addStudent();
    //         break;
    //         case 2:
    //         s.del();
    //         break;
    //         case 3:
    //         s.update();
    //         break;
    //         case 4:
    //         s.search();
    //         break;
    //         case 5:
    //         s.display();
    //         break;
    //         case 6:
    //         cout<<"Exited Successfully"<<endl;
    //         exit(0);
    //     }
    // }
}