
// Segment Tree を用いた Range Sum Query

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REP(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define bit(x, i) (((x) >> (i)) & 1)
#define all(x) x.begin(), x.end()
#define fcout cout << fixed << setprecision(15)
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
const ll INF = 1000000000000000000;
const ll NIL = -1;
const ll MOD = 998244353;
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};

ll N, Q;

template <typename T>
struct Range_Sum_Query
{
    const T inf = numeric_limits<T>::max();
    int n;
    vector<T> dat;
    void RSQ(int n_)
    {
        int x = 1;
        while (n_ > x)
        {
            x *= 2;
        }
        n = x;
        dat.resize(n * 2 - 1, 0);
    }

    void update(int i, T x)
    {
        i += n - 1;
        dat[i] += x;
        while (i > 0)
        {
            i = (i - 1) / 2;
            dat[i] = dat[i * 2 + 1] + dat[i * 2 + 2];
        }
        return;
    }

    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
        {
            return 0;
        }
        else if (a <= l && r <= b)
        {
            return dat[k];
        }
        else
        {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return vl + vr;
        }
    }
};

int main(void)
{
    cin >> N >> Q;
    Range_Sum_Query<ll> seg;
    seg.RSQ(N);
    while (Q--)
    {
        ll type, X, Y;
        cin >> type >> X >> Y;
        if (type == 0)
        {
            seg.update(X - 1, Y);
        }
        else
        {
            cout << seg.query(X - 1, Y) << endl;
        }
    }
    return 0;
}
