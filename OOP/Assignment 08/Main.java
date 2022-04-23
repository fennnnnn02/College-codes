import java.util.* ;
import java.io.*;

class StudentData{
    
    static int total=0;

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public void ReadFile(){
        try{
            File f = new File("sample.txt");
            Scanner Read = new Scanner(f);
            while (Read.hasNextLine()) {
              String data = Read.nextLine();
              System.out.println(data);
            }
            Read.close();
        } 

        catch (FileNotFoundException e){
            System.out.println("File not found.");
            e.printStackTrace();
          }
        
    }
	
	public void searchRecords() throws IOException{
		Scanner sc = new Scanner(System.in);
		try  {   
			File f1=new File("sample.txt"); 
            String[] words=null;  
            FileReader fr = new FileReader(f1);  
            BufferedReader br = new BufferedReader(fr); 
            String s; 
            System.out.print("Enter name or id of student to search: ");    
            String input=sc.next();   
            int count=0;   
            while((s=br.readLine())!=null)   
            {
                words=s.split(" ");  
                for (String word : words){
                    if (word.equals(input)) {
                        count++;   
                    }
                }
            }
            if(count!=0){
                System.out.println("Record Found");
            }
            else{
                System.out.println("Record not found");
            }
                fr.close();
		} 
		catch(FileNotFoundException e) {
			System.out.println("File not Found");
		}
	}
	
	public void addStudent() throws IOException  {
		
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("sample.txt",true)));
		
		String name;
		String address;
		String s;
		int id, rollno, Class;
		float marks;
		
		
		System.out.print("Name of the Student: "); 
		name = br.readLine();

		System.out.print("Student Id: "); 
		id = Integer.parseInt(br.readLine()); 

		System.out.print("Roll no: ");
		rollno = Integer.parseInt(br.readLine()); 
		System.out.print("Address: ");  
		address = br.readLine();  
		System.out.print("Class: ");
		Class = Integer.parseInt(br.readLine());  
		System.out.print("Marks : ");  
		marks = Float.parseFloat(br.readLine()); 
		total++;
		pw.println(name+" "+id+" "+rollno+" "+address+" "+Class+" "+marks+ " "+total);
			  
		System.out.print("Record added "); 
			  
		pw.close(); 
		}

   

    
    
    public void DeleteRecord() throws IOException{
        try  {   
			BufferedReader file1 = new BufferedReader(new FileReader("sample.txt")); 
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("new.txt",true)));
			String name;  
			int flag=0; 
			Scanner sc=new Scanner(System.in); 
			System.out.print("Enter the name of the student you want to delete: ");  
			String searchname=sc.next();  
			while((name = file1.readLine()) != null)   {     
				String[] line = name.split(" ");     
				if(!searchname.equalsIgnoreCase(line[0])){
					pw.println(name);  
					flag=0;  
				}  
				else{  
					System.out.println("Record found");  
					flag=1;
				}  
				}   file1.close();
				pw.close(); 
				
				File delName =  new File("sample.txt");
				File oldName =  new File("new.txt");   
				File newName =   new File("sample.txt");    
				
				if(delName.delete())        
					System.out.println("Deleted successfully");       
				else         
					System.out.println("Error");
				
				if (oldName.renameTo(newName))           
					System.out.println("Renamed successfully");  
				else         
					System.out.println("Error");
		
		} 
		catch(FileNotFoundException e)  {
			System.out.println("ERROR : File not Found !!!");  
		} 
	
    }
    public void updateRecords() throws IOException  {
		try  {  
			// Open the file
			BufferedReader file1 = new BufferedReader(new FileReader("sample.txt"));  
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("new.txt",true))); 
			String name;
			int flag=0;  
			Scanner sc=new Scanner(System.in); 
			System.out.print("Enter the name of the student you want to update: ");  
			String searchname=sc.next();   
			
			while((name = file1.readLine()) != null)   {  
				String[] line = name.split(" "); 
    
				if(!searchname.equalsIgnoreCase(line[0])){  
					pw.println(name);       
					flag=0;  
					} 
				else   
					{    
					System.out.println("Record found");  
					System.out.print("Enter updated marks: ");  
					String up_mark=sc.next();    
					System.out.println(line[0]+" "+line[1]+" "+line[2]+" "+line[3]+" "+line[4]+" ");
					pw.println(line[0]+" "+line[1]+" "+line[2]+" "+line[3]+" "+line[4]+" "+up_mark);   
					flag=1;    
					}     
				} 
			    file1.close(); 
				pw.close();   
				File delName =  new File("sample.txt");
				File oldName =  new File("new.txt");   
				File newName =   new File("sample.txt");  
				
				if(delName.delete())           
					System.out.println("Record updated successfully");  
				else     
					System.out.println("Error"); 
				
				if (oldName.renameTo(newName))       
					System.out.println("Renamed successfully");    
				else             
					System.out.println("Error");    
				
				}  
		catch(FileNotFoundException e)  {  
			System.out.println("\nERROR : File not Found !!!"); 
			} 
		} 
}

