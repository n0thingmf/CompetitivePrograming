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
	cout << setprecision(12) << fixed;
	int t;
	cin>>t;
	while(t--){
        string t;
        cin>>t;
        int n=t.size()+2;
        string s(1,'0');
        s+=t+"1";
        int i=0,j=1;
        while(i<=n){
            j=i+1;
            while(j<=n && s[j]=='?') j++;
            char rep;
            if(s[i]==s[j]) rep=s[i];
            else rep='0';
            for(int k=i+1;k<j;k++) s[k]=s[i];
            i=j;
        }
        t=s.substr(1,n-2);
        cout<<t<<"\n";
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
