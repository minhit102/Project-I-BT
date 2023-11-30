#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    // Read the input sequence
    int n;
    cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    // Process queries
    string query;
    while (true) {
        cin >> query;
        if (query == "***") {
            break;
        }

        if (query == "find-max") {
            int max_element = numeric_limits<int>::min();
            for (int i = 0; i < n; i++) {
                if (sequence[i] > max_element) {
                    max_element = sequence[i];
                }
            }
            cout << max_element << endl;
        } else if (query == "find-min") {
            int min_element = numeric_limits<int>::max();
            for (int i = 0; i < n; i++) {
                if (sequence[i] < min_element) {
                    min_element = sequence[i];
                }
            }
            cout << min_element << endl;
        } else if (query == "sum") {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += sequence[i];
            }
            cout << sum << endl;
        } else if (query == "find-max-segment") {
            int i, j;
            cin >> i >> j;
            if (i < 1 || j > n || i > j) {
                cout << "INCORRECT" << endl;
                continue;
            }
            int max_element = numeric_limits<int>::min();
            for (int k = i - 1; k <= j - 1; k++) {
                if (sequence[k] > max_element) {
                    max_element = sequence[k];
                }
            }
            cout << max_element << endl;
        }
    }

    return 0;
}

