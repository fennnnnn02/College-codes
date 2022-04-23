import java.util.Scanner;


class Publication {

    private String title;

    private double price;

    private int copies;

    Scanner sc = new Scanner(System.in);

    public int getcopies() {
        return this.copies;
    }

    public void setcopies(int copies) {
        this.copies = copies;
    }

    public String gettitle(){
        return this.title;
    }

    public double getprice(){
        return this.price;
    }

    public void salecopies(int n) {

        if(copies<n) System.out.println("Insufficiency");

        else {
            copies -= n;
            System.out.println("You have to Pay: "+(n*price));
        }

    }

    public void readpub(){
        System.out.print("Enter title, price, copies of the publication: ");
        title = sc.next();
        price = sc.nextDouble();
        copies = sc.nextInt();
    }

    public void display(){
        System.out.println(title+"\t"+copies+"\t"+price);
    }

}

class Book extends Publication {
    private String author;
    public void readbook(){
        readpub();
        System.out.print("Enter author: ");
        author = sc.next();
    }
    public void ordercopies(int copies){
        setcopies(getcopies() + copies);
        System.out.println("Copies available now are: "+(getcopies()));
    }
    public void salecopies(int qty) {
        System.out.println("Total Book sell: " + (qty* getprice()));
    }
    public void display(){
        super.display();
        System.out.println("Author: "+author);
    }
}

class Magazine extends Publication{
    private int orderqty;
    private String issue;
    public void recieveissue(){
        System.out.print("Enter order quantity: ");
        orderqty = sc.nextInt();
        System.out.print("Enter current issue: ");
        issue = sc.next();
        setcopies(orderqty);
    }
    public void salecopies() {
        System.out.println("Total Payment is: " + (orderqty * getprice()));
    }

    public void display(){
        super.display();
        System.out.println("Issue: "+issue);
    }
}


public class Polymorphism {
    public static void main(String[] args) {
        
        Publication p = new Publication();

        Book b = new Book();

        Magazine m = new Magazine();

        Scanner sc = new Scanner(System.in);

        while(true){
            System.out.println("");
            System.out.println("Enter one of the following details......");
            System.out.println("1.Publication 2.Book 3. Magazine");
            System.out.print("Enter command: ");

            int ch = sc.nextInt();

            switch(ch){

                case 1:
                p.readpub();
                break;

                case 2:
                b.readbook();
                break;

                case 3:
                m.recieveissue();
                break;

            }
            System.out.println("");
            System.out.println("Do you want to order copies or sell books? ");
            System.out.println("Order/Sell/None");
            String a = sc.next();

            switch(a){

                case "Order":
                System.out.println("Enter quantity: ");
                int qty = sc.nextInt();
                b.ordercopies(qty);
                break;

                case "Sell":
                System.out.print("Enter no. of books to sell: ");
                b.salecopies(sc.nextInt());
                System.out.println("Thank you!");
                System.out.println("");
                break;
                default:
                break;

            }
            System.out.println("Display one of the following 1.Pub 2.Book 3.Magazine");

            int c = sc.nextInt();

            switch(ch){

                case 1:
                p.display();
                System.out.println("");
                break;

                case 2:
                b.display();
                System.out.println("");
                break;

                case 3:
                m.display();
                System.out.println("");
                break;

            }
        }
    }
}
