
// 部分永続 Union-Find Tree (by size)
// t 秒後 の状態を参照できる

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

struct PartiallyPersistentUnionFind
{
    vector<ll> par, time;
    vector<vector<pair<ll, ll>>> history;

    PartiallyPersistentUnionFind(ll n) : par(n, -1), time(n, -1), history(n)
    {
        for (auto &vec : history)
            vec.emplace_back(-1, -1);
    }

    ll root(ll t, ll x)
    {
        if (time[x] == -1 || t < time[x])
            return x;
        return root(t, par[x]);
    }

    bool same(ll t, ll x, ll y)
    {
        return root(t, x) == root(t, y);
    }

    bool unite(ll t, ll x, ll y)
    {
        ll rx = root(t, x), ry = root(t, y);
        if (rx == ry)
            return false;
        if (par[rx] > par[ry])
            swap(rx, ry);
        par[rx] += par[ry];
        par[ry] = rx;
        time[ry] = t;
        history[rx].emplace_back(t, par[rx]);
        return true;
    }

    ll size(ll t, ll x)
    {
        ll rx = root(t, x);
      	pair<ll,ll> qst={t,0};
        auto ANS= *prev(lower_bound(history[rx].begin(), history[rx].end(), qst));
        return -ANS.second;
    }
};
