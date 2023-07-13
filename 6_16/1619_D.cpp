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
const ll INF = 1e18;
int n,m; 
vi p[N];
bool check(int x){
    vector<int> ok(n+1,0);
    vector<int> ok1(m+1,0);
    int cnt = 0;
    rep(i,1,m){
        rep(j,1,n){
            if (p[i][j] >= x) ok[j]++, ok1[i]++;
        }
    }
    bool flag = 1;
    bool big = 0;
    rep(i,1,n) {if (!ok[i]) flag = 0;}
    rep(i,1,m) {if (ok1[i] >= 2) big = 1;} 
    return ((big || n > m) && flag);
}
void solve(){
    cin >> m >> n;
    int mx = 0;
    rep(j,1,m){
        p[j].resize(n+1);
        rep(i,1,n) {cin >> p[j][i]; chmax(mx,p[j][i]);}
    };
    int lo = 1, hi = mx;
    while (lo < hi){
        int mid = lo + (hi - lo + 1) / 2;
        if(check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << nl;
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}