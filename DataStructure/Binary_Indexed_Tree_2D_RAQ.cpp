
// Binary Indexed Tree (2-dimensions, Range Update Query)

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
#define all(x) x.begin(), x.end()
#define fcout cout << fixed << setprecision(15)
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
const ll INF = 1000000000000000000;
const ll NIL = -1;
const ll MOD = 998244353;
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};

template <typename T>
struct Binary_Indexed_Tree_2D // 1-indexed, 2-dimensions
{
    ll h, w;
    vector<vector<T>> bit[2][2];

    Binary_Indexed_Tree_2D(ll h_, ll w_) { init(h_, w_); }
    void init(ll h_, ll w_)
    {
        h = h_ + 1;
        w = w_ + 1;
        rep(i, 2) rep(j, 2) bit[i][j].assign(h + 1, vector<T>(w + 1, 0));
    }

    inline void subsub_add(ll f, ll s, ll p, ll q, T x)
    {
        for (ll i = p; i < h; i += (i & -i))
            for (ll j = q; j < w; j += (j & -j))
                bit[f][s][i][j] += x;
    }

    inline void sub_add(ll p, ll q, T x)
    {
        subsub_add(0, 0, p, q, x * (p - 1) * (q - 1));
        subsub_add(1, 0, p, q, -x * (q - 1));
        subsub_add(0, 1, p, q, -x * (p - 1));
        subsub_add(1, 1, p, q, x);
    }

    inline void add(ll p1, ll q1, ll p2, ll q2, T x) // [p1, p2], [q1, q2]
    {
        sub_add(p1, q1, x);
        sub_add(p1, q2 + 1, -x);
        sub_add(p2 + 1, q1, -x);
        sub_add(p2 + 1, q2 + 1, x);
    }

    inline T subsub_sum(ll f, ll s, ll p, ll q)
    {
        T res(0);
        for (ll i = p; i > 0; i -= (i & -i))
            for (ll j = q; j > 0; j -= (j & -j))
                res += bit[f][s][i][j];
        return res;
    }

    inline T sub_sum(ll p, ll q)
    {
        T res(0);
        res += subsub_sum(0, 0, p, q);
        res += subsub_sum(1, 0, p, q) * (p);
        res += subsub_sum(0, 1, p, q) * (q);
        res += subsub_sum(1, 1, p, q) * (p) * (q);
        return res;
    }

    inline T sum(ll p1, ll q1, ll p2, ll q2)
    {
        return sub_sum(p2, q2) - sub_sum(p1 - 1, q2) - sub_sum(p2, q1 - 1) + sub_sum(p1 - 1, q1 - 1);
    }
};
