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

struct Trie{
    Trie *nxt[2];
};

void insert(ll x, Trie* r)
{
    Trie* p=r;
    repb(i,30,0)
    {
        ll k=((1LL<<i)&x)?1:0;
        if(!p->nxt[k]) 
        {
            p->nxt[k]=new Trie;
        }
        p=p->nxt[k];
    }
}

ll query(ll x, Trie* r)
{
    Trie* p=r;
    ll ans=0;
    repb(i,30,0)
    {
        ll k=((1LL<<i)&x)?1:0;
        if(p->nxt[k^1]) 
        {
            ans+=1LL<<i;
            p=p->nxt[k^1];
        }
        else p=p->nxt[k];
    }
    return ans;
}

int main()
{
    IOS;
    ll n,m;
    cin>>n;
    Trie *root=new Trie;
    ll a[n];
    repf(i,0,n) 
    {
        cin>>a[i];
        insert(a[i],root);
    }
    cin>>m;
    repf(i,0,m)
    {
        ll x;
        cin>>x;
        cout<<query(x,root)<<endl;
    }
}     
