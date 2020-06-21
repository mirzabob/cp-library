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

map<ll,ll> mp;

ll lp[1000001];

void prime()
{
    repf(i,1,1000001) lp[i]=i;
    repf(i,2,1000001)
    {
        if(lp[i]==i)
        {
            for(ll j=2*i;j<1000001;j+=i)
            {
                if(lp[j]==j) lp[j]=i;
            }
        }
    }
}

void factorize(ll n)
{
    while(n!=lp[n])
    {
        mp[lp[n]]++;
        n/=lp[n];
    }
    if(lp[n]>1) mp[lp[n]]++;
}

int main()
{
    IOS;
    prime();
    ll n;
    cin>>n;
    factorize(n);
    for(auto i:mp)
    {
        cout<<i.fi<<"->"<<i.se<<endl;
    }
}     