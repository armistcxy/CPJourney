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

void solve(){
    int n; cin >> n;
    vl cnt(n+1); vl a(n+1);
    rep(i,1,n){
        cin >> a[i];
        cnt[a[i]]++;
    }   
    vl ans(n+1);
    ans[0] = cnt[0];
    stack<pl> q;
    ll need = 0;
    rep(k,1,n){
        if (cnt[k-1] > 1) q.push({k-1,cnt[k-1]-1});
        if (cnt[k-1] == 0){
            if (q.empty()){
                //cout << k << nl;
                rep(i,k,n) ans[i] = -1;
                break;
            }   
            int t = q.top().fi, left = q.top().se;
            (q.top().se)--;
            if (left == 1) q.pop();
            need += k - 1 - t;
        }
        ans[k] = need + cnt[k];
    }
    rep(i,0,n) cout << ans[i] << ' ';
    cout << nl;
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