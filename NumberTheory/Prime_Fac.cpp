
// N を素因数分解して列挙

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

vector<pair<ll,ll>> Prime_Fac(long long N) {
    vector<pair<ll,ll>> res;
    ll N2 = N;
    for (ll i = 2; i * i <= N; ++i) {
        if (N2 % i == 0) {
            ll cnt = 0;
            while (N2 % i == 0) {
                N2 /= i;
                cnt++;
            }
            res.push_back({ i,cnt });
        }
    }
    if (N2 * N2 > N) {
        res.push_back({ N2,1 });
    }
    return res;
}
