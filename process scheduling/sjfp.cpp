#include<bits/stdc++.h>
using namespace std;
int r()
{
  return rand()%(10)+1;
}
bool isDONE(bool done[],int n)
{
  for(int i=0;i<n;i++)
  {
    if(done[i]==false)
     return false;
  }
  return true;
}
int compare(pair<int,pair<int,pair<int,int> > >p,pair<int,pair<int,pair<int,int> > >q)
{
  if(p.first==q.first)
  {
    return p.second.second.first<q.second.second.first;
  }
  return p.first<q.first;
}
int main()
{
  int n;
  srand(time(0));
  cout<<"enter the number of processes :";
  cin>>n;
  pair<int,pair<int,pair<int,int> > >p[n];
  int pid,at,bt;
  bool done[n];
  int ct[n];
  for(int i=0;i<n;i++)
  { done[i]=false;
    ct[i]=0;
    pid=i;
    at=r();
    bt=r();
  //  cin>>at>>bt;
    p[i] = make_pair(at, make_pair(pid,make_pair(bt,bt)));
  }
  sort(p,p+n,compare);

/*  cout<<"pid   at    bt"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<p[i].second.first<<" "<<p[i].first<<" "<<p[i].second.second<<endl;
  }
*/
  int k=p[0].first;
  while(!isDONE(done,n))
  {  //cout<<k<<endl;
     int burst=INT_MAX;
     int p_index=-1;
     int j;
    for(j=0;j<n && p[j].first<=k;j++)
    {
      if(done[p[j].second.first])
       continue;

      if(p[j].second.second.first < burst)
      {
        burst=p[j].second.second.first;
        p_index=j;
      }
    }
    if(p_index== -1  && j<n)
     {
       p_index=j;
    //   k=p[p_index].first;
     }
    if(p_index!= -1)
     { ct[p[p_index].second.first]=k+1;
       p[p_index].second.second.first= p[p_index].second.second.first-1;
       if(p[p_index].second.second.first == 0)
        {
          done[p[p_index].second.first]=true;
        }
     }
    k++;


  }

   cout<<"pid   at   bt   ct   tat   wt"<<endl;
   for(int i=0;i<n;i++)
   { int turn=ct[p[i].second.first]-p[i].first;
     cout<<p[i].second.first<<"    "<<p[i].first<<"    "<< p[i].second.second.second <<"    "<<ct[p[i].second.first]<<"    "<<turn<<"    "<<turn-p[i].second.second.second<<endl;
   }
}
