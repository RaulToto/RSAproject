#include "rsa.h"
#include <string>
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

string RSA::intToString(int number)
{
    std::stringstream ss;
    ss << number;
    std::string str;
    ss >> str;
    return str;
}

int RSA::stringToInt(string)
{

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
    int k=size_number(this->N);//el tamaño de los bloques sera cantidad de cifras de n-1
    vector<string> vec;//vector para almacenar las posiciones de las letras
    size_t t;
    for (int i = 0; i < message.size(); ++i) {
        size_t t=alfabeto.find(message[i]);
        cout << t << endl;
        vec.push_back(intToString(t));
    }
    cout << "this string" << endl;
    for (int i = 0; i < vec.size(); ++i) {//si esta solo una cifra lo convierte a 2
        string n=vec[i];
        if(n.length()==1)
        {
            n='0'+n;
            vec[i]=n;
        }
    }

}
string RSA::decrypt(string)
{

}
