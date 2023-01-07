
// V 頂点 V 辺からなる無向グラフ(なもりグラフ)は閉路を1つ持つ BFS と DFS を用いて 閉路 (loop) と閉路内の頂点をを含む木 (forest) に分解する

/*
verified:
https://atcoder.jp/contests/abc266/submissions/37785779
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

template <typename G>
struct Namori
{
    const G &g;
    vector<int> in;
    Namori(const G &g) : g(g), in(g.size(), 0) {}

    void decomposition(vector<ll> &loop, vector<vector<ll>> &forest)
    {
        ll n = in.size();
        for (ll i = 0; i < n; i++)
        {
            in[i] = g[i].size();
        }
        forest.resize(n);
        queue<ll> q;
        vector<bool> v(n, 0);
        for (ll i = 0; i < n; i++)
        {
            if (in[i] == 1)
            {
                q.emplace(i);
                v[i] = 1;
            }
        }
        while (!q.empty())
        {
            ll idx = q.front();
            q.pop();
            for (auto &to : g[idx])
            {
                if (v[to])
                    continue;
                in[to]--;
                forest[to].push_back(idx);
                forest[idx].push_back(to);
                if (in[to] > 1)
                    continue;
                q.emplace(to);
                v[to] = 1;
            }
        }
        function<void(ll)> dfs = [&](ll idx) -> void
        {
            loop.push_back(idx);
            for (auto &to : g[idx])
            {
                if (v[to])
                    continue;
                v[to] = 1;
                dfs(to);
            }
        };
        for (ll i = 0; i < n; i++)
        {
            if (v[i])
                continue;
            v[i] = 1;
            dfs(i);
            break;
        }
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    ll N;
    cin >> N;
    Graph<> G(N);
    G.read(N);
    Namori<Graph<int>> CQ(G);
    vector<ll> loop;
    vector<vector<ll>> forest;
    CQ.decomposition(loop, forest);
    /*
    for (auto &to : loop)
    {
        cout << to << " ";
    }
    */
    cout << endl;
    vector<int> id(N, -1);
    function<void(int, int)> cnct = [&](int k, int p) -> void
    {
        if (id[k] != -1)
            return;
        id[k] = p;
        for (auto &to : forest[k])
        {
            cnct(to, p);
        }
    };
    rep(i, N)
    {
        cnct(i, i);
    }
    ll Q;
    cin >> Q;
    while (Q--)
    {
        ll X, Y;
        cin >> X >> Y;
        X--;
        Y--;
        cout << (id[X] == id[Y] ? "Yes" : "No") << endl;
    }
    return 0;
}
