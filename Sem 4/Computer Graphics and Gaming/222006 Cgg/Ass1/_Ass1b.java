
package cgg_final;
import java.awt.*;
import javax.swing.JFrame;
import java.lang.Math;
import java.lang.Thread;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Bresenham extends JFrame 
{

    public static void main(String[] args) 
    {
       Bresenham b=new Bresenham();
       b.setSize(600,600);
       b.setTitle("Bresenham Algorithm");
       b.setVisible(true);
       System.out.println("Bresenham Line Drawing Algorithm");
    }
    public void paint(Graphics g)
    {
       Bresenham_Algo(200,200,500,200,g);
       Bresenham_Algo(500, 500, 500, 200, g);
    }
    public void Bresenham_Algo(int x1,int y1,int x2,int y2,Graphics g)
    {
        int s1,s2,ex,x,y,i;
        int dx,dy,temp,p;
        dx=Math.abs(x2-x1);
        dy=Math.abs(y2-y1);
        x=x1;
        y=y1;
        s1=sign(x2-x1);
        s2=sign(y2-y1);
        
        if(dy>dx)
        {
            temp=dx;
            dx=dy;
            dy=temp;
            ex=1;
        }
        else
            ex=0;
        
        p=(2*dy)-dx;
        i=1;
        g.drawOval(x,y,1,1); 
        while(i<=dx)
        { 
            if(p>=0)
            {
                x=x+s1;
                y=y+s2;
                p=p+(2*(dy-dx));
            }
            else
            {
                if(ex==1)
                    y=y+s2;
                else
                    x=x+s1;
            p=p+2*dy;
            }
            i++;
            if(x%3==0 || y%3==0)
            {
                try {
                    g.drawOval(x,y,1,1);
                    g.setColor(Color.red);
                    Thread.sleep(100);
                } catch (InterruptedException ex1) {
                    Logger.getLogger(Bresenham.class.getName()).log(Level.SEVERE, null, ex1);
                }
            }
        }
    }
    public int sign(int arg)
    {
        if(arg<0)
            return -1;
        else if(arg==0)
            return 0;
        else
            return 1;
    }
}
