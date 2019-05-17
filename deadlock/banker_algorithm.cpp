#include<bits/stdc++.h>
using namespace std;
int maximum[1000][1000],allocated[1000][1000];
bool done[1000];
int p,r;
int need[1000][1000];
int available[1000];
int request[1000];
bool isdone()
{
  for(int i=0;i<p;i++)
  {
    if(done[i]==false)
     return false;
  }
  return true;
}
void safe_sequence()
{
  vector<int>ans;
  int counter=0;
  int flag=0;
  while(!isdone())
  {
    if(counter>10000)
     { flag=1;
       break;
     }
    for(int i=0;i<p;i++)
    { int set=0;
      if(done[i]==false)
      {
          for(int j=0;j<r;j++)
          {
              if(need[i][j] > available[j])
               {
                 set=1;
                 break;
               }
          }
          if(set==0)
          {
              for(int j=0;j<r;j++)
              {
                available[j]+=allocated[i][j];

              }
              ans.push_back(i);
              done[i]=true;
          }
      }
    }
    counter++;
  }
  if(flag==1)
  {
    cout<<"No safe sequence exists "<<endl;
  }
   else
   { for(int i=0;i<ans.size();i++)
     cout<<ans[i]<<" ";
     cout<<endl;
   }

}
int main()
{

  cout<<"Enter the number of process and resources : ";
  cin>>p>>r;


  cout<<"maximum allocation matrix "<<endl;
  for(int i=0;i<p;i++)
  { done[i]=false;
    for(int j=0;j<r;j++)
    {
      cin>>maximum[i][j];
    }
  }
  cout<<"allocated resource matrix "<<endl;
  for(int i=0;i<p;i++)
  {
    for(int j=0;j<r;j++)
    {
      cin>>allocated[i][j];
    }
  }

  for(int i=0;i<p;i++)
  {
    for(int j=0;j<r;j++)
    {
      need[i][j]=maximum[i][j]-allocated[i][j];
    }
  }
  cout<<" available resource "<<endl;

  for(int i=0;i<r;i++)
   {cin>>available[i];
   }
   safe_sequence();

   cout<<" enter process id and resource request "<<endl;
   int pid;
   cin>>pid;
   for(int i=0;i<r;i++)
    {
      cin>>request[i];
    }
    for(int i=0;i<r;i++)
    {
      if(request[i]<=need[pid][i])
      {
        if(request[i]<=available[i])
        { //cout<<"dfg"<<endl;
          available[i]=available[i] - request[i];
          allocated[pid][i]=allocated[pid][i] + request[i];
          need[pid][i]=need[pid][i] - request[i];
        }
      }
    }
    for(int i=0;i<p;i++)
     done[i]=false;
    safe_sequence();
}
