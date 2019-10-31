package cgg_final;

import java.awt.Graphics;
import java.util.Scanner;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class KochCurve extends JFrame 
{
	static int lev=0;
	static Scanner in=new Scanner(System.in);
	private static final long serialVersionUID = 1L;
	public void drawSnow(Graphics g,int lev,int x1,int y1,int x5,int y5)
	{
		int x2,y2,x3,y3,x4,y4;
		int deltaX,deltaY;
		if(lev==0)
		{
			g.drawLine(x1, y1, x5, y5);
			try {
				Thread.sleep(200);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		else
		{
			deltaX=x5-x1;
			deltaY=y5-y1;
			
			x2=x1+deltaX/3;
			y2=y1+deltaY/3;
			
			x3=(int) (0.5*(x1+x5)+Math.sqrt(3)*(y1-y5)/6);
			y3=(int) (0.5*(y1+y5)+Math.sqrt(3)*(x5-x1)/6);
			
			x4=x1+2*deltaX/3;
			y4=y1+2*deltaY/3;
			
			drawSnow(g,lev-1, x1, y1, x2, y2);
			drawSnow(g,lev-1, x2, y2, x3, y3);
			drawSnow(g,lev-1, x3, y3, x4, y4);
			drawSnow(g,lev-1, x4, y4, x5, y5);
		}
	}
	public void paint(Graphics g)
	{
		drawSnow(g,lev,20,280,280,280);
        drawSnow(g,lev,280,280,150,20);
        drawSnow(g,lev,150,20,20,280);
        
	}
	public static void main(String[] args) 
	{
		KochCurve obj=new KochCurve();
		String msg=JOptionPane.showInputDialog("Enter Level : ");
		lev=Integer.parseInt(msg);
		//System.out.print("Enter Level : ");
		//lev=in.nextInt();
		obj.setTitle("Koch Curve");
		obj.setSize(800,800);
		obj.setVisible(true);
		obj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
