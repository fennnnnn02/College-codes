import java.util.*;


class Employee{
    private String name;
    private String post;
    public int id;
    public String address;
    public String mail;
    public long mob;
   
    public void read(String post,String name,int id,String address,String mail,long mob){
        this.name = name;
        this.id = id;
        this.address = address;
        this.mail = mail;
        this.mob = mob;
        this.post = post;
    }
    public void display(){
        System.out.println("Post of the Employee: "+post);
        System.out.println("Emp name: "+name);
        System.out.println("Address: "+address);
        System.out.println("Emp ID: "+id);
        System.out.println("Mail: "+mail);
        System.out.println("Mobile no.: "+mob);
    }
}

class Salary extends Employee{
    
    private double bp;
    private double net;
    private double gross;
    Scanner s = new Scanner(System.in);
    Salary(){
        System.out.println("Enter post,name,id,add,mail,no");
        super.read(s.next(),s.next(),s.nextInt(),s.next(),s.next(),s.nextLong());
        System.out.println("Enter BP: ");
        bp = s.nextDouble();
        double da = 0.97*bp;
        double hra = 0.1*bp;
        double pf = 0.12*bp;
        double scf = 0.001*bp;
        net = bp+da+hra-pf-scf;
        gross = bp+da+hra;
    }
    public void display(){
        super.display();
        System.out.println("Net salary: "+net);
        System.out.println("Gross salary: "+gross);
    }
}


public class OOPL03 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter total Employees: ");
        int n = s.nextInt();
        Employee p[] = new Salary[n];
        int ch,i=0;
        while(true){
            System.out.println("1.Read, 2.Display, 3.Exit ");
            System.out.println("Enter command: ");
            ch = s.nextInt();
            switch(ch){
                case 1:
                p[i] = new Salary();
                p[i].display();
                break;
                case 2:
                p[i-1].display();
                break;
                case 3:
                System.exit(0);
            }
            i++;
        }
    }
}
