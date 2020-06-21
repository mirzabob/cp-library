#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(),v.end()
#define repf(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define MOD 998244353 

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<ll> ods;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll power(ll a, ll n, ll m)
{
    ll ans=1;
    while(n)
    {
        if(n&1) ans=(ans*a)%m;
        n>>=1;
        a=(a*a)%m;
    }
    return ans;
}

ll invmod(ll a, ll m)
{
    return power(a,m-2,m);
}

const ll N=100101;
const ll M=100101;
ll a[N],en[N],ex[N],dp[N][22];
ll val[N],vis[N],dep[N];
ll ID[N<<1], BL[N<<1];
vector<ll> v[N];
ll ans[M];
ll Tm;
ll n,m;

struct query{
    ll id,l,r,lc;
    bool operator < (const query& rhs)
    {
        return (BL[l]==BL[rhs.l])?(r<rhs.r):(BL[l]<BL[rhs.l]);
    }
}Q[M];

void dfs(ll x, ll p)
{
    dp[x][0]=p;
    repf(i,1,22)
    {
        if(dp[x][i-1]!=-1) dp[x][i]=dp[dp[x][i-1]][i-1];
    }
    en[x]=++Tm;
    ID[Tm]=x;
    for(auto i:v[x])
    {
        if(i==p) continue;
        dep[i]=dep[x]+1;
        dfs(i,x);
    }
    ex[x]=++Tm;
    ID[Tm]=x;
}

ll up(ll x, ll k)
{
    repf(i,0,22)
    {
        if((1<<i)&k)
        {
            x=dp[x][i];
        }
    }
    return x;
}

ll lca(ll x, ll y)
{
    if(dep[x]>dep[y]) x=up(x,dep[x]-dep[y]);
    if(dep[y]>dep[x]) y=up(y,dep[y]-dep[x]);
    if(x==y) return x;
    repb(i,21,0)
    {
        if(dp[x][i]!=dp[y][i])
        {
            x=dp[x][i];
            y=dp[y][i];
        }
    }
    return dp[x][0];
}

void process(ll x, ll &res)
{
    if(vis[x] && (--val[a[x]]==0)) res--;
    else if((!vis[x]) && (val[a[x]]++==0)) res++;
    vis[x]^=1;
}

void compute()
{
    ll curL=Q[0].l, curR=Q[0].l-1, res=0;
    repf(i,0,m)
    {
        while(curL>Q[i].l)
        {
            process(ID[--curL],res);
        }
        while(curR<Q[i].r)
        {
            process(ID[++curR],res);
        }
        while(curL<Q[i].l)
        {
            process(ID[curL++],res);
        }
        while(curR>Q[i].r)
        {
            process(ID[curR--],res);
        }
        
        ll x=ID[curL], y=ID[curR];
        if(Q[i].lc!=x && Q[i].lc!=y) process(Q[i].lc,res);
        
        ans[Q[i].id]=res;
        
        if(Q[i].lc!=x && Q[i].lc!=y) process(Q[i].lc,res);
    }
}

void solve(ll t)
{
    // cout<<"Case #"<<t<<":\n";
    cin>>n>>m;
    // while (scanf("%lld %lld", &n, &m) != EOF)
    {
        Tm=0;
        memset(vis,0,sizeof vis);
        memset(val,0,sizeof val);
        repf(i,1,n+1) v[i].clear();
        
        repf(i,1,n+1) cin>>a[i];
        ll d[n+1];
        repf(i,1,n+1) d[i]=a[i];
        sort(d+1,d+n+1);
        // ll K=unique(d+1,d+n+1)-d-1;
        repf(i,1,n+1) a[i]=lower_bound(d+1,d+n+1,a[i])-d;
        
        repf(i,0,n-1)
        {
            ll x,y;
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        memset(dp,-1,sizeof dp);
        dfs(1,-1);
        ll sz=sqrt(Tm);
        repf(i,1,Tm+1) BL[i]=(i-1)/sz+1;
        
        repf(i,0,m)
        {
            ll x,y;
            cin>>x>>y;
            Q[i].lc=lca(x,y);
            if(en[x]>en[y]) swap(x,y);
            if(Q[i].lc==x) Q[i].l=en[x],Q[i].r=en[y];
            else Q[i].l=ex[x], Q[i].r=en[y];
            Q[i].id=i;
        }
        sort(Q,Q+m);
        compute();
        repf(i,0,m) cout<<ans[i]<<endl;
    }
}

int main()
{
    IOS;
    ll t;
    // cin>>t;
    t=1;
    ll tt=1;
    while(t--)
    {
        solve(tt);
        tt++;
    }
}     