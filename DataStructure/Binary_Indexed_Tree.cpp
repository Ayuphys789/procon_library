
// Binary Indexed Tree

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
struct Binary_Indexed_Tree
{
    ll n;
    vector<T> bit;
    BIT(ll n_) : n(n_ + 1), bit(n, 0) {} //1-indexed
    
    void add(ll i, T x)
    {
        for (ll id = i; id < n; id += (id & -id))
        {
            bit[id] += x;
        }
    }
    
    // sum of [1,i]
    T sum(ll i)
    {
        T s(0);
        for (ll id = i; id > 0; id -= (id & -id))
        {
            s += bit[id];
        }
        return s;
    }
};
