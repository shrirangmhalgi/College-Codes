package com.threadExecutor;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.net.Socket;
import java.util.Dictionary;
import java.util.Hashtable;

import com.dataObjects.AttendenceBean;
import com.dataObjects.UsersBean;
import com.databaseAccess.AttendanceDBO;
import com.databaseAccess.UsersDBO;
import com.enumerations.Months;

public class ThreadExecutor implements Runnable{
	Socket socket;
	ObjectOutputStream out = null;
	ObjectInputStream in = null;
	UsersBean usersBean = null;
	AttendenceBean attendenceBean = new AttendenceBean();
	Hashtable<String, Integer> attendence = new Hashtable<>();
	
	public ThreadExecutor(Socket socket, ObjectInputStream in, ObjectOutputStream out) {
		this.socket = socket;
		this.in = in;
		this.out = out;
	}
	
	@Override
	public void run() {
		try {
			
			Months months[] = Months.values();
			usersBean = (UsersBean) in.readObject();
			
			UsersDBO usersDBO = new UsersDBO();
			usersBean = usersDBO.readUserName(usersBean);
			
			if(usersBean.getUserName() == "") {
				out.writeObject(attendence);
				out.writeObject(usersBean);
			}
			else {
				AttendanceDBO attendenceDBO = new AttendanceDBO();
				attendence = (Hashtable<String, Integer>)attendenceDBO.readAttendence(usersBean);
				
				attendenceBean.setGrNo(usersBean.getGrNo());
				attendenceBean.setTable(attendence);
				
				out.writeObject(attendence);
				out.writeObject(usersBean);
				
			}
			
			System.out.println("request processed");
			socket.close();
								
		} catch (IOException | ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}	
}
