#include<bits/stdc++.h>
using namespace std;
int r(){
  return rand()%(9)+1;
}
int main()
{
  cout<<"enter the number of processes : ";
  int n;
  cin>>n;
  srand(time(0));
  pair<int,pair<int,int> >p[n];
  int pid,at,bt;
  for(int i=0;i<n;i++)
  {
    pid=i;
    at=r();
    bt=r();
    //cin>>at>>bt;
    p[i]= make_pair(at,make_pair(pid,bt));
  }
  sort(p,p+n);
  int ct[n];
  int k=p[0].first;
  for(int i=0;i<n;i++)
  { if(k< p[i].first)
     {k=p[i].first;}
    ct[p[i].second.first]=k+p[i].second.second;
    k=ct[p[i].second.first];
  }
  cout<<"pid   at   bt   ct   tat   wt"<<endl;
  for(int i=0;i<n;i++)
  { int turn=ct[p[i].second.first]-p[i].first;
    cout<<p[i].second.first<<"    "<<p[i].first<<"    "<< p[i].second.second <<"    "<<ct[p[i].second.first]<<"    "<<turn<<"    "<<turn-p[i].second.second<<endl;
  }
}
