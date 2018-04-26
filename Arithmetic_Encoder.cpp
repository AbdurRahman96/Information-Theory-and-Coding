// This is an Arithmetic encoder which transmits streams of constant size///////
/// This file requires dec2bin file to execute. Download it too

 // Author: Abdur Rahman Mohamed Ismail

 ///////////////////////////////////////////////




#include<iostream>

using namespace std;


int main()
{
 void dec2bin(float );
  const int inle=4;
 int num;
 int tem;
 float in=0,dec;
char inp[4];
  
 cout<<"Enter the number of available symbols in dictionary";
 cin>>num; 

 float q[num],lb[num],ub[num],wi[num],pr[num];
 char sy[num]; 
 cout<<"Enter the symbols and corresponding probablity";
 for(int i=0;i<num;i++)
   {
     cin>>sy[i];    
     cin>>pr[i];
     }
 
  cout<<"Enter the input stream:";
for(int i=0;i<inle;i++)
  { cin>>inp[i];
  }

  
 for(int j=0;j<num;j++)
   {
     q[j]=in;
     in=in+pr[j];
    
   }
 lb[0]=0;
 ub[0]=1;
 wi[0]=1;

 for(int i=1;i<inle+1;i++)
   {
      for (int k=0;k<num;k++)
       {
	 if (sy[k]==inp[i-1])
		  { tem=k; }
         }
     
                        lb[i]=lb[i-1]+ wi[i-1]*q[tem];
		     	wi[i]=pr[tem]* wi[i-1];
	                ub[i]=lb[i]+wi[i];
			cout<<endl;
		            
		     
}

 cout<<"The lower limit is:"<< lb[inle]<<endl;
 cout<<"The upper limit is:"<<ub[inle]<<endl;  
 cout<< "The code word is:"<< (lb[inle]+ub[inle])/2<<endl;
 dec=(lb[inle]+ub[inle])/(2.0);
 dec2bin(dec);
 
 
 return 0; 

 

}

 

 

