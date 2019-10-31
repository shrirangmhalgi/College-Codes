
package cgg_final;

import java.awt.Graphics;
import java.util.Scanner;
import javax.swing.JFrame;

public class Assignment12_Rhombus extends JFrame
{
        int tx,ty,sx,sy;
        int sum=0;
	int vertex[][]={{300,400,200,300},{100,100,200,200},{1,1,1,1}},transm[][]=new int[3][3],res[][]=new int[3][4];
        //double sum=0.0;
        //double transm[][]=new double[3][3],res[][]=new double[3][4],vertex[][]={{300,400,200,300},{100,100,200,200},{1,1,1,1}};
	Scanner in=new Scanner(System.in);
        
	public void setMatrix_Translation() 
	{
		System.out.println("Enter Translating Factor ");
		System.out.print("Enter tx : ");
		tx=in.nextInt();
		System.out.print("Enter ty : ");
		ty=in.nextInt();
		transm[0][0]=1;transm[1][1]=1;transm[2][2]=1;transm[0][2]=tx;transm[1][2]=ty;
	}
        public void setMatrix_Scaling() 
	{
		System.out.println("Enter Scaling Factor ");
		System.out.print("Enter Sx : ");
		sx=in.nextInt();
		System.out.print("Enter Sy : ");
		sy=in.nextInt();
		transm[0][0]=sx;transm[1][1]=sy;transm[2][2]=1;
	}
        public void setMatrix_Rotation() 
        {
             //Rotation by 30 degree  
                //transm[0][0]=0.8660;transm[0][1]=-0.5;transm[1][0]=0.5;transm[1][1]=0.8660;transm[2][2]=1;
	}
        public void setMatrix_shearX()
        {
            double Sx;
            System.out.println("Enter Shearing Factor in X : ");
            Sx=in.nextDouble();
            //transm[0][0]=transm[1][1]=transm[2][2]=1;transm[0][1]=Sx;
        }
         public void setMatrix_shearY()
        {
            double Sy;
            System.out.println("Enter Shearing Factor in Y : ");
            Sy=in.nextDouble();
            //transm[0][0]=transm[1][1]=transm[2][2]=1;transm[1][0]=Sy;
        }
	public void Multi() 
	{
	for(int i=0;i<3;i++)
        {
            for(int j=0;j<4;j++)
            {
             sum=0;
               for(int k=0;k<3;k++)
               {
                   sum=sum+transm[i][k]*vertex[k][j];
               }
               res[i][j]=sum;
            }
        }
	}
       
	public void paint(Graphics g)
    {
            //Before Transformation Rhombus
             g.drawLine(300,100,400,100);
	     g.drawLine(300,100,200,200);
	     g.drawLine(200,200,300,200);
             g.drawLine(400,100,300,200);
             
            //After Transformation Rhombus
             g.drawLine((int)res[0][0],(int)res[1][0],(int)res[0][1],(int)res[1][1]);
	     g.drawLine((int)res[0][1],(int)res[1][1],(int)res[0][3],(int)res[1][3]);
	     g.drawLine((int)res[0][2],(int)res[1][2],(int)res[0][0],(int)res[1][0]);
             g.drawLine((int)res[0][3],(int)res[1][3],(int)res[0][2],(int)res[1][2]);
             
    }
	public static void main(String[] args) 
	{
		Assignment12_Rhombus obj=new Assignment12_Rhombus();
		//obj.setMatrix_Translation(); 
                obj.setMatrix_Scaling();
                //obj.setMatrix_Rotation();
                //obj.setMatrix_shearX();
                //obj.setMatrix_shearY();
                
                obj.Multi();
                
		obj.setSize(900,900);
		obj.setTitle("Translation");
		obj.setVisible(true);
		obj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}

