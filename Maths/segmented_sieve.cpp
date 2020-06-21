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

bool isprime[1000001];
vector<ll> prime;
 
void sieve()
{
    memset(isprime,true,sizeof isprime);
    isprime[0]=isprime[1]=false;
    repf(i,2,1000001)
    {
        if(isprime[i])
        {
            for(ll j=2*i;j<1000001;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    repf(i,2,1000001) if(isprime[i]) prime.pb(i);
}

void printPrimes(ll l, ll r)
{
    bool isp[r-l+1];
    memset(isp,true,sizeof isp);
    for(ll i=0;prime[i]*prime[i]<=r;i++)
    {
        ll cur=prime[i];
        ll base=(l/cur)*cur;
        if(base<l) l+=cur;
        for(ll j=base;j<=r;j+=cur)
        {
            isp[j-l]=false;     
        }
        if(base==cur) isp[base-l]=true;
    }
    repf(i,0,r-l+1)
    {
        if(isp[i]) cout<<i+l<<endl;
    }
}

int main()
{
    IOS;
    sieve();
    ll t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        printPrimes(l,r);
    }
}     