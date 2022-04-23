import java.util.Scanner;
import java.util.ArrayList;

class ShoppingCart{

    ArrayList<String> cart=new ArrayList<String>();
    int total;

    public void add(String item,int price){
        cart.add(item);
        total += price;
    }

    public void DisplayCart(){
        System.out.println("Items included in the cart are: ");
        for(String i:cart){
            System.out.println(i);
        }
    }
    
    public void remove(String item,int price){
        cart.remove(item);
        total-=price;
    }

    public void pay(PaymentType p,int amount){
        p.pay(amount);
    }

    public int getPrice(){
        return total;
    }
}

interface PaymentType{
    public void pay(int amount);
}


class Paypal implements PaymentType{

    private String email; 
    private String password;

    Paypal(String email, String pwd){
        this.email=email;
        this.password=pwd;
    }

    public void pay(int amount){
        System.out.println(amount + " Rupees paid using Paypal.");
    }
}

class CreditCard implements PaymentType{

    private String name;
    private String cardNumber;
    private String cvv;
    private String dateofExpiry;

    CreditCard(String name, String cardNumber,String cvv,String doe){
        this.name=name;
        this.cardNumber=cardNumber;
        this.cvv = cvv;
        this.dateofExpiry = doe;
    }

    public void pay(int amount){
        System.out.println(amount + " paid using Credit Card.");
    }
}

class Bitcoin implements PaymentType{
    private String transactionID;
    Bitcoin(String t){
        this.transactionID=t;
    }
    public void pay(int amount){
        System.out.println(amount + " paid using Bitcoin.");
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PaymentType p;
        ShoppingCart s = new ShoppingCart();
        int ch;
        while(true){
            System.out.println("-------------------------------------------------------");
            System.out.println("1. Add item");
            System.out.println("2. Remove item");
            System.out.println("3. Display Cart");
            System.out.println("4. Pay using Credit Card");
            System.out.println("5. Pay using Bitcoin");
            System.out.println("6. Pay using Paypal");
            System.out.println("7. Exit");
            System.out.println("-------------------------------------------------------");
            System.out.print("Enter command: ");
            ch = sc.nextInt();
            
            
            
            switch(ch){
                case 1:
                System.out.println("-------------------------------------------------------");
                System.out.print("Enter name and price of item to include: ");
                s.add(sc.next(),sc.nextInt());
                break;
                case 2:
                System.out.println("-------------------------------------------------------");
                System.out.print("Enter name and price of item to remove: ");
                s.remove(sc.next(),sc.nextInt());
                break;
                case 3:
                System.out.println("-------------------------------------------------------");
                s.DisplayCart();
                break;
                case 4:
                System.out.println("-------------------------------------------------------");
                System.out.println("Enter name,card number, cvv and date of expiry in order: ");
                s.pay(new CreditCard(sc.next(),sc.next(),sc.next(),sc.next()),s.getPrice());
                break;
                case 5:
                System.out.println("-------------------------------------------------------");
                System.out.println("Enter transaction address: ");
                s.pay(new Bitcoin(sc.next()),s.getPrice());
                break;
                case 6:
                System.out.println("Enter email and password in order: ");
                s.pay(new Paypal(sc.next(),sc.next()),s.getPrice());
                case 7:
                System.out.println("Exited Successfully");
                System.exit(0);

            }
        }
    }
}

/*

-------------------------------------------------------
1. Add item
2. Remove item
3. Display Cart
4. Pay using Credit Card
5. Pay using Bitcoin
6. Pay using Paypal
7. Exit
-------------------------------------------------------
Enter command: 1
-------------------------------------------------------
Enter name and price of item to include: Milk 60
-------------------------------------------------------
1. Add item
2. Remove item
3. Display Cart
4. Pay using Credit Card
5. Pay using Bitcoin
6. Pay using Paypal
7. Exit
-------------------------------------------------------
Enter command: 1
-------------------------------------------------------
Enter name and price of item to include: Apples 200
-------------------------------------------------------
1. Add item
2. Remove item
3. Display Cart
4. Pay using Credit Card
5. Pay using Bitcoin
6. Pay using Paypal
7. Exit
------------------------------------------------------- 
Enter command: 1
-------------------------------------------------------
Enter name and price of item to include: Perfume 1000
-------------------------------------------------------
1. Add item
2. Remove item
3. Display Cart
4. Pay using Credit Card
5. Pay using Bitcoin
6. Pay using Paypal
7. Exit
------------------------------------------------------- 
Enter command: 3
-------------------------------------------------------
Items included in the cart are:
Milk
Apples
Perfume
------------------------------------------------------- 
1. Add item
2. Remove item
3. Display Cart
4. Pay using Credit Card
5. Pay using Bitcoin
6. Pay using Paypal
7. Exit
------------------------------------------------------- 
Enter command: 4
-------------------------------------------------------
Enter name,card number, cvv and date of expiry in order:
parth 12345678 999 20/10/30
1260 paid using Credit Card.
------------------------------------------------------- 
1. Add item
2. Remove item
3. Display Cart
4. Pay using Credit Card
5. Pay using Bitcoin
6. Pay using Paypal
7. Exit
------------------------------------------------------- 
Enter command: 5
-------------------------------------------------------
Enter transaction address:
1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa
1260 paid using Bitcoin.
------------------------------------------------------- 
1. Add item
2. Remove item
3. Display Cart
4. Pay using Credit Card
5. Pay using Bitcoin
6. Pay using Paypal
7. Exit
------------------------------------------------------- 
Enter command: 6
Enter email and password in order: 
abc@gmail.com
12345
1260 Rupees paid using Paypal.
------------------------------------------------------- 
1. Add item
2. Remove item
3. Display Cart
4. Pay using Credit Card
5. Pay using Bitcoin
6. Pay using Paypal
7. Exit
------------------------------------------------------- 
Enter command: 7
Exited Successfully

*/
