import java.util.Scanner;

public class Calc {
   static {
      System.loadLibrary("calculator"); // Load native library at runtime
                                   // hello.dll (Windows) or libhello.so (Unixes)
   }
 
   // Declare a native method sayHello() that receives nothing and returns void
   private native void calculate(int a,int b,char op);
 
   // Test Driver
   public static void main(String[] args) {
   	  char choice='Y';
   	  while (choice=='Y' || choice=='y')
   	  {
	   	  System.out.println("********MENU********");
	   	  System.out.println("1.Addition");
	   	  System.out.println("2.Substraction");
	   	  System.out.println("3.Multiplication");
	   	  System.out.println("4.Division");
	   	  System.out.println("\nEnter your choice : ");
	   	  Scanner scan= new Scanner(System.in);
	   	  int ch=scan.nextInt();
	   	  System.out.println("Enter Two Numbers : ");
	   	  int a=scan.nextInt();
	   	  int b=scan.nextInt();
	   	  
	   	  if(ch==1)
	   	  {
	   	  	new Calc().calculate(a,b,'+');
	   	  }
	   	  
	   	  if(ch==2)
	   	  {
	   	  	new Calc().calculate(a,b,'-');
	   	  }
	   	  
	   	  if(ch==3)
	   	  {
	   	  	new Calc().calculate(a,b,'*');
	   	  }
	   	  
	   	  if(ch==4)
	   	  {
	   	  	new Calc().calculate(a,b,'/');
	   	  }
	   	  	   	  
	   	  System.out.println("Execute Again (Yes=Y OR No=N): ");
	   	  choice=scan.next().charAt(0);
	  }
   }
}
