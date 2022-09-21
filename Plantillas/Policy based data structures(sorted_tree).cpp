#include<bits/stdc++.h>
//Policy based data structures header:
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//Mas informacion en: https://codeforces.com/blog/entry/11080


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
using namespace __gnu_pbds;

template <typename num_t>
using ordered_set = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
// less_equal<num_t>:multiset
// less<num_t>:set

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(12) << fixed;
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
