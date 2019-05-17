#include<bits/stdc++.h>
using namespace std;
int r()
{
  return rand()%(9)+1;
}
bool isdone(bool done[],int n)
{
  for(int i=0;i<n;i++)
  {
    if(done[i]==false)
     return false;
  }
  return true;
}
int main()
{
  int n;
  srand(time(0));
  cout<<"Enter the number of processes : ";
  cin>>n;
  int ct[n];
  bool done[n];
  pair<int,pair<int, pair<int,int> > >p[n];
  for(int i=0;i<n;i++)
  { done[i]=false;
    int pid=i;
    int at=r();
    int bt=r();
    int pri=r();
    //int at,bt,pri;
    //cin>>at>>bt>>pri;
    p[i].first=at;
    p[i].second.first=pid;
    p[i].second.second.first=bt;
    p[i].second.second.second=pri;
  }
  sort(p,p+n);
  int k=p[0].first;
  ct[p[0].second.first]=k+p[0].second.second.first;
  k=ct[p[0].second.first];
  done[p[0].second.first]=true;
  while(!isdone(done,n))
  { int pri=INT_MIN;
    int pid=-1;
    int p_index=-1;
    int j;
    for(j=0;j<n && p[j].first<=k;j++)
    {
      if(done[p[j].second.first])
       continue;
      if(p[j].second.second.second > pri)
      {
        pri=p[j].second.second.second;
        p_index=j;
        pid=p[j].second.first;
      }

    }
    if(pid== -1 && j<n)
    {
      p_index=j;
      k=p[p_index].first;
    }
    ct[p[p_index].second.first]=k+p[p_index].second.second.first;
    k=ct[p[p_index].second.first];
    done[p[p_index].second.first]=true;
  }

  cout<<"pid   at     bt    ct    tat    wt    prioriy"<<endl;
  for(int i=0;i<n;i++)
  { int turn=ct[p[i].second.first]-p[i].first;
    cout<< p[i].second.first<<"     "<<p[i].first<<"      "<< p[i].second.second.first <<"      "<<ct[p[i].second.first]<<"     "<<turn<<"      "<<turn-p[i].second.second.first<<"     "<<p[i].second.second.second<<endl;
  }
}
