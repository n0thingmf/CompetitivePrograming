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
        int l,r;
        cin>>l>>r;
        vector<int> a(r-l+1);
        for(int i=l;i<=r;i++){
            cin>>a[i-l];
        }
        int ans=0,delta=1;
        sort(all(a));
        while(l<=r){
            if((r-l+1)%2){
                for(int i=l;i<=r;i++){
                    ans^=a[i-l]^i;
                }
                break;
            }else if(l%2){
                vector<int> pos;
                for(int i=l;i<=r;i++){
                    if(i<r && a[i-l]%2==0 && a[i-l+1]==a[i-l]+1){
                        i++;
                    }else{
                        pos.pb(a[i-l]);
                    }
                }
                assert(pos.size()==2);
                bool aea=true;
                ans=pos[0]^l;
                for(int i=l;i<=r;i++){
                    if((a[i-l]^ans)<l || (a[i-l]^ans)>r){
                        aea=false;
                        break;
                    }
                }
                if(aea) break;
                ans=pos[0]^r;
                break;
            }else{
                for(int i=0;i<(r-l+1)/2;i++){
                    a[i]=a[2*i]/2;
                }
                r=l/2+(r-l+1)/2-1;
                l=l/2;
                delta*=2;
            }
        }
        cout<<ans*delta<<"\n";
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
