<%-- 
    Document   : hello
    Created on : Mar 26, 2018, 9:16:51 PM
    Author     : capricon
--%>

    <%@ page import="java.sql.*"%>  
      
    <%  
    String s=request.getParameter("val");  
    if(s==null || s.trim().equals("")){  
    out.print("Please enter id");  
    }else{  
    int id=Integer.parseInt(s);  
    out.print(id);  
    try{  
     //   out.print("inside try");
    Class.forName("com.mysql.jdbc.Driver");  
    Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/loginpage","root","root");  
    PreparedStatement ps=con.prepareStatement("select * from emp where id=?");  
  //  out.print("after query");
    ps.setInt(1,id);  
    ResultSet rs=ps.executeQuery();  
    while(rs.next()){  
    out.print(rs.getInt(1)+" "+rs.getString(2));  
    }  
    con.close();  
    }catch(Exception e){e.printStackTrace();}  
    }  
    %>  
