import java.util.Scanner;

class Book{
    private String name;
    int n;
    String[] author;
    private int cost;
    private String publication;
    public Book(String name, String publication, int cost,int n){
        this.name = name;
        this.cost = cost;
        this.publication = publication;
        this.n=n;
        author = new String[n];
    }
    public void display(){
        System.out.println("Name: "+name+", cost: "+cost+", publication: "+publication);
        for(int i=0;i<n;i++){
            System.out.println("Author name: "+ author[i]);
        }
    }
}

public class Books{
    public static void main(String[] args) {
        Book[] b = new Book[10];
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<10;i++){
            System.out.println("Enter name, publication, no. of authors and cost: ");
            b[i] = new Book(sc.next(),sc.next(),sc.nextInt(),sc.nextInt());
            for(int j=0;j<b[i].n;j++){
                System.out.println("Enter author names: ");
                b[i].author[j] = sc.next();
            }
            b[i].display();
        }
        sc.close();
    }
}



