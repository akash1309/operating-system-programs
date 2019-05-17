#include<bits/stdc++.h>
using namespace std;
int r(int h,int l)
{
  return rand()%(h-l+1)+l;
}
int main()
{
  srand(time(0));
  int n;
  cout<<"Enter the number of files : ";
  cin>>n;
  bool arr[1000];
  int next[1000];
  for(int i=0;i<1000;i++)
   { arr[i]=false;
     next[i]=-1;
   }

  for(int i=0;i<n;i++)
  { int start,end;
    cout<<"enter the starting and ending block for file "<<i<<" : ";
    cin>>start>>end;
    int size=r(10,1);
    set<int>v;
    if(arr[start] || arr[end])
    {
      cout<<"file "<<i<<" cannot be allocated memory address for index block "<<endl;
      continue;
    }
    else
    {  // v.insert(start);
      //  v.insert(end);
        int k=0;
        while(v.size()!=(size-2))
        {  if(k>10000)
            {
                 cout<<"file "<<i<<" cannot be allocated memory address for index block "<<endl;
                 break;
            }
           int block=rand()%(999)+1;
           if(!arr[block])
           {
             v.insert(block);
           }
           else
            {  k++; }
        }
        if(v.size()==(size-2))
        { cout<<"Allocated blocks for file "<<i<<" are "<<start<<" ";
          int pre=start;
          for(set<int>::iterator j=v.begin();j!=v.end();j++)
           {
             arr[*j]=true;
             //cout<<(*j)<<" ";
             next[pre]=(*j);
             pre=(*j);
           }
           arr[start]=true;
           arr[end]=true;
           next[pre]=end;
           pre=end;
           next[pre]=-1;
           pre=start;
           while(next[pre]!=-1)
           {
             cout<<next[pre]<<" ";
             pre=next[pre];
           }
           cout<<endl;
        }
     }
  }
}
