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
const int maxn=1e5;
int ft[maxn+1];
void add(int pos,int val){
    for(++pos;pos<=maxn;pos+=pos&-pos){
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
int query(int l,int r){
    return sum(r)-sum(l-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(ft,0,sizeof(maxn));
	add(0,5);
	add(2,12);
	add(4,4);
	add(1,7);
	add(3,2);
	cout<<sum(4);
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