public class Main {
    public static void main(String[] args) throws IOException{
        StudentData f = new StudentData();
        
        int c;
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.println("-------------------------------------------------------");
                System.out.println("1. Add Student in the file");
                System.out.println("2. Search Record");
                System.out.println("3. Delete Record");
                System.out.println("4. Display File");
                System.out.println("5. Update Record");
                System.out.println("6. Exit");
                System.out.println("-------------------------------------------------------");
                System.out.print("Enter command: ");
                c = sc.nextInt();
                
                
                
                switch(c){
                    case 1:
                    System.out.println("-------------------------------------------------------");
                    f.addStudent();
                    break;
                    case 2:
                    System.out.println("-------------------------------------------------------");
                    f.searchRecords();
                    break;
                    case 3:
                    System.out.println("-------------------------------------------------------");
                    f.DeleteRecord();
                    break;
                    case 4:
                    f.ReadFile();
                    break;
                    case 5:
                    f.updateRecords();
                    break;
                    case 6:
                    System.out.println("Exited Successfully");
                    System.exit(0);

            }
        }
    }
}

/*

Output

-------------------------------------------------------
1. Add Student in the file
2. Search Record
3. Delete Record
4. Display File
5. Update Record
6. Exit
-------------------------------------------------------
Enter command: 1
-------------------------------------------------------

Enter Student Name: Parth
Enter Student Id: 23338
Enter Roll no: 23338
Enter Address: Pune
Enter Class: 11
Enter Marks : 8

Records added successfully !

-------------------------------------------------------
1. Add Student in the file
2. Search Record
3. Delete Record
4. Display File
5. Update Record
6. Exit
-------------------------------------------------------
Enter command: 1
-------------------------------------------------------

Enter Student Name: Yash
Enter Student Id: 20
Enter Roll no: 20
Enter Address: Pune
Enter Class: 11
Enter Marks : 9

Records added successfully !

-------------------------------------------------------
1. Add Student in the file
2. Search Record
3. Delete Record
4. Display File
5. Update Record
6. Exit
-------------------------------------------------------
Enter command: 2
-------------------------------------------------------
Enter name or id of student to search: parth
Record not found
-------------------------------------------------------
1. Add Student in the file
2. Search Record
3. Delete Record
4. Display File
5. Update Record
6. Exit
-------------------------------------------------------
Enter command: 2
-------------------------------------------------------
Enter name or id of student to search: Parth
Record Found
-------------------------------------------------------
1. Add Student in the file
2. Search Record
3. Delete Record
4. Display File
5. Update Record
6. Exit
-------------------------------------------------------
Enter command: 3
-------------------------------------------------------
Enter the name of the student you want to delete: Yash  
Record found
Deleted successfully
Renamed successfully
-------------------------------------------------------
1. Add Student in the file
2. Search Record
3. Delete Record
4. Display File
5. Update Record
6. Exit
-------------------------------------------------------
Enter command: 4
Parth    23338    23338    Pune    11    8.0
-------------------------------------------------------
1. Add Student in the file
2. Search Record
3. Delete Record
4. Display File
5. Update Record
6. Exit
-------------------------------------------------------
Enter command: 5
Enter the name of the student you want to update: Parth
Record found
Enter updated marks: 25
Record updated successfully
Renamed successfully
-------------------------------------------------------
1. Add Student in the file
2. Search Record
3. Delete Record
4. Display File
5. Update Record
6. Exit
-------------------------------------------------------
Enter command: 6
Exited Successfully

*/