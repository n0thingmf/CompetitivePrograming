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
    int need=0;
    for(int i=0;i<n;i++){
        int j=n-1-i;
        if(i<j){
            if(s[i]!=s[j]) need++;
        } else break;
    }
    if(need>k) cout<<"-1\n";
    else{
        int over=k-need;
        for(int i=0;i<n;i++){
            int j=n-1-i;
            if(i<j){
                if(s[i]!=s[j]){
                    s[i]=s[j]=max(s[i],s[j]);
                    if(s[i]!='9' && over>0) s[i]=s[j]='9',over--;
                }else{
                    if(s[i]!='9' && over>1) s[i]=s[j]='9',over-=2;
                }
            }else if(i==j){
                if(s[i]!=9 && over>0) s[i]='9',over--;
            }else break;
        }
        cout<<s<<"\n";
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
