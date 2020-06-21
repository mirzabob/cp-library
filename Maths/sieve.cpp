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

void prime()
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
}

int main()
{
    IOS;
    prime();
    repf(i,1,100)
    {
        cout<<isprime[i]<<" ";
    }
    cout<<endl;
}     