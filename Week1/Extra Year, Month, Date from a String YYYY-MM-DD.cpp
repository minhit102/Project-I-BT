//C++ 
#include <bits/stdc++.h> 
using namespace std;

int main() {
    string ngaythanhnam;
    cin >> ngaythanhnam;

    if (ngaythanhnam.size() != 10 || ngaythanhnam[7] != '-' || ngaythanhnam[4] != '-' ) {
        cout << "INCORRECT" << endl;
        return 0;
    }

    int nam, thang, ngay;
    if (sscanf(ngaythanhnam.c_str(), "%d-%d-%d", &nam, &thang, &ngay) != 3) {
        cout << "INCORRECT" << endl;
        return 0;
    }


    if (nam < 1 || ngay < 1 || thang < 1 || thang > 12 || ngay > 31) {
        cout << "INCORRECT" << endl;
        return 0;
    }

    cout << nam << " " << thang << " " << ngay << endl;

    return 0;
}

