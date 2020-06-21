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

unordered_map<ll,ll> tr[2];
ll root;

void insert(ll x)
{
    ll p=0;
    repb(i,30,0)
    {
        ll k=(1LL<<i)&x?1:0;
        if(!tr[k][p]) 
        {
            root++;
            tr[k][p]=root;
        }
        p=tr[k][p];
    }
}

ll query(ll x)
{
    ll p=0;
    ll ans=0;
    repb(i,30,0)
    {
        ll k=(1LL<<i)&x?1:0;
        if(tr[k^1][p]) 
        {
            ans+=1LL<<i;
            p=tr[k^1][p];
        }
        else p=tr[k][p];
    }
    return ans;
}

int main()
{
    IOS;
    ll n,m;
    cin>>n;
    ll a[n];
    repf(i,0,n) 
    {
        cin>>a[i];
        insert(a[i]);
    }
    cin>>m;
    repf(i,0,m)
    {
        ll x;
        cin>>x;
        cout<<query(x)<<endl;
    }
}     
