
import java.util.*;

enum CarType{
    Sedan,Luxury,SUV;
}

class Car{
    private CarType model;
    private String color;private int year;

    Scanner sc = new Scanner(System.in);

    Car(CarType model){
        this.model= model;
    }

    public void construct(){
        System.out.print("Choose the color of your car(red/white/blue): ");
        color = sc.next();
        System.out.print("Set Car Year: ");
        year = sc.nextInt();
    }

    public void display(){
        System.out.println("The color of your car is: "+color);
        System.out.println("The manufacturing year of your car is: "+year);
        System.out.println("The model of your car is: "+model);
    }
}

class Sedan extends Car{
    Sedan(){
        super(CarType.Sedan);
        super.construct();
    }
    public static void details(String company,String carname){
        System.out.println("Company- "+company);
		System.out.println("Name of Car- "+carname);
        System.out.println("Fuel- Diesel");
		System.out.println("Gears- Manual/Automatic");
    }
}

class SUV extends Car{
    SUV(){
        super(CarType.SUV);
        super.construct();
    }
    public static void details(String company,String carname){
        System.out.println("Company- "+company);
		System.out.println("Name of Car- "+carname);
        System.out.println("Fuel- Petrol");
		System.out.println("Gears- Manual");
    }
}

class Luxury extends Car{
    Luxury(){
        super(CarType.Sedan);
        super.construct();
    }
    public static void details(String company,String carname){
        System.out.println("Company- "+company);
		System.out.println("Name of Car- "+carname);
        System.out.println("Fuel- Diesel");
		System.out.println("Gears- Manual/Automatic");
    }
}

class CarFactory {
    public static Car buildCar(CarType model) {
        Car car = null;
        switch (model) {
        case SUV:
            car = new SUV();
            SUV.details("Toyota","Fortuner");
            car.display();
            break;
 
        case Sedan:
            car = new Sedan();
            Sedan.details("Hyundai","Verna");
            car.display();
            break;
 
        case Luxury:
            car = new Luxury();
            Luxury.details("Mercedes","Benz");
            car.display();
            break;
        }
        return car;
    }
}


public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int ch;

        while(true){
            
            System.out.println("-------------------------------------------------------");
            System.out.println("Select car type");
            System.out.println("1. Sedan");
            System.out.println("2. SUV");
            System.out.println("3. Luxury");
            System.out.println("-------------------------------------------------------");
            ch = sc.nextInt();
            switch(ch){
                case 1:
                System.out.println(CarFactory.buildCar(CarType.Sedan));
                break;
                case 2:
                System.out.println(CarFactory.buildCar(CarType.SUV));
                break;
                case 3:
                System.out.println(CarFactory.buildCar(CarType.Luxury));
                break;
                case 4:
                System.out.println("Exited Successfully");
                System.exit(0);
            }
        }
    }
}

/*

Output

-------------------------------------------------------
Select car type
1. Sedan
2. SUV
3. Luxury
-------------------------------------------------------
1

Choose the color of your car(red/white/blue): Red
Set Car Year: 2018
Company- Hyundai
Name of Car- Verna
Fuel- Diesel
Gears- Manual/Automatic
The color of your car is: Red
The manufacturing year of your car is: 2018
The model of your car is: Sedan
Sedan@3feba861
-------------------------------------------------------
Select car type
1. Sedan
2. SUV
3. Luxury
-------------------------------------------------------
2

Choose the color of your car(red/white/blue): White
Set Car Year: 2010
Company- Toyota
Name of Car- Fortuner
Fuel- Petrol
Gears- Manual
The color of your car is: White
The manufacturing year of your car is: 2010
The model of your car is: SUV
SUV@6f496d9f
-------------------------------------------------------
Select car type
1. Sedan
2. SUV
3. Luxury
-------------------------------------------------------
3

Choose the color of your car(red/white/blue): Blue
Set Car Year: 2020
Company- Mercedes
Name of Car- Benz
Fuel- Diesel
Gears- Manual/Automatic
The color of your car is: Blue
The manufacturing year of your car is: 2020
The model of your car is: Sedan
Luxury@10f87f48
-------------------------------------------------------
Select car type
1. Sedan
2. SUV
3. Luxury
-------------------------------------------------------
4
Exited Successfully

*/