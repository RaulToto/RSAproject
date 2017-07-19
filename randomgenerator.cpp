#include "randomgenerator.h"
#include "bitvector.h"
RandomGenerator::RandomGenerator()
{

}

ZZ RandomGenerator::module(ZZ x, ZZ y)
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

ZZ RandomGenerator::expModulo(ZZ base, ZZ exponent, ZZ mod)
{
    ZZ x = conv<ZZ>(1);
    ZZ y = base;
    while (exponent > 0)
    {
        if (module(exponent , conv<ZZ>(2)) == 1)
            x =module( (x * y) , mod);
        y = module((y * y) , mod);
        //exponent = exponent / 2;
        exponent=exponent>>1;
    }
    return module(x , mod);


}

void RandomGenerator::SeedXorShift()
{
    time_t timer = time(NULL);
    struct tm y2k;
    ZZ seconds;
    y2k.tm_hour=0;
    y2k.tm_min=0;
    y2k.tm_sec=0;
    y2k.tm_year=100;
    y2k.tm_mon=0;
    y2k.tm_mday=1;
    seconds= conv<ZZ>(difftime(timer,mktime(&y2k)));
    xorshift_x=seconds;
    xorshift_y=seconds^123456789;
    xorshift_z=seconds << 31;
    xorshift_w=seconds >> 28321;

}

ZZ RandomGenerator::XorShift()
{
    ZZ tmp;
    //ZZ MAX_XOR ;
    tmp=xorshift_x^(xorshift_x << 11);
    xorshift_x=xorshift_y;
    xorshift_y=xorshift_z;
    xorshift_z=xorshift_w;
    xorshift_w=xorshift_w^(xorshift_w >> 19) ^ (tmp^(tmp >> 8));
    return module(xorshift_w,(conv<ZZ>(MAX_XOR)));

}

void RandomGenerator::SeedBBS()
{
    ZZ p;
    ZZ q;
    p=13;
    q=37;
    n_bbs=p*q;
    ZZ seed=XorShift();
    xi_bbs=expModulo(seed,conv<ZZ>(2),n_bbs);//call exp modular

}

ZZ RandomGenerator::BlumBlumShub(int tam)
{
    ZZ res;
    BitVector bits(tam);
    for (int i = tam-1; i>=0; i--)
    {
        xi_bbs=expModulo(xi_bbs,conv<ZZ>(2),n_bbs);
        bits.SetBit(i,(xi_bbs%2)==1);

    }
    res=ZZFromBytes(bits.vector,tam/8);
    if (module(res,conv<ZZ>(2))==0) {
        res+=1;
    }
    return res;

}
