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

int peso_mochila,n;
vector<int> peso,valor;
int peso_total=0,valor_total=0,mejor_valor=0;

void backtracking(int i){
    if(i==n){
        mejor_valor=max(mejor_valor,valor_total); //asumir que a todos los estados que llego, son buenos
        return;
    }
    backtracking(i+1); //no tomo el elemento
    peso_total+=peso[i];
    valor_total+=valor[i];
    if(peso_total<=peso_mochila) backtracking(i+1); //si tomo el elemento, verifico que el nodo sea bueno
    peso_total-=peso[i];
    valor_total-=valor[i];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	peso_mochila=9;
	n=4;
	peso={4,3,5,2};
	valor={30,40,30,20};
	backtracking(0);
	cout<<mejor_valor<<"\n";
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
