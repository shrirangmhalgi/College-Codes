package assignment12;
import java.io.BufferedReader;
import java.io.InputStreamReader;
// Java Program for udp client-server chat
import java.net.*;
import java.util.Scanner;

public class Client {
	public static void main(String[] args) {
		Client client = new Client();
		client.connectToServer();
	}
	public void connectToServer() {
		String message="";
		String recievedMessage="";
		try {
			// Create Datagram Socket
			DatagramSocket clientSocket = new DatagramSocket();
			InetAddress ipAddress = InetAddress.getByName("localhost");
			
			while(true)
			{
				byte []sendData = new byte[1024];
				byte []recieveData = new byte[1024];
				// take input to send to client
				System.out.println(" Enter message to send to server ");
				Scanner sc = new Scanner(System.in);
				message = sc.nextLine();
				sendData = message.getBytes(); // encodes string into sequence bytes
				//System.out.println("Client : "+message);
				// convert to packet
				DatagramPacket sendPacket =  new DatagramPacket(sendData,sendData.length,ipAddress,9876);
				clientSocket.send(sendPacket);
				if(message.equalsIgnoreCase("stop"))
					break;
				DatagramPacket receivePacket = new DatagramPacket(recieveData, recieveData.length);
				clientSocket.receive(receivePacket);
				recievedMessage = new String(receivePacket.getData());
				System.out.println("Server : "+recievedMessage.trim());
				if(recievedMessage.trim().equalsIgnoreCase("stop"))
					break;
				recievedMessage="";
			}
			clientSocket.close();
			System.out.println("Client stopped");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
