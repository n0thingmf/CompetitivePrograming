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

void print(int r,int c,char x){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++) cout<<x;
        cout<<"\n";
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	for(int cs=1;cs<=t;cs++){
        cout<<"Case #"<<cs<<": ";
        int r,c,cnt=0;
        cin>>r>>c;

        for(int i=0;i<r;i++){
            string s;
            cin>>s;
            for(int j=0;j<c;j++) if(s[j]=='^') cnt++;
        }
        if(r==1 || c==1){
            if(cnt==0){
                cout<<"Possible\n";
                print(r,c,'.');
            }
            else cout<<"Impossible\n";
        }else{
            cout<<"Possible\n";
            print(r,c,'^');
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
