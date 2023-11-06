#include <iostream>
using namespace std;

int Check(int n){
    int sum=0;
    for (int i=1;i<n;i++)
        if (n%i==0) sum+=i;
    return sum==n;
}

int MinPerfect(int a[][1000],int m,int n){
    int min=0;
    for (int i=0;i<m;i++) 
        for (int j=0;j<n;j++)
            if (Check(a[i][j]) && (min==0||a[i][j]<min)) 
                min=a[i][j];
    return min;
}

int main() {
    int n,m;
    cout << "Enter m,n of Matrix (m x n): ";
    cin >> m >> n;
    int a[1000][1000];
    cout << "Enter Matrix (m x n):\n";
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            cin >> a[i][j];
    cout << "-> " << MinPerfect(a,m,n);
}