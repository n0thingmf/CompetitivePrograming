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

bool prime[100];
void init(){
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for(int i=2;i<100;i++){
        if(prime[i]){
            for(int j=i*i;j<100;j+=i){
                prime[j]=false;
            }
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	//for(int i=1;i<100;i++) if(prime[i]) cout<<i<<"\n";
	int t;
	cin>>t;
	while(t--){
        int k;
        cin>>k;
        string s;
        cin>>s;
        bool ok=false;
        for(int i=0;i<k;i++){
            int cif=s[i]-'0';
            if(!prime[cif]){
                cout<<1<<"\n"<<cif<<"\n";
                ok=true;
                break;
            }
        }
        if(!ok){
            bool fd=true;
            for(int i=0;i<k && fd;i++){
                for(int j=i+1;j<k && fd;j++){
                    int a=s[i]-'0',b=s[j]-'0';
                    if(!prime[a*10+b]){
                        cout<<2<<"\n"<<a*10+b<<"\n";
                        fd=false;
                    }
                }
            }
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
