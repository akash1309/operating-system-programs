#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;

	cout<<"Enter number of processes : ";
	cin>>n;
	cout<<"Enter number of memory chunks available: ";
	cin>>m;

	int proc[n];
	int size;

	int sum = 0;
	cout<<endl;
	cout<<"Enter memory requirements for each of the process: ";
	for(int i=0;i<n;i++)
	cin>>proc[i];
	cout<<"Enter the amount of each chunk available: ";
    cin>>size;
	int blockSize[m];
  bool allocated[m];
  for(int i=0;i<m;i++)
  {
    blockSize[i]=size;
    allocated[i]=false;
  }
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
    {
      if(blockSize[j]>= proc[i] && allocated[j]==false)
      {
        blockSize[j]-=proc[i];
        allocated[j]=false;
        sum+=blockSize[j];
        break;
      }
    }

	}
	cout<<endl;
	cout<<"The amount of internal fragmentation is: "<<sum<<endl;
}
