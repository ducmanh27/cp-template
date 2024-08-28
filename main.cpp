/**
*    author:  manhpd9
 *    created: 28.08.2024 22:07:12
**/
#include <bits/stdc++.h>
#define LOCAL
#define ONLINEJUDGE
using namespace std;

using ll = long long;
using ld = long double;
//

bool isPrime(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int lcm(int a, int b) {
    return std::abs(a * b) / std::gcd(a, b);
}

ll sqr(ll x) {
    return x*x;
}

ll _pow(ll _a, ll _b, ll _mod) {
    if (_b == 1) return _a % _mod;
    if (_b == 0) return 1 % _mod;

    if (_b % 2 == 0)
        return sqr(_pow(_a, _b/2, _mod)) % _mod;
    return _a * (sqr(_pow(_a, _b/2, _mod)) % _mod) % _mod;
}
/* Theory
 * m is prime => a^(m-2) === a^-1
 */

// Global variable
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll a[MAXN];
ll S[MAXN];
void solve()
{
    S[0] = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S[i] = (S[i - 1] * a[i]) % MOD;
    }

    int tc; cin >> tc;
    while(tc--) {
        int ans;
        int u, k; cin >> u >> k;
        ans =(S[u + k - 1]* _pow(S[u - 1], MOD - 2, MOD)) % MOD ;
        cout << ans << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    // cin >> TC;
    while (TC--)
    {
        solve();
    }

    return 0;
}
