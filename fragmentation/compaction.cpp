#include<bits/stdc++.h>
using namespace std;
bool arr[100000];
pair<int,int>p[100000];
void reset()
{
  for(int i=0;i<100000;i++)
   arr[i]=false;
}
void print(int n)
{
  for(int i=0;i<=n;i++)
  {
    cout<<"Process "<<i<<" : "<<p[i].first<<" to "<<p[i].second<<endl;
  }
}
void compaction(int n)
{
   reset();
   int start=0;
   for(int i=0;i<=n;i++)
   {
      int s=p[i].first;
      int e=p[i].second;
      p[i].first=start;
     //  start=e-s;
      p[i].second=start+e-s;
      start=p[i].second+1;
   }
   for(int i=0;i<start;i++)
    arr[i]=true;
}
int main()
{
  int n;
  cout<<"Enter the number of process : ";
  cin>>n;
  //pair<int,int>p[n];
  for(int i=0;i<n;i++)
  { int s,e;
    cout<<"Enter the starting and ending block of process "<<i<<" : ";
    cin>>s>>e;
    int set=0;
    p[i].first=s;
    p[i].second=e;
    for(int j=s;j<=e;j++)
    {
      if(arr[j]==true)
      { set=1;
        cout<<" Before compaction \n"<<endl;
        print(i);
        compaction(i);
        cout<<" After compaction \n"<<endl;
        break;
      }
    }
    if(set==0)
    {
      for(int j=s;j<=e;j++)
        arr[j]=true;
    }
    print(i);
    cout<<"<------------------------------->\n"<<endl;
  }
  cout<<" After compaction \n"<<endl;
  compaction(n-1);
  print(n-1);
}
