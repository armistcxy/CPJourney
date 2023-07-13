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

const int MOD = 1e9 + 7; // 998244353
const int N = 7e5 + 5;
const ll INF = 1e18;
vi adj[N];
int color[N];
int n,m; 
bool is_contradiction;
int team1, team2;
void dfs(int x){
    if (color[x] == 0 && x <= n) team1++;
    else if (x <= n) team2++;
    each(adj[x],y){
        if (color[y] == -1) color[y] = 1 - color[x], dfs(y);
        else if (color[x] == color[y]) is_contradiction = true;
    }
}
void solve(){
    cin >> n >> m;
    is_contradiction = false;
    int cur = n + 1;
    map<pi,bool> mp;
    rep(i,1,n+m+1) adj[i].clear(), color[i] = -1;
    rep(i,1,m){
        int a,b; cin >> a >> b;
        string c; cin >> c;
        if (c == "crewmate"){
            //sameteam
            adj[a].pb(cur), adj[cur].pb(a);
            adj[b].pb(cur), adj[cur].pb(b);
            cur++;
        }
        else{
            adj[a].pb(b), adj[b].pb(a);
        }
    }
    int ans = 0;
    rep(i,1,n){
        if (color[i] == -1){
            color[i] = 0;
            team1 = 0, team2 = 0;
            dfs(i);
            ans += max(team1,team2);
        }
    }
    cout << (is_contradiction ? -1 : ans) << nl;
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