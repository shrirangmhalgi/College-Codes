//Write a java program that demonstrates a concept intefaces and packages.
//In this assignment use of customized package and interfaces is for specific application is expected

package ads.assignments.servers;

import java.util.Scanner;

import ads.assignments.interfaces.Accept;
import ads.assignments.interfaces.Display;

public class Assignment13InterfacesPackages implements Accept, Display{
	
	String name, mobile, curclass, division, rollno;
	
	@Override
	public void display() {
		System.out.println("----------STUDENT INFORMATION----------");
		System.out.println("NAME : " +name);
		System.out.println("CLASS : " +curclass);
		System.out.println("DIVISION : " +division);
		System.out.println("ROLL NO : " +rollno);
		System.out.println("MOBILE : " +mobile);
	}

	@Override
	public void accept() {
		Scanner sc = new Scanner(System.in);
		System.out.print("\nENTER NAME : ");
		name = sc.next();
		System.out.print("\nENTER CLASS : ");
		curclass = sc.next();
		System.out.print("\nENTER DIVISION : ");
		division = sc.next();
		System.out.print("\nENTER ROLLNO : ");
		rollno = sc.next();
		System.out.print("\nENTER MOBILE : ");
		mobile = sc.next();
	}

}
