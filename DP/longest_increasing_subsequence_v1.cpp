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

typedef
tree<
	pair<int, int>,
	null_type,
	less<pair<int, int>>,
	rb_tree_tag,
	tree_order_statistics_node_update>
ordered_set;

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

int main() //Longest Non decreasing Subsequence
{
    IOS;
    ll n;
    cin>>n;
    ll a[n];
    repf(i,0,n) cin>>a[i];
    multiset<ll> st;
    repf(i,0,n)
    {
        st.insert(a[i]);
        auto it=st.upper_bound(a[i]);
        if(it!=st.end())
        {
            st.erase(it);
        }
    }
    cout<<st.size()<<endl;
}     

/*
int main() //Longest Strictly Increasing Subsequence
{
    IOS;
    ll n;
    cin>>n;
    ll a[n];
    repf(i,0,n) cin>>a[i];
    multiset<ll> st;
    repf(i,0,n)
    {
        st.insert(a[i]);
        auto it=st.lower_bound(a[i]);
        ++it;
        if(it!=st.end())
        {
            st.erase(it);
        }
    }
    cout<<st.size()<<endl;
}  
*/