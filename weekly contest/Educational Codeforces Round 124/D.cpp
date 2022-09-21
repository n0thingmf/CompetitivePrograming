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
#define p pair<int,int>
using namespace std;

const int maxn=2e5;
vector<int> x[maxn+2];
vector<int> x2[maxn+2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<p> pt(n);
	for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        x[a].pb(b);
        pt[i].first=a;
        pt[i].second=b;
	}
	for(int i=1;i<=maxn;i++){
        if(x[i].size()==0) continue;
        sort(all(x[i]));
        x2[i].pb(x[i][0]-1);
        for(int j=1;j<x[i].size();j++){
            if(x[i][j]-x[i][j-1]!=1){
                x2[i].pb(x[i][j-1]+1);
                x2[i].pb(x[i][j]-1);
            }
        }
        x2[i].pb(x[i].back()+1);
        x2[i].erase(unique(all(x2[i])),x2[i].end());
	}
    for(int i=0;i<n;i++){
        int ux=pt[i].first,uy=pt[i].second,d,ansx,ansy;
        ansx=ux;
        if(uy<=x2[ux][0]) d=x2[ux][0]-uy,ansy=x2[ux][0];
        else if(x2[ux].back()<=uy) d=uy-x2[ux].back(),ansy=x2[ux].back();
        else{
            int j=lower_bound(all(x2[ux]),uy)-x2[ux].begin();
            if(x2[ux][j]-uy>uy-x2[ux][j-1]){
                d=uy-x2[ux][j-1];
                ansy=x2[ux][j-1];
            }else{
                d=x2[ux][j]-uy;
                ansy=x2[ux][j];
            }
        }
        for(int j=1;j<d;j++){
            if(x[ux-j].size()==0){
                d=j;
                ansx=ux-j;
                ansy=uy;
            }
            else{
                int id=lower_bound(all(x[ux-j]),uy)-x[ux-j].begin();
                 if(id>=x[ux-j].size() || x[ux-j][id]!=uy){
                    d=j;
                    ansx=ux-j;
                    ansy=uy;
                 }
                if(uy<=x2[ux-j][0]){
                    if(d>j+x2[ux-j][0]-uy){
                        d=j+x2[ux-j][0]-uy;
                        ansx=ux-j;
                        ansy=x2[ux-j][0];
                    }
                }
                else if(x2[ux-j].back()<=uy){
                    if(d>j+uy-x2[ux-j].back()){
                        d=j+uy-x2[ux-j].back();
                        ansx=ux-j;
                        ansy=x2[ux-j].back();
                    }
                }
                else{

                    int k=lower_bound(all(x2[ux-j]),uy)-x2[ux-j].begin();

                    if(d>x2[ux-j][k]-uy+j){
                        d=x2[ux-j][k]-uy+j;
                        ansx=ux-j;
                        ansy=x2[ux-j][k];
                    }
                    if(d>uy-x2[ux-j][k-1]+j){
                        d=uy-x2[ux-j][k-1]+j;
                        ansx=ux-j;
                        ansy=x2[ux-j][k-1];
                    }
                }
            }
            if(x[ux+j].size()==0){
                d=j;
                ansx=ux+j;
                ansy=uy;
            }else{
                int id=lower_bound(all(x[ux+j]),uy)-x[ux+j].begin();
                 if(id>=x[ux+j].size() || x[ux+j][id]!=uy){
                    d=j;
                    ansx=ux+j;
                    ansy=uy;
                 }
                if(uy<=x2[ux+j][0]){
                    if(d>j+x2[ux+j][0]-uy){
                        d=j+x2[ux+j][0]-uy;
                        ansx=ux+j;
                        ansy=x2[ux+j][0];
                    }
                }
                else if(x2[ux+j].back()<=uy){
                    if(d>j+uy-x2[ux+j].back()){
                        d=j+uy-x2[ux+j].back();
                        ansx=ux+j;
                        ansy=x2[ux+j].back();
                    }
                }
                else{
                    int k=lower_bound(all(x2[ux+j]),uy)-x2[ux+j].begin();
                    if(d>x2[ux+j][k]-uy+j){
                        d=x2[ux+j][k]-uy+j;
                        ansx=ux+j;
                        ansy=x2[ux+j][k];
                    }
                    if(d>uy-x2[ux+j][k-1]+j){
                        d=uy-x2[ux+j][k-1]+j;
                        ansx=ux+j;
                        ansy=x2[ux+j][k-1];
                    }
                }
            }
        }
        //cout<<ansx<<" "<<ansy<<" "<<d<<"\n";
        cout<<ansx<<" "<<ansy<<"\n";
    }
    /*for(int i=0;i<=maxn;i++){
        if(x[i].size()!=0){
            cout<<i<<":\n";
            for(int y:x2[i]) cout<<y<<" ";
            cout<<"\n";
        }
    }*/
	//cout << setprecision(12) << fixed;

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
