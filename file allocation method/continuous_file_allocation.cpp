#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout<<"Enter the number of files : ";
  cin>>n;
  bool arr[1000];
  for(int i=0;i<1000;i++)
   arr[i]=false;

  for(int i=0;i<n;i++)
  { int start,length;
    cout<<" Enter the starting address and length  for file "<<i<<endl;
    cin>>start>>length;
    int set=0;
    for(int j=start;j<=(start+length);j++)
    {
      if(arr[j]==true)
       { set=1;
         cout<<"file "<<j<<" cannot be allocated the memory space from "<<start<< " to "<<start+length<<endl;
         break;
       }
    }
    if(set==0)
    {
      for(int j=start;j<(start+length);j++)
       {
         arr[j]=true;
       }
       cout<<"file "<<i<<" is allocated memory space from "<<start<<" to "<<start+length<<endl;
    }
  }
}
