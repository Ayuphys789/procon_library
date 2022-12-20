
// BIT 上の二分探索

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
#include <random>
#include <cstdlib>
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
    Binary_Indexed_Tree(ll n_) : n(n_ + 1), bit(n, 0) {}

    void add(ll i, T x)
    {
        for (ll id = i; id < n; id += (id & -id))
        {
            bit[id] += x;
        }
    }

    T sum(ll i)
    {
        T s(0);
        for (ll id = i; id > 0; id -= (id & -id))
        {
            s += bit[id];
        }
        return s;
    }

    ll LB(T w) // [1,x] の和が w 以上となる最小の x
    {
        if (w <= 0)
            return 0;
        else
        {
            ll x = 0, r = 1;
            while (r < n - 1)
            {
                r *= 2;
            }
            for (ll len = r; len > 0; len /= 2)
            {
                if (x + len < n && bit[x + len] < w)
                {
                    w -= bit[x + len];
                    x += len;
                }
            }
            return x + 1;
        }
    }
};

int main(void)
{
    ll Q;
    cin >> Q;
    Binary_Indexed_Tree<ll> BIT(200010);
    while (Q--)
    {
        ll type, X;
        cin >> type >> X;
        if (type == 1)
        {
            BIT.add(X, 1);
        }
        else
        {
            ll val = BIT.LB(X);
            cout << val << endl;
            BIT.add(val, -1);
        }
    }
}
