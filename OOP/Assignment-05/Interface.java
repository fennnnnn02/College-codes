interface Vehicle{
    void change_gear(int a);
    void change_speed();
    void apply_brakes();
    void disp();
}

class Bicycle implements Vehicle{
    private int gear,speed;
    Bicycle(){
        gear = 0 ;
        this.speed = 0 ;
    }
    public void change_gear(int a){
        if(gear<=6 && gear>=0){
            gear = a;
            System.out.println("Gear changed to: "+gear);
        }
        else{
            System.out.println("Cannot change to the specified gear.");
        }
    }

    public void change_speed(){
        speed = speed +5;
        if(speed>60){
            System.out.println("Cannot be beyond that speed.");
            speed -=5;
        }
        else{
            System.out.println("Speed increased to: "+speed);
        }
    }

    public void apply_brakes(){
        if(speed>5){
            speed = speed - 5;
            System.out.println("Speed decreased to: "+speed);
        }
        else {
            speed = 0;
            gear = 0;
            System.out.println("Bicycle Stopped.");
        }
    }

    public void disp(){
        System.out.println("Speed = "+speed+"  "+"Gear = "+gear);
    }

}

class Bike implements Vehicle{
    private int gear,speed;
    Bike(){
        gear = 0 ;
        speed = 0 ;
    }
    public void change_gear(int a){
        if(gear<=6 && gear>=0){
            gear = a;
            System.out.println("Gear changed to: "+gear);
        }
        else{
            System.out.println("Cannot change to the specified gear.");
        }
    }

    public void change_speed(){
        
        if(speed>160){
            System.out.println("Cannot be beyond that speed.");
        }
        else{
            speed = speed +10;
            System.out.println("Speed increased to: "+speed);
        }
    }

    public void apply_brakes(){
        if(speed>10){
            speed = speed - 10;
            System.out.println("Speed decreased to: "+speed);
        }
        else {
            speed = 0;
            gear = 0;
            System.out.println("Bike Stopped.");
        }
    }
    public void disp(){
        System.out.println("Speed = "+speed+"  "+"Gear = "+gear);
    }
}

class Car implements Vehicle{
    private int gear,speed;
    Car(){
        gear = 0 ;
        speed = 0 ;
    }
    public void change_gear(int a){
        if(gear<=6 && gear>=0){
            gear = a;
            System.out.println("Gear changed to: "+gear);
        }
        else{
            System.out.println("Cannot change to the specified gear.");
        }
    }

    public void change_speed(){
        
        if(speed>200){
            System.out.println("Cannot be beyond that speed.");
        }
        else{
            speed = speed +15;
            System.out.println("Speed increased to: "+speed);
        }
    }

    public void apply_brakes(){
        if(speed>15){
            speed = speed - 15;
            System.out.println("Speed decreased to: "+speed);
        }
        else {
            speed = 0;
            gear = 0;
            System.out.println("Bike Stopped.");
        }
    }
    public void disp(){
        System.out.println("Speed = "+speed+"  "+"Gear = "+gear);
    }
}

public class Interface {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        Vehicle v=null;
        while(true){
            System.out.println();
            System.out.print("Select 1.Bicycle 2.Bike 3.Car: ");
            int ch = sc.nextInt();
            switch(ch){
                case 1:
                v = new Bicycle();
                break;
                case 2:
                v = new Bike();
                break;
                case 3:
                v = new Car();
                break;
                case 4:
                System.exit(0);
            }
            int c =1;
            while(c>0){
                System.out.println();
                System.out.print("Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: ");
                c = sc.nextInt();
                switch(c){
                    case 1:
                    v.change_speed();
                    break;
                    case 2:
                    System.out.print("Change gear to? ");
                    v.change_gear(sc.nextInt());
                    break;
                    case 3:
                    v.apply_brakes();
                    break;
                    case 4:
                    v.disp();
                    break;
                }
            }
        }
    }
}

//Output

// Select 1.Bicycle 2.Bike 3.Car: 1

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 1
// Speed increased to: 5

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 2
// Change gear to? 1
// Gear changed to: 1

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 1
// Speed increased to: 10

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 2
// Change gear to? 2
// Gear changed to: 2

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 1
// Speed increased to: 15

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 3
// Speed decreased to: 10

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 3
// Speed decreased to: 5

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 3
// Bicycle Stopped.

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 4
// Speed = 0  Gear = 0

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 0

// Select 1.Bicycle 2.Bike 3.Car: 2

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 1
// Speed increased to: 10

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 1
// Speed increased to: 20

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 2
// Change gear to? 2
// Gear changed to: 2

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 1
// Speed increased to: 30

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 4
// Speed = 30  Gear = 2

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 0

// Select 1.Bicycle 2.Bike 3.Car: 3

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 1
// Speed increased to: 15

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 1
// Speed increased to: 30

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 2
// Change gear to? 1
// Gear changed to: 1

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 4
// Speed = 30  Gear = 1

// Select [0.Stop] [1.Change speed] [2.Change gear] [3.Apply Brake] [4.Display]: 3
// Speed decreased to: 15
