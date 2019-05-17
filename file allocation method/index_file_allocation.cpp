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
  for(int i=0;i<1000;i++)
   arr[i]=false;

  for(int i=0;i<n;i++)
  { int index_block;
    cout<<"enter the index block for file "<<i<<" : ";
    cin>>index_block;
    int size=r(10,1);
    set<int>v;
    if(arr[index_block])
    {
      cout<<"file "<<i<<" cannot be allocated memory address for index block "<<endl;
      continue;
    }
    else
    {   v.insert(index_block);
        int k=0;
        while(v.size()!=size)
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
        if(v.size()==size)
        { cout<<"Allocated blocks for file "<<i<<" are ";
          for(set<int>::iterator j=v.begin();j!=v.end();j++)
           {
             arr[*j]=true;
             cout<<(*j)<<" ";
           }
           cout<<endl;
        }
     }
  }
}
