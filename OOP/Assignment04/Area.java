package Assignment04;
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