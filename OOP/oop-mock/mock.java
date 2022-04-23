import java.util.*;


// Design and develop inheritance for a given case study, identify objects and relationships 
// and implement inheritance wherever applicable. Employee class has Emp_name, Emp_id, 
// Address, Mail_id, and Mobile_no as members. Inherit the classes: Programmer, Team Lead, 
// Assistant Project Manager and Project Manager from employee class. Add Basic Pay (BP) as 
// the member of all the inherited classes . with 97% of BP as DA, 10 % of BP as HRA, 12% of 
// BP as PF, 0.1% of BP for staff club fund. Generate pay slips for the employees with their 
// gross and net salary

class Employee{
    Scanner sc = new Scanner(System.in);
    // Declaring employee details
    String emp_name; 
	String address;
	String mail_id;
	long mobile_no;
	int emp_id;
	double basic_pay;
    static int id=100;
    double net_salary,gross;
	double hra,da,pf,staff;

    // Constructor for employee class
    Employee(){
        id++;
    }

    void input_details() {
        System.out.print("Enter the name of Employee: ");
        emp_name=sc.nextLine();
        emp_id=id;
        System.out.print("Enter Address:  ");
        address=sc.next();
        System.out.print("Enter Mobile No.:  ");
        mobile_no=sc.nextLong();
    }

    void display_details(){
        System.out.println("=================================================================================");
        System.out.println("Employee name: "+emp_name);
        System.out.println("Employee id: "+emp_id);
        System.out.println("Employee mail: "+mail_id);
        System.out.println("Employee mobile no. : "+mobile_no);
        System.out.println("Employee address: "+address);
        System.out.println("=================================================================================");
        
    }
    void cal_salary(){
        da=basic_pay*.97;
		hra=basic_pay*.10;
		 pf=basic_pay*.12;
		staff=basic_pay*0.001;
		gross=basic_pay + hra;
        net_salary=gross-pf-staff;
    }
}  

class Programmer extends Employee{

    void read_programmer(){
        input_details();
        System.out.print("Enter Basic pay of the programmer between 30000-40000: ");
        basic_pay = sc.nextDouble();
        cal_salary();
    }

    void display_salary(){
        System.out.println("=================================================================================");
        System.out.println(" Basic pay of the Programmer:	"+basic_pay);
		System.out.println(" HRA:"+hra);
		System.out.println(" PF:	"+pf);
		System.out.println(" Gross Salary: 	"+gross);
		System.out.println(" Net Salary: "+ net_salary);
        System.out.println("=================================================================================");
    }
}

class Team_lead extends Employee{

    void read_team_lead(){
        input_details();
        System.out.print("Enter Basic pay of the Team lead between 40000-50000: ");
        basic_pay = sc.nextDouble();
        cal_salary();
    }

    void display_salary(){
        System.out.println("=================================================================================");
        System.out.println(" Basic pay of the Team lead:	"+basic_pay);
		System.out.println(" HRA:"+hra);
		System.out.println(" PF:	"+pf);
		System.out.println(" Gross Salary: 	"+gross);
		System.out.println(" Net Salary: "+ net_salary);
        System.out.println("=================================================================================");
    }
}

class Ass_Pro_Manager extends Employee{

    void read_Ass_Pro_Manager(){
        input_details();
        System.out.print("Enter Basic pay of the Assitant Project Manager: ");
        basic_pay = sc.nextDouble();
        cal_salary();
    }

    void display_salary(){
        System.out.println("=================================================================================");
        System.out.println(" Basic pay of the Assistant Project Manager: "+basic_pay);
		System.out.println(" HRA:"+hra);
		System.out.println(" PF: "+pf);
		System.out.println(" Gross Salary: 	"+gross);
		System.out.println(" Net Salary: "+ net_salary);
        System.out.println("=================================================================================");
    }
}

class Pro_Manager extends Employee{

    void read_Pro_Manager(){
        input_details();
        System.out.print("Enter Basic pay of the Project Manager: ");
        basic_pay = sc.nextDouble();
        cal_salary();
    }

    void display_salary(){
        System.out.println("=================================================================================");
        System.out.println(" Basic pay of the Assistant Project Manager: "+basic_pay);
		System.out.println(" HRA:"+hra);
		System.out.println(" PF: "+pf);
		System.out.println(" Gross Salary: 	"+gross);
		System.out.println(" Net Salary: "+ net_salary);
        System.out.println("=================================================================================");
    }
}

