#include<bits/stdc++.h>
using namespace std;
int r(int l,int h)
{
  return rand()%(h-l+1)+l;
}
void bestFit(int blockSize[],int processSize[], int n)
{
    int allocation[n];
    int m[n];
    for(int i=0;i<n;i++)
    {
      m[i]=blockSize[i];
    }
    memset(allocation, -1, sizeof(allocation));
    for (int i=0; i<n; i++)
    {
        int bestIdx = -1;
        for (int j=0; j<n; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t"<<m[i]<<"\t\t";
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

    bestFit(blocks,process_size,n);

    return 0 ;
}
