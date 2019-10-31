package com.databaseAccess;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Dictionary;

import com.dataObjects.UsersBean;
import com.util.DBUtilities;

public class UsersDBO {
	public UsersBean readUserName(UsersBean bean){
			
		try(Connection connection = DBUtilities.getDBConnection()) {
			
			Statement statement = connection.createStatement();
			
			String query = "SELECT * FROM user_table WHERE gr_no = '" +bean.getGrNo() +"' and password = '" +bean.getPassword() +"'";
			
			ResultSet rs = statement.executeQuery(query);
			
			while(rs.next()) {
				bean.setUserName(rs.getString(2));
			}
			return bean;
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}				
	}	
}
