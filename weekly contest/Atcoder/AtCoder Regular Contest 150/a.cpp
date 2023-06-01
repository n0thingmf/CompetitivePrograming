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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int l=n,r;
        for(int i=0;i<n;i++){
            if(s[i]=='1') l=min(l,i),r=i;
        }
        if(l==n){
            int delta=0,cnt=0,now=0;
            for(int i=0;i<n;i++){
                if(s[i]!='?'){
                    if(now>delta){
                        delta=now;
                        cnt=1;
                    }else if(now==delta){
                        cnt++;
                    }
                    now=0;
                }
                else now++;
            }
            if(now>delta){
                delta=now;
                cnt=1;
            }else if(now==delta){
                cnt++;
            }
            if(delta==k && cnt==1) cout<<"Yes\n";
            else cout<<"No\n";
        }else{
            bool ok=true;
            for(int i=l;i<=r;i++){
                if(s[i]=='0'){
                    ok=false;
                }
            }
            if(!ok){
                cout<<"No\n";
                continue;
            }
            int now=r-l+1;
            int delta1=0,delta2=0;
            for(int i=l-1;i>=0;i--){
                if(s[i]=='?') delta1++;
                else break;
            }
            for(int i=r+1;i<n;i++){
                if(s[i]=='?') delta2++;
                else break;
            }
            if(now>k) cout<<"No\n";
            else if(now==k) cout<<"Yes\n";
            else if(now+delta1>=k && delta2==0) cout<<"Yes\n";
            else if(now+delta2>=k && delta1==0) cout<<"Yes\n";
            else if(now+delta1+delta2==k) cout<<"Yes\n";
            else cout<<"No\n";
        }
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
