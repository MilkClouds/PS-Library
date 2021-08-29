# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1e5;
ll N, X, C[MAX], ans, j, cnt;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> X; X <<= 1;
    rep(i, 0, N) cin >> C[i], C[i] <<= 1;
    sort(C, C + N);
    rep2(i, 0, N){
        if(C[i] == X){
            ans++; cnt++;
            continue;
        }
        while(j < i && C[j] < X / 2 - C[i]) j++;
        if(j >= i) break;
        if(C[j] + C[i] < X / 2) break;
        ans++; cnt += 2; j++;
    }
    ans += (N - cnt) / 3;
    cout << ans << endl;
}
