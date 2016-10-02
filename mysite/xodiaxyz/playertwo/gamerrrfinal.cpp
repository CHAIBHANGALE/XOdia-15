#include<iostream>
using namespace std;
int main()
{  int i,j,k;
  char s[3600];
 cin>>s;
 char array[20][20][9];
  for(i=0;i<20;i++)
 {
   for(j=0;j<20;j++)
   {
     for(k=0;k<9;k++)
      {
       array[i][j][k]=s[i*9*20+j*9+k];
     }
   }
 }
     
  //your code to grow

 //for first move
  cout<<"0,0,1,1";
  //where (i1,j1)(i2,j2) are coordinates of the seed and leaf

 //for the rest of the moves
// cout<<i1<<","<<j1<<","<<i2<<","<<j2<<","<<i3<<","<<j3;
  //where (i1,j2)(i2,j2)(i3,j3) are coordinates of the seed and leaves

}
