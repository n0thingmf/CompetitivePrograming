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

int f(int k,int cx,int cy,int x,int y){
    int ans=cx-k<=x && x<=cx+k && cy-k<=y && y<=cy+k;
    if(k==1) return ans;
    else{
        int k2=k/2;
        return f(k2,cx-k,cy-k,x,y)+f(k2,cx-k,cy+k,x,y)+f(k2,cx+k,cy-k,x,y)+f(k2,cx+k,cy+k,x,y)+ans;
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k,x,y;
	while(cin>>k>>x>>y && x!=0 && y!=0 && k!=0){
        cout<<right<<setw(3)<<f(k,1024,1024,x,y)<<"\n";
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
