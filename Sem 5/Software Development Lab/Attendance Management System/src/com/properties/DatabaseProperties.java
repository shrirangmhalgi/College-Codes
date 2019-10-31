 package com.properties;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Properties;

public class DatabaseProperties {
	static Properties prop = new Properties();
	
	public void setProperties() {
		try {
			OutputStream output = new FileOutputStream("config.properties");

			// set the properties value
			prop.setProperty("JDBC_DRIVER", "com.mysql.cj.jdbc.Driver");
			prop.setProperty("DB_URL", "jdbc:mysql://@localhost:3306/attendence");
			prop.setProperty("USERNAME", "root");
			prop.setProperty("PASSWORD", "root");

			// save properties to project root folder
			prop.store(output, null);

		} catch (IOException io) {
			io.printStackTrace();
		} 
	}
	
	public static Properties loadProperties() {
		try {
			InputStream input = new FileInputStream("config.properties");

			// load a properties file
			prop.load(input);
			
			return prop;
			
		} catch (IOException ex) {
			ex.printStackTrace();
			return null;
		} 
	}
}
