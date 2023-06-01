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

const int maxn=1e5 + 1;
int ft[maxn];

void update(int pos,int val){
    for(++pos;pos<maxn;pos+=pos&-pos){
        ft[pos]+=val;
    }
}

int sum(int pos){
    int ans=0;
    for(++pos;pos>0;pos&=pos-1){
        ans+=ft[pos];
    }
    return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	memset(ft,0,sizeof(ft));
	for(int i=0;i<n;i++) update(i,1);
	vector<int> ans(n);
	for(int i=n-1;i>=0;i--){
        int l=0,r=n-1;
        while(l<r){
            int m=(l+r)>>1;
            if(sum(m)>=a[i]+1) r=m;
            else l=m+1;
        }
        update(l,-1);
        ans[n-1-l]=i+1;
	}
	for(int i=0;i<n;i++) cout<<ans[i]<<" ";
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
