#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sequence(n);
    unordered_map<int, bool> previous_occurrence;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
        if (previous_occurrence.find(sequence[i]) != previous_occurrence.end()) {
            result.push_back(1);
        } else {
            result.push_back(0);
        }
        previous_occurrence[sequence[i]] = true;
    }

    for (int r : result) {
        cout << r << endl;
    }

    return 0;
}
