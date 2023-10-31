#include <iostream>
#include<cmath>
using namespace std;

void printMatrix(double **arr,int n){
    for(int i=0;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int calculateDeterminant(double **arr,int n,double var=1)
{
    long double newVar=var*(1/pow(arr[0][0],n-2));
    if(n==2){
        cout<<arr[0][0]*arr[1][1] -arr[0][1]*arr[1][0]<<endl;
        return (arr[0][0]*arr[1][1] -arr[0][1]*arr[1][0])*var;
    }
    //int tmp[size_x-1][size_y-1];
    double **tmp; 
    tmp =  new double*[n-1];
    for(int i=0;i<n-1;i++)
    tmp[i]= new double[n-1];

    for(int j=1;j<n;j++){
        for(int k=1;k<n;k++){
            int a=arr[0][0];
            int b=arr[0][k];
            int c=arr[j][0];
            int d=arr[j][k];
            tmp[j-1][k-1]=(a*d - b*c);
        }
    }
    printMatrix(tmp,n-1);
    return 1* calculateDeterminant(tmp,n-1,newVar);
}
int main(){
    int c[5][5]={
        {3,7,1,3,5},
        {4,1,9,4,6},
        {3,2,1,7,3},
        {1,5,14,3,2},
        {5,8,6,7,11}
    };
    double **b = new double*[5];
    for (int i = 0; i < 5; i++)
    {
        b[i]=new double[5];
        for (int j=0;j<5;j++){

            b[i][j]=c[i][j];
        }
    }
    int C[4][4]={
        {2,8,5,6},
        {4,7,1,6},
        {5,8,9,4},
        {2,5,8,7}
    };
    double **d = new double*[4];
    for (int i = 0; i < 4; i++)
    {
        d[i]=new double[4];
        for (int j=0;j<4;j++){

            d[i][j]=C[i][j];
        }
    }
    cout<<calculateDeterminant(b,5);
    

    
}
