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
	int t;
	cin>>t;
	while(t--){
        string w;
        cin>>w;
        int n=w.size();
        vector<int> s(n);
        if(w[0]=='B') s[0]=1;
        else s[0]=-1;
        for(int i=1;i<n;i++){
            if(w[i]=='B') s[i]=s[i-1]+1;
            else s[i]=s[i-1]-1;
        }
        vector<int> l(n),r(n);
        l[0]=s[0];
        for(int i=1;i<n;i++) l[i]=min(l[i-1],s[i]);
        r[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--) r[i]=min(r[i+1],s[i]);
        bool ok=false;
        if(l[n-1]>=0){
            cout<<"0\n";
            ok=true;
        }
        for(int i=0;i+1<n && !ok;i++){
            if(l[i]-s[i]>=0 && r[i+1]-s[i]>=0){
                ok=true;
                cout<<i+1<<"\n";
            }
        }
        if(!ok) cout<<"-1\n";
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
