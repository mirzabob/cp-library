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

vector<pair<ll,ll>> v[100001];
ll d[100001];

void bfs(ll x)
{
    deque<ll> q;
    q.push_back(x);
    d[x]=0;
    while(!q.empty())
    {
        ll u=q.front();
        q.pop_front();
        for(auto i:v[u])
        {
            if(d[i.fi]>d[u]+i.se)
            {
                d[i.fi]=d[u]+i.se;
                if(d[i.fi]) q.push_back(i.fi);
                else q.push_front(i.fi);
            }
        }
    }
}

int main()
{
    IOS;
    ll n,m;
    cin>>n>>m;
    repf(i,0,m)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        v[x].pb({y,w});
        v[y].pb({x,w});
    }
    repf(i,1,n+1) d[i]=1e18;
    bfs(1);
    repf(i,1,n+1) cout<<d[i]<<endl;
}     