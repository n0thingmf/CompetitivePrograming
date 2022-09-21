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

double read(string s){
    int a,b,c,d;
    if(s.size()==5) a=0,b=s[1]-'0',c=s[3]-'0',d=s[4]-'0';
    if(s.size()==6) a=s[1]-'0',b=s[2]-'0',c=s[4]-'0',d=s[5]-'0';
    return 1000*a+100*b+10*c+d;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(12) << fixed;
	int n;
	cin>>n;
	string s;
	int now;
	cin>>s;
	now=read(s);
	int ans=0;
	for(int i=0;i<n;i++){
        int add;
        cin>>s;
        add=read(s);
        now+=add;
        if(now%100!=0) ans++;
	}
	cout<<ans<<"\n";
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
