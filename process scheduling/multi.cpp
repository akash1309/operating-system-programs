#include<bits/stdc++.h>
using namespace std;
int r()
{
   return rand()%(9) + 1;
}
struct p {
  int at;
  int bt;
  int abt;
  bool done;
  int ct;
  int pid;
};
bool cmp(struct p a,struct p b)
{
   return a.at<b.at;
}
int main(){
  srand(time(0));
  cout<<"enter number of processes and time quantum for queue 1 : ";
  int n,time;
  cin>>n>>time;
  p arr[n];
  for(int i=0;i<n;i++)
  {
    arr[i].at=r();
    arr[i].bt=r();
    arr[i].abt=arr[i].bt;
    arr[i].pid=i;
    arr[i].done=false;
    arr[i].ct=0;
  }
  sort(arr,arr+n,cmp);
  int k=arr[0].at;
  for(int i=0;i<n;i++)
  {
     if(arr[i].at>k)
     {
       k=arr[i].at;
     }
     if(arr[i].abt<=time)
     {
       arr[i].ct=k+arr[i].abt;
       arr[i].done=true;
       arr[i].abt=0;
       k=arr[i].ct;
     }
     else
     {
        arr[i].ct=k+time;
        arr[i].abt=arr[i].abt-time;
        k+=time;
     }
  }
  cout<<"  ----- queue 1 ----  "<<endl;
  cout<<"pid   at   bt    ct    tat    wt "<<endl;
  int pp=n;
  for(int i=0;i<n;i++)
  {
    if(arr[i].done==true)
    {  pp--;
      int t=arr[i].ct-arr[i].at;
      int w=t-arr[i].bt;
      cout<<arr[i].pid<<" "<<arr[i].at<<" "<<arr[i].bt<<" "<<arr[i].ct<<" "<<t<<" "<<w<<endl;
    }
  }
  cout<<"\n\n\n\n";
  cout<<"enter the number of process for second queue "<<endl;
  int b;
  cin>>b;
  p brr[pp+b];
  int j=0;
  for(int i=0;i<n;i++)
  {
    if(arr[i].done==false)
    {
      brr[j].at=arr[i].at;
      brr[j].bt=arr[i].bt;
      brr[j].abt=arr[i].abt;
      brr[j].pid=i;
      brr[j].done=false;
      brr[j].ct=arr[i].ct;
      j++;
    }
  }
  for(;j<(pp+b);j++)
  {
    brr[j].at=r();
    brr[j].bt=r();
    brr[j].abt=brr[j].bt;
    brr[j].pid=j;
    brr[j].done=false;
    brr[j].ct=0;
  }
  int l=pp+b;
  sort(brr,brr+l,cmp);
  //int k=brr[0].at;
  for(int i=0;i<l;i++)
  {
     if(brr[i].at>k)
     {
       k=brr[i].at;
     }
     brr[i].ct= k+brr[i].abt;
     k=brr[i].ct;
     brr[i].done=true;
  }
  cout<<"  ----- queue 2 ----  "<<endl;
  cout<<"pid   at   bt    ct    tat    wt "<<endl;
  for(int i=0;i<l;i++)
  {
    if(brr[i].done==true)
    {
      int t=brr[i].ct-brr[i].at;
      int w=t-brr[i].bt;
      cout<<brr[i].pid<<" "<<brr[i].at<<" "<<brr[i].bt<<" "<<brr[i].ct<<" "<<t<<" "<<w<<endl;
    }
  }
}
