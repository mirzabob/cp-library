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

int main()
{
    IOS;
    ll a=1000,b=2000;
    cout<<a%mod<<endl;
    ll sum=(a%mod+b%mod)%mod;
    ll dif=(a%mod-b%mod+mod)%mod;
    ll mul=(a%mod*b%mod)%mod;
    cout<<"Sum: "<<sum<<endl;
    cout<<"Dif: "<<dif<<endl;
    cout<<"Mul: "<<mul<<endl;
}     