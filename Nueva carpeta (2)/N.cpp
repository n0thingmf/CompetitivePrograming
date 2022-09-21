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

int x[3]={5,7,5};
bool isvowel(char c){
    return c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n[3];
        cin>>n[0]>>n[1]>>n[2];
        bool ok=true;
        for(int i=0;i<3;i++){
            int cnt=0,delta=0;
            for(int j=0;j<n[i];j++){
                string s;
                cin>>s;
                for(int k=0;k<s.size();k++){
                    if(isvowel(s[k])){
                        cnt++;
                    }else if(s[k]=='Y' || s[k]=='y'){
                        delta++;
                    }
                }
            }
            if(!(cnt<=x[i] && x[i]<=cnt+delta)){
                ok=false;
            }
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
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
