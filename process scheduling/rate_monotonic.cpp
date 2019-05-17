#include<bits/stdc++.h>
using namespace std;
struct p{
  int pid;
  int remtime;
  int bt;
  int deadline;
  int appear;
};
bool cmp(struct p a,struct p b)
{
  return a.deadline<b.deadline;
}
bool isSchedule(struct p arr[],int n)
{   float a=0.0,b=0.0;
    for(int i=0;i<n;i++)
    {
      a=a+ (float)arr[i].bt/(float)arr[i].deadline;
    }
    b= (float)n*(pow(2,1.0/(float)n)-1);
    if(a<b)
     return true;
    return false;
}
int main()
{
  int n;
  cin>>n;
  p arr[n];
  for(int i=0;i<n;i++)
  {
     cin>>arr[i].bt;
     cin>>arr[i].deadline;
     arr[i].appear=1;
     arr[i].pid=i;
     arr[i].remtime=arr[i].bt;
  }
  if(!isSchedule(arr,n))
  {
     cout<<"NOT Schedulable"<<endl;
  }
  else
  {  cout<<"time and process "<<endl;
     int time=1;
     while(time<500)
     {  sort(arr,arr+n,cmp);
        int y=-1;
        for(int i=0;i<n;i++)
        {
           if(arr[i].appear==1)
           {
              y=i;
              break;
           }

        }
        if(y == -1)
         cout<<time<<"  --- "<<endl;
        else
        {
          cout<<time<<"   "<<y+1<<endl;
          arr[y].remtime--;
          if(arr[y].remtime == 0)
          {
             arr[y].appear =0;
          }
        }
        for(int i=0;i<n;i++)
        {
           if(time%arr[i].deadline == 0)
           {
              arr[i].appear=1;
              arr[i].remtime=arr[i].bt;
           }
        }
        time++;
     }
  }
}
