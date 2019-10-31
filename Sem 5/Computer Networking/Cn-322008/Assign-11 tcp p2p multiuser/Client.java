package assignment11;

import java.io.*;
import java.net.*;

public class Client {
	public static void main(String args[]) {
		Client c = new Client();
		c.sendConnectionReq();
		System.out.println(" Client stopped ");
	}
	public void sendConnectionReq() {
		try {
			String str1="",str2="";
			// create socket using socket class
			Socket s = new Socket("localhost",6666);
			DataOutputStream dout =new DataOutputStream(s.getOutputStream()); // returns outputstream attached with this object
			DataInputStream din = new  DataInputStream(s.getInputStream());
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			while(true) {
				System.out.println("Enter string1 and 'stop' to Stop");
				str1=br.readLine();
				dout.writeUTF(str1);
				dout.flush();
				if(str1.equals("stop"))
					break;
				str2=din.readUTF();
				System.out.println(" Message from server : "+str2);
			}
			//din.close();
			dout.close();
			s.close();
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}
}