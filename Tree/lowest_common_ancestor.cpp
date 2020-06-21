#include<bits/stdc++.h>
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

vector<ll> v[200001];
ll D[200001][22];
ll depth[200001];

void dfs(ll x, ll p, ll h=0)
{
    D[x][0]=p;
    depth[x]=h;
    repf(i,1,22)
    {
        if(D[x][i-1]!=-1 && D[D[x][i-1]][i-1]!=-1)
        {
            D[x][i]=D[D[x][i-1]][i-1];
        }
    }
    for(auto i:v[x])
    {
        if(i==p) continue;
        dfs(i,x,h+1);
    }
}

ll walk(ll x, ll k)
{
    repf(i,0,22)
    {
        if((1<<i)&k)
        {
            x=D[x][i];
        }
    }
    return x;
}

ll lca(ll x, ll y)
{
    if(depth[x]>depth[y]) x=walk(x,depth[x]-depth[y]);
    if(depth[y]>depth[x]) y=walk(y,depth[y]-depth[x]);
    if(x==y) return x;
    repb(i,21,0)
    {
        if(D[x][i]!=D[y][i])
        {
            x=D[x][i];
            y=D[y][i];   
        }
    }
    return D[x][0];
}

int main()
{
    IOS;
    memset(D,-1,sizeof D);
    ll n;
    cin>>n;
    repf(i,0,n-1)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x); 
    }    
    dfs(1,-1);
    ll q;
    cin>>q;
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<endl;
    }
}     