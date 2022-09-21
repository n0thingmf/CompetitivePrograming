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
        vector<int> str(n);
        for(int i=0;i<n;i++){
            if(s[i]=='1') str[i]=1;
            else str[i]=0;
        }
        vector<int> ans(n,0);
        if(n==1){
            cout<<str[0]<<"\n";
            cout<<k<<"\n";
            continue;
        }
        if(k&1){
            if(s[0]=='1'){
                ans[0]++,k--;
                        for(int j=0;j<n;j++){
                            if(0==j) continue;
                            str[j]=str[j]^1;
                        }
            }
            else{
                for(int i=0;i<n;i++){
                    if(str[i]==1){
                        ans[i]++,k--;
                        for(int j=0;j<n;j++){
                            if(i==j) continue;
                            str[j]=str[j]^1;
                        }
                        break;
                    }
                }
                if(k&1){
                    ans[n-1]++,k--;
                        for(int j=0;j<n;j++){
                            if(n-1==j) continue;
                            str[j]=str[j]^1;
                        }
                }
            }
        }
                int last=-1;
                for(int i=0;i<n && k>0;i++){
                    if(str[i]==0){
                        if(last!=-1){
                            ans[last]++,ans[i]++;
                            str[last]^=1;
                            str[i]^=1;
                            k-=2;
                            last=-1;
                        }else last=i;
                    }
                }
                if(k>0){
                    if(last==n-1 || last==-1) ans[n-1]+=k;
                    else{
                        ans[last]++,ans[n-1]++;
                        str[last]^=1;
                        str[n-1]^=1;
                        k-=2;
                        ans[n-1]+=k;
                    }
                }
        for(int i=0;i<n;i++) cout<<str[i];
        cout<<"\n";
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<"\n";
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
