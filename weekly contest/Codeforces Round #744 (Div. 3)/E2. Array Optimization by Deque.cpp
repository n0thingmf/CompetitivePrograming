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

vector<int> ft;
void add(int pos,int val){
    for(++pos;pos<ft.size();pos+=pos&-pos) ft[pos]+=val;
}
int sum(int pos){
    int ans=0;
    for(++pos;pos>0;pos&=pos-1) ans+=ft[pos];
    return ans;
}
int query(int l,int r){
    return sum(r)-sum(l-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int> a2=a;
        sort(all(a2));
        a2.erase(unique(all(a2)),a2.end());
        ft.assign(a2.size()+1,0);
        for(int i=0;i<n;i++) a[i]=lower_bound(all(a2),a[i])-a2.begin();
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=min(sum(a[i]-1),query(a[i]+1,a2.size()-1));
            add(a[i],1);
        }
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
