package com.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

import com.properties.DatabaseProperties;

public class DBUtilities {
	
	//method for getting D.B. connection
	static public Connection getDBConnection() {
		Properties properties = DatabaseProperties.loadProperties();
		Connection connection= null;
		try {
			//registering jdbc driver
			Class.forName(properties.getProperty("JDBC_DRIVER"));
			
			//opening a connection
			connection = DriverManager.getConnection(properties.getProperty("DB_URL"), properties.getProperty("USERNAME"), properties.getProperty("PASSWORD"));
				
		} catch (ClassNotFoundException | SQLException e) {
			e.printStackTrace();
		}
		return connection;
	}
}
