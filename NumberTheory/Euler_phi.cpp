
// N の Eulerのφ関数を求める

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REP(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define bit(x, i) (((x) >> (i)) & 1)
#define all(x) x.begin(), x.end()
#define fcout cout << fixed << setprecision(15)
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
const ll INF = 1000000000000000000;
const ll NIL = -1;
const ll MOD = 998244353;
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};

ll Euler_phi(ll n)
{
    ll ret = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret -= ret / i;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        ret -= ret / n;
    return ret;
}