class mock{
    public static void main(String[] args) {

        int ch,p_n,t_n,c;
        Scanner sc = new Scanner(System.in);
        
        Ass_Pro_Manager a = new Ass_Pro_Manager();
        Pro_Manager m = new Pro_Manager();

        // A team of employee contains p_n programmers, t_n team_leads , 1 assistant manager and 1 project manager

        


        System.out.print("Enter no. of programmers: ");
        p_n = sc.nextInt();
        System.out.print("Enter no. of Team leads: ");
        t_n = sc.nextInt();
        
        Programmer p[] = new Programmer[p_n];
        Team_lead t[] = new Team_lead[t_n];

        while(true){
            System.out.println("");
            System.out.println("1. Input 2. Display");
            System.out.println("");
            c = sc.nextInt();
            switch(c){
            case 1:
            System.out.println("=================================================================================");
            System.out.println("Choose one of the following: ");
            System.out.println("Programmer- 1");
            System.out.println("Team Lead- 2");
            System.out.println("Assistant Project Manager- 3");
            System.out.println("Project Manager- 4");
            System.out.println("=================================================================================");
            ch = sc.nextInt();
            switch(ch){
                case 1:
                for(int i=0;i<p_n;i++){
                    p[i] = new Programmer();
                    p[i].read_programmer();
                }
                break;
                case 2:
                for(int i=0;i<t_n;i++){
                    t[i] = new Team_lead();
                    t[i].read_team_lead();
                }
                break;
                case 3:
                a.read_Ass_Pro_Manager();
                break;
                case 4:
                m.read_Pro_Manager();
                break;
            }
            break;
            case 2:
            System.out.println("=================================================================================");
            System.out.println("Choose one of the following to display salary slips: ");
            System.out.println("Programmer- 1");
            System.out.println("Team Lead- 2");
            System.out.println("Assistant Project Manager- 3");
            System.out.println("Project Manager- 4");
            System.out.println("Go back-5");
            System.out.println("=================================================================================");
            ch = sc.nextInt();
            int id;
            switch(ch){
                case 1:
                
                for(int i=0;i<p_n;i++){
                        p[i].display_salary();
                        p[i].display_details();
                }
                break;
                case 2:
            
                for(int i=0;i<t_n;i++){
                        t[i].display_salary();
                        t[i].display_details();
                }
                break;
                case 3:
                a.display_salary();
                a.display_details();
                break;
                case 4:
                m.display_salary();
                m.display_details();
                break;
                case 5:
                continue;
            }
            break;
            case 3:
            System.exit(0);
        }
        }
        

    }
}

/*

Output

Enter no. of programmers: 1 
Enter no. of Team leads: 1

1. Input 2. Display

1
=================================================================================
Choose one of the following: 
Programmer- 1
Team Lead- 2
Assistant Project Manager- 3
Project Manager- 4
=================================================================================
1
Enter the name of Employee: P1
Enter Address:  P1
Enter Mobile No.:  9876543210
Enter Basic pay of the programmer: 30000

1. Input 2. Display

1
=================================================================================
Choose one of the following: 
Programmer- 1
Team Lead- 2
Assistant Project Manager- 3
Project Manager- 4
=================================================================================
2
Enter the name of Employee: TeamLead1
Enter Address:  T1
Enter Mobile No.:  9876543210
Enter Basic pay of the Team lead: 40000

1. Input 2. Display

1
=================================================================================
Choose one of the following:
Programmer- 1
Team Lead- 2
Assistant Project Manager- 3
Project Manager- 4
=================================================================================     
3
Enter the name of Employee: APM1
Enter Address:  A1
Enter Mobile No.:  9876543210
Enter Basic pay of the Assitant Project Manager: 50000

1. Input 2. Display

1
=================================================================================
Choose one of the following:
Programmer- 1
Team Lead- 2
Assistant Project Manager- 3
Project Manager- 4
=================================================================================     
4
Enter the name of Employee: PM1
Enter Address:  P1
Enter Mobile No.:  9876543210
Enter Basic pay of the Project Manager: 60000

1. Input 2. Display

2
=================================================================================
Choose one of the following to display salary slips:
Programmer- 1
Team Lead- 2
Assistant Project Manager- 3
Project Manager- 4
Go back-5
=================================================================================     
1
=================================================================================
 Basic pay of the Programmer:   30000.0
 HRA:3000.0
 PF:    3600.0
 Gross Salary:  33000.0
 Net Salary: 29370.0
=================================================================================     
=================================================================================     
Employee name: P1
Employee id: 103
Employee mail: null
Employee mobile no. : 9876543210
Employee address: P1
=================================================================================     

1. Input 2. Display

2
=================================================================================
Choose one of the following to display salary slips:
Programmer- 1
Team Lead- 2
Assistant Project Manager- 3
Project Manager- 4
Go back-5
=================================================================================     
2
=================================================================================
 Basic pay of the Team lead:    40000.0
 HRA:4000.0
 PF:    4800.0
 Gross Salary:  44000.0
 Net Salary: 39160.0
=================================================================================     
=================================================================================     
Employee name: TeamLead1
Employee id: 104
Employee mail: null
Employee mobile no. : 9876543210
Employee address: T1
=================================================================================     

1. Input 2. Display

2
=================================================================================
Choose one of the following to display salary slips:
Programmer- 1
Team Lead- 2
Assistant Project Manager- 3
Project Manager- 4
Go back-5
=================================================================================     
3
=================================================================================
 Basic pay of the Assistant Project Manager: 50000.0
 HRA:5000.0
 PF: 6000.0
 Gross Salary:  55000.0
 Net Salary: 48950.0
=================================================================================     
=================================================================================     
Employee name: APM1
Employee id: 104
Employee mail: null
Employee mobile no. : 9876543210
Employee address: A1
=================================================================================     

1. Input 2. Display

2
=================================================================================
Choose one of the following to display salary slips:
Programmer- 1
Team Lead- 2
Assistant Project Manager- 3
Project Manager- 4
Go back-5
=================================================================================     
4
=================================================================================
 Basic pay of the Assistant Project Manager: 60000.0
 HRA:6000.0
 PF: 7200.0
 Gross Salary:  66000.0
 Net Salary: 58740.0
=================================================================================     
=================================================================================     
Employee name: PM1
Employee id: 104
Employee mail: null
Employee mobile no. : 9876543210
Employee address: P1
=================================================================================     

1. Input 2. Display
3

Exited Successfully

*/