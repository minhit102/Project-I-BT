#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    int n;
    cin >> n;
    double k ;
    if(n<=50){
         k = 0;
    }
    else if(n <= 100){
        k = (n-50)*(1728-1786);
    }

    else if(n <= 300){
        k = 50*(1728-1786);
    }
    ////
    else if(n <= 400){
        k = 50*(1728-1786) + (n-300)*(2612-2919);
    }
    else if(n <= 700){
        k = 50*(1728-1786) + 100*(2612-2919) + (n-400)*(3111-3015);
    }
    else {
        k = 50*(1728-1786) + 100*(2612-2919) + 300*(3111-3015) + (n-700)*(3457-3015);
    }

    cout << fixed << setprecision(2) << k * 110/100; // Đã thêm fixed và setprecision(2) để in ra 2 số thập phân

    return 0;
}

