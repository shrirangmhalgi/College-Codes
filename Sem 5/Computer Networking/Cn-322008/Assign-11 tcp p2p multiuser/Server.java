package assignment11;

import java.io.*;
import java.net.*;

public class Server {
	public static void main(String args[]) {
		Server s = new Server();
		s.establishConnection();
		System.out.println(" Server stopped ");
	}
	public void establishConnection() {
		try {
			String str1="",str2="";
			System.out.println("Server starting");
			ServerSocket ss = new ServerSocket(6666); // port number needed to connect
			Socket s=ss.accept(); //  establishes connection
			DataInputStream din = new DataInputStream(s.getInputStream());
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			BufferedReader br = new BufferedReader(new  InputStreamReader(System.in));
			System.out.println("Connected to client");
			while(true) {
				str1 =din.readUTF();
				System.out.println("Message from client : "+str1);
				System.out.println("Enter message to be sent to client");
				if( str1.equals("stop"))
					break;
				str2 = br.readLine();
				dout.writeUTF(str2);
				dout.flush();
			}
			//dout.close();
			din.close();
			s.close();
			ss.close();
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}
}