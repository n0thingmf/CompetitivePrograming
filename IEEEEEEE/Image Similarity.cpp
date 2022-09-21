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
bool tab1[4][4][30][30];
bool tab2[90][90];

void tclear(){
    for(int t=0;t<4;t++){
        for(int r=0;r<4;r++){
            for(int i=0;i<30;i++){
                for(int j=0;j<30;j++){
                    tab1[t][r][i][j]=false;
                }
            }
        }
    }
    for(int i=0;i<90;i++){
        for(int j=0;j<90;j++){
            tab2[i][j]=false;
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int r1,c1,r2,c2;
        tclear();
        cin>>r1>>c1;
        for(int i=0;i<r1;i++){
            string s;
            cin>>s;
            for(int j=0;j<c1;j++){
                if(s[j]=='#') tab1[0][0][i][j]=true;
                else tab1[0][0][i][j]=false;
            }
        }
        cin>>r2>>c2;
        for(int i=0;i<r2;i++){
            string s;
            cin>>s;
            for(int j=0;j<c2;j++){
                if(s[j]=='#') tab2[30+i][30+j]=true;
                else tab2[30+i][30+j]=false;
            }
        }
        for(int t=0;t<4;t++){
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    tab1[1][0][i][j]=tab1[0][0][i][c1-1-j];
                }
            }
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    tab1[2][0][i][j]=tab1[0][0][r1-1-i][j];
                }
            }
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    tab1[3][0][i][j]=tab1[0][0][r1-1-i][c1-1-j];
                }
            }
            for(int r=1;r<4;r++){
                for(int i=0;i<r1;i++){
                    for(int j=0;j<c1;j++){
                        tab1[t][1][c1-1-j][i]=tab1[t][0][i][j];
                    }
                }
                for(int i=0;i<r1;i++){
                    for(int j=0;j<c1;j++){
                        tab1[t][2][r1-1-i][c1-1-j]=tab1[t][0][i][j];
                    }
                }
                for(int i=0;i<r1;i++){
                    for(int j=0;j<c1;j++){
                        tab1[t][3][j][r1-1-i]=tab1[t][0][i][j];
                    }
                }
            }
        }
        int ans=0;
        for(int t=0;t<4;t++){
            for(int r=0;r<4;r++){
                for(int x=1;x<60;x++){
                    for(int y=1;y<60;y++){
                        int res=0;
                        for(int i=30;i<60;i++){
                            for(int j=30;j<60;j++){
                                if(i-x>=0 && i-x<30 && j-y<30 && j-y>=0){
                                    if(tab2[i][j] && tab1[t][r][i-x][j-y]) res++;
                                }
                            }
                        }
                        ans=max(ans,res);
                    }
                }
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
