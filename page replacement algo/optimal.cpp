#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout<<"Enter the number of frames : ";
  cin>>n;
  list<int>l;
  map<int,list<int>::iterator > m;
  int len;
  cout<<"Enter the length of reference pages length : ";
  cin>>len;
  int arr[len];
  cout<<"enter reference string : ";
  for(int i=0;i<len;i++)
  {
    cin>>arr[i];
  }
  int pagefaults=0;
  for(int i=0;i<len;i++)
  {
    if(m.find(arr[i])==m.end())
    {
      if(m.size()==n)
      { int seq=1;
        map<int,int> temp;
        for(map<int,list<int>::iterator >::iterator it=m.begin();it!=m.end();it++)
        {
          temp[it->first]++;
        }
        for(map<int,int>::iterator it=temp.begin();it!=temp.end();it++)
        {
          it->second = INT_MAX;
        }
        for(int j=i+1;j<len;j++)
        {
          if(temp.find(arr[j])!=temp.end())
          { if(temp[arr[j]] != INT_MAX)
             continue;
            temp[arr[j]]=seq;
            seq++;
          }
        }
        pair<int,int>p= make_pair(-1,-1);
        for(map<int,int>::iterator it=temp.begin();it!=temp.end();it++)
        {
          if(p.second < it->second){
            p.second=it->second;
            p.first= it->first;
          }
        }
        l.erase(m[p.first]);
        m.erase(p.first);
      }
      l.push_front(arr[i]);
      m[arr[i]]=l.begin();
      pagefaults++;
    }

    cout<<"queue : ";
    for(list<int>:: iterator it=l.begin();it!=l.end();it++)
    {
      cout<<(*it)<<" ";
    }
    cout<<endl;
  }
   cout<<"total pagefaults : "<<pagefaults<<endl;

}
