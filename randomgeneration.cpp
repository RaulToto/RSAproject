#include "randomgeneration.h"

RandomGeneration::RandomGeneration()
{

}

ZZ RandomGeneration::module(ZZ x, ZZ y)
{
    ZZ q=x/y,r;
    if(q<0)
    {
        q=-1*q;
        q++;
        q=-1*q;
        r=x-(q*y);
    }
    else
    {
        r=x-(q*y);
    }
    return r;

}

OT RandomGeneration::mulmod(OT a, OT b, OT mod)
{
    OT x = 0,y = a % mod;
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
OT RandomGeneration::modulo(OT base, OT exponent, OT mod){
    OT x = 1;
    OT y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)x = mulmod(x, y, mod);
        y = mulmod(y, y, mod);
        exponent = exponent / 2;
    }
    return x % mod;
}
ZZ RandomGeneration::BBS(int bits){
    OT p,q;
    p=RandomBnd(2048-1)+2;
    while(p%4!=3){
        p=RandomBnd(2048-1)+2;
    }
    q=RandomBnd(2048-1)+2;
    while(q%4!=3 || q==p){
        q=RandomBnd(2048-1)+2;
    }
    //cout<<p<<" "<<q<<endl;
    OT n;
    n=p*q;
    OT s;
    s=RandomBnd(n-1)+1;
    while(GCD(s,n)!=1){
        s=RandomBnd(n-1)+1;
    }
    OT *x=new OT[2048];
    OT *z=new OT[2048];
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
    delete [] x;
    delete [] z;
    return res;
}

