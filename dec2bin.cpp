#include<iostream>
#include<math.h>
using namespace std;


void dec2bin(float dec)
{
int i;
float f;

f=dec;
while(f!=1.0)
  {
    f=dec*2;
    i=f;
    cout<<i;
    dec=fmodf(f,1);
  }

}
