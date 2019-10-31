<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="viit.comp.*, javax.naming.*, javax.ejb.EJB"%>

 <%

 float result=0;
 //  CalculatorBeanRemote calculator=null;

 
      try {
			
          InitialContext ic = new InitialContext();
 

			CalculatorBeanRemote  calculator = (CalculatorBeanRemote) ic.lookup("java:global/calculator/CalculatorBean!viit.comp.CalculatorBeanRemote");

			System.out.println("Loaded Calculator Bean");
//CalculatorBean



          String s1 = request.getParameter("num1");
			String s2 = request.getParameter("num2");
			String s3 = request.getParameter("group1");

System.out.println(s3);

          if ( s1 != null && s2 != null ) {
              Float num1  = new Float(s1);
				Float num2  = new Float(s2);
				
				if(s3.equals("add"))
					result=calculator.add(num1.floatValue(),num2.floatValue());
				else if(s3.equals("sub"))
					result=calculator.subtract(num1.floatValue(),num2.floatValue());
				else if(s3.equals("multi"))
					result=calculator.multiply(num1.floatValue(),num2.floatValue());
				else
					result=calculator.division(num1.floatValue(),num2.floatValue());
				
       %>
      <p>
      <b>The result is:</b> <%= result %>
      <p>
      
      <%
          }
		}// end of try
		catch (Exception e) {
    e.printStackTrace ();
   //result = "Not valid";
  }

%>