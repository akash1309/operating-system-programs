#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
bool visited[10000];
void dfs(int s,int &sett)
{
   if(!visited[s])
   { //cout<<s<<" ";
     visited[s]=true;
     for(int i=0;i<v[s].size();i++)
     {
       dfs(v[s][i],sett);
     }
   }
   else
    { sett = 1;
      return;
     }
}
int main()
{
  cout<<"Enter the number of processes and resources : ";
  int p,r;
  cin>>p>>r;
  //vector<int>v[p+r+1];
  cout<<"Enter the total number of edges : ";
  int edges;
  cin>>edges;

  for(int i=0;i<edges;i++)
  { cout<<"enter the egde "<<i<<" : ";
    int x,y;
    cin>>x>>y;
    cout<<"Is it assignment or request edge ? ( 0 -assignment , 1 - request )  : ";
    int ch;
    cin>>ch;
    if(ch==0)
    {
      v[p+y].push_back(x);
    }
    if(ch==1)
    {
      v[x].push_back(p+y);
    }
  }
  cout<<" request edges : "<<endl;
  cout<<"process    Resource"<<endl;
  for(int i=0;i<p;i++)
  {
    if(!v[i].empty())
    { //cout<< i <<" : ";
      for(int j=0;j<v[i].size();j++)
      {
        cout<<i<<"    "<<v[i][j]-p<<endl;
      }
      //cout<<endl;
    }
  }
  cout<<" assignment edges : "<<endl;
  cout<<"process    Resource"<<endl;
  for(int i=p;i<=(p+r);i++)
  {
    if(!v[i].empty())
    { //cout<< i <<" : ";
      for(int j=0;j<v[i].size();j++)
      {
      cout<<v[i][j]<<"    "<<i-p<<endl;
      }
      //cout<<endl;
    }
  }
   //bool visited[p+r];
   int sett=0;
   for(int i=0;i<p;i++)
   {
     for(int j=0;j<(p+r);j++)
      {visited[j]=false;}


      dfs(i,sett);
      if(sett==1)
       break;

   }
   if(sett==1)
   { cout<<"Cycle detected "<<endl;
    }
   else
   {
     cout<<" No Cycle detected "<<endl;
   }

}
