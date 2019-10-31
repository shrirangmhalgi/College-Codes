package assignment12;

//Java Program for udp client-server chat
import java.net.*;
import java.util.Scanner;

public class Server {
	public static void main(String[] args) {
		Server server = new Server();
		server.connectToClient();
	}
	public void connectToClient() {
		int port;
		String message="";
		String recievedMessage="";
		try {
			DatagramSocket serverSocket = new DatagramSocket(9876);
			
			
			InetAddress ipAddress = InetAddress.getByName("localhost");
			
			while(true) {
				byte []recieveData = new byte[1024];
				byte []sendData = new byte[1024];
				DatagramPacket recievePacket = new DatagramPacket(recieveData,recieveData.length);
				serverSocket.receive(recievePacket);
				recievedMessage = new String(recievePacket.getData());
				if(recievedMessage.equalsIgnoreCase("stop"))
					break;
				System.out.println("Client : "+recievedMessage);
				Scanner sc = new Scanner(System.in);
				System.out.println("Enter message to send to client");
				message = sc.nextLine();
				sendData = message.getBytes();
				System.out.println("Server : "+message);
				port = recievePacket.getPort(); // get port no. of client
				DatagramPacket sendPacket = new DatagramPacket(sendData,sendData.length,ipAddress,port);
				serverSocket.send(sendPacket);
				if(message.equalsIgnoreCase("stop"))
					break;
				recievedMessage="";
			}
			serverSocket.close();
			System.out.println("Server Stopped");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
