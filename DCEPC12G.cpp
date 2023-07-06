#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 10000000

ll dp[MAX+1];
ll isPrime[MAX+1];
ll fn[MAX+1];
ll phi[MAX+1];
ll fact[MAX+1];
ll ans=0;
ll mod = 1e9+7;
ll power(long long x, long long y) {

    if(y==0) return 1%mod;
    if(y==1) return x%mod;
    ll temp = power(x, y / 2);
    if(y%2==0) return (temp*temp)%mod;
    else return (x*temp*temp)%mod;
}
void sieve(){
    isPrime[1]=0;
    for (ll i = 2; i<=MAX; ++i) {
        isPrime[i]=1;
    }
    for(int i=2;i<=MAX;i++){                                         
        if(isPrime[i]==1){
            for(int j=i+i;j<=MAX;j+=i){
                isPrime[j]=0;
            }
        }
    }
}
void compute(){
    for(int i=1;i<MAX;i++){
        phi[i]=i;
    }
    for(int i=2;i<MAX;i++){                                         
        if(phi[i]==i){
            for(int j=i;j<MAX;j+=i){
                phi[j]-=phi[j]/i;
            }
        }
    }
}
void sum()
{
    dp[2]=1;
    fn[2]=0;
    fn[1]=0;
    for(int i=3;i<MAX;i++){
        if(isPrime[i]){
            dp[i]=dp[i-1]+1;
            
        }
        else{
            dp[i]=dp[i-1];
        }
        fn[i]=(dp[i]-phi[i])>0?dp[i]-phi[i]:0;
        

    }
    fact[0]=1;
    for(int i=1;i<3;i++){
        fact[i]= (fact[i-1] * i) % mod;
    }
    
}
int main()

{ 
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    compute();
    sieve();
    sum();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<power(phi[n],fact[f[n]])<<endl;
    }
    
    
return 0;
}   