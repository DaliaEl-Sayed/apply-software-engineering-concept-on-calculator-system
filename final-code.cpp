#include <iostream>
#include <new>
using namespace std;
///////////////////////////////////////////////////////
class inverse
{
    public:

//constructor 
inverse ()
{
double D;//determ
cout << "Enter One Number For columns and rows\n";
cin >> Dimention;
//Dimention=Di;
for ( int i=0 ; i < Dimention;i++)
{
mat_A[i]=new double [Dimention];
mat_B[i]=new double [Dimention];
}
for ( int i=0 ; i < 2;i++)
mat_C[i]=new double [2];

set_a(Dimention);

if (Dimention==3){D=Det();
if (D==0){cout << "The Determinant = Zero , There is no Inverse To this Matrix"<<endl;}
else {
transpose();
for (int i = 0 ; i < Dimention ; i++)
for (int j=0 ; j < Dimention ;j++)
detOfMinorMatrix(i,j);

coFactors();
detMultibly( D);print_Inverse();}//endiF
}//end if Dimention = 3
else if (Dimention==2){
D=mat_A[0][0]*mat_A[1][1]-mat_A[0][1]*mat_A[1][0];
if (D!=0){
mat_B[0][0]=(1/D)*mat_A[1][1];
mat_B[0][1]=(-1/D)*mat_A[0][1];
mat_B[1][0]=(-1/D)*mat_A[1][0];
mat_B[1][1]=(1/D)*mat_A[0][0];
for (int i = 0 ; i < 2 ; i++)
for (int j = 0; j < 2 ; j++)
mat_A[i][j]=mat_B[i][j];
print_Inverse();
}else {cout << "The Determinant = Zero , There is no Inverse To this Matrix"<<endl;}
}//if cond Dimention = 2


}
//end of constructor 
    private:
	short unsigned int Dimention;
	double **mat_A= new double* [Dimention];
	double **mat_B= new double* [Dimention];
	double **mat_C= new double*[2];
//////////////////////////////////////////////////////////////////
	void print_Inverse(){
	cout << "The Inverse Is :\n";
	for (int i = 0 ; i< Dimention ; i++){
	for (int  j = 0 ; j<Dimention;j++)
	cout << mat_A[i][j] <<" ";
	cout <<endl;
	}
	}
//////////////////////////////////////////////////////////////////
	void set_a(int D){
	double entry;
	for (int i = 0; i < D ;i++ ){
	cout << "Enter "<< D<< " Elements for row # "<<i+1<<endl;
	for (int j =0; j <D ;j++){
	cin >> entry;
	mat_A[i][j]=entry;
	}//end of j for
	}//end of i for 
	}
//////////////////////////////////////////////////////////////////
	double Det(){
	double firstElement=0,secondElement=0,product=1;
	int jj,ii;
	for (int i = 0 ; i < Dimention;i++){
	jj=i;ii=0;product=1;
	for (int j = 0; j<Dimention ; j++)
	{
	if (jj==Dimention){jj=0;}
	product *=mat_A[ii][jj];
	jj++;ii++;
	}firstElement+=product;}//first for 

	for (int i = Dimention-1 ; i >= 0;i--){
	jj=i;ii=0;product=1;
	for (int j = 0; j<Dimention ; j++)
	{
	if (jj<0){jj=Dimention-1;}
	product *=mat_A[ii][jj];
	jj--;ii++;
	}secondElement+=product;}//second for
	return firstElement-secondElement;
	}
//////////////////////////////////////////////////////////////////
	void transpose(){
	for (int i = 0 ;i <Dimention; i++ )
	for (int j = 0 ; j < Dimention;j++)
	mat_B[j][i]=mat_A[i][j];
	}
//////////////////////////////////////////////////////////////////
	void detOfMinorMatrix(int row,int column){
	int ii=0,jj=0;//counters to represent i and j i Matrix C
	for (int i = 0 ;i<Dimention ; i++)
	for (int j = 0 ; j<Dimention ; j++){
	if (i == row || j == column){}
	else {mat_C[ii][jj]=mat_B[i][j];if (jj==1){jj=0;ii++;}else{jj++;}	}
	}
	mat_A[row][column]=mat_C[0][0]*mat_C[1][1]-mat_C[0][1]*mat_C[1][0];
	}
//////////////////////////////////////////////////////////////////
	void coFactors(){
	int sign=1;
	for (int i = 0 ; i < Dimention; i ++)
	for (int j =0 ; j<Dimention ; j++){
	mat_A[i][j]*=sign;
	sign*=-1;
	}
	}
//////////////////////////////////////////////////////////////////
	void detMultibly(double D){
	for (int i = 0 ; i < Dimention; i++)
	for (int j =0 ; j < Dimention ; j++)
	mat_A[i][j]*=1/D;
	}
//////////////////////////////////////////////////////////////////	
};
class matrix
{               
	int rows,cols,i,j;
	float ar[3][3];
	public:
	void getmatrix();
	void display_matrix();
	void add(matrix,matrix); 
	void sub (matrix , matrix );
	void exe (int);
};
void matrix::getmatrix()
{
	cout<<"Enter the number of rows and columns of the matrix \n";
	cout <<"number of rows = ";
	cin>>rows ;
	cout << "number of columns = " ; 
	cin >> cols;
	if ( rows < 4 && cols <4 ) {
	cout<<"Enter the elements for "<<rows<<" rows and "<<cols<<" columns \n";
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++){
			cout << "element [ " << i << " ] [ " << j << " ] = " ;
			cin>>ar[i][j];}}
	else {
		cout << " invalid dimensions try again " ;
		for (long long k = 0 ; k<1000000000; k++) {}
		exit (0) ;
	}
}
void matrix::display_matrix()
{
	cout<<"The matrix = \n";
	for(int i=0;i<rows;i++)
	{
		cout<<"\n";
		for(int j=0;j<cols;j++)
			cout<<ar[i][j]<<"  ";
	}
	cout << "\n" ;
}
void matrix::add(matrix ob1,matrix ob2)
{
	if((ob1.rows!=ob2.rows)||(ob1.cols!=ob2.cols))
	{
		cout<<"Matrix addition is impossible error diffrent dimensions try again please \n";
		for (long long k = 0 ; k<1000000000; k++) {}
		exit (0) ;
	}
	else
	{
		cout<<"Addition is performed \n";
		rows=ob1.rows;
		cols=ob1.cols;
			for(int i=0;i<rows;i++)
				for(int j=0;j<cols;j++)
					ar[i][j]=ob1.ar[i][j]+ob2.ar[i][j];
	}
}

void matrix::sub (matrix ob1,matrix ob2)
{
	if((ob1.rows!=ob2.rows)||(ob1.cols!=ob2.cols))
	{
		cout<<"Matrix subtraction is impossible , error defferent dimensions . please try again ";
		for (long long k = 0 ; k<1000000000; k++) {}
		exit( 0 ) ;
	}
	else {
		cout<<"subtraction is performed \n";
		rows=ob1.rows;
		cols=ob1.cols;
		for(int i=0;i<rows;i++)
			for(int j=0;j<cols;j++)
				ar[i][j]=ob1.ar[i][j]-ob2.ar[i][j];
	}
}	

void matrix :: exe (int input) {
	matrix mat1,mat2 ,sum,sub;
	if ( input == 1 ) {
		mat1.getmatrix();
		
		mat2.getmatrix();

		sum.add(mat1,mat2);
		sum.display_matrix();
	}
	else if (input == 2 ) {

		matrix mat1,mat2,sub ;
		mat1.getmatrix();

		mat2.getmatrix();

		sub.sub (mat1,mat2);
		sub.display_matrix();
	}
}

class mulMat
{
public:
mulMat();
};
mulMat::mulMat(void)
{ 
int rows;
cout<<"enter the dimentions ";
cin>>rows;
 int i,j,k;
	double **mat1= new double* [rows];
	double **mat2= new double* [rows];
	double **mat3= new double*[rows];
for ( int i=0 ; i < rows;i++)
{
mat1[i]=new double [rows];
mat2[i]=new double [rows];
mat3[i]=new double [rows];
}
//////////////////////////////////////////////////////////////////

//user enter first mat
cout<<"enter your first mat";
for(i=0;i<rows;i++)
for(j=0;j<rows;j++){
//user enter sec mat
cout << "Enter Element ["<<i<<"]["<<j<<"]:";
cin>>mat1[i][j];
}
cout<<"enter your sec.mat";
for(i=0;i<rows;i++)
for(j=0;j<rows;j++){
cout << "Enter Element ["<<i<<"]["<<j<<"]:";
cin>>mat2[i][j];}
// code multiply
for(i=0;i<rows;i++)
for (j=0;j<rows;j++)
for (k=0;k<rows;k++)
mat3[i][j]+=mat1[i][k]*mat2[k][j];
//print mat3
for(i=0;i<rows;i++)
{
for(j=0;j<rows;j++)
{cout<<mat3[i][j];
 cout<<" ";
}
cout<<"\n";
}



}//endcons

class t {
	public:
	
	// convert time
	
	t();
	};
t::t(void){ float a;  int x; 
cout<<"please enter the number of operation\n (1) Hours->minutes \n (2) minutes->hours \n (3) minutes->seconds\n (4) seconds->hours \n (5) hours->seconds\n (6) seconds->hours \n";
 cin>>x; float y; 
	if(x==1) // convert from hour to minute
	{
		cout<<"please enter number of hours"; cin>>a; y=a*60.000; cout<<"=";cout<<y;cout<<"minutes\n";
	}
	else if (x==2) // convert from minute to hour
	{
			cout<<"please enter number of minutes"; cin>>a; y=a/60.00; cout<<"=";cout<<y;cout<<"hours\n";
	}	
	else if(x==3) // convert from minute to sec
	{ 	cout<<"please enter number of minutes"; cin>>a; y=a*60.00; cout<<"=";cout<<y;cout<<"sec.\n";
		} else if (x==4) // convert from sec to minute
		{
				cout<<"please enter number of sec"; cin>>a; y=a/60.00; cout<<"=";cout<<y;cout<<"min.\n";
		}
		else if (x==5)  // convert from hour to sec.
		{
				cout<<"please enter number of hours"; cin>>a; y=a*60*60; cout<<"=";cout<<y;cout<<"sec.\n";
		} 
		else if(x==6) // convert from sec to hours
		{
				cout<<"please enter number of sec"; cin>>a; y=a/(60.00*60.00); cout<<"=";cout<<y;cout<<"hours\n";
		}
	} //mass
	class mass
	{public:
	
	mass();	
	};
	mass::mass(void)
	{
		long  m; int h; long  v;cout<<"please enter the number of operation\n (1) tons->kg \n (2) kg->tons \n (3) kg->gm\n (4) gm->kg \n (5) tons->gm\n (6) gm->tons ";  float y; cin>>h;
		if(h==1) //convert from ton to kg
		{ cout<<"please enter number of tons"; cin>>m; v=m*1000; cout<<"=";cout<<v; cout<<"kg\n";
			} 
			if (h==2) // convert from kg to ton
			{ cout<<"please enter number of kg"; cin>>m; v=m/1000.00; cout<<"=";cout<<v; cout<<"ton\n";
				
			} 
			if (h==3) // convert from kg to gm
			{
				 cout<<"please enter number of kg"; cin>>m; v=m*1000; cout<<"=";cout<<v; cout<<"gm\n";
			}
			if (h==4) //convert from gm to kg 
			{
				 cout<<"please enter number of gm"; cin>>m; v=m/1000.00; cout<<"=";cout<<v; cout<<"kg\n";
			}
			if(h==5) //convert from ton to gm
			{
				 cout<<"please enter number of tons"; cin>>m; v=m*(1000000); cout<<"=";cout<<v; cout<<"gm\n";
			} if(h==6) // convert from gm to ton
			{
				 cout<<"please enter number of gm"; cin>>m; v=m/1000000.00; cout<<"=";cout<<v; cout<<"ton\n";
			}
	} // length
	class length
	{
		public:
		length();
	};
	length::length(void){float a; int b; float c;cout<<"please enter the number of operation\n (1) km->m \n (2) m->km \n (3) m->dm\n (4) dm->m \n (5) dm->cm\n (6) cm->dm \n (7) cm->mm \n (8) mm->cm \n (9) m->mm \n (10) mm->m\n"; cin>>b;
	if(b==1) //convert from km to m
	{
		cout<<"please enter number of km"; cin>>a; c=a*1000; cout<<"="; cout<<c; cout<<"m\n";
	}
		if(b==2) // convert from m to km
		{ cout<<"please enter number of m"; cin>>a; c=a/1000.00; cout<<"="; cout<<c; cout<<"km\n";
			}
			if(b==3) //convert from m to dm
			{
				cout<<"please enter number of m"; cin>>a; c=a*10; cout<<"="; cout<<c; cout<<"dm\n";
			}
			if(b==4) // convert from dm to m 
			{
					cout<<"please enter number of dm"; cin>>a; c=a/10.00; cout<<"="; cout<<c; cout<<"m\n";
			}
			if (b==5)// convert from dm to cm
			{
					cout<<"please enter number of dm"; cin>>a; c=a*10.00; cout<<"="; cout<<c; cout<<"cm\n";
			}
			if(b==6) // convert from cm to dm
			{
					cout<<"please enter number of cm"; cin>>a; c=a/10.00; cout<<"="; cout<<c; cout<<"dm\n";
			} 
			if(b==7)// convert from cm to mm
			{
					cout<<"please enter number of cm"; cin>>a; c=a*10; cout<<"="; cout<<c; cout<<"mm\n";
			}
			if(b==8) // convert from mm to cm
			{
					cout<<"please enter number of mm"; cin>>a; c=a/10.00; cout<<"="; cout<<c; cout<<"cm\n";
			} if(b==9)// convert from m to mm
			{
			cout<<"please enter number of m"; cin>>a; c=a*1000; cout<<"="; cout<<c; cout<<"mm\n";
			} if (b==10) // convert from mm to m 
			{cout<<"please enter number of mm"; cin>>a; c=a/1000.00; cout<<"="; cout<<c; cout<<"m\n";
				
			}
	}

