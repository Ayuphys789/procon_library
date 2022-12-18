
// Union-Find Tree (by size)

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

struct UnionFind
{
    vector<ll> par, rank, siz;

    UnionFind(ll n) : par(n, -1), rank(n, 0), siz(n, 1) {}

    ll root(ll x)
    {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool same(ll x, ll y)
    {
        return root(x) == root(y);
    }

    bool unite(ll x, ll y)
    {
        ll rx = root(x), ry = root(y);
        if (rx == ry)
            return false;
        if (siz[rx] < siz[ry])
            swap(rx, ry);
        par[ry] = rx;
        if (rank[rx] == rank[ry])
            rank[rx]++;
        siz[rx] += siz[ry];
        return true;
    }

    ll size(ll x)
    {
        return siz[root(x)];
    }
};
