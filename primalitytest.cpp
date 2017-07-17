#include "primalitytest.h"
#include <bitset>
PrimalityTest::PrimalityTest()
{

}

ZZ PrimalityTest::module(ZZ x, ZZ y)
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

ZZ PrimalityTest::mulmod(ZZ a, ZZ b, ZZ mod)
{
    ZZ x = conv<ZZ>(0),y =conv<ZZ>(module(a , mod));
    while (b > 0)
    {
        if (module(b,conv<ZZ>(2)) == 1)
        {
            x = module((x + y), mod);
        }
        y = module((y * 2) , mod);
        //b /= 2;//corregir
        b=b>>1;
    }
    return module(x , mod);
}

ZZ PrimalityTest::modulo(ZZ base, ZZ exponent, ZZ mod)
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

bool PrimalityTest::Miller(ZZ p, int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && module(p ,conv<ZZ>(2))==0)
    {
        return false;
    }
    ZZ s = p - 1;
    while (module(s ,conv<ZZ> (2)) == 0)
    {
        //s /= 2;
        s=s>>1;
    }
    for (int i = 0; i < iteration; i++)
    {
        ZZ a = module(conv<ZZ>(rand()) , (p - 1)) + 1;
        ZZ temp = s;
        ZZ mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && module(temp ,conv<ZZ>(2)) == 0)
        {
            return false;
        }
    }
    return true;

}
