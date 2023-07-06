#include <bits/stdc++.h>
using namespace std;
#define MAX 10000000

int cnt[10];
bool arePermutations(int a, int b){
    for(int i = 0; i < 10; i ++){
        cnt[i] = 0;
    }
    while(a > 0){
        cnt[a % 10] ++;
        a /= 10;
    }
    while(b > 0){
        cnt[b % 10] --;
        b /= 10;
    }
    for(int i = 0; i < 10; i ++){
        if(cnt[i] != 0){
            return false;
        }
    }
    return true;
}

void compute(vector<int>& phi){
    for (int i = 1;i<MAX; ++i) {
        phi[i]=i;
    }
    for(int i=2;i<MAX;i++){
        if(phi[i]==i){
            for(int j=i;j<MAX;j+=i) {
                phi[j]-=phi[j]/i;
            }
        }
    }

}
void permutation(vector<int>& phi,vector<int>& ans){
    double last_ratio=INT_MAX;
    int last_permutation =-1;
    ans[1]=-1;
    for (int i = 2; i<MAX; ++i) {
        ans[i]=last_permutation;
        if(arePermutations(phi[i],i)){
            double result = static_cast<double>(i) / phi[i];
            if(result < last_ratio || (result == last_ratio && i > last_permutation)){
                last_ratio=result;
                last_permutation = i;
                ans[i]=last_permutation;
            }

            
        }
    }
}
int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    vector<int> phi(MAX,0);
    vector<int> ans(MAX,0);
    compute(phi);
    permutation(phi,ans);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(ans[n]==-1) cout<<"No solution."<<endl;
        else cout<<ans[n]<<endl;
    }
return 0;
}