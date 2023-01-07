
// V 頂点 V 辺からなる無向グラフ(なもりグラフ)は閉路を1つ持つ BFS と DFS を用いて 閉路 (loop) と閉路内の頂点をを含む木 (forest) に分解する

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
#define Graph vector<vector<ll>>
#define fcout cout << fixed << setprecision(15)
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
const ll INF = 1000000000000000000;
const ll NIL = -1;
const ll MOD = 998244353;
// const ll MOD = 1000000007;
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};

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
        forest.resize(N);
        queue<ll> q;
        vector<bool> v(N, 0);
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
        function<void(ll)> dfs = [&](ll idx)
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
