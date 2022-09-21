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

vector<bool> v(26,false);
ll solve(string &s,int i,int j,bool rev){
    if(i==j){
        if(!v[s[i]-'a']) return 1;
        int ind=(rev?-1:1);
        ll ans=1;
        for(int k=i+ind;k>=0 && k<s.size() && !v[s[k]-'a'];k+=ind) ans++;
        return ans;
    }
    if(rev){
        if(!v[s[i]-'a']) return solve(s,i+1,j,true);
        else if(v[s[j]-'a']) return solve(s,i,j-1,false);
    }else{
        if(!v[s[j]-'a']) return solve(s,i,j-1,false);
        else if(v[s[i]-'a']) return solve(s,i+1,j,true);
    }
    return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	v[0]=v[4]=v[8]=v[14]=v[20]=true;
	string s;
	cin>>s;
	cout<<solve(s,0,s.size()-1,false)<<"\n";
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
