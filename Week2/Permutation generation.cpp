#include<bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        elements[i] = i + 1;
    }

    do {
        for (int i = 0; i < n; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    } while (next_permutation(elements.begin(), elements.end()));

    return 0;
}
