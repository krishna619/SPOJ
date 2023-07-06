#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100000
ll dp[MAX];
void compute(vector<ll>& arr){
    for(int i=1;i<MAX;i++){
        arr[i]=i;
    }
    for(int i=2;i<MAX;i++){                                         
        if(arr[i]==i){
            for(int j=i;j<MAX;j+=i){
                arr[j]-=arr[j]/i;
            }
        }
    }
}
void sum(vector<ll>& phi)
{
    dp[2]=1;
    dp[3]=2;
    for(int i=4;i<MAX;i++){
        dp[i]=i-phi[i]+dp[i-1];
    }
    
}
int main()

{ 
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> vec(MAX,0);
    compute(vec);
    sum(vec);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        int n;
        cin>>n;
        ll ans=dp[n];
        cout<<"Case"<<" "<<i++<<":"<<" "<<ans<<endl;
    }
    
    
return 0;
}   