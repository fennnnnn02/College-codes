#include <fstream>
#include <iostream>
#include <conio.h>

using namespace std;
class student
{
private:
    string name, roll_no, div, address;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};


void student::menu()
{
    while(true){int choice;
    char x;

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t STUDENT MANAGEMENT SYSTEM " << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t Add Another Student Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }}
}
void student::insert() // add student details
{
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Student Details ---------------------------------------------" << endl;
    
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_no;
    cout << "\t\t\tEnter div: ";
    cin >> div;
    cout << "\t\t\tEnter Address: ";
    cin >> address;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << div << " " << address << "\n";
    file.close();
}

void student::display() 
{
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        /* code */
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> div >> address;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Student No.: " << total++ << endl;
            cout << "\t\t\t Student Name: " << name << endl;
            cout << "\t\t\t Student Roll No.: " << roll_no << endl;
            cout << "\t\t\t Student course: " << div << endl;
            cout << "\t\t\t Student Address: " << address << endl;
            file >> name >> roll_no >>div>> address;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file.close();
}
void student::modify() // Modify Students Details
{

    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> div >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)

                file1 << " " << name << " " << roll_no << " " << div << " " << address << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "\t\t\tEnter Div: ";
                cin >> div;
                cout << "\t\t\tEnter Address: ";
                cin >> address;
                file1 << " " << name << " " << roll_no << " " << div << " " << address << "\n";
                found++;
            }
            file >> name >> roll_no >> div >> address;
            if (found == 0)
            {
                cout << "\n\n\t\t\t Student Roll No. Not Found....";
            }
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
void student::search() 
{

    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n Enter Roll No. of Student Which You Want to Search: ";
        cin >> rollno;
        file >> name >> roll_no >> div >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\t\t\t Student Name: " << name << endl;
                cout << "\t\t\t Student Roll No.: " << roll_no << endl;
                cout << "\t\t\t Student div: " << div << endl;
                cout << "\t\t\t Student Address: " << address << endl;
                found++;
            }
            file >> name >> roll_no >> div>> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent Roll No. Not Found...";
        }
        file.close();
    }
}
void student::deleted()
{
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> div >> address;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << div<< " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll_no >> div>> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
main()
{
    student project;
    project.menu();
    return 0;
}          


/*

Output

-----------------------------------------------------------------------------------------------------
------------------------------------- Add Student Details ---------------------------------------------
                        Enter Name: Parth
                        Enter Roll No.: 23338
                        Enter div: 11
                        Enter Address: Pune                                                     -----
                                                                                                -------
                         Add Another Student Record (Y,N): Y

-----------------------------------------------------------------------------------------------------
------------------------------------- Add Student Details ---------------------------------------------
                        Enter Name: Parth
                        Enter Roll No.: 33338                                                   -----
                        Enter div: 11                                                           -------
                        Enter Address: Pune

                         Add Another Student Record (Y,N): Y

-----------------------------------------------------------------------------------------------------
------------------------------------- Add Student Details ---------------------------------------------                                                                                         -----
                        Enter Name: Sayali                                                      -------
                        Enter Roll No.: 43338
                        Enter div: 11
                        Enter Address: Delhi

                         Add Another Student Record (Y,N): N
                        -----------------------------
                        -----------------------------
                         1. Enter New Record
                         2. Display Record
                         3. Modify Record
                         4. Search Record
                         5. Delete Record
                         6. Exit
                        ---------------------------
                        Choose Option:
                        ---------------------------
Enter Your Choice: 2

-------------------------------------------------------------------------------------------------------
------------------------------------- Student Record Table --------------------------------------------


                         Student No.: 1
                         Student Name: Parth
                         Student Roll No.: 23338
                         Student course: 11
                         Student Address: Pune


                         Student No.: 2
                         Student Name: Parth
                         Student course: 11
                         Student Address: Pune


                         Student No.: 3
                         Student Name: Sayali
                         Student Roll No.: 43338
                         Student course: 11
                         Student Address: Delhi
                        -----------------------------
                         STUDENT MANAGEMENT SYSTEM
                        -----------------------------
                         1. Enter New Record
                         2. Display Record
                         3. Modify Record
                         4. Search Record
                         5. Delete Record
                         6. Exit
                        ---------------------------
                        Choose Option:
                        ---------------------------
Enter Your Choice: 3

------------------------------------------------------------------------------------------------------------------------------------- Student Modify Details ------------------------------------------

Enter Roll No. of Student which you want to Modify: 23338

                        Enter Name: Paarth
                        Enter Roll No.: 23333
                        Enter Div: 11
                        Enter Address: Khed
                        -----------------------------
                         STUDENT MANAGEMENT SYSTEM
                        -----------------------------
                         1. Enter New Record
                         2. Display Record
                         3. Modify Record
                         4. Search Record
                         5. Delete Record
                         6. Exit
                        ---------------------------
                        Choose Option:
                        ---------------------------
Enter Your Choice: 4

-------------------------------------------------------------------------------------------------------
------------------------------------- Student Search Data ------------------------------------------

 Enter Roll No. of Student Which You Want to Search: 33338

                         Student Name: Parth
                         Student Roll No.: 33338
                         Student div: 11
                         Student Address: Pune

                        -----------------------------
                         STUDENT MANAGEMENT SYSTEM
                        -----------------------------
                         1. Enter New Record
                         2. Display Record
                         3. Modify Record
                         4. Search Record
                         5. Delete Record
                         6. Exit
                        ---------------------------
                        Choose Option:
                        ---------------------------
Enter Your Choice: 5

-------------------------------------------------------------------------------------------------------
------------------------------------- Delete Student Details ------------------------------------------

Enter Roll No. of Student which you want Delete Data: 23333

                        Successfully Delete Data


*/