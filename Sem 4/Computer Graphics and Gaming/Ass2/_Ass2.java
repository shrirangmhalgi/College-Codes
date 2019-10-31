package cgg;

import java.awt.Graphics;
import javax.swing.JFrame;

public class Assignment5LinePatterns extends JFrame{
	
	public void ddaLineThick(Graphics g, int x1, int y1, int x2, int y2){
		double length;
		double x, y;
		
		double dx = x2 -x1;
		double dy = y2 - y1;
		
		if(Double.compare(dx, dy) == 1)
			length = dx;
		else
			length = dy;
		
		dx = (x2 - x1)/length;
		dy = (y2 - y1)/length;
		
		/*System.out.println("length = " +length);
		System.out.println("dx = " +dx);
		System.out.println("dy = " +dy);*/
		
		x = x1 + (0.5 * Integer.signum((int)dx));
		y = y1 + (0.5 * Integer.signum((int)dy));
		
		//g.fillOval((int)x, (int)y, 2, 2);
		int i = 1;
		while(i <= length){
			g.fillOval((int)x, (int)y, 2, 2);
			x = x + dx;
			y = y + dy;
			i++;
		}	
	}
	
	public void ddaLineDash(Graphics g, int x1, int y1, int x2, int y2){
		double length;
		double x, y;
		
		double dx = x2 -x1;
		double dy = y2 - y1;
		
		if(Double.compare(dx, dy) == 1)
			length = dx;
		else
			length = dy;
		
		dx = (x2 - x1)/length;
		dy = (y2 - y1)/length;
		
		/*System.out.println("length = " +length);
		System.out.println("dx = " +dx);
		System.out.println("dy = " +dy);*/
		
		x = x1 + (0.5 * Integer.signum((int)dx));
		y = y1 + (0.5 * Integer.signum((int)dy));
		
		g.fillOval((int)x, (int)y, 2, 2);
		int i = 1;
		while(i <= length && x <= x2){
			x = x + dx;
			y = y + dy;
			if(i % 20 == 0)
				x = x + 10;
			else
				g.fillOval((int)x, (int)y, 2, 2);
			i++;
		}	
	}
	
	
	public void ddaLineDashDot(Graphics g, int x1, int y1, int x2, int y2){
		double length;
		double x, y;
		
		double dx = x2 -x1;
		double dy = y2 - y1;
		
		if(Double.compare(dx, dy) == 1)
			length = dx;
		else
			length = dy;
		
		dx = (x2 - x1)/length;
		dy = (y2 - y1)/length;
		
		/*System.out.println("length = " +length);
		System.out.println("dx = " +dx);
		System.out.println("dy = " +dy);*/
		
		x = x1 + (0.5 * Integer.signum((int)dx));
		y = y1 + (0.5 * Integer.signum((int)dy));
		
		g.fillOval((int)x, (int)y, 2, 2);
		int i = 1;
		while(i <= length && x <= x2){
			x = x + dx;
			y = y + dy;
			if(i % 22 == 0){
				x = x + 16;
				g.fillOval((int)x, (int)y, 2, 2);
			}
			else
				g.fillOval((int)x - 8, (int)y, 2, 2);
			i++;
		}	
	}
	
	public void ddaLineDotted(Graphics g, int x1, int y1, int x2, int y2){
		double length;
		double x, y;
		
		double dx = x2 -x1;
		double dy = y2 - y1;
		
		if(Double.compare(dx, dy) == 1)
			length = dx;
		else
			length = dy;
		
		dx = (x2 - x1)/length;
		dy = (y2 - y1)/length;
		
		/*System.out.println("length = " +length);
		System.out.println("dx = " +dx);
		System.out.println("dy = " +dy);*/
		
		x = x1 + (0.5 * Integer.signum((int)dx));
		y = y1 + (0.5 * Integer.signum((int)dy));
		
		g.fillOval((int)x, (int)y, 2, 2);
		int i = 1;
		while(i <= length && x <= x2){
			x = x + dx;
			y = y + dy;
			if(i % 8 == 0)
				g.fillOval((int)x, (int)y, 2, 2);
			i++;
		}	
	}
	
	
	public static void main(String[] args) {
		Assignment5LinePatterns obj = new Assignment5LinePatterns();
		obj.setSize(1024, 768);
		obj.setVisible(true);
		obj.setDefaultCloseOperation(EXIT_ON_CLOSE);

	}
	
	public void paint(Graphics g) {
		
		ddaLineThick(g, 150, 150, 450, 150);
	    ddaLineThick(g, 150, 152, 450, 152);
	    ddaLineThick(g, 150, 154, 450, 154);
	    ddaLineDash(g, 150, 170, 450, 170);
	    ddaLineDotted(g, 150, 190, 450, 190);
	    ddaLineDashDot(g, 150, 210, 450, 210);
		
	}
}