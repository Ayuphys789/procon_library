//Nが素数かどうかO(√N)で判定

#include <iostream>
using namespace std;
typedef long long ll;

bool isPrime(ll n) {
    if (n <= 1) return false;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p == 0) return false;
    }
    return true;
}

int main() {
    int n; cin >> n;
    if (isPrime(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
