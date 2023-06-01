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

vector<int> conjunto,subconjunto;

void rec(int i){ //O(n)
    if(i==conjunto.size()){
        for(int j=0;j<subconjunto.size();j++) cout<<subconjunto[j]<<" ";
        cout<<"\n";
        return;
    }
    rec(i+1); // no tomo el elemento conjunto[i]
    subconjunto.pb(conjunto[i]);
    rec(i+1); //si tomo el elemento conjunto[i]
    subconjunto.pop_back();
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	conjunto={1,2,3};
	rec(0);
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