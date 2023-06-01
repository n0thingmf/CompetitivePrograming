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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int ans=0;
	vector<map<char,int>> f((k+1)/2);7
	for(int i=0;i<(n+1)/2;i+=k){
        for(int j=0;j<(k+1)/2;j++){
            set<int> st;
            st.insert(i+j);
            st.insert(i+k-j-1);
            st.insert(n-i-j-1);
            st.insert(n-i-k+j);
            for(int x:st){
                //cout<<x<<" ";
                f[j][s[x]]++;
            }
            //cout<<"\n";
        }
	}
	for(int j=0;j<(k+1)/2;j++){
        int mx=-1,sz=0;
        for(auto x:f[j]){
            sz+=x.second;
            mx=max(mx,x.second);
        }
        ans+=sz-mx;
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
