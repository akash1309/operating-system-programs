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
  srand(time(0));
  int n;
  cout<<"Enter the number of processes : ";
  cin>>n;
  pair<int, pair<int, pair<int,int> > >p[n];
  int ct[n];
  bool done[n];
  int burst[n];
  for(int i=0;i<n;i++)
  {   int pid,at,bt,pri;
    ct[i]=0;
    done[i]=false;
    pid=i;
  /*  at=r();
    bt=r();
    pri=r();*/
    //int at,bt,pri;
    cin>>at>>bt>>pri;
    burst[i]=bt;
    p[i].first=at;
    p[i].second.first=pid;
    p[i].second.second.first=bt;
    p[i].second.second.second=pri;
    //p[i]= make_pair(at, make_pair(pid, make_pair(bt,pri)));
  }
  sort(p,p+n);
  int k=p[0].first;
  while(!isdone(done,n))
  {
    int pid=-1;
    int p_index=-1;
    int pri=INT_MIN;
    int i;
    for(i=0;i<n && p[i].first<=k;i++)
    {
      if(done[p[i].second.first])
       continue;
      if(p[i].second.second.second > pri)
      {
        p_index=i;
        pid=p[i].second.first;
        pri=p[i].second.second.second;
      }
    }
    if(pid== -1 && i<n)
    {
      p_index=i;
    }
    if(p_index!= -1)
    {   ct[p[p_index].second.first]=k+1;
        p[p_index].second.second.first=p[p_index].second.second.first-1;
        if(p[p_index].second.second.first == 0)
         done[p[p_index].second.first]=true;
    }
    k++;
  }

  cout<<"pid   at     bt    ct    tat    wt    prioriy"<<endl;
  for(int i=0;i<n;i++)
  { int turn=ct[p[i].second.first]-p[i].first;
    cout<< p[i].second.first<<"     "<<p[i].first<<"      "<< burst[p[i].second.first] <<"      "<<ct[p[i].second.first]<<"     "<<turn<<"      "<<turn-burst[p[i].second.first]<<"     "<<p[i].second.second.second<<endl;
  }


}
