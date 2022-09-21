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
        int t0=0,t1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') t0++;
            else t1++;
        }
        if(abs(t0-t1)%2==1){
            cout<<"NO\n";
            continue;
        }
        int target=(t0-t1)/2;
        map<int,int> f;
        f[0]=-1;
        int r0=0,r1=0,ansl,ansr;
        bool ok=false;
        for(int i=0;i<n && !ok;i++){
            if(s[i]=='0'){
                r0++;
                if(f.count(r0-r1-target)){
                    ok=true;
                    ansl=f[r0-r1-target]+1;
                    ansr=i;
                }
                f[r0-r1]=i;
            }else{
                r1++;
                if(f.count(r0-r1-target)){
                    ok=true;
                    ansl=f[r0-r1-target]+1;
                    ansr=i;
                }
                f[r0-r1]=i;
            }
        }
        if(ok){
            cout<<"YES\n";
            cout<<ansl+1<<" "<<ansr+1<<"\n";
        }else cout<<"NO\n";
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
