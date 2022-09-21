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

const int maxn=5e3;

int ft[2][maxn+1];

void add(int id,int pos,int val){
    for(++pos;pos<=maxn;pos+=pos&-pos){
        ft[id][pos]+=val;
    }
}
int sum(int id,int pos){
    int ans=0;
    for(++pos;pos>0;pos&=pos-1){
        ans+=ft[id][pos];
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<int> p(n);
        for(int i=0;i<n;i++) cin>>p[i];
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>i;j--){
                ans+=1ll*sum(0,p[j]-1)*sum(1,p[i]-1);
                add(1,p[j],1);
            }
            memset(ft[1],0,sizeof(ft[1]));
            add(0,p[i],1);

        }
        memset(ft[0],0,sizeof(ft[0]));
        cout<<ans<<"\n";
	}
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
