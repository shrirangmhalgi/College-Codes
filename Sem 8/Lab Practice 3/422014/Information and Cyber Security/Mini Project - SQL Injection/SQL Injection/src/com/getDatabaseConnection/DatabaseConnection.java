package com.getDatabaseConnection;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import com.beans.UserDetails;


public class DatabaseConnection {
	public ArrayList<UserDetails> getDatabaseConnection(String userName, String password){
		Connection connection= null;
		ArrayList<UserDetails> data = new ArrayList<UserDetails>();
		try {
			//registering jdbc driver
			Class.forName("com.mysql.cj.jdbc.Driver");
			
			//opening a connection
			connection = DriverManager.getConnection("jdbc:mysql://@localhost:3306/attendence", "root", "root");
			
			// Creating a statement
			Statement statement = connection.createStatement();
			
			// Query
			String query = "select * from user_table where username = \"" + userName + "\" and password = \"" + password + "\"";
			
			// Extracting Results
			ResultSet resultset = statement.executeQuery(query);
			
			while(resultset.next()) {
				data.add(new UserDetails(resultset.getString("username"), resultset.getString("password")));
			}
		} 
		catch (ClassNotFoundException | SQLException e) {
			e.printStackTrace();
		}
		
		return data;
	}
}
