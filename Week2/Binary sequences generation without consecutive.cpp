#include <iostream>
using namespace std;

void generate_sequences(int n, string prefix = "") {
    if (n == 0) {
        cout << prefix << endl;
        return;
    }
    if (!prefix.empty() && prefix.back() == '1') {
        generate_sequences(n - 1, prefix + '0');
    } else {
        generate_sequences(n - 1, prefix + '0');
        generate_sequences(n - 1, prefix + '1');
    }
}

int main() {
    int n;
    cin >> n;
    generate_sequences(n);
    return 0;
}
