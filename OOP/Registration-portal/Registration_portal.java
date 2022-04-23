import java.util.*;

class Course{
    private String host;
    private int hrs;
    private int assign;
    private String ld;
    public int students;
    public void display(){
        System.out.println("");
        System.out.println("Instructor: "+host);
        System.out.println("No. of hrs: "+hrs);
        System.out.println("No. of assignments: "+assign);
        System.out.println("Last date of enrolment: "+ld);
    }
    Course(String a,int b,int c,String d){
        this.host = a;
        this.hrs = b;
        this.assign = c;
        this.ld = d;
        this.students = 0;
    }
    public void enroll(){
        System.out.println("No. of Students enrolled: "+students);
    }
}

class Info{
    String name;
    String coursename;
    Info(String name , String coursename){
        this.name = name;
        this.coursename = coursename;
    }
    // public void setname(String name){
    //     this.name = name;
    // }
}

public class Registration_portal {
    public static void main(String[] args) {
        Course java = new Course("person1",23,10,"30/09/21");
        Course cpp = new Course("person2",29,12,"25/09/21");
        Course aiml = new Course("person3",40,15,"10/10/21");
        Course dbms = new Course("person4",42,13,"20/10/21");

        Info[] info1 = new Info[10];
        int i=0;

        while(true){
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter name");
            info1[i]= new Info(sc.next(),"");
            i++;
            System.out.println("");
            System.out.println("Select a course");
            System.out.println("1. Java, 2. C++, 3. AI/ML, 4. DBMS");
            int ch;
            
            ch = sc.nextInt();
            switch(ch){
                case 0:
                System.exit(0);
                case 1:
                java.display();
                break;
                case 2:
                cpp.display();
                break;
                case 3:
                aiml.display();
                break;
                case 4:
                dbms.display();
                break;
            }

            System.out.println("1.Enroll, 2.Quit");
            int ch1 = sc.nextInt();
            switch(ch1){
                case 1:
                System.out.println("");
                System.out.println("Thanks for enrolling");
                System.out.println("");
                switch(ch){
                    case 1:
                    java.students++;
                    info1[i-1].coursename = "Java";
                    break;
                    case 2:
                    cpp.students++;
                    info1[i-1].coursename = "C++";
                    break;
                    case 3:
                    aiml.students++;
                    info1[i-1].coursename = "AI/ML";
                    break;
                    case 4:
                    dbms.students++;
                    info1[i-1].coursename = "DBMS";
                    break;
                }
                break;
                case 2:
                System.exit(0);
                
            }
            for(int j=0;j<i;j++){
                System.out.println("Student name: "+info1[j].name+", "+"Student course: "+info1[j].coursename);
            }
            System.out.println("");
            System.out.println("Total Enrollments: ");
            System.out.println("Java: "+java.students);
            System.out.println("C++: "+cpp.students);
            System.out.println("AI/ML: "+aiml.students);
            System.out.println("DBMS: "+dbms.students);
            System.out.println("");

            
        }
    }
}


