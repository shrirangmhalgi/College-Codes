package com.authentication;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.beans.UserDetails;
import com.getDatabaseConnection.DatabaseConnection;
import com.google.gson.Gson;

/**
 * Servlet implementation class AuthenticationServlet
 */
@WebServlet("/AuthenticationServlet")
public class AuthenticationServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AuthenticationServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(request.getInputStream()));
	    String frontendData = "";
	    if(br != null){
	    	frontendData = br.readLine();
	    }
	    
	    Gson gson = new Gson();
		UserDetails userDetails = gson.fromJson(frontendData, UserDetails.class);
		
		if(userDetails != null) {
			String userName = userDetails.getUserName();
			String password = userDetails.getPassword();
			
			DatabaseConnection connection = new DatabaseConnection();
			ArrayList<UserDetails> data = connection.getDatabaseConnection(userName, password);
			
			String dataJson = gson.toJson(data);
			
			PrintWriter writer = response.getWriter();
			String statusJson = gson.toJson("{ 'success': 'true'}");
			String jsonArray = "[" + statusJson + "," + dataJson + "]";
			
			writer.println(jsonArray);
			writer.flush();
		}
	}

}
