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

ordered_set<ll> dp;

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

const ll MX=200001;
ll a[MX];
ll S[4*MX],lazy[4*MX];

void build(ll id, ll st, ll en)
{
    if(st==en)
    {
        S[id]=a[st];
        return;
    }
    ll mid=(st+en)/2;
    build(2*id,st,mid);
    build(2*id+1,mid+1,en);
    S[id]=min(S[2*id],S[2*id+1]);
}

void push(ll id)
{
    S[2*id]+=lazy[id];
    lazy[2*id]+=lazy[id];
    S[2*id+1]+=lazy[id];
    lazy[2*id+1]+=lazy[id];
    lazy[id]=0;
}

void modify(ll id, ll st, ll en, ll l, ll r, ll v)
{
    if(l>en || r<st) return;
    if(l<=st && r>=en)
    {
        S[id]+=v;
        lazy[id]+=v;
        return;
    }
    push(id);
    ll mid=(st+en)/2;
    modify(2*id,st,mid,l,r,v);
    modify(2*id+1,mid+1,en,l,r,v);
    S[id]=min(S[2*id],S[2*id+1]);
}

ll query(ll id, ll st, ll en, ll l, ll r)
{
    if(l>en || r<st) return 1e18;
    if(l<=st && r>=en)
    {
        return S[id];
    }
    push(id);
    ll mid=(st+en)/2;
    return min(query(2*id,st,mid,l,r),query(2*id+1,mid+1,en,l,r));
}

void solve()
{
    ll n;
    cin>>n;
    repf(i,0,n) cin>>a[i];
    build(1,0,n-1);
    ll m;
    cin>>m;
    while(m--)
    {
        string str;
        getline(cin>>ws,str);
        stringstream s(str);
        ll l,r,v;
        s>>l;
        s>>r;
        if(s>>v)
        {
            if(r<l)
            {
                modify(1,0,n-1,0,r,v);
                modify(1,0,n-1,l,n-1,v);
            }
            else
            {
                modify(1,0,n-1,l,r,v);
            }
        }
        else
        {
            if(r<l)
            {
                cout<<min(query(1,0,n-1,0,r),query(1,0,n-1,l,n-1))<<endl;
            }
            else
            {
                cout<<query(1,0,n-1,l,r)<<endl;
            }
        }
    }
}

int main()
{
    IOS;
    ll t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}     