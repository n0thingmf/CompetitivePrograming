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
const int N = 3005;
int n, m;
vector<vector<int>> a;
struct Node {
    int mn;
};

struct SegmentTree2D {
    vector<vector<Node>> t=vector<vector<Node>>(4*n,vector<Node>(4*m));

    void build(int px, int lx, int rx, int py, int ly, int ry) {
        if (lx == rx && ly == ry) {
            t[px][py].mn = a[lx][ly];
            return;
        }
        int mx = lx + rx >> 1, my = ly + ry >> 1;
        build(px << 1, lx, mx, py << 1, ly, my);
        build(px << 1, mx + 1, rx, py << 1, ly, my);
        build(px << 1, lx, mx, py << 1 | 1, my + 1, ry);
        build(px << 1 | 1, mx + 1, rx, py << 1 | 1, my + 1, ry);
        t[px][py].mn = min({t[px << 1][py << 1].mn, t[px << 1][py << 1 | 1].mn, t[px << 1 | 1][py << 1].mn, t[px << 1 | 1][py << 1 | 1].mn});
    }

    int query(int px, int lx, int rx, int py, int ly, int ry, int xl, int xr, int yl, int yr) {
        if (xl <= lx && rx <= xr && yl <= ly && ry <= yr) {
            return t[px][py].mn;
        }
        int mx = lx + rx >> 1, my = ly + ry >> 1;
        int res = 1e9;
        if (xl <= mx && yl <= my) {
            res = min(res, query(px << 1, lx, mx, py << 1, ly, my, xl, xr, yl, yr));
        }
        if (xl <= mx && my < yr) {
            res = min(res, query(px << 1, lx, mx, py << 1 | 1, my + 1, ry, xl, xr, yl, yr));
        }
        if (mx < xr && yl <= my) {
            res = min(res, query(px << 1 | 1, mx + 1, rx, py << 1, ly, my, xl, xr, yl, yr));
        }
        if (mx < xr && my < yr) {
            res = min(res, query(px << 1 | 1, mx + 1, rx, py << 1 | 1, my + 1, ry, xl, xr, yl, yr));
        }
        return res;
    }
};


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        cin>>n>>m;
        a=vector<vector<int>>(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin>>a[i][j];
        }

        SegmentTree2D st;
        st.build(1, 1, n, 1, 1, m);
        auto stmin = [&](int x1,int y1,int x2,int y2) -> int {
            return st.query(1, 1, n, 1, 1, m, x1, x2, y1, y2);
        };

        //cout<<stmin(0,0,n-1,m-1)<<"\n";
        int left=1,right=n;
        while(left<right){
            int mid=(left+right+1)>>1;
            bool ok=false;
            for(int i=0;i+mid-1<n;i++){
                for(int j=0;j+mid-1<m;j++){
                    if(stmin(i+1,j+1,i+mid,j+mid)>=mid){
                        ok=true;
                    }
                }
            }
            if(ok) left=mid;
            else right=mid-1;
        }
        cout<<left<<"\n";
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
