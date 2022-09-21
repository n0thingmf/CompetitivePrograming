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

string grid[500];
string patt[200];
int go[200][2];
int kmp[200][500][500];
char h[2]={'.','#'};
bool compare(char a,char b){
    if(a=='-' || b=='-') return false;
    if(a=='?' || b=='?') return true;
    else return a==b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	map<char,int> ht;
	ht['.']=0;
	ht['#']=1;
    int t;
    cin>>t;
    while(t--){
        int r,c,a,b;
        cin>>r>>c;
        for(int i=0;i<r;i++) cin>>grid[i];
        cin>>a>>b;
        for(int i=0;i<a;i++) cin>>patt[i];
        for(int i=0;i<a;i++){
            patt[i]+='-';
            //compute kmp
            vector<int> pi(b+1,0);
            for(int j=1;j<=b;j++){
                int k=pi[j-1];
                while(k>0 && !compare(patt[i][j],patt[i][k])){
                    k=pi[k-1];
                }
                if(compare(patt[i][j],patt[i][k])) k++;
                pi[j]=k;
            }
            //compute automaton
            for(int j=0;j<=b;j++){
                for(int c=0;c<2;c++){
                    if(j>0 && !compare(h[c],patt[i][j])){
                        go[j][c]=go[pi[j-1]][c];
                    }else{
                        go[j][c]=i+compare(h[c],patt[i][j]);
                    }
                }
            }
            for(int row=0;row<r;row++){
                kmp[i][row][0]=go[0][ht[grid[row][0]]];
                for(int col=1;col<c;col++){
                    kmp[i][row][col]=go[kmp[i][row][col-1]][ht[grid[row][col]]];
                }
            }
        }



        int ans=0;

        for(int i=0;i+a-1<r;i++){
            for(int j=0;j+b-1<c;j++){
                    bool ok=true;
                for(int row=0;row<a;row++){
                    if(kmp[row][i+row][j+b]!=b){
                        ok=false;
                        break;
                    }
                }
                if(ok=true) ans++;
            }
        }
        cout<<ans<<"\n";
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
