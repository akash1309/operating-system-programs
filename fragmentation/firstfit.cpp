#include<bits/stdc++.h>
using namespace std;
int r(int l,int h)
{
  return rand()%(h-l+1)+l;
}
void firstFit(int blockSize[],int processSize[], int n)
{
    int allocation[n];
    int p[n];
    for(int i=0;i<n;i++)
     p[i]=blockSize[i];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlockSize\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t"<< processSize[i] << "\t\t" << p[i]<< "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }

    int external=0;
    for(int i=0;i<n;i++)
    {
        external+=blockSize[i];
    }
    cout<<endl;
    //cout<<"internal fragmentation : "<<internal<<endl;
    cout<<"external fragmentation : "<<external<<endl;
}

int main()
{
  int n;
  cout<<"Enter the number of processes : ";
  cin>>n;
  srand(time(0));
  int blocks[n];
  int process_size[n];
  for(int i=0;i<n;i++)
  {
    blocks[i]=r(100,500);
    process_size[i]=r(100,500);
  }
  firstFit(blocks,process_size,n);

}
