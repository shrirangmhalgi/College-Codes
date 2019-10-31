package com.dataObjects;

import java.io.Serializable;

public class UsersBean implements Serializable{
	String grNo, userName, password;
	
	public UsersBean() {
		grNo = null;
		userName = null;
		password = null;
	}
	
	public UsersBean(String grNo, String userName, String password) {
		this.grNo = grNo;
		this.userName = userName;
		this.password = password;
	}

	public String getGrNo() {
		return grNo;
	}

	public String getUserName() {
		return userName;
	}

	public String getPassword() {
		return password;
	}

	public void setGrNo(String grNo) {
		this.grNo = grNo;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public void setPassword(String password) {
		this.password = password;
	}
	
	
}
