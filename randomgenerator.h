#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H
#include <NTL/ZZ.h>
#include <iostream>
#include <time.h>
#define ull unsigned long long

using namespace NTL;
using namespace std;

class RandomGenerator
{
public:
    RandomGenerator();
    ZZ module(ZZ,ZZ);
    ZZ expModulo(ZZ,ZZ,ZZ);
    void SeedXorShift();
    ZZ XorShift();
    void SeedBBS();
    ZZ BlumBlumShub(int);

    ull mulmod(ull a, ull b, ull mod){
    ull x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
    }
    ull modulo(ull base, ull exponent, ull mod){
    ull x = 1;
    ull y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)x = mulmod(x, y, mod);
        y = mulmod(y, y, mod);
        exponent = exponent / 2;
    }
    return x % mod;
    }

    ZZ BBS(int bits){
        ull p,q;
        p=RandomBnd(2048-1)+2;
        while(p%4!=3){
            p=RandomBnd(2048-1)+2;
        }
        q=RandomBnd(2048-1)+2;
        while(q%4!=3 || q==p){
            q=RandomBnd(2048-1)+2;
        }
        //cout<<p<<" "<<q<<endl;
        ull n;
        n=p*q;
        ull s;
        s=RandomBnd(n-1)+1;
        while(GCD(s,n)!=1){
            s=RandomBnd(n-1)+1;
        }
        ull *x=new ull[2048];
        ull *z=new ull[2048];
        x[0]=MulMod(s,s,n);
        ZZ res;
        for(int i=1;i<=bits;i++){
            x[i]=modulo(x[i-1],2,n);
            z[i]=x[i]%2;
        }
        ZZ base;
        base=2;
        for(int i=1;i<=bits;i++){
            res=z[i]*power(base,i-1)+res;
        }
        return res;
    }

private:
    ZZ n_bbs;
    ZZ xi_bbs;
    ZZ MAX_XOR=conv<ZZ>(12312312312312);
    //xorshift
    ZZ xorshift_x;
    ZZ xorshift_y;
    ZZ xorshift_w;
    ZZ xorshift_z;

};

#endif // RANDOMGENERATOR_H
