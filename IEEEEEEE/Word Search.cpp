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

const int maxn=1e2;
int r,c;
string grid[maxn];
int dy[8]={-1,0,1,-1,1,-1,0,1};
int dx[8]={-1,-1,-1,0,0,1,1,1};

bool isok(int x,int y){
    return x>=0 && x<r && y>=0 && y<c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>r>>c>>q;
	for(int i=0;i<r;i++){
        cin>>grid[i];
	}
	while(q--){
        string word;
        cin>>word;
        bool solved=false;
        for(int i=0;i<r && !solved;i++){
            for(int j=0;j<c && !solved;j++){
                for(int d=0;d<8 && !solved;d++){
                    int x=i,y=j;
                    bool good=true;
                    for(int k=0;k<word.size();k++){
                        if(isok(x,y) && grid[x][y]==word[k]){
                            x+=dx[d];
                            y+=dy[d];
                        }else{
                            good=false;
                            break;
                        }
                    }
                    if(good){
                        cout<<i<<" "<<j<<" "<<x-dx[d]<<" "<<y-dy[d]<<"\n";
                        solved=true;
                    }
                }
            }
        }
        if(!solved) cout<<"-1\n";
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
