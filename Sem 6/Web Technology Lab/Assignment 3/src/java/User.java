/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.sql.*;

/**
 *
 * @author capricon
 */
public class User extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet User</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet User at " + request.getContextPath() + "</h1>");
            out.println("</body>");
            out.println("</html>");
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException 
    {
       
        String a=request.getParameter("user1");
        System.out.println("username"+a);
        String b=request.getParameter("pass");
        System.out.println("password"+b);
        String id=null,name=null,userid=null,email=null;
        try
        {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/loginpage","root","root");
//Connection con = databasecon.getconnection();
            PreparedStatement ps=con.prepareStatement("select sid,sname,suserid,email from student where suserid='"+a+"' && spass='"+b+"'");
            ResultSet rs=ps.executeQuery();
            if(rs.next())
            {
                id=rs.getString("sid");
                name=rs.getString("sname");
                userid=rs.getString("suserid");
                email=rs.getString("email");

//response.sendRedirect("user5.jsp");
            response.sendRedirect("LoginSuccess.jsp");
//out.print(name2);
            }
            else
            {
                response.sendRedirect("LoginFailure.jsp");
            }
        }

        catch(Exception e2)
        {
            System.out.println(e2.getMessage());
        }

  
    }
}
