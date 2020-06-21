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

struct Tr{
    Tr *nxt[2];
};

const ll MX=300001;
ll a[MX];
Tr *S[4*MX];

void insert(ll x, Tr *s)
{
    Tr *p=s;
    repb(i,30,0)
    {
        ll k=(1LL<<i)&x?1:0;
        if(!p->nxt[k]) 
        {
            p->nxt[k]=new Tr();
        }
        p=p->nxt[k];
    }
}

ll query(Tr *s, ll x)
{
    Tr *p=s;
    ll ans=0;
    repb(i,30,0)
    {
        ll k=(1LL<<i)&x?1:0;
        if(p->nxt[k^1]) 
        {
            ans+=1LL<<i;
            p=p->nxt[k^1];
        }
        else p=p->nxt[k];
    }
    return ans;
}

void combine(Tr* &s, Tr *n1, Tr *n2)
{
    if(!n1 && !n2) return;
    s=new Tr();
    if(!n1) {s=n2;return;}
    if(!n2) {s=n1;return;}
    combine(s->nxt[0],n1->nxt[0],n2->nxt[0]);
    combine(s->nxt[1],n1->nxt[1],n2->nxt[1]);
}

void build(ll id, ll st, ll en)
{
    if(st==en)
    {
        S[id]=new Tr();
        insert(a[st],S[id]);
        return;
    }
    ll mid=(st+en)/2;
    build(2*id,st,mid);
    build(2*id+1,mid+1,en);
    combine(S[id],S[2*id],S[2*id+1]);
}

ll query(ll id, ll st, ll en, ll l, ll r, ll x)
{
    if(l>en || r<st) return 0;
    if(l<=st && r>=en)
    {
        return query(S[id],x);
    }
    ll mid=(st+en)/2;
    return max(query(2*id,st,mid,l,r,x),query(2*id+1,mid+1,en,l,r,x));
}

int main()
{
    IOS;
    ll n;
    cin>>n;
    repf(i,0,n) cin>>a[i];
    build(1,0,n-1);
    ll m;
    cin>>m;
    while(m--)
    {
        ll l,r,x;
        cin>>l>>r>>x;
        --l,--r;
        cout<<query(1,0,n-1,l,r,x)<<endl;
    }
}     