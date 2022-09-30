#include<iostream>
 
using namespace std;
 
int main()
{
int m,n,a[10][10],i,j,high,low;
cout<<"Enter no. of rows and coloumns:";
cin>>m>>n;
cout<<"\nEnter matrix:\n";
for(i=0;i<m;++i)
{
for(j=0;j<n;++j)
cin>>a[i][j];
}
 
high=a[0][0];
low=a[0][0];
for(i=0;i<m;++i)
{
for(j=0;j<n;++j)
{
if(a[i][j]>high)
high=a[i][j];
else
if(a[i][j]<low)
low=a[i][j];
}
}
cout<<"\nHeighst Element:"<<high<<"\nLowest Element:"<<low<<"\n";
 
return 0;
}







// Output

// Enter no. of rows and columns:3
// 3
// Enter matrix:
// 3 5 9
// 15 6 0
// 12 4 7
  
  
// Highest Element:15
// Lowest Element:0
