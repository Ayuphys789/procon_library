
// x ^ a を MOD で割った余りを O(logN) で求める

/*
verified:
https://codeforces.com/contest/1768/submission/188108419
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <functional>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <array>
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

long long modPow(long long x, long long a, ll mod)
{
  if (a == 0)
    return 1;
  if (a == 1)
    return x;
  if (a % 2)
    return (x * modPow(x, a - 1, mod)) % mod;
  long long t = modPow(x, a / 2, mod);
  return (t * t) % mod;
}
