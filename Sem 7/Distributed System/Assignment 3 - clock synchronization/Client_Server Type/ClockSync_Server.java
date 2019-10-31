import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.List;

public class ClockSync_Server {

	static int sequenceNumber = 0 ;
	static List<Integer>list = new ArrayList<Integer>();

	public static void main(String[] args) throws UnknownHostException {
		String bindAddr = InetAddress.getLocalHost().getHostAddress();
		int Serverport = 1200;
		//ServerSocket serverSocket = new ServerSocket(port);
		System.out.println("Server Started at IP: " + bindAddr+
				" Listening to port: "+Serverport);
		try {
			DatagramSocket serverSocket = new DatagramSocket(Serverport);
			byte[] receiveData = new byte[64];
	        byte[] sendData = new byte[64];
	        while(true)
            {
	        	System.out.println("-----------------------------------");
               DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
               serverSocket.receive(receivePacket);
               System.out.println("Size of received datagram is "+receiveData.length);
               Instant instant = Instant.now();
       		//long millsecs = System.currentTimeMillis();
       		String serverReceivedTime = instant.getEpochSecond()+"."+(instant.getNano()/1000);
               //String serverReceivedTime = 
            		   
            		   //Instant.now().getEpochSecond() +
   					//"."+(Instant.now().truncatedTo( ChronoUnit.MICROS ).getNano()/1000);
               System.out.println("instant time is "+serverReceivedTime);
   			   System.out.println("System.currentTimeMillis() is :"+System.currentTimeMillis());
               String sentence = new String( receivePacket.getData());
               System.out.println("RECEIVED: " + sentence);
               System.out.println("Size is "+sentence.length());
               String [] stringArr = sentence.split(" ");
               sentence = sentence.trim();
               System.out.println("After trin Size is "+sentence.length());
               InetAddress IPAddress = receivePacket.getAddress();
               int port = receivePacket.getPort();
               System.out.println("Client port id : "+port);
               String response = sentence+" "+serverReceivedTime +" "+(Instant.now().getEpochSecond() +
   					"."+(Instant.now().getNano()/1000));
               System.out.println("Sending :"+response);
               sendData = response.getBytes();
               DatagramPacket sendPacket =
               new DatagramPacket(sendData, sendData.length, IPAddress, port);
               serverSocket.send(sendPacket);
            }
		} catch (SocketException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        
	}
}
