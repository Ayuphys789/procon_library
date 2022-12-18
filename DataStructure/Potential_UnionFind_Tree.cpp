
// Potential つき Union-Find Tree (by size)

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

template <typename Abel>
struct UnionFind
{
    const Abel UNITY_SUM = 0;
    vector<ll> par;
    vector<Abel> diff_weight;

    UnionFind(ll n) : par(n, -1), diff_weight(n, UNITY_SUM) {}

    ll root(ll x)
    {
        if (par[x] < 0)
            return x;
        ll r = root(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = r;
    }

    Abel calc_weight(ll x)
    {
        root(x);
        return diff_weight[x];
    }

    bool same(ll x, ll y)
    {
        return root(x) == root(y);
    }

    bool unite(ll x, ll y, Abel w = 0)
    {
        w += calc_weight(x);
        w -= calc_weight(y);
        ll rx = root(x), ry = root(y);
        if (rx == ry)
            return false;
        if (par[rx] > par[y])
        {
            swap(rx, ry);
            w = -w;
        }
        par[rx] += par[ry];
        par[ry] = rx;
        diff_weight[ry] = w;
        return true;
    }

    Abel diff(ll x, ll y)
    {
        return calc_weight(y) - calc_weight(x);
    }

    ll size(ll x)
    {
        return -par[root(x)];
    }
};

