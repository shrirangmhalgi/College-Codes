
package cgg_final;

import java.awt.*;
import javax.swing.JFrame;
import java.lang.Math;

public class Dda extends JFrame
{
    //int x1,y1,x2,y2;
    public static void main(String[] args) 
    {
       Dda d=new Dda();
       d.setSize(600,500);
       d.setTitle("DDA Algorithm");
       d.setVisible(true);
       System.out.println("\n\tDDA Line Genaration Algorithm");
        
    }
    public void paint(Graphics g)
    {
        DDA_Algorithm(000,000,400,400,g);
    }
    public void DDA_Algorithm(int x1,int y1,int x2,int y2,Graphics g)
    {
        int i,dx,dy,steps;
        int x,y,xinc,yinc;
        dx=(x2-x1);
        dy=(y2-y1);
        if(Math.abs(dx) > Math.abs(dy))
            steps=dx;
        else
            steps=dy;
        
        xinc=dx/steps;
        yinc=dy/steps;
        x=x1;
        y=y1;
        g.fillOval(x,y,3,3);
        
        for(i=1;i<steps;i++)
        {
        	try {
				Thread.sleep(100);
				Color c=new Color(((2*i)%255),Math.abs((255-i)%255),Math.abs((0+i)%255));
	            g.setColor(c);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
            x=x+xinc;
            y=y+yinc;
            
            g.fillOval(x,y,3,3);
        }
    }
}
