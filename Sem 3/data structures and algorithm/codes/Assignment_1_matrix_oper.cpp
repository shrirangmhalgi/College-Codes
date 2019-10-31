#include <iostream>
using namespace std;
struct Matrix
{
    int a[5][5],m;
}p;

void accept()
{
    cout<<"Enter the order of the square matrix ";
    cin>>p.m;
    cout<<"Enter the square matrix "<<endl;
    for(int i=0;i<p.m;i++)
    {
        for(int j=0;j<p.m;j++)
            cin>>p.a[i][j];
    }
}

void trans()
{
    cout<<"The transpose of matrix is\n";
    for(int i=0;i<p.m;i++)
    {
        for(int j=0;j<p.m;j++)
        {
            cout<<p.a[j][i]<<" ";
        }
            cout<<endl;
    }
}

void diagsum()
{
    int sum=0;
    for(int i=0;i<p.m;i++)
    {
        for(int j=0;j<p.m;j++)
            {
            if(i==j)
                sum=sum+p.a[i][j];
            }
    }
    cout<<"The sum of diagonal elements of matrix is "<<sum<<endl;
    cout<<"\n";
}

void upchk()
{
    int upper=0;
    for(int i=0;i<p.m;i++)
    {
        for (int j = 0; j<p.m ; j++)
        {
          if(i<=j)
          {
              if (p.a[i][j]==0)
              {
                  upper=1;
              }
          }
          else //i>j
          {
              if(p.a[i][j]!=0)
              {
                  upper=upper+1;
              }
          }
        }
    }

     if(upper==0)
     {
         cout<<"Matrix is an upper triangular matrix "<<endl;
     }
        else
        {
            cout<<"Not an upper triangular matrix"<<endl;
        }
    cout<<"\n\n Matrix :\n";
    for(int i=0; i< p.m ; i++)
    {
        for (int j = 0; j< p.m ; j++)
            cout<<p.a[i][j] << " ";

        cout<< endl;
    }
    cout<<"\n";
}

void arit()
{
    int b[5][5],c[5][5];
    cout<<"Enter the second square matrix ";
    for(int i=0;i<p.m;i++)
    {
        for(int j=0;j<p.m;j++)
        cin>>b[i][j];
    }
    for(int i=0;i<p.m;i++)
    {
        for(int j=0;j<p.m;j++)
            c[i][j]=p.a[i][j]+b[i][j];
    }
    cout<<"\nThe sum of the matrices are\n";
    for(int i=0;i<p.m;i++)
    {
        for(int j=0;j<p.m;j++)
            cout<<c[i][j]<<" ";
            cout<<"\n";
    }
    for(int i=0;i<p.m;i++)
    {
        for(int j=0;j<p.m;j++)
            c[i][j]=p.a[i][j]-b[i][j];
    }
    cout<<"\nThe difference of the matrices is\n";
    for(int i=0;i<p.m;i++)
    {
        for(int j=0;j<p.m;j++)
            cout<<c[i][j]<<" ";
            cout<<"\n";
    }
    for(int i=0;i<p.m;i++)
    {
        for(int j=0;j<p.m;j++)
        {
            c[i][j]=0;
            for(int k=0;k<p.m;k++)
            c[i][j]=c[i][j]+p.a[i][j]*b[i][j];
        }
    }
    cout<<"\nThe multiplication of the matrices is\n";
    for(int i=0;i<p.m;i++)
    {
        for(int j=0;j<p.m;j++)
            cout<<c[i][j]<<" ";
            cout<<"\n";
    }
}

int main()
{
    int ch;
    do
    {
    cout<<"\n****Choice menu****\n";
    cout<<"1.Enter first matrix \n";
    cout<<"2.Transpose matrix\n";
    cout<<"3.Diagonal sum of matrix\n";
    cout<<"4.Check upper triangle matrix\n";
    cout<<"5.Enter another matrix and addition,subtraction,multication of matrices\n";
    cout<<"6.Exit\n";
    cout<<"Enter your choice : ";
    cin>>ch;
    cout<<"\n";
    switch(ch)
    {
        case 1:accept();
        break;
        case 2:trans();
        break;
        case 3:diagsum();
        break;
        case 4:upchk();
        break;
        case 5:arit();
        break;
        case 6:break;
    }
    }while(ch!=6);
}

/*
****Choice menu****
1.Enter first matrix
2.Transpose matrix
3.Diagonal sum of matrix
4.Check upper triangle matrix
5.Enter another matrix and addition,subtraction,multication of matrices
6.Exit
Enter your choice : 1

Enter the order of the square matrix 3
Enter the square matrix
1
2
3
4
5
6
7
8
9

****Choice menu****
1.Enter first matrix
2.Transpose matrix
3.Diagonal sum of matrix
4.Check upper triangle matrix
5.Enter another matrix and addition,subtraction,multication of matrices
6.Exit
Enter your choice : 2

The transpose of matrix is
1 4 7
2 5 8
3 6 9

****Choice menu****
1.Enter first matrix
2.Transpose matrix
3.Diagonal sum of matrix
4.Check upper triangle matrix
5.Enter another matrix and addition,subtraction,multication of matrices
6.Exit
Enter your choice : 3

The sum of diagonal elements of matrix is 15


****Choice menu****
1.Enter first matrix
2.Transpose matrix
3.Diagonal sum of matrix
4.Check upper triangle matrix
5.Enter another matrix and addition,subtraction,multication of matrices
6.Exit
Enter your choice : 4

Not an upper triangular matrix


 Matrix :
1 2 3
4 5 6
7 8 9


****Choice menu****
1.Enter first matrix
2.Transpose matrix
3.Diagonal sum of matrix
4.Check upper triangle matrix
5.Enter another matrix and addition,subtraction,multication of matrices
6.Exit
Enter your choice : 5

Enter the second square matrix 9
8
7
6
5
4
3
2
1

The sum of the matrices are
10 10 10
10 10 10
10 10 10

The difference of the matrices is
-8 -6 -4
-2 0 2
4 6 8

The multiplication of the matrices is
27 48 63
72 75 72
63 48 27

****Choice menu****
1.Enter first matrix
2.Transpose matrix
3.Diagonal sum of matrix
4.Check upper triangle matrix
5.Enter another matrix and addition,subtraction,multication of matrices
6.Exit
Enter your choice : 6


Press any key to continue . . .*/
