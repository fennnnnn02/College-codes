
import java.util.*;

class Account{

    protected String name,location;

    protected double accno,balance;

    protected int age;

    public void createAcc(){

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter account name: ");
        name = sc.next();

        System.out.print("Enter address: ");
        location = sc.next();

        System.out.print("Enter Account no. : ");
        accno = sc.nextDouble();

        System.out.print("Enter Balance: ");
        balance = sc.nextDouble();

        System.out.print("Enter age: ");
        age = sc.nextInt();
        if(age<18){
            System.out.println("Minimum age should be 18 to create an account.​");
            System.out.print("Please enter valid age: ");
            age = sc.nextInt();
        }

    }

    public void DisplayAcc(){

        System.out.println("HELLO " + name +"! The details of the account are as follows: ");
        System.out.println("Account name: "+name);
        System.out.println("Account address: "+location);
        System.out.println("Account accno: "+accno);
        System.out.println("Account age: "+age);

    }

}

class BankingSolution extends Account{
    
    public void deposit(double amt){
        System.out.println("Successfully deposited "+amt);
        balance += amt;
    }

    public void withdraw(double amt){

        int limit = 10000;

        if(amt>balance ){
            System.out.println("Withdrawal failed. Check your balance.");
            return;
        }

        if(amt>limit){
            System.out.println("Sorry! Daily withdrawal limit is "+limit);
            return;
        }

        else{
            balance-=amt;
            System.out.println("Withdrawal successfull.");
        }

    }

    public void checkBalance(){
        System.out.println("Account balance of account id"+accno+" is: "+balance);
    }

}


public class Main{
    public static void main(String[] args) {

        BankingSolution f = new BankingSolution();

        int c,amt;
        Scanner sc = new Scanner(System.in);

        while(true){

                System.out.println("-------------------------------------------------------");
                System.out.println("1. Create Account");
                System.out.println("2. Display Account");
                System.out.println("3. Withdraw Money");
                System.out.println("4. Deposit Money");
                System.out.println("5. Check Balance");
                System.out.println("6. Exit");
                System.out.println("-------------------------------------------------------");
                System.out.print("Enter command: ");

                c = sc.nextInt();
                
                switch(c){
                    case 1:
                    System.out.println("-------------------------------------------------------");
                    f.createAcc();
                    break;
                    case 2:
                    System.out.println("-------------------------------------------------------");
                    f.DisplayAcc();
                    break;
                    case 3:
                    System.out.println("-------------------------------------------------------");
                    System.out.print("Enter amount to withdraw: ");
                    amt = sc.nextInt();
                    f.withdraw(amt);
                    break;
                    case 4:
                    System.out.print("Enter amount to deposit: ");
                    amt = sc.nextInt();
                    f.deposit(amt);;
                    break;
                    case 5:
                    f.checkBalance();
                    break;
                    case 6:
                    System.out.println("Exited Successfully");
                    System.exit(0);

            }
        }
    }
}

/*

Output

-------------------------------------------------------
1. Create Account
2. Display Account
3. Withdraw Money
4. Deposit Money
5. Check Balance
6. Exit
-------------------------------------------------------
Enter command: 1
-------------------------------------------------------
Enter account name: Parth
Enter address: Pune
Enter Account no. : 12243648
Enter age: 19
Enter Balance: 5000
-------------------------------------------------------
1. Create Account
2. Display Account
3. Withdraw Money
4. Deposit Money
5. Check Balance
6. Exit
-------------------------------------------------------
Enter command: 2
------------------------------------------------------- 
HELLO Parth! The details of the account are as follows: 
Account name: Parth
Account address: Pune
Account accno: 12243648
Account age: 19
-------------------------------------------------------
1. Create Account
2. Display Account
3. Withdraw Money
4. Deposit Money
5. Check Balance
6. Exit
-------------------------------------------------------
Enter command: 3
-------------------------------------------------------
Enter amount to withdraw: 10000
Withdrawal failed. Check your balance.
-------------------------------------------------------
1. Create Account
2. Display Account
3. Withdraw Money
4. Deposit Money
5. Check Balance
6. Exit
-------------------------------------------------------
Enter command: 3
-------------------------------------------------------
Enter amount to withdraw: 2000
Withdrawal successfull.
-------------------------------------------------------
1. Create Account
2. Display Account
3. Withdraw Money
4. Deposit Money
5. Check Balance
6. Exit
-------------------------------------------------------
Enter command: 4
Enter amount to deposit: 5000
Successfully deposited 5000.0
-------------------------------------------------------
1. Create Account
2. Display Account
3. Withdraw Money
4. Deposit Money
5. Check Balance
6. Exit
-------------------------------------------------------
Enter command: 5
Account balance of account id 12243648 is: 8000.0
-------------------------------------------------------
1. Create Account
2. Display Account
3. Withdraw Money
4. Deposit Money
5. Check Balance
6. Exit
-------------------------------------------------------
Enter command: 6
Exited Successfully

*/