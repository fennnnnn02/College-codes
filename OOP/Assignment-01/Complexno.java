
import java.util.*;


class complex{
     float real;
     float imaginary;
    complex(){
        real = 0;
        imaginary = 0;
    }
    complex (float r,float i){
        this.real = r;
        this.imaginary = i;
    }
   
     complex add(complex c){
        complex temp = new complex();
        temp.real = this.real + c.real;
        temp.imaginary = this.imaginary + c.imaginary;
        return temp;
     }

     complex sub(complex c){
        complex temp = new complex();
        temp.real = this.real - c.real;
        temp.imaginary = this.imaginary - c.imaginary;
        return temp;
     }
     complex mul(complex c){
         complex temp = new complex();
         temp.real = this.real*c.real - this.imaginary*c.imaginary;
         temp.imaginary =  this.imaginary*c.real+c.imaginary*this.real;
         return temp;
     }
     complex div(complex c){
         complex temp = new complex();
         temp.real = (this.real*c.real+this.imaginary*c.imaginary)/(c.real*c.real+c.imaginary*c.imaginary);
         temp.imaginary = (this.imaginary*c.real-c.imaginary*this.real)/(c.real*c.real+c.imaginary*c.imaginary);
         return temp;
     }
    
}

public class Complexno {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int ch;
        while(true){
           
            System.out.println("Enter two complex no.s");
            complex c1 = new complex(s.nextFloat(),s.nextFloat());
            complex c2 = new complex(s.nextFloat(),s.nextFloat());
            
            System.out.println("1.ADD 2.SUB 3.MUL 4.DIV 5.EXIT");
            System.out.println("Enter command");
             ch = s.nextInt();
            
            switch(ch){
                case 1:
                complex c3 = c1.add(c2);
                System.out.println(c3.real+" "+c3.imaginary+"i");
                break;
                case 2:
                complex c4 = c1.sub(c2);
                System.out.println(c4.real+" "+c4.imaginary+"i");
                break;
                case 3:
                complex c5 = c1.mul(c2);
                System.out.println(c5.real+" "+c5.imaginary+"i");
                break;
                case 4:
                complex c6 = c1.div(c2);
                System.out.println(c6.real+" "+c6.imaginary+"i");
                break;
                case 5:
                System.exit(0);
            }
        }
    }
}

