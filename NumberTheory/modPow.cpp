//(N^P)%modをO(logN)で計算

#include<bits/stdc++.h?
using namespace std;

ll modPow(ll x, ll a) {
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1)) % MOD;
  ll t = modPow(x, a / 2);
  return (t * t) % MOD;
}
