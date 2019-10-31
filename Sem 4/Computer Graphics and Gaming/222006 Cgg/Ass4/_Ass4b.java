package cgg;

import java.awt.Graphics;
import javax.swing.JFrame;

public class Assignment4Pattern2 extends JFrame{

	public void dda(Graphics g, int x1, int y1, int x2, int y2){
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

	void bresenhamCircle(Graphics g, int xc, int yc, int r){
		//int xc = 0, yc = 0;
		int x = 0;
		int y = r;
		int p = 3 - 2 * r;
		do{
			if(p < 0)
				p = p + 4 * x + 6;
			else{
				p = p + 4 * (x - y) + 10;
				y--;
			}
			x++;
			g.drawLine(xc + x, yc + y, xc + x, yc + y);
			g.drawLine(xc + x, yc - y, xc + x, yc - y);
			g.drawLine(xc - x, yc + y, xc - x, yc + y);
			g.drawLine(xc - x, yc - y, xc - x, yc - y);
			g.drawLine(xc + y, yc + x, xc + y, yc + x);
			g.drawLine(xc + y, yc - x, xc + y, yc - x);
			g.drawLine(xc - y, yc + x, xc - y, yc + x);
			g.drawLine(xc - y, yc - x, xc - y, yc - x);
		}while(x < y);
	}

	public static void main(String[] args) {
		Assignment4Pattern2 obj1 = new Assignment4Pattern2();
 		obj1.setSize(2000, 1524);
		obj1.setVisible(true);
		obj1.setDefaultCloseOperation(EXIT_ON_CLOSE);
	}

	public void paint(Graphics g) {
		bresenhamCircle(g, 1200, 885, 115);//radius of incircle = (root 3 * side of triangle)/6
		bresenhamCircle(g, 1200, 885, 231);//radius of circumcircle = (root 3 * side of triangle)/3
		dda(g, 1000, 1000, 1400, 1000);
		dda(g, 1000, 1000, 1200, 654);
		dda(g, 1200, 654, 1400, 1000);



	}
}
