
// 2回DFSしてGraphの直径を求める O(V)
/*
verified:
https://atcoder.jp/contests/agc033/submissions/37788900
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
const ll MOD = 998244353;
// const ll MOD = 1000000007;
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};

template <typename T = int>
struct Edge
{
    int from, to;
    T cost;
    int idx;
    Edge() = default;
    Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}
    operator int() const { return to; }
};

template <typename T = int>
struct Graph
{
    vector<vector<Edge<T>>> g;
    int es;
    Graph() = default;
    explicit Graph(int n) : g(n), es(0) {}
    size_t size() const
    {
        return g.size();
    }

    void add_directed_edge(int from, int to, T cost = 1)
    {
        g[from].emplace_back(from, to, cost, es++);
    }

    void add_edge(int from, int to, T cost = 1)
    {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    void read(int m, int padding = -1, bool weighted = false, bool directed = false)
    {
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            a += padding, b += padding;
            T c = T(1);
            if (weighted)
                cin >> c;
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }

    inline vector<Edge<T>> &operator[](const int &k)
    {
        return g[k];
    }

    inline const vector<Edge<T>> &operator[](const int &k) const
    {
        return g[k];
    }
};

template <typename T = int>
using Edges = vector<Edge<T>>;

// ここまでグラフテンプレート

template <typename T = int>
struct TreeDiameter : Graph<T>
{
public:
    using Graph<T>::Graph;
    using Graph<T>::g;
    Edges<T> path;
    T build()
    {
        to.assign(g.size(), -1);
        auto p = dfs(0, -1);
        auto q = dfs(p.second, -1);
        int now = p.second;
        while (now != q.second)
        {
            for (auto &e : g[now])
            {
                if (to[now] == e.to)
                {
                    path.emplace_back(e);
                }
            }
            now = to[now];
        }
        return q.first;
    }
    explicit TreeDiameter(const Graph<T> &g) : Graph<T>(g) {}

private:
    vector<int> to;
    pair<T, int> dfs(int idx, int par)
    {
        pair<T, int> res(0, idx);
        for (auto &e : g[idx])
        {
            if (e.to == par)
                continue;
            auto cost = dfs(e.to, idx);
            cost.first += e.cost;
            if (res < cost)
            {
                res = cost;
                to[idx] = e.to;
            }
        }
        return res;
    }
};
int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    TreeDiameter<int> CQ(N);
    CQ.read(N - 1);
    int DL = CQ.build();
    cout << (DL % 3 == 1 ? "Second" : "First") << endl;
    return 0;
}
