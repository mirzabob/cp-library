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

ll gcd(ll a, ll b)
{
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

int main()
{
    IOS;
    cout<<gcd(4,6)<<endl;    
}     