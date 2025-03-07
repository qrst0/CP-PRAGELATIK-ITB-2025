#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

vector<vector<ll>> matmul(vector<vector<ll>> a, vector<vector<ll>> b, int im, int jm, int km){
    vector<vector<ll>> res(im,vector<ll>(jm,0));
    for(int i=0;i<im;i++){
        for(int j=0;j<jm;j++){
            ll cur=0;
            for(int k=0;k<km;k++){
                cur+=(a[i][k]*b[k][j])%MOD;
                cur%=MOD;
            }
            res[i][j]=cur;
        }
    }
    return res;
}

vector<vector<ll>> matexpo(vector<vector<ll>> a, ll n, ll po){
    vector<vector<ll>> cur(a);
    vector<vector<ll>> res(n,vector<ll> (n,0));
    for (int i = 0; i < n; i++){
        res[i][i] = 1;
    }
    while(po){
        if(po%2){
            res=matmul(cur, res, n, n, n);
        }
        cur=matmul(cur,cur, n, n, n);
        po/=2;
    }
    return res;
}

int main(){
    int n;
    cin>>n;

    vector<ll> a(n,0);
    vector<ll> b(n,0);
    vector<ll> c(n,0);
    vector<ll> d(n,0);
    vector<vector<ll>> cura(1, vector<ll>(n,0));
    vector<vector<ll>> grovec(n,vector<ll> (n,0));

    for(int i = 0; i < n; i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    ll makstaun = b[0];

    for(int i = 0; i < n; i++){
        b[i] = makstaun - b[i];
    }
    
    for(int i = 0; i < n; i++){
        cura[0][i] = a[i];
        grovec[i][i] = c[i] - d[i];
        if(i > 0){
            grovec[i][i-1] = d[i];
        }
        vector<vector<ll>> pengali;
        if(i == n-1){
            pengali = matexpo(grovec,n ,makstaun - b[i]);
        }
        else{
            pengali = matexpo(grovec,n ,b[i+1] - b[i]);
        }
        cura = matmul(cura, pengali, 1, n , n);
    }
    for(int i = 0; i < n; i++){
        cout<<cura[0][i]<<endl;
    }
}