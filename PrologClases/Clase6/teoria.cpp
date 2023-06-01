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

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int bezout(int a,int b,int &x,int &y){//a*x+b*y=g, retorna g, misma complejidad que el gcd
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x2,y2;
    int g=bezout(b,a%b,x2,y2);
    x=y2;
    y=x2-(a/b)*y2;
    return g;
}

int CRT(int a,int m,int b,int n){
    int x,y;
    int g = bezout(m,n,x,y);
    assert((a-b)%g==0); //else no solution
    x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;

}
