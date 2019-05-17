#include<bits/stdc++.h>
using namespace std;
int r()
{
  return rand()%(20)+1;
}
int compare(pair<int,pair<int,int> >p,pair<int,pair<int,int> >q)
{
  if(p.first==q.first)
  {
    return p.second.second<q.second.second;
  }
  return p.first<q.first;
}
int main()
{
  int n;
  srand(time(0));
  cout<<"enter the number of processes :";
  cin>>n;
  pair<int,pair<int,int> >p[n];
  int pid,at,bt;
  bool done[n];
  for(int i=0;i<n;i++)
  { done[i]=false;
    pid=i;
  //  at=r();
  //  bt=r();
    cin>>at>>bt;
    p[i] = make_pair(at, make_pair(pid, bt));
  }
  sort(p,p+n,compare);
  int ct[n];
  done[p[0].second.first]=true;
  ct[p[0].second.first]= p[0].first+p[0].second.second;
  int k=ct[p[0].second.first];
  for(int i=1;i<n;i++)
  {   pid=-1;
      int burst=1000;
      int p_index=-1;
      int j;
     for(j=0;j<n && p[j].first<= k;j++)
     {
       if(done[p[j].second.first])
        continue;
       if(p[j].second.second<burst)
       { p_index=j;
         pid=p[j].second.first;
         burst=p[i].second.second;
       }

     }
     if(pid==-1 && j<n)
     {
       p_index=j;
       k=p[p_index].first;
     }
     if(pid== -1 && j==n)
      break;
     ct[p[p_index].second.first]=k+p[p_index].second.second;
     k=ct[p[p_index].second.first];
     done[p[p_index].second.first]=true;
   }

   cout<<"pid   at   bt   ct   tat   wt"<<endl;
   for(int i=0;i<n;i++)
   { int turn=ct[p[i].second.first]-p[i].first;
     cout<<p[i].second.first<<"    "<<p[i].first<<"    "<< p[i].second.second <<"    "<<ct[p[i].second.first]<<"    "<<turn<<"    "<<turn-p[i].second.second<<endl;
   }
}
