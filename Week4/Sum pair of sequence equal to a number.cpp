#include <iostream>
#include <unordered_map>
using namespace std;

int count_pairs(int arr[], int n, int M) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int complement = M - arr[i];
        if (freq.find(complement) != freq.end()) {
            count += freq[complement];
        }
        freq[arr[i]]++;
    }

    return count;
}

int main() {
    int n, M;
    cin >> n >> M;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = count_pairs(arr, n, M);
    cout << result << endl;

    return 0;
}
