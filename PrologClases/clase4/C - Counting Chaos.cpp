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
	set<int> p;
	for(int i=0;i<24*60;i++){
        int h=i/60,m=i%60;
        string s;
        if(h==0){
            s=to_string(m);
        }else{
            s=to_string(h);
            s.pb('0'+(m/10)%10);
            s.pb('0'+m%10);
        }
        string r=s;
        reverse(all(r));
        if(s==r){
            //cout<<s<<"\n";
            p.insert(i);
        }
	}
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int h,m;
        char c;
        cin>>h>>c>>m;
        m=60*h+m;
        auto it=p.upper_bound(m);
        if(it==p.end()){
            cout<<"00:00\n";
        }else{
            h=(*it)/60,m=(*it)%60;
            cout<<(h/10)%10<<h%10<<":"<<(m/10)%10<<m%10<<"\n";
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
