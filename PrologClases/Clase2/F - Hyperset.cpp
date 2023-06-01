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
	int n,k;
	cin>>n>>k;
	vector<string> s(n);
	set<string> st;
	for(int i=0;i<n;i++) cin>>s[i],st.insert(s[i]);
	int ans=0;
	for(int i=0;i<n;i++){//fijamos el primer elemento
        for(int j=i+1;j<n;j++){//fijamos el segundo elemento
            string target(k,' ');//construimos el tercer elemento
            for(int u=0;u<k;u++){
                if(s[i][u]==s[j][u]) target[u]=s[i][u];
                else target[u]='S'+'E'+'T'-s[i][u]-s[j][u];
            }
            if(st.count(target)){//verificamos si existe el tercer elemento
                ans++;
            }
        }
	}

	for(auto it=st.begin();it!=st.end();it++){
        for(auto it2=st.begin();it2!=st.end();it2++){
            if(it==it2) continue;
            string s1=*it,s2=*it2;
            cout<<s1<<" "<<s2<<"\n";

        }
	}





	cout<<ans/3<<"\n";//se divide el conteo entre 3 porque cada terna se cuenta 3 veces.
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
