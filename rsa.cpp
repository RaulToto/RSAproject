#include "rsa.h"
using namespace std;
RSA::RSA(int x)
    :size(x)
{
    this->p=17;
    this->q=59;
    this->N=1003;
    ZZ phi_n=(p-1)*(q-1);
    this->e=3;
    this->d=619;
}

ZZ RSA::module(ZZ  x , ZZ  y)
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
//halla las cifras de un numero
int RSA::size_number(ZZ num)
{
    int cont=1;
    while (num/conv<ZZ>(10)>0) {
        num/=conv<ZZ>(10);

        cont++;
    }
    return cont;
}

string RSA::encrypt(string message)
{
    size_t t;
    for (int i = 0; i < message.size(); ++i) {
        size_t t=alfabeto.find(message[i]);
        cout << t << endl;
        cout << "---" << size_number(this->N) << endl;
    }

}

string RSA::decrypt(string)
{

}
