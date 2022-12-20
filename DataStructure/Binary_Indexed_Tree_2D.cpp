
// Binary Indexed Tree (2-dimensions)

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
    vector<vector<T>> bit;

    Binary_Indexed_Tree_2D(ll h_, ll w_) { init(h_, w_); }
    void init(ll h_, ll w_)
    {
        h = h_ + 1;
        w = w_ + 1;
        bit.assign(h, vector<T>(w, 0));
    }

    void add(ll p, ll q, T x)
    {
        for (ll i = p; p < h; p += (p & -p))
            for (ll j = q; j < w; j += (j & -j))
                bit[i][j] += x;
    }

    T sum(ll p, ll q) // [1, p] ∧ [1, q]
    {
        T s(0);
        for (ll i = p; p > 0; p -= (p & -p))
            for (ll j = q; j > 0; j -= (j & -j))
                s += bit[i][j];
        return s;
    }

    T query_sum(ll p1, ll q1, ll p2, ll q2) // [p1, p2] ∧ [q1, q2]
    {
        return sum(p2, q2) - sum(p1 - 1, q2) - sum(p2, q1 - 1) + sum(p1 - 1, q1 - 1);
    }
};
