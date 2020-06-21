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

ll phi[1000001];

void ETF()
{
    repf(i,1,1000001) phi[i]=i;
    repf(i,2,1000001)
    {
        if(phi[i]==i)
        {
            for(ll j=i;j<1000001;j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
}

int main()
{
    IOS;
    ETF();
    ll n;
    cin>>n;
    cout<<phi[n]<<endl;
}     