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

class rectan{
public:
    int x1,y1,x2,y2;
    rectan(){
        x1=y1=x2=y2=0;
    }
    rectan(int xx1,int yy1,int xx2,int yy2){
        x1=xx1;
        x2=xx2;
        y1=yy1;
        y2=yy2;
    }
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(12) << fixed;
	int r,c,k;
	cin>>r>>c>>k;
	vector<int> x,y;
	vector<rectan> rs;
    for(int i=0;i<r;i++){
        string s;
        cin>>s;
        for(int j=0;j<c;j++){
            if(s[j]=='#'){
                x.pb(i-k);
                x.pb(i+k+1);
                y.pb(j-k);
                y.pb(j+k+1);
                rs.pb(rectan(i-k,j-k,i+k+1,j+k+1));
            }
        }
    }
    sort(all(x));
    sort(all(y));
    auto it1=unique(all(x)),it2=unique(all(y));
    x.resize(distance(x.begin(),it1));
    y.resize(distance(y.begin(),it2));
    int u=x.size(),v=y.size();
    vector<vector<int>> tab(u,vector<int>(v,0));
    for(auto rec:rs){
        int ix1,iy1,ix2,iy2;
        ix1=lower_bound(all(x),rec.x1)-x.begin();
        iy1=lower_bound(all(y),rec.y1)-y.begin();
        ix2=lower_bound(all(x),rec.x2)-x.begin();
        iy2=lower_bound(all(y),rec.y2)-y.begin();
        tab[ix1][iy1]++;
        tab[ix1][iy2]--;
        tab[ix2][iy1]--;
        tab[ix2][iy2]++;
    }
    for(int j=0;j<v;j++){
        for(int i=1;i<u;i++){
            tab[i][j]+=tab[i-1][j];
        }
    }
    for(int i=0;i<u;i++){
        for(int j=1;j<v;j++){
            tab[i][j]+=tab[i][j-1];
        }
    }
    ll area=0;
    for(int i=0;i<u-1;i++){
        for(int j=0;j<v-1;j++){
            if(tab[i][j]){
                area+=1ll*(y[j+1]-y[j])*(x[i+1]-x[i]);
            }
        }
    }
    cout<<area<<"\n";
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
