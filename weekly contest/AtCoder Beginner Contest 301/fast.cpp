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
	cout << setprecision(12) << fixed;
	string s,t;
	cin>>s>>t;
	int fs[26],ft[26],cs=0,ct=0;
	memset(fs,0,sizeof(fs));
	memset(ft,0,sizeof(ft));
	for(int i=0;i<s.size();i++){
        if(s[i]=='@') cs++;
        else fs[s[i]-'a']++;
	}
	for(int i=0;i<t.size();i++){
        if(t[i]=='@') ct++;
        else ft[t[i]-'a']++;
	}
	bool kek[26];
	memset(kek,false,sizeof(kek));
	kek['a'-'a']=true;
	kek['t'-'a']=true;
	kek['c'-'a']=true;
	kek['o'-'a']=true;
	kek['d'-'a']=true;
	kek['e'-'a']=true;
	kek['r'-'a']=true;
	for(int i=0;i<26;i++){
        if(fs[i]==ft[i]) continue;
        if(!kek[i]){
            cout<<"No\n";
            return 0;
        }
        if(fs[i]<ft[i]){
            cs-=ft[i]-fs[i];
        }else{
            ct-=fs[i]-ft[i];
        }
	}
	if(cs>=0 && ct>=0) cout<<"Yes\n";
	else cout<<"No\n";
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
