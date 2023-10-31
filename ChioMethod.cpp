#include <iostream>
#include <cmath>
using namespace std;

template <size_t size_x, size_t size_y>
void printMatrix(int (&arr)[size_x][size_y])
{
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

template <size_t size_x, size_t size_y>
void copyMatrix(int (&to)[size_x][size_x],int (&from)[size_y][size_y]){
    for(int i=0;i<size_x;i++){
        for(int j=0;j<size_x;j++){
            to[i][j]=from[i][j];
        }
    }
}


template <size_t size_x, size_t size_y>
int calculateDeterminant(int (&arr)[size_x][size_y])
{
    int copy[size_x][size_x];

    //copyMatrix(copy,arr);
    
    for(int i=0;i<size_x;i++){
        for(int j=0;j<size_x;j++){
            copy[i][j]=arr[i][j];
        }
    }

    printMatrix(copy);
    int n=size_x;
    long double factor=1;
    while (n>2)
    {
        
        if(copy[0][0]==0){
            int index=0;
            for(int i=0;i<n-1;i++){
                for(int j=0;j<n-1;j++){
                    if(copy[i][j]!=0){
                        if(j!=0){
                            for(int k=0;k<n-1;k++){
                                int a=copy[0][0];
                            }
                        }
                    }
                }
            }
        }

        factor *= (1/pow(copy[0][0],n-2));

        int tmp[n-1][n-1];
        for(int j=1;j<n;j++){
            for(int k=1;k<n;k++){
                int a=copy[0][0];
                int b=copy[0][k];
                int c=copy[j][0];
                int d=copy[j][k];
                tmp[j-1][k-1]=(a*d - b*c);
            }
            
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                copy[i][j]=tmp[i][j];
            }
        }
        printMatrix(copy);
        n--;
    }
    return (copy[0][0]*copy[1][1] -copy[0][1]*copy[1][0])*factor;
}
int main(){
    int A[5][5]={
        {3,7,1,3,5},
        {4,1,9,4,6},
        {3,2,1,7,3},
        {1,5,14,3,2},
        {5,8,6,7,11}
    };
    int B[4][4]={
        {1,2,3,4},
        {5,6,7,8},
        {8,7,6,5},
        {4,2,3,1}
    };
    int C[4][4]={
        {2,8,5,6},
        {4,7,1,6},
        {5,8,9,4},
        {2,5,8,7}
    };
    cout<<calculateDeterminant(A);
}
