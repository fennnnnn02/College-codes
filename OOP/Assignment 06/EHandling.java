
import java.util.Scanner;

class Exception1{

    public void Arithmetic(String num1,String num2){
        double ans;
        
        try{
            int a = Integer.parseInt(num1);
            int b = Integer.parseInt(num2);
            ans = a/b;
            System.out.println("Division of two numbers is "+ans);
        }
        catch(ArithmeticException e){
            System.out.println("Cannot divide the number by zero ");
            System.out.println(e);
        }
        catch(Exception e){
            System.out.println("Invalid Input. Only Integers allowed");
            System.out.println(e);
        }
        finally{
            System.out.println("Arithmetic and Number Format Exception checked successfully.");
        }
        
    }

    public void OutofBound(int []a,int i){
        try{
            System.out.println(a[i]);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Index out of bound "+e);
        }
        finally{
            System.out.println("Index out of Bound Handled.");
        }
    }

    public void NumberFormat(String num1){
        try{
            int a=Integer.parseInt(num1);
            System.out.println("The number is an integer.");
        }
        catch(Exception e){
            System.out.println("The number entered is not an integer");
            System.out.println(e);
        }
        finally{
            System.out.println("Integer format checked successfully");
        }
    }
}

public class EHandling{
    public static void main(String[] args) {
        
        int ch;
        int a[] = new int[5];
        Exception1 e = new Exception1();
        Scanner sc = new Scanner(System.in);

        while(true){
            System.out.println("-------------------------------------------------------");
            System.out.println("1. Check Arithmetic and Number Format Exception");
            System.out.println("2. Array out of Bound Exception");
            System.out.println("3. Number Format Exception only");
            System.out.println("4. Exit");
            System.out.println("-------------------------------------------------------");
            System.out.print("Enter command: ");
            ch = sc.nextInt();

            switch(ch){
                case 1:
                System.out.println("-------------------------------------------------------");
                System.out.print("Enter two numbers: ");
                e.Arithmetic(sc.next(),sc.next());
                break;
                case 2:
                System.out.println("-------------------------------------------------------");
                System.out.print("Enter 5 elements of array: ");
                a[0] = sc.nextInt();
                a[1] = sc.nextInt();
                a[2] = sc.nextInt();
                a[3] = sc.nextInt();
                a[4] = sc.nextInt();
                System.out.println("-------------------------------------------------------");
                System.out.print("Enter index of element to display: ");
                int i = sc.nextInt();
                e.OutofBound(a,i);
                break;
                case 3:
                System.out.println("-------------------------------------------------------");
                System.out.print("Enter a number: ");
                e.NumberFormat(sc.next());
                break;
                case 4:
                System.out.println("Exited Successfully.");
                System.exit(0);
            }
        }

    }
}

/*

Output

-------------------------------------------------------
1. Check Arithmetic and Number Format Exception
2. Array out of Bound Exception
3. Number Format Exception only
4. Exit
-------------------------------------------------------
Enter command: 1
-------------------------------------------------------
Enter two numbers: 120 10
Division of two numbers is 12.0
Arithmetic and Number Format Exception checked successfully.
-------------------------------------------------------
1. Check Arithmetic and Number Format Exception
2. Array out of Bound Exception
3. Number Format Exception only
4. Exit
-------------------------------------------------------
Enter command: 1
-------------------------------------------------------
Enter two numbers: 10 0
Cannot divide the number by zero 
java.lang.ArithmeticException: / by zero
Arithmetic and Number Format Exception checked successfully.
-------------------------------------------------------
1. Check Arithmetic and Number Format Exception
2. Array out of Bound Exception
3. Number Format Exception only
4. Exit
-------------------------------------------------------
Enter command: 1
-------------------------------------------------------
Enter two numbers: ab ab
Invalid Input. Only Integers allowed
java.lang.NumberFormatException: For input string: "ab"
Arithmetic and Number Format Exception checked successfully.
-------------------------------------------------------
1. Check Arithmetic and Number Format Exception
2. Array out of Bound Exception
3. Number Format Exception only
4. Exit
-------------------------------------------------------
Enter command: 2
-------------------------------------------------------
Enter 5 elements of array: 1 2 3 4 5
-------------------------------------------------------
Enter index of element to display: 10
Index out of bound java.lang.ArrayIndexOutOfBoundsException: Index 10 out of bounds for length 5
Index out of Bound Handled.
-------------------------------------------------------
1. Check Arithmetic and Number Format Exception
2. Array out of Bound Exception
3. Number Format Exception only
4. Exit
-------------------------------------------------------
Enter command: 3
-------------------------------------------------------
Enter a number: 10
The number is an integer.
Integer format checked successfully
-------------------------------------------------------
1. Check Arithmetic and Number Format Exception
2. Array out of Bound Exception
3. Number Format Exception only
4. Exit
-------------------------------------------------------
Enter command: 3
-------------------------------------------------------
Enter a number: ab 
The number entered is not an integer
java.lang.NumberFormatException: For input string: "ab"
Integer format checked successfully
-------------------------------------------------------
1. Check Arithmetic and Number Format Exception
2. Array out of Bound Exception
3. Number Format Exception only
4. Exit
-------------------------------------------------------
Enter command: 4
Exited Successfully.

*/