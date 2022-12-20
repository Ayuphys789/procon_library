
// Binary Indexed Tree (RAQ)

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
struct Binary_Indexed_Tree // 1-indexed, [left,right]
{
    ll n;
    vector<T> bit[2];
    Binary_Indexed_Tree(ll n_) { init(n_); }
    void init(ll n_)
    {
        n = n_ + 2;
        for (int p = 0; p < 2; p++)
            bit[p].assign(n, 0);
    }

    void add_sub(int p, ll i, T x)
    {
        for (ll id = i; id < n; id += (id & -id))
        {
            bit[p][id] += x;
        }
    }

    void add(ll left, ll right, T x)
    {
        add_sub(0, left, -x * (left - 1));
        add_sub(0, right + 1, x * right);
        add_sub(1, left, x);
        add_sub(1, right + 1, -x);
    }

    T sum_sub(int p, ll i)
    {
        T s(0);
        for (ll id = i; id > 0; id -= (id & -id))
        {
            s += bit[p][id];
        }
        return s;
    }

    T sum(ll i) // [1, i]
    {
        return sum_sub(0, i) + sum_sub(1, i) * i;
    }
    
    T query_sum(ll i, ll j) // [i, j]
    {
        return sum(j) - sum(i - 1);
    }
};
