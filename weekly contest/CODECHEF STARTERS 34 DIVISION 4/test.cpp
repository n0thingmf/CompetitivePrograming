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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n=7;
	vector<int> a(n),ans;
	for(int i=0;i<n;i++) a[i]=i+1;
	bool res=false;
	do{
        bool ok=true;
        for(int i=0;i<n;i++) if(a[i]==i+1) ok=false;
        if(ok){
            int val=0;
            for(int i=0;i<n;i++){
                val^=abs(i+1-a[i]);
            }
            if(val==0){
                ans=a;
                res=true;
            }
        }
	}while(next_permutation(all(a)));
	if(res){
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<"\n";
	}else cout<<"no existe"<<"\n";
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
