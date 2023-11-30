#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    int n ;
    cin >> n ;
    int a[100000];
    int sole = 0;
    for(int i = 0 ; i< n ; i++){
        cin >> a[i];
        if(a[i] % 2) sole++;
    }
    cout << sole << " " << n-sole;

}

