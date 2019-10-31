package cgg;

import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JFrame;

public class Assignment7TraslationRotationScalingByInbuiltMethods extends JFrame{
	
	public void drawRectangle(Graphics g) {
		g.drawLine(100, 100, 500, 100);
		g.drawLine(100, 300, 500, 300);
		g.drawLine(100, 100, 100, 300);
		g.drawLine(500, 100, 500, 300);
		//g.fillRect(100, 100, 400, 200);
	}
	
	public static void main(String[] args) {
		Assignment7TraslationRotationScalingByInbuiltMethods cObj = new Assignment7TraslationRotationScalingByInbuiltMethods();
		cObj.setSize(2000, 2000);
		cObj.setVisible(true);
		cObj.setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	
	public void paint(Graphics g) {
		//draw and fill rectangle
		
		Graphics2D g2d = (Graphics2D) g;
		drawRectangle(g2d);
		g2d.translate(200, 200);
		drawRectangle(g2d);
		g2d.translate(200, 200);
		drawRectangle(g2d);
		g2d.rotate(45);
		drawRectangle(g2d);
		g2d.shear(2.5, 0);
		drawRectangle(g2d);
		g2d.scale(1.5, 1.5);
		drawRectangle(g2d);

		
		
	}

}
