#include<iostream>

using namespace std;
void rowcol(int[][10],int[][10],int,int);

int det(int arr[][10],int n)
{
    int cofact[10][10];
    if(n==2)
        return (arr[0][0]*arr[1][1])-(arr[0][1]*arr[1][0]);
    else
    {
        int c,d=0,flg=1;
        for(c=0;c<n;c++)
        {
            int subi=0;
            for(int i=1;i<n;i++)
            {
                int subj=0;
                for(int j=0;j<n;j++)
                {
                    if((j==c))
                        continue;
                    cofact[subi][subj]=arr[i][j];
                    subj++;
                }
                subi++;
            }

            d=d+(flg*arr[0][c]*det(cofact,n-1));
            flg*=-1;
        }

        return d;
    }
    

}




int main()
{
    int n,val;
    int arr[10][10];
    cout<<"Enter the size of matrix:";
    cin>>n;
    cout<<"\nEnter the array elements row by row";
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Row "<<i<<":";
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    val=det(arr,n);
    cout<<"\nThe determinant of given matrix is:"<<val;

    return 0;
}

