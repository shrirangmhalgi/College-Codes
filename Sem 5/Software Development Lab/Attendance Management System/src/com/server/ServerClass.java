package com.server;

import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import com.threadExecutor.ThreadExecutor;

public class ServerClass {
	public static void main(String[] args) {
		ExecutorService executorService = Executors.newFixedThreadPool(5);
		try {
			ServerSocket serverSocket = new ServerSocket(9498); //you are defining a unique port to your server
			System.out.println("waiting for client..");
			
			while(true) {
				Socket socket = serverSocket.accept();  //creating a new separate socket for each request as you dont wanna jam the servers accepting abilities
				System.out.println("client connected");
				
				ObjectInputStream in = new ObjectInputStream(socket.getInputStream());
				ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
				
				executorService.execute(new ThreadExecutor(socket, in, out));
			}			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}




