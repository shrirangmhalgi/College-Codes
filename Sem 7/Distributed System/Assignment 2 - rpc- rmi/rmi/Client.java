
/**
 *
 * @author Ria Mittal
 */
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws RemoteException{
        Client C = new Client();
        C.connectRemote();
    }
    private void connectRemote() throws RemoteException{
        try{
            Scanner sc = new Scanner(System.in);
            Registry reg = LocateRegistry.getRegistry("localhost", 9999);
            Adder ad = (Adder) reg.lookup("server");
            Subtractor sb = (Subtractor) reg.lookup("server");
            Multiplier m = (Multiplier) reg.lookup("server");
            Divider d = (Divider) reg.lookup("server");
            char ch = 'y';
         while(ch=='y' || ch=='Y'){
            System.out.println("1.Addition\n2.Subtraction\n3.Mutiplication\n4.Division\n");
            int input = sc.nextInt();
            switch(input){
            	case 1:{
            		System.out.println("Enter two numbers: ");
            		int a = sc.nextInt();
            		int b = sc.nextInt();
            		System.out.println("Addition is: "+ad.add(a, b)+"\n");
            		break;
            	}
            	case 2:{
            		System.out.println("Enter two numbers: ");
            		int a = sc.nextInt();
		          int b = sc.nextInt();
          		System.out.println("Subtraction is: "+sb.sub(a, b)+"\n");
          		break;
          	}
            	case 3:{
            		System.out.println("Enter two numbers: ");
            		int a = sc.nextInt();
		          int b = sc.nextInt();
          	  	System.out.println("Multiplication is: "+m.mul(a, b)+"\n");
          	  	break;
          	}
            	case 4:{
            		System.out.println("Enter two numbers: ");
            		int a = sc.nextInt();
            		int b = sc.nextInt();
            		System.out.println("Division is: "+d.div(a, b)+"\n");
            		break;
            	}
            	default:System.out.println("Invalid Input\n");
            }
          System.out.println("Do you want to continue?(y/n)\n");
          ch = sc.next().charAt(0);  
        }    
        } catch(NotBoundException|RemoteException e) {
            System.out.println(e);
        }
    }
}