class Eqn{
    private:
    
    float mix2[2][3];
    float coef2[2][2];
    float cons2[2][1];
    float x2[2][2];
    float y2[2][2];
   
    
    
    float mix3[3][4];
    float coef3[3][3];
    float cons3[3][1];
    float x3[3][3];
    float y3[3][3];
    float z3[3][3];
    
    
    float x, y, z, D, Dx, Dy, Dz;
    
     void ReplaceColoumn2( int colnumber, float a[2][2], float b[2][1])
     { int j= colnumber;
         for (int i=0; i<2; i++)
         {
             a[i][j]=b[i][0];
         }
         
     }
     
     void ReplaceColoumn3( int colnumber, float a[3][3], float b[3][1])
     { int j= colnumber;
         for (int i=0; i<3; i++)
         {
             a[i][j]=b[i][0];
         }
         
     }
    
   public:
  
   Eqn(){
       int NoOfEqn;
       cout<<"Please enter no of equations"<< endl;
       cin>> NoOfEqn;
       
       if (NoOfEqn==2){cout<<"Please enter x, y and constant of both equations"<< endl;
            
    for(int i=0; i<2; i++) //takes 2*3 numbers
    {
        for (int j=0; j<3; j++)
        {
            cin>> mix2[i][j];
        }
    }
     for (int i=0; i<2; i++) //makes coeff matrix
     {
         for (int j=0; j<2; j++)
         { 
             coef2[i][j]= mix2[i][j];
             
         }
     }
     for (int i=0; i<2; i++) //makes const matrix
     {  cons2 [i][0]= mix2 [i][2];   }
     
    
     for (int i=0; i<2; i++){ for (int j=0; j<2; j++){
     x2[i][j]=coef2[i][j];
     y2[i][j]=coef2[i][j];}} 
     
     ReplaceColoumn2( 0, x2, cons2);
     ReplaceColoumn2( 1, y2, cons2);
     Dx=TwoByTwoDeterminant( x2);
     Dy=TwoByTwoDeterminant( y2);
     D=TwoByTwoDeterminant( coef2);
     if (D==0) { cout<<"Error! Please enter different numbers";} else{
     x=Dx/D;
     y=Dy/D;
     cout<< "x="<< x<< endl<< "y=" << y<<endl;
       }}
       
       
       else if (NoOfEqn==3){cout<<"Please enter x, y, z and constant of all equations" <<endl;
       
    for(int i=0; i<3; i++) // takes 3*4 nos
    {
        for (int j=0; j<4; j++)
        {
            cin>> mix3[i][j];
            
        }
    } 
    
    
    
     for (int i=0; i<3; i++) // makes coeff matrix
     {
         for (int j=0; j<3; j++)
         { 
             coef3[i][j]= mix3[i][j];
             
         }
     }
     for (int i=0; i<3; i++)  //makes const matrix
     {  cons3 [i][0]= mix3 [i][3];   }
     
     for (int i=0; i<3; i++)
     {for(int j=0; j<3; j++){
    x3[i][j]=coef3[i][j];
    y3[i][j]=coef3[i][j];
    z3[i][j]=coef3[i][j];}}
      
    
     ReplaceColoumn3( 0, x3, cons3);
     ReplaceColoumn3( 1, y3, cons3);
     ReplaceColoumn3( 2, z3, cons3);
     
     
     Dx=ThreeByThreeDeterminant( x3);
     Dy=ThreeByThreeDeterminant( y3);
     Dz=ThreeByThreeDeterminant( z3);
     D= ThreeByThreeDeterminant( coef3);
     if (D==0){cout<<"Error! Please enter different numbers";
     } else{
     x=Dx/D;
     y=Dy/D;
     z=Dz/D;
     
     cout<< "x="<< x<< endl<< "y=" << y<<endl<<"z="<< z<< endl;
       }}
       
       
       
       
       else {cout<<"Error! Please enter 2 or 3 only";}
       
   }
   
float TwoByTwoDeterminant( float a[2][2])
{ return ((a[0][0]*a[1][1])-(a[0][1]*a[1][0])); }

float ThreeByThreeDeterminant( float a[3][3])
{ return ((a[0][0]*((a[1][1]*a[2][2])-(a[1][2]*a[2][1])))
        -(a[0][1]*((a[1][0]*a[2][2])-(a[1][2]*a[2][0])))
        +(a[0][2]*((a[1][0]*a[2][1])-(a[1][1]*a[2][0])))); }

};

