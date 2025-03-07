#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define per(i, n) for (int i = n-1; i >=0; i--)
 
#define pb push_back
#define mp make_pair
 
typedef vector<ll> vl;
const int MAXN = 1e6;
double a[MAXN];
double b[MAXN];
double p[MAXN];
 
void solve(){
    int n;
    cin>>n;
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        cin>>b[i];
    }
    rep(i,n){
        if(a[i]+b[i]==0){
            p[i] = 0;
        }
        else p[i] = b[i] / (a[i] + b[i]);
    }
    double tempprob;
    for(int i = 1;i<n;i++){
        tempprob = p[i-1]*(b[i]+1)/(a[i]+b[i]+1) + (1-p[i-1])*(b[i])/(a[i]+b[i]+1);
        p[i] = max(p[i],tempprob);
    }
    cout<<fixed<<setprecision(6)<<p[n-1]<<endl;
}
int main(){
    solve();
    return 0;
}