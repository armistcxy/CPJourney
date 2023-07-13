#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep_r(i,a,b) for(int i=a;i>=b;i--)
#define each(a,x) for (auto& x : a)
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
#define fi first    
#define se second
#define sz(x) int(x.size())
#define so(x) sort(all(x))
#define so_r(x) sort(all(x),greater<int>())
#define zero(x) memset(x,0,sizeof(x))
#define pb push_back
#define lb lower_bound
#define ub upper_bound
const char nl = '\n';
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int bit_cnt(int x){
    return __builtin_popcount(x);
}
ll bex(ll a, ll b, ll mod = 1){ll res = 1LL; while(b){ if (b&1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

// winter is coming 
const int MOD = 1e9 + 7; // 998244353
const int N = 1e5 + 5;
const ll INF = 1e9;
ll dp[205][205][205]; // [len][number of already changes][number of t[0]]
void solve(){
    int n,k; cin >> n >> k; 
    string s,t; cin >> s >> t;
    ll ans = 0;
    if (t[0] == t[1]){
        int cnt = 0;
        each(s,x){
            cnt += (x == t[0]);
        }
        cnt = min(cnt+k,n);
        cout << cnt * (cnt - 1) / 2 << nl;
        return;
    }

    rep(i,0,204) rep(j,0,204) rep(k,0,204) dp[i][j][k] = -INF;
    dp[0][0][0] = 0;
    rep(i,0,n-1) rep(j,0,i+1) rep(k,0,i) {
        if (s[i] == t[0]) chmax(dp[i+1][j][k+1],dp[i][j][k]);
        else if (s[i] == t[1]) chmax(dp[i+1][j][k],dp[i][j][k]+k);
        else chmax(dp[i+1][j][k],dp[i][j][k]);

        chmax(dp[i+1][j+1][k+1],dp[i][j][k]);
        chmax(dp[i+1][j+1][k],dp[i][j][k]+k);
    }

    rep(i,0,k) rep(j,0,n) chmax(ans,dp[n][i][j]);
    cout << ans << nl;
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin >> t;
    while (t--){
        solve();
    }
}