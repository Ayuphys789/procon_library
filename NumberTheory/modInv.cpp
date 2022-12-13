
// x の MOD での逆元を求める

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

ll modPow(ll x, ll a)
{
  if (a == 1)
    return x;
  if (a % 2)
    return (x * modPow(x, a - 1)) % MOD;
  ll t = modPow(x, a / 2);
  return (t * t) % MOD;
}

ll modInv(ll x)
{
  return modPow(x, MOD - 2);
}
