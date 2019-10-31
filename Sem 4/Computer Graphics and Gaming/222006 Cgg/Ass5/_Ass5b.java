package cgg;

import java.awt.*;

import java.awt.Graphics;

import javax.swing.JFrame;

public class Assignment8TraslationRotationScalingByMyMethods extends JFrame{
	
	double triangle[][] = {{200, 200, 400}, {100, 500, 500}, {1, 1, 1}};
	double translate[][] = { {1, 0, 0}, {0, 1, 0}, {5, 5, 1} };
	double rotation[][] = { {0.5, 0.8660, 0}, {-0.8660, 0.5, 0}, {0, 0, 1} };
	double scale[][] = { {.5, 0, 0}, {0, .5, 0}, {0, 0, 1} };
	
	public void translate(Graphics g) {
		double result[][] = { {}, {}, {} };
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				for(int k = 0; k < 3; k ++)
					result[i][j] =+ triangle[i][k] * translate[k][j];
			}
		}		
	}
	
	public void rotate(Graphics g) {
		double result[][] = { {}, {}, {} };
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				for(int k = 0; k < 3; k ++)
					result[i][j] =+ triangle[i][k] * rotation[k][j];
			}
		}
	}
	
	public void scale(Graphics g) {
		double result[][] = { {}, {}, {} };
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				for(int k = 0; k < 3; k ++)
					result[i][j] =+ triangle[i][k] * scale[k][j];
			}
		}
	}
	
	@Override
	public void paint(Graphics g) {
		g.drawLine(200, 200, 500, 500);
		g.drawLine(200, 200, 1500, 500);
		g.drawLine(500, 500, 1500, 500);
		translate(g);
		
	}

	public static void main(String[] args) {
		Assignment8TraslationRotationScalingByMyMethods aObj = new Assignment8TraslationRotationScalingByMyMethods();
		aObj.setSize(4000, 4000);
		aObj.setVisible(true);
		aObj.setDefaultCloseOperation(EXIT_ON_CLOSE);
	}

}
