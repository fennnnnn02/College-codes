import java.util.Scanner;

import java.util.Objects;

class Collection<T>{

    private final Object[] arr;

    public final int length;

    Collection(int length){
        arr = new Object[length];
        this.length = length;
    }

    Scanner sc = new Scanner(System.in);

    public void input(){
        for(int i=0;i<length;i++){
            System.out.print("Enter element: ");
            arr[i] = sc.next();
        }
    }

    public Object[] getarray(){
        return arr;
    }

    String getindex(int i){
        return arr[i].toString();
    }

    public static <T> void Palindrome(T s){
		String a=(String)s; 
		
		a=a.toLowerCase();
		
		StringBuilder sb = new StringBuilder(a); 

		String b= new String(sb.reverse());
		

		if(Objects.equals(a, b))	
			System.out.println(s+" is Palindrome");
		else
			System.out.println(s+" is not Palindrome");
	}

    public <T>void evenodd(T a){
        int b = (Integer.parseInt(getindex((int)a)));
		if(b%2==0)	
			System.out.println(b+" is Even Number."); 

		else
			System.out.println(b+" is Odd Number."); 
	}

    public  <T>void prime(T a) {
        int c = (Integer.parseInt(getindex((int)a)));
		if(c==1)	
			System.out.println("1 is Not Prime NNumber");

		else if ((c==2) )
			System.out.println("2 is a Prime Number");

		else {
			double b=Math.sqrt((int)c)+1; 
			Boolean temp=false; 
			for(int i=3;i<b;i=i++) {
				if((int)a%i==0) 
					temp=true; 
			}
			if(temp) 
				System.out.println(c+" is Not Prime Number");
			else
				System.out.println(c+" is Prime NNumber");
		}
			
	}
}

class Main{
    public static void main(String[] args) {
        
        
        Scanner sc = new Scanner(System.in);
        int ch;
        System.out.print("Enter length of array: ");
        int length = sc.nextInt();
        Collection<Integer> a;
        a = new Collection(length);

        while(true){
            System.out.println("-------------------------------------------------------");
            System.out.println("1. Input Array");
            System.out.println("2. Check Palindrome");
            System.out.println("3. Check even odd");
            System.out.println("4. Prime");
            System.out.println("-------------------------------------------------------");
            System.out.print("Enter command: ");
            ch = sc.nextInt();
            
            
            
            switch(ch){
                case 1:
                System.out.println("-------------------------------------------------------");
                a.input();
                break;
                case 2:
                System.out.println("-------------------------------------------------------");
                System.out.print("Enter String to check: ");
                Collection.Palindrome(sc.next());
                break;
                case 3:
                System.out.println("-------------------------------------------------------");
                System.out.print("Enter index to check: ");
                a.evenodd(sc.nextInt());
                break;
                case 4:
                System.out.println("-------------------------------------------------------");
                System.out.print("Enter index to check: ");
                a.prime(sc.nextInt());
                break;
                case 5:
                System.out.println("Exited Successfully");
                System.exit(0);

            }
        }
    }
}

/*

Output

Enter length of array: 5
-------------------------------------------------------
1. Input Array
2. Check Palindrome
3. Check even odd
4. Prime
-------------------------------------------------------
Enter command: 1
-------------------------------------------------------
Enter element: 1
Enter element: 2
Enter element: 3
Enter element: 4
Enter element: 5
-------------------------------------------------------
1. Input Array
2. Check Palindrome
3. Check even odd
4. Prime
-------------------------------------------------------
Enter command: 2
-------------------------------------------------------
Enter String to check: ABABA
ABABA is Palindrome
-------------------------------------------------------
1. Input Array
2. Check Palindrome
3. Check even odd
4. Prime
-------------------------------------------------------
Enter command: 3
-------------------------------------------------------
Enter index to check: 0
1 is Odd Number.
-------------------------------------------------------
1. Input Array
2. Check Palindrome
3. Check even odd
4. Prime
-------------------------------------------------------
Enter command: 4
-------------------------------------------------------
Enter index to check: 4
5 is Prime NNumber
-------------------------------------------------------
1. Input Array
2. Check Palindrome
3. Check even odd
4. Prime
-------------------------------------------------------
Enter command: 5
Exited Successfully
-------------------------------------------------------

*/