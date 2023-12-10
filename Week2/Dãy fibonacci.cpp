#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long factorial(long long  n) {
    long long  result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

long long  binomial_coefficient(long long  k, long long  n) {
    long long  numerator = factorial(n);
    long long  denominator = (factorial(k) * factorial(n - k)) % MOD;
    long long  inverse_denominator = 1;
    long long  power = MOD - 2;
    while (power > 0) {
        if (power % 2 == 1) {
            inverse_denominator = (inverse_denominator * denominator) % MOD;
        }
        denominator = (denominator * denominator) % MOD;
        power /= 2;
    }
    return (numerator * inverse_denominator) % MOD;
}

int main() {
    int k, n;
    cin >> k >> n;
    long long  result = binomial_coefficient(k, n);
    cout << result << endl;
    return 0;
}

