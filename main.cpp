/**
*    author:  manhpd9
 *    created: 28.08.2024 22:07:12
**/
#include <bits/stdc++.h>
// #define LOCAL
using namespace std;

using ll = long long;
using ld = long double;
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
// Dem so
ll lcmForArray(ll arr[], ll n)
{
    ll ans = arr[0];
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));

    return ans;
}
// Dem so uoc cua mot so
int countDivisors(int n) {
    int count = 1;
    int exponent = 0;
    while (n % 2 == 0) {
        n /= 2;
        exponent++;
    }
    if (exponent > 0) {
        count *= (exponent + 1);
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        exponent = 0;
        while (n % i == 0) {
            n /= i;
            exponent++;
        }
        if (exponent > 0) {
            count *= (exponent + 1);
        }
    }
    if (n > 2) {
        count *= (1 + 1);
    }
    return count;
}

// Sang so nguyen to
void Eratosthenes(int n,bool is_prime[]){
    for (int i = 2; i <= n; i++)
        is_prime[i] = true;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            // j sẽ bắt đầu chạy từ i * i
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
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
#ifdef LOCAL
    freopen("CAU3.INP", "r", stdin);
    freopen("CAU3.OUT", "w", stdout);
#endif
    int TC = 1;
    // cin >> TC;
    while (TC--)
    {
        solve();
    }

    return 0;
}
