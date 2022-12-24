
// 2回DFSしてGraphの直径を求める

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

using Graph = vector<vector<ll>>;
struct Diameter
{
    vector<ll> PRE;

    pair<ll, ll> DiameterDFS(const Graph &G, ll v, ll p)
    {
        pair<ll, ll> res(v, 0);
        for (ll i = 0; i < G[v].size(); i++)
        {
            if (G[v][i] == p)
                continue;
            pair<ll, ll> tmp = DiameterDFS(G, G[v][i], v);
            tmp.second++;
            if (tmp.second > res.second)
                res = tmp, PRE[G[v][i]] = v;
        }
        return res;
    }

    vector<ll> solve(const vector<vector<ll>> &G)
    {
        PRE.assign(G.size(), -1);
        pair<ll, ll> leaf = DiameterDFS(G, 0, 1);
        PRE.assign(G.size(), -1);
        pair<ll, ll> t = DiameterDFS(G, leaf.first, -1);
        vector<ll> res;
        ll cur = t.first;
        while (cur != -1)
        {
            res.push_back(cur);
            cur = PRE[cur];
        }
        return res; // resは直径に含まれる頂点の列,res.size()が直径の大きさ
    }
};
