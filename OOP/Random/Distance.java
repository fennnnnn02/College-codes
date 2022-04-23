import java.util.*;
import java.lang.Math;

class points{
    private int x;
    private int y;
    public int getX(){
        return x;
    }
    public void setX(int x){
        this.x = x;
    }
    public int getY(){
        return y;
    }
    public void setY(int y){
        this.y = y;
    }
}

public class Distance{
    public static void main (String[] args){
        points point1 = new points();
        points point2 = new points();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter co-ordinates of first point");
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        System.out.println("Enter co-ordinates of second point");
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();
        sc.close();
        point1.setX(x1);
        point1.setY(y1);
        point2.setX(x2);
        point2.setY(y2);

        double dist =  Math.sqrt(Math.pow(point2.getX() - point1.getX(), 2) +Math.pow(point2.getY() - point1.getY(), 2));

        System.out.println("Distance between points= " + dist);
    }
}

// time difference