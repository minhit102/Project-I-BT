//CPP 
#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    int n;
    cin >> n; // Get the value of 'n'

    int a[100000];
    long long sum = 0;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    } 
    cout << sum;

    return 0; 
}

