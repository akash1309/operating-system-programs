#include<bits/stdc++.h>
using namespace std;
bool isdone(bool done[],int n)
{
  for(int i=0;i<n;i++)
  {
    if(done[i]==false)
     return false;
  }
  return true;
}
bool cmp(pair<int,pair<int,int> >p, pair<int,pair<int,int> >q)
{
    if(p.first == q.first)
    {
        return p.second.second < q.second.second;
    }
    return p.first<q.first;
}
int main()
{
   int n,time;
   cout<<"Enter the number of processes and time quantum : ";
   //cout<<"S";
   cin>>n>>time;
   pair<int,pair<int,int> >p[n];
   int ct[n];
   int burst[n];
   bool done[n];
   //cout<<"Sa";
   for(int i=0;i<n;i++)
   {
     //cout<<"hey";
     int at,bt;
     int pid=i;
     //at=r();S
     //bt=r();
     cin>>at>>bt;
     burst[i]=bt;
     done[i]=false;
     p[i].first=at;
     p[i].second.first=pid;
     p[i].second.second=bt;
   }
   //cout<<"gk";
   sort(p,p+n,cmp);
   for(int i=0;i<n;i++)
   {
       cout<<p[i].second.first<<"  "<<p[i].first<<"  "<<p[i].second.second<<endl;
   }
   queue<int>q;
   int k=p[0].first;
   q.push(0);
   int index=0;
   int top;
   while(!isdone(done,n))
   {
       while(!q.empty())
       {
         top=q.front();
         q.pop();
         if(!done[p[top].second.first])
          {  if(p[top].second.second > time)
             {
               p[top].second.second = p[top].second.second - time;
               cout<<"process "<<p[top].second.first+1<<" runs from "<<k<<" to "<<k+time<<endl;
               k+=time;
             }
             else
             {  cout<<"process "<<p[top].second.first+1<<" runs from "<<k<<" to "<<k+p[top].second.second<<endl;

                 k+=p[top].second.second;
                p[top].second.second=0;
                ct[p[top].second.first]=k;
                done[p[top].second.first]=true;

             }
          }
          int j;
          for(j=index;j<n && p[j].first <=k;j++)
           { if(j==top)
              continue;
             q.push(j);
            }
          if(done[p[top].second.first]==false)
             q.push(top);
        index=j;
       }
       int j;
       for(j=index;j<n && p[j].first <=k;j++)
       { if(j==top || done[p[j].second.first])
          continue;
         q.push(j);
       }
       if(done[p[top].second.first]==false)
         q.push(top);
       index=j;
       if(q.empty()==true)
        {k++;}
      // cout<<k<<endl;
   }
   cout<<endl;
   cout<<"pid   at   bt   ct  tat  wt"<<endl;
   for(int i=0;i<n;i++)
   { int turn=ct[p[i].second.first]-p[i].first;
     int wt=turn-burst[p[i].second.first];
     cout<<p[i].second.first<<"     "<<p[i].first<<"    "<<burst[p[i].second.first]<<"    "<<ct[p[i].second.first]<<"   "<<turn<<"   "<<wt<<endl;
   }
}
