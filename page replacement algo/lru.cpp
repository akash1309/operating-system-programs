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
  int pagefaults=0;
  for(int i=0;i<len;i++)
  { cout<<"enter page : ";
    int x;
    cin>>x;
    if(m.find(x)==m.end())
    {
      if(m.size() == n)
      {
        int last=l.back();
        l.pop_back();
        m.erase(last);
      }
      pagefaults++;
    }
    else
    {
       l.erase(m[x]);
    }
    l.push_front(x);
    m[x]=l.begin();


    cout<<"queue : ";
    for(list<int>:: iterator it=l.begin();it!=l.end();it++)
    {
      cout<<(*it)<<" ";
    }
    cout<<endl;
  }
  cout<<"total pagefaults : "<<pagefaults<<endl;
}
