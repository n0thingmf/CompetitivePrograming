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
vector<int> z_fun(string s){
    int n=s.size();
    vector<int> z(n,0);
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i<=r) z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r){
            r=i+z[i]-1;
            l=i;
        }
    }
    return z;
}
vector<int> p_fun(string s){
    int n=s.size();
    vector<int> phi(n,0);
    for(int i=1;i<n;i++){
        int j=phi[i-1];
        while(j>0 && s[i]!=s[j]) j=phi[j-1];
        j+=s[i]==s[j];
        phi[i]=j;
    }
    return phi;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s,t;
	cin>>s>>t;
	int n=s.size(),m=t.size();
	vector<int> z=z_fun(t+"#"+s);
	vector<int> p=p_fun(t);
	vector<int> cnt(m+1,0);
	for(int i=0;i<m;i++){
        if(p[i]!=0) cnt[i-p[i]+1]++;
	}
	for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
	ll ans=m;
	for(int i=1;i<n;i++){
        //if(z[m+1+i]>0) ans+=m-cnt[z[m+1+i]-1];
        //else ans+=m;
        ans+=m-cnt[z[m+1+i]];
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
