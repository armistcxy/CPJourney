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
const int N = 32000;
const ll INF = 1e18;
vi pr;
bool is_pr[N+1];
void solve(){
    ll x,d; cin >> x >> d;
    int cnt = 0;
    while (x % d == 0){
        cnt++, x /= d;
    }
    if (cnt < 2){
        cout << "NO\n";
        return;
    }
    vector<pi> div;
    each(pr,a){
        int cur = 0;
        while (d % a == 0) d /= a, cur++;
        if (cur > 0) div.pb({a,cur});
    }
    if (d > 1) div.pb({d,1});

    int e = div[0].se;
    int mn = 2;
    if (sz(div) == 1){
        int t = cnt * e; 
        int tmp = x;
        while(tmp % div[0].fi == 0) tmp /= div[0].fi, t++;
        mn = (t + 2 * e - 2) / (2 * e - 1);
    }
    if (mn < cnt) cout << "YES\n"; 
    else {
        each(pr,a) if (x % a == 0 && x > a){
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
    }
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    rep(i,2,N) is_pr[i] = 1;
    rep(i,2,N){
        if (is_pr[i]){
            pr.pb(i);
            for (ll j = i * i; j <= N; j += i) is_pr[j] = 0;
        }
    }
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}