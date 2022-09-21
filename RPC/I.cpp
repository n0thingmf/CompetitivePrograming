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

int n;
int solve(int i,vector<int> &num){
    if(i==n-1){
        return min(num[i],11-num[i]);
    }
    if(num[i]>=6){
        for(int j=0;j<n-1;j++) num[j]=9-num[j];
        num[n-1]=10-num[n-1];
        return 1+num[i]+solve(i+1,num);
    }else{
        return num[i]+solve(i+1,num);
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	n=s.size();
	vector<int> num(n);
	for(int i=0;i<n;i++) num[i]=s[i]-'0';
    cout<<solve(0,num)<<"\n";
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
