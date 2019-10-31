import java.net.*;
import java.util.*;

public class Dns{

   public static void main(String []args){
      Scanner sc = new Scanner(System.in);
      Dns d = new Dns();
      while(true){
         System.out.println("1 : ip \n 2 : host \n 0 : exit");
         int choice = sc.nextInt();
         switch(choice){
            case 1 :
               d.getIP();
               break;
               
            case 2 :
               d.getHost();
               break;
               
            case 0 :
               System.exit(0);
         }
      } 
   }
   
   public void getIP(){
      Scanner sc = new Scanner(System.in);
      String url = sc.nextLine();
      
      try{
         InetAddress inet = InetAddress.getByName(url);
         System.out.println(inet.getHostAddress());        
      }
      catch(Exception e){
         System.out.println("error in url");        
      }     
   }
   
   public void getHost(){
      Scanner sc = new Scanner(System.in);
      String ip = sc.nextLine();
      
      try{
         InetAddress inet = InetAddress.getByName(ip);
         System.out.println(inet.getHostName());        
      }
      catch(Exception e){
         System.out.println("error in ip");        
      }     
   }
   
}
