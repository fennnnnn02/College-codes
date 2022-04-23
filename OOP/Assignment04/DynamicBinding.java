
import java.util.Scanner;

abstract class Area{

    protected double length;
    protected double breadth;

    Scanner sc = new Scanner(System.in);

    Area(){
        System.out.print("Enter two sides: ");
        this.length = sc.nextDouble();
        this.breadth = sc.nextDouble();
    }

    public abstract double ComputeArea();

}

class Rectangle extends Area{

    public double ComputeArea(){
        return super.length*super.breadth;
    }

}

class Triangle extends Area{

    public double ComputeArea(){
        return super.length*super.breadth*0.5;
    }

}

public class DynamicBinding {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        while(true){

            System.out.println("1. Area of Triangle");
            System.out.println("2. Area of Rectangle");
            System.out.println("3. Exit");
            System.out.print("Enter command: ");
            int ch = sc.nextInt();
            
            switch(ch){

                case 1:
                Area t = new Triangle();
                System.out.println(t.ComputeArea());
                break;

                case 2:
                Area r = new Rectangle();
                System.out.println(r.ComputeArea());
                break;

                case 3:
                System.exit(0);

            }
            System.out.println();
        }
    }
}


// Output 

// 1. Area of Triangle
// 2. Area of Rectangle
// 3. Exit
// Enter command: 1
// Enter two sides: 10 6
// 30.0

// 1. Area of Triangle
// 2. Area of Rectangle
// 3. Exit
// Enter command: 2
// Enter two sides: 10 4
// 40.0

// 1. Area of Triangle
// 2. Area of Rectangle
// 3. Exit
// Enter command: 3
// Exited Successfully
