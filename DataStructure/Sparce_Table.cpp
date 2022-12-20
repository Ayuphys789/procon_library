
// Sparce Table (更新がない場合 Range Minimum Query を O(1) で求める)

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
struct SparceTable // 1-indexed, [left, right]
{
    vector<vector<T>> st;
    vector<ll> LU;

    SparceTable(const vector<T> &v)
    {
        ll b = 0;
        while ((1 << b) <= v.size())
            b++;
        st.assign(b, vector<T>(1 << b));
        for (ll i = 0; i < v.size(); i++)
        {
            st[0][i] = v[i];
        }
        for (ll i = 1; i < b; i++)
        {
            for (ll j = 0; j + (1 << i) <= (1 << b); j++)
            {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
        LU.resize(v.size() + 1);
        for (ll i = 2; i < LU.size(); i++)
        {
            LU[i] = LU[i >> 1] + 1;
        }
    }

    inline T RMQ(ll left, ll right) // [left, right)
    {
        ll b = LU[right - left];
        return min(st[b][left], st[b][right - (1 << b)]);
    }
};

int main(void)
{
    ll N, Q;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    SparceTable<ll> ST(A);
    cin >> Q;
    while (Q--)
    {
        ll X, Y;
        cin >> X >> Y;
        X--;
        cout << ST.RMQ(X, Y) << endl;
    }
    return 0;
}
