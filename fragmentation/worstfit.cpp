#include<bits/stdc++.h>
using namespace std;
int r(int l,int h)
{
  return rand()%(h-l+1)+l;
}
void worstFit(int blocks[],int process_size[], int n)
{
    int allocation[n];
    int m[n];
    for(int i=0;i<n;i++)
    {
      m[i]=blocks[i];
    }
    memset(allocation, -1, sizeof(allocation));
    for (int i=0; i<n; i++)
    {
        int index = -1;
        for (int j=0; j<n; j++)
        {
            if (blocks[j] >= process_size[i])
            {
                if (index == -1)
                    index = j;
                else if (blocks[index] < blocks[j])
                    index = j;
            }
        }

        if (index != -1)
        {
            allocation[i] = index;
            blocks[index] -= process_size[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << process_size[i] << "\t\t"<<m[i]<<"\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }

    int external=0;
    for(int i=0;i<n;i++)
    {
        external+=blocks[i];
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

    worstFit(blocks,process_size,n);

    return 0 ;
}
