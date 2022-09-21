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
        string s;
        cin>>s;
        vector<int> a;
        vector<int> val(n);
        for(int i=0;i<s.size();i++){
            val[i]=s[i]-'0';
        }
        int cnt=1;
        bool ok=false;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else{
                if(cnt&1){
                    ok=!ok;
                }
                if(ok) val[i]=val[i-1]=2;
                a.pb(cnt),cnt=1;
            }
        }
        if(cnt&1){
            ok=!ok;
        }
        if(ok) val[n-1]=val[n-2]=2;
        a.pb(cnt);
        int last=val[0];
        int res=0;
        for(int i=1;i<n;i++){
            if(last==2 || val[i]==last || val[i]==2){
                if(last==2) last=val[i];
            }else{
                last=val[i];
                res++;
            }
        }
        res++;
        /*int res2=0;
        for(int i=n-2;i>=0;i--){
            if(val[i]!=val[i+1] && val[i]!=2) res2++;
        }*/


        int ans=0;
        last=-1;
        for(int i=0;i<a.size();i++){
            if(a[i]&1){
                if(last==-1) last=i;
                else ans+=i-last,last=-1;
            }
        }
        cout<<ans<<" "<<res<<"\n";
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
