
// Union-Find Tree (by rank)

/*
verified:
https://atcoder.jp/contests/abc284/submissions/37885258
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
#include <random>
#include <cstdlib>
#include <cassert>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REP(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define rFOR(i, a, b) for (ll i = a; i >= b; i--)
#define all(x) x.begin(), x.end()
#define fcout cout << fixed << setprecision(15)
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
const ll INF = 1000000000000000000;
const ll NIL = -1;
// const ll MOD = 998244353;
// const ll MOD = 1000000007;
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};

struct UnionFind
{
    vector<int> par, rank, siz;
    int num_c;

    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1), num_c(n) {}

    int root(int x)
    {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }

    bool unite(int x, int y)
    {
        int rx = root(x), ry = root(y);
        if (rx == ry)
            return false;
        if (rank[rx] < rank[ry])
            swap(rx, ry);
        par[ry] = rx;
        if (rank[rx] == rank[ry])
            rank[rx]++;
        siz[rx] += siz[ry];
        num_c--;
        return true;
    }

    int size(int x)
    {
        return siz[root(x)];
    }

    int connected_num()
    {
        return num_c;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    UnionFind uf(N);
    rep(i, M)
    {
        ll U, V;
        cin >> U >> V;
        uf.unite(U - 1, V - 1);
    }
    cout << uf.connected_num() << "\n";
    return 0;
}
