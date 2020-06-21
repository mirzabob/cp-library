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

struct Matrix
{
    vector<vector<ll>> mat;
    ll n_rows,n_cols;

    Matrix() {}
    Matrix(vector<vector<ll>> values): mat(values), n_rows(values.size()), n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n)
    {
        vector<vector<ll>> values(n,vector<ll>(n,0));
        repf(i,0,n) values[i][i]=1;
        return values;
    }

    Matrix operator*(const Matrix &other) const
    {
        ll n=n_rows, m=other.n_cols;    
        vector<vector<ll>> result(n,vector<ll>(m,0));
        assert(n_cols==other.n_rows);
        repf(i,0,n)
        {
            repf(j,0,m)
            {
                repf(k,0,n_cols)
                {
                    result[i][j]=(result[i][j]+(mat[i][k]*other.mat[k][j])%mod)%mod;
                }
            }
        }
        return Matrix(result);
    }   

    inline bool is_square() const
    {
        return n_rows==n_cols;
    }
};

Matrix fast_expo(Matrix m, ll p)
{
    assert(m.is_square());
    Matrix result=Matrix::identity_matrix(m.n_rows);
    while(p)
    {
        if(p&1)
        {
            result=result*m;
        }
        m=m*m;
        p>>=1;
    }
    return result;
}


int main()
{
    IOS;
    Matrix M({
        {1,0,0},
        {0,1,0},
        {0,0,1}
    });
    Matrix R=fast_expo(M,2);
    repf(i,0,R.n_rows)
    {
        repf(j,0,R.n_cols)
        {
            cout<<R.mat[i][j]<<" ";
        }
        cout<<endl;
    }
}     