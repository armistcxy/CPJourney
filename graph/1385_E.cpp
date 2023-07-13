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
const int N = 2e5 + 5;
const ll INF = 1e18;
vector<pi> edges;
vi adj[N];
bool vis[N];
vi topo;
void dfs(int u){
    vis[u] = 1;
    each(adj[u],v){
        if (!vis[v]) dfs(v);
    }
    topo.pb(u);
}
void solve(){
    int n,m; cin >> n >> m;
    vi pos(n+1);
    rep(i,1,n) adj[i].clear();
    edges.clear();
    rep(i,1,n) vis[i] = 0;
    topo.clear();
    rep(i,1,m){
        int op; int a,b; cin >> op >> a >> b;
        edges.pb({a,b});
        if (op == 1) adj[a].pb(b);
    }
    rep(i,1,n){
        if (!vis[i]) dfs(i);
    }
    reverse(all(topo));
    rep(i,1,n) pos[topo[i-1]] = i;
    bool flag = 1;
    rep(i,1,n){
        each(adj[i],j) if (pos[j] < pos[i]) flag = 0;
    }
    if (!flag) cout << "NO" << nl;
    else {
        cout << "YES" << nl;
        each(edges,e){
            int u = e.fi, v = e.se;
            if (pos[u] < pos[v]) cout << u << ' ' << v << nl;
            else cout << v << ' ' << u << nl;
        }
    }

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