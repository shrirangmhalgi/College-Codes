package com.databaseAccess;

import java.io.Serializable;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Dictionary;
import java.util.Hashtable;

import com.dataObjects.UsersBean;
import com.enumerations.Months;
import com.util.DBUtilities;

public class AttendanceDBO implements Serializable{
	Months months[] = Months.values();
	Dictionary<String, Integer> attendance = new Hashtable<>();
	
	public Dictionary<String, Integer> readAttendence(UsersBean bean){
		
		try(Connection connection = DBUtilities.getDBConnection()) {
			
			Statement statement = connection.createStatement();
			
			String query = "SELECT * FROM attendence_table WHERE gr_no = '" +bean.getGrNo() +"'";
			
			ResultSet rs = statement.executeQuery(query);
			
			while(rs.next()) {
				for(int i = 2, j = 0; i <= 13; i++, j++) {
					attendance.put(months[j].toString(), rs.getInt(i));
				}
			}
			return attendance;
		} catch (SQLException e) {
			e.printStackTrace();
			return null;
		}				
	}
}
