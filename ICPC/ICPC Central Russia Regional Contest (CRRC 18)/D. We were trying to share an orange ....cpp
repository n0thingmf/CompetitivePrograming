#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

using namespace std;
int primes[10]={2,3,5,7,11,13,17,19,23,29};
vector<int> res(500,9);

vector<int> mul(vector<int> num,int x){
    vector<int> ans;
    for(int i=0,carry=0;i<num.size();i++){
        int now=num[i]*x+carry;
        ans.pb(now%10);
        carry=now/10;
        if(carry!=0 && i==num.size()-1) num.pb(0);
    }
    return ans;
}
bool cmp(vector<int> &a,vector<int> &b){
    if(a.size()!=b.size()) return a.size()<b.size();
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]!=b[i]) return a[i]<b[i];
    }
    return false;
}
void backtrack(vector<int> now,int k,int maxdiv,int nprime){
    if(k==1){
        if(cmp(now,res)) res=now;
        return;
    }
    for(int i=2;i<=min(k,maxdiv);i++){
        if(k%i==0){
            vector<int> next=now;
            for(int j=0;j<i-1;j++){
                next=mul(next,primes[nprime]);
                if(cmp(res,next)) return;
            }
            backtrack(next,k/i,i,nprime+1);
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin>>k;
	vector<int> num(1,1);
	backtrack(num,k,k,0);
	for(int i=res.size()-1;i>=0;i--) cout<<res[i];
	//cout << setprecision(12) << fixed;
	return 0;
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* bitwise and boolean operations
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
