#include "gamal.h"

gamal::gamal(int n)
    :size(n)
{
    //calculamos un primo grande
    RandomGenerator random;//create a random number generator
    PrimalityTest primo;
    random.SeedXorShift();
    random.SeedBBS();
    //random.SeedXorShift();
    ZZ num;
    //cout << random.BlumBlumShub(512) << endl;
    //se encuentra p y q dos primos grandes ambos del tamaño
    num=random.BlumBlumShub(this->size);
    //cout << num << endl;
    //cout << num << endl;
    for (ZZ i=num; ; i+=2) {
        if(primo.Miller(i,5))
        {
            this->p=i;//establecemos nuestro primo grande
            break;
        }
    }
    //cout << "p is --->" << p;
    this->raiz_primitiva=RaizPrimitiva();
    //cout << "la raiz primitiva es " << raiz_primitiva;
    random.SeedBBS();
    this->private_key=random.BlumBlumShub(120);
    //cout << private_key << endl;
    public_key_B=expModule(raiz_primitiva,private_key,p);
    random.SeedBBS();
    this->ni=random.BlumBlumShub(250);
}

void gamal::encrypt(ZZ num)
{
    N1=expModule(raiz_primitiva,ni,p);
    N2=num*(expModule(public_key_B,ni,p));
    cout << "EL MENSAJE 1 -->" << N1 << endl;
    cout << "EL MENSAJE 2 -->" << N2 << endl;

}

void gamal::decrypt()
{
    ZZ N3,N4,resultado;
    N3=expModule(N1,private_key,p);
    N4=inverse(N3,p);
    resultado=module(N2*N4,p);
    cout << resultado << endl;
}
ZZ gamal::RaizPrimitiva()
{
    ZZ q=(this->p-1)/2,g,dos=to_ZZ(2);
     for(int i=1;i<p-1;i++){
         g = i;
         if((expModule(g,dos,p)!=1) && (expModule(g,q,p)!= 1))
             return g;
     }
     return g;
}

ZZ gamal::inverse(ZZ n, ZZ modulus)
{
    ZZ a = n, b = modulus;
    ZZ x = conv<ZZ>(0), y = conv<ZZ>(1), x0 = conv<ZZ>(1), y0 =conv<ZZ>(0), q, temp;
    while(b != 0) {
        q = a / b;
        temp = module(a , b);
        a = b;
        b = temp;
        temp = x; x = x0 - q * x; x0 = temp;
        temp = y; y = y0 - q * y; y0 = temp;
    }
    if(x0 < 0) x0 += modulus;
    return x0;

}

ZZ gamal::module(ZZ x, ZZ y)
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

ZZ gamal::expModule(ZZ base, ZZ exponent,ZZ mod)
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
