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

int n=10,m=100,cnt=0;
bool a[10][100];
void backtrack(int x,y){
    if(x==n && y==m){
        cnt++;
        for(int i=0;i<n;i++) cout<<a[i];
        cout<<"\n";
        return;
    }
    backtrack(pos+1);
    if(pos<n-1){
        a[pos]=a[pos+1]=true;
        backtrack(pos+2);
        a[pos]=a[pos+1]=false;
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	backtrack(0);
	cout<<cnt<<"\n";
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
