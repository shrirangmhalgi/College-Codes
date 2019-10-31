package jdbc;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.sql.*;
import java.util.Scanner;

public class JDBC {

	public static void main(String[] args) {
		try {
			// TODO Auto-generated method stub
			Scanner scan = new Scanner(System.in);
			String name = null;
			Integer ID;
			Double percentage;
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/student","root","rohit123");
			System.out.println("Student Database: ");
			while(true) {
				System.out.println("\n\tEnter 1 for new entry: ");
				System.out.println("\tEnter 2 for display student list: ");
				System.out.println("\tEnter 3 to delete an entry: ");
				System.out.println("\tEnter 4 for exit: ");
				Integer x = scan.nextInt();
				switch (x) {
					case 1:	System.out.println("Enter student information: ");
							System.out.println("Enter ID: ");
							ID = scan.nextInt();
							System.out.println("\tEnter Name: ");
							name = scan.next();
							System.out.println("\tEnter percentage: ");
							percentage = scan.nextDouble();
							String query1 = " insert into attendance ("+" ID, NAME, PERCENT) values "+"(?, ?, ?)";
							PreparedStatement pstmt1 = con.prepareStatement(query1);
							pstmt1.setInt(1, ID);
							pstmt1.setString(2, name);
							pstmt1.setDouble(3, percentage);
							pstmt1.executeUpdate();
							pstmt1.close();
							break;
					case 2: Statement stmt = con.createStatement();
							ResultSet rs = stmt.executeQuery("select * from attendance");
							while(rs.next()) {
								System.out.println(rs.getString(1) +"   "+ rs.getString(2)+" "+rs.getString(3));
							}
							stmt.close();
							rs.close();
							break;
					case 3:	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));						
							System.out.println("\tEnter ID: ");
							ID = br.read();	
							String query2 = "delete from attendance where ID = ?";
							PreparedStatement pst =con.prepareStatement(query2);
//							pst.setString(1, name);
//							pst.setDate(2, date);1
							pst.executeUpdate();
							pst.close();
							break;
					case 4:	scan.close();
							con.close();
							System.exit(0);
				}
			}
		} catch(Exception e) {
			System.out.println(e);
			e.printStackTrace();
		}
	}
}