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
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int bit_cnt(int x){
    return __builtin_popcount(x);
}
ll bex(ll a, ll b, ll mod = 1){ll res = 1LL; while(b){ if (b&1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

const int MOD = 1e9 + 7; // 998244353
const int N = 1e5 + 5;
const ll INF = 1e18;
int n;
int a[6];
int b[N];
int lim[N];
vi p[N];
set<pi> s;
void solve(){
    rep(i,0,5) cin >> a[i];
    cin >> n;
    rep(i,1,n) cin >> b[i];
    
    sort(a,a+6);
    rep(i,1,n) rep_r(j,5,0) p[i].pb(b[i]-a[j]);
    rep(i,1,n) s.insert({p[i][0],i});
    ll res = INF;
    while(1){
        chmin(res,(*s.rbegin()).fi-(*s.begin()).fi);
        int id = (*s.begin()).se;
        s.erase(s.begin());
        if (lim[id] + 1 == sz(p[id])) break;
        lim[id]++;
        s.insert({p[id][lim[id]],id});
    } 
    cout << res << '\n';
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