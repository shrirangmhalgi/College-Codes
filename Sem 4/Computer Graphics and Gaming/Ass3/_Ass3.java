
package cgg_final;

import java.awt.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;


public class Bresenham_circle extends JFrame 
{

    public static void main(String[] args) 
    {
        Bresenham_circle b=new Bresenham_circle();
        b.setSize(700,700);
        b.setTitle("Bresenham Circle");
        b.setVisible(true);
    }
    public void paint(Graphics g)
    {
        Bre_Cir(400,400,150,g);
    }
    public void Bre_Cir(int x,int y,int rad,Graphics g)
    {
        int dp;
        int x1,y1;
        x1=0;
        y1=rad;
        dp=3-(2*rad);
        
        while(x1<=y1)
        {
            if(dp<=0)
                dp=dp+(4*x1)+6;
            else
            {
                dp=dp+4*(x1-y1)+10;
                y1--;
            }
            x1++;
            
            try {
                Thread.sleep(100);
            } catch (InterruptedException ex) 
            {
                Logger.getLogger(Bresenham_circle.class.getName()).log(Level.SEVERE, null, ex);
            }
            g.setColor(Color.red);
            g.fillOval(x1+x,y1+y,2,2);
            g.setColor(Color.PINK);
            g.fillOval(x1+x,y-y1,2,2);
            g.setColor(Color.BLUE);
            g.fillOval(x-x1,y1+y,2,2);
            g.setColor(Color.darkGray);
            g.fillOval(x-x1,y-y1,2,2);
            g.setColor(Color.blue);
            g.fillOval(x+y1,y+x1,2,2);
            g.setColor(Color.BLACK);
            g.fillOval(x+y1,y-x1,2,2);
            g.setColor(Color.magenta);
            g.fillOval(x-y1,y+x1,2,2);
            g.setColor(Color.GREEN);
            g.fillOval(x-y1,y-x1,2,2);
            g.setColor(Color.LIGHT_GRAY);
        }
    }
}
