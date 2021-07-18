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

const int MAX = 2e5 + 10;
int N;
ll A[MAX], B[MAX], ans[MAX], ret;
priority_queue<ll> pq;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 1, N) B[i] = B[i - 1] + max(0LL, A[i] - A[i - 1]);
    rep(i, 0, N){
        pq.push(-B[i]);
        pq.push(A[i] - B[i]);
        pq.pop();
        ans[i] = pq.top();
    }
    rep2(i, 0, N - 1) if(ans[i] > ans[i + 1]) ans[i] = ans[i + 1];
    rep(i, 0, N){
        ans[i] += B[i];
        ret += abs(ans[i]) + abs(ans[i] - A[i]);
    }
    cout << ret << endl;
}