int main (){
	int in ;
cout << "*for adding two matrices enter 1  \n";
	cout << "*for subtracting two matrices enter 2 \n " ;
	cout << "*for Multiplying two matrices enter 3 \n " ;
	cout << "*for finding the inverse of a  matrix enter 4 \n " ;
	cout << "*for normal operation(+ - * /)  enter 5 \n " ;
	cout << "*for finding the solution of two equations enter 6 \n " ;
	cout << "*for time conversion enter  7 \n " ;
	cout << "*for mass conversion enter  8 \n " ;
		cout << "*for length conversion enter  9 \n " ;
	cout << "";
	cout << "your choice = " ; 
	cin >> in ;
	if (in == 1 ) {//sum
	matrix sum_result;
	sum_result.exe(in);
	}
	else if ( in == 2 ) {//sub
	matrix sub_result ;
	sub_result . exe(in);
	}
	else if (in == 3)
	mulMat m;	
	else if ( in ==4)
	inverse matrix;
	else if (in == 5){
	char op;
	float num1, num2;
    cout << "Enter operator either + or - or * or /: ";
    cin >> op;
    cout << "Enter two operands: ";
    cin >> num1 >> num2;
    switch(op)
    {
        case '+':
            cout << num1+num2<<endl;
            break;

        case '-':
            cout << num1-num2<<endl;
            break;

        case '*':
            cout << num1*num2<<endl;
            break;

        case '/':
            if (num2 == 0)
            cout << "error";
            else if (num1 == 0 ) 
            cout << "0" ;
            else
            cout << num1/num2<<endl;
            break;

        default:
            // If the operator is other than +, -, * or /, error message is shown
            cout << "Error! operator is not correct\n";
            break;
    }
	}//aya
else if (in==6){
 Eqn PROJECT;
}//Salma K
else if (in==7){
t x;
}

else if (in==8){
mass m;
}
else if (in==9){
length l;
}
else 
	cout << " error \n" ;
}
