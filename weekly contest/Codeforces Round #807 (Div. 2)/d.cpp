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
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<int> x(n-1),y(n-1);
        int s1=0,s2=0;
        for(int i=0;i<n-1;i++){
            int a=s[i]=='1',b=s[i+1]=='1';
            x[i]=a^b;
            s1+=x[i];
        }
        for(int i=0;i<n-1;i++){
            int a=t[i]=='1',b=t[i+1]=='1';
            y[i]=a^b;
            s2+=y[i];
        }
        if(s1!=s2) cout<<"-1\n";
        else{
            for(int i=0;i<n;i++){

            }
        }

	}
	cout << setprecision(12) << fixed;
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
