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

int mlog(ll x) {
    return __builtin_clzll(1ll) - __builtin_clzll(x);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin>>a[i][j];
        }
        int lgn=mlog(n),lgm=mlog(m);
        vector<vector<vector<vector<int>>>> st(1+lgn,vector<vector<vector<int>>>(n,vector<vector<int>>(1+lgm,vector<int>(m))));
        for(int ri=0;ri<n;ri++){
            for(int ci=0;ci<m;ci++) st[0][ri][0][ci]=a[ri][ci];

            for(int cj=1;cj<=lgm;cj++){
                for(int ci=0;(ci+(1<<(cj-1)))<m;ci++){
                    st[0][ri][cj][ci]=min(st[0][ri][cj-1][ci],st[0][ri][cj-1][ci+(1<<(cj-1))]);
                }
            }
        }
        for(int rj=1;rj<=lgn;rj++){
            for(int ri=0;(ri+(1<<(rj-1)))<n;ri++){
                for(int cj=1;cj<=lgm;cj++){
                    for(int ci=0;ci<m;ci++){
                        st[rj][ri][cj][ci]=min(st[rj-1][ri][cj][ci],st[rj-1][ri+(1<<(rj-1))][cj][ci]);
                    }
                }
            }
        }

        auto stmin = [&](int x1,int y1,int x2,int y2) -> int {
            int lenx=x2-x1+1;
            int kx=mlog(lenx);
            int leny=y2-y1+1;
            int ky=mlog(leny);
            int min_R1 = min ( st[kx][x1][ky][y1] , st[kx][x1][ky][y2+1-(1<<ky) ]);
            int min_R2 = min ( st[kx][x2+1-(1<<kx)][ky][y1], st[kx][x2+1-(1<<kx)][ky][y2+1-(1<<ky)]);
            return min(min_R1,min_R2);
        };

        //cout<<stmin(0,0,n-1,m-1)<<"\n";
        int left=1,right=n;
        while(left<right){
            int mid=(left+right+1)>>1;
            bool ok=false;
            for(int i=0;i+mid-1<n;i++){
                for(int j=0;j+mid-1<m;j++){
                    if(stmin(i,j,i+mid-1,j+mid-1)>=mid){
                        ok=true;
                    }
                }
            }
            if(ok) left=mid;
            else right=mid-1;
        }
        cout<<left<<"\n";
        st.clear();
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
