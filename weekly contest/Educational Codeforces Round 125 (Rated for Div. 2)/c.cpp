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

vector<int> d;
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = -1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res), end(res));
}
bool ispal(int i,int j){
    if(i>=j) return false;
    if(i+j+d[i+j+1]>=2*j+1) return true;
    else return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        d=manacher(s);
        /*for(int i=0;i<d.size();i++) cout<<d[i]<<" ";
        cout<<"\n";*/
        vector<int> p;
        bool ok=true;
        int c=0,r=0;
        for(int i=0,j=0;i<n;i++){
            if(s[i]=='(') p.pb(i);
            else if(p.size()==0){
                ok=false;
            }
            else p.popb();

            if((ok && p.size()==0) || ispal(j,i)){
                c++,r=0;
                ok=true;
                j=i+1;
                p.clear();
            }else r++;
        }
        cout<<c<<" "<<r<<"\n";
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
