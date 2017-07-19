#include "rsa.h"
#include <string>
using namespace std;
RSA::RSA(int x)
    :size(x)
{
    RandomGenerator random;//create a random number generator
    PrimalityTest primo;
    random.SeedXorShift();
    random.SeedBBS();
    //random.SeedXorShift();
    ZZ prime,num;
    //cout << random.BlumBlumShub(512) << endl;
    //se encuentra p y q dos primos grandes ambos del tamaño
    num=random.BlumBlumShub(this->size);
    cout << num << endl;
    for (ZZ i=num; i < num+1001; i+=2) {
        if(primo.Miller(i,5))
        {
            this->p=i;
            break;
        }
    }
    random.SeedBBS();
    num=random.BlumBlumShub(this->size);
    for (ZZ i=num; i < num+1001; i+=2) {
        if(primo.Miller(i,5))
        {
            this->q=i;
            break;
        }
    }
    //cout << "primo" << prime << endl;
    cout << "q-->" <<this->q << endl;
    cout << "p-->" << this->p << endl;
    /*
    this->N=p*q;//se calcula n a partir de la multiplicacion de estos dos primos
    cout << "n-->" <<this->N << endl;
    this->phi_n=(p-1)*(q-1);//se calcula phi de n p-1*q-1
    while(!(binary_gcd(e,phi_n)==1))
    {
        this->e=random.BlumBlumShub(255);
    }
    cout << "e--->" << this->e << endl;
    this->d=euclides_extendido(e,phi_n);
    cout << "d--->" << this->d << endl;
    //hallaremos nuestra clave publica
    /*random.BBS(1024);
    this->p=17;
    this->q=59;
    this->N=1003;
    ZZ phi_n=(p-1)*(q-1);
    this->e=3;
    this->d=619;*/
}

ZZ RSA::binary_gcd(ZZ u , ZZ v)
{
    int i;
    if (u == 0) return v;
    if (v == 0) return u;
    //cout << "a" << '\t' << "b" <<'\t' << "i" <<  endl;
    for (i = 0; ((u | v) & 1) == 0; ++i) {
           u >>= 1;
           v >>= 1;
           //cout << u << '\t' << v  << '\t' << i << endl;
           //guardar(u,v,i);
    }

    while ((u & 1) == 0)
      u >>= 1;

    do {
         //guardar(u,v,i);
         //cout << u << '\t' << v  << '\t' << i << endl;
         while ((v & 1) == 0)
             v >>= 1;
         if (u > v) {
            ZZ t = v; v = u; u = t;}
         v = v - u;
       } while (v != 0);
    //cout << "---- " << i << endl;
    return u << i;
}

ZZ RSA::euclides_extendido(ZZ a, ZZ b)
{

    ZZ q,r,r1=a,r2=b,s,s1,s2,t,t1,t2;
    s1=1,s2=0,t,t1=0,t2=1;
    //cout << "q" << "\t"<<"r1 "<< "\t" << "r2 "<< "\t" << "r "<< "\t" << "s1 "<< "\t" << "s2 "<< "\t" << "s "<< "\t" << "t1" << "\t"<< "t2 " << "\t"<< "t " << endl;
    while(r2>0)
    {
        q=r1/r2;
        r=r1-(q*r2);
        r1=r2;
        r2=r;
        //-----
        s=s1-(q*s2);
        s1=s2;
        s2=s;
        //cout << s << "\t" << s1 << "\t" << s2 << endl;
        //-------
        t=t1-(q*t2);
        t1=t2;
        t2=t;
        //guardar(q,r1,r2,r,s1,s2,s,t1,t2,t);
        //cout << q << "\t" << r1<< "\t" << r2<< "\t" << r<< "\t" << s1<< "\t" << s2<< "\t" << s<< "\t" <<t1<< "\t" <<t2<< "\t" << t << endl;
    }
    return s1;
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

string RSA::stringConvertInBlocks(vector<string> &vec, int size_numbers)//recibe como argumento el vector y el tamaño de cifras
{
    string allpos;
    for (int i = 0; i < vec.size(); ++i) {//si esta solo una cifra lo convierte a 2
        string n=vec[i];
        while(n.length()<size_numbers)
        {
            n='0'+n;
            vec[i]=n;
        }
        allpos+=vec[i];
        //cout << allpos << endl;
    }
    return allpos;
}

vector<ZZ> RSA::numberConvertInBlocks(string & allpos, int k)
{
    vector<ZZ> vec1;
    int cont=0,cont1=0,cont2=0;
    if(allpos.length()<k)
    {
        vec1.push_back(stringToInt(allpos));
    }
    else
    {
        while (cont<allpos.length()/k) {
            string str;
            while (cont1<k) {
                str+=allpos[cont2];
                cont1++;
                cont2++;
            }
            vec1.push_back(conv<ZZ>(stringToInt(str)));
            //cout << str << endl;
            cont1=0;
            str="";
            cont++;
        }
    }
    return vec1;
}


string RSA::intToString(ZZ number)
{
    std::stringstream ss;
    ss << number;
    std::string str;
    ss >> str;
    return str;
}

ZZ RSA::stringToInt(string number)
{
    stringstream sstr;
    sstr << number;
    ZZ converted;
    sstr >> converted;
    return converted;
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

ZZ RSA::expModule(ZZ base , ZZ exponent, ZZ mod)
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

string RSA::encrypt(string message)
{
    int k=size_number(this->N)-1;//el tamaño de los bloques sera cantidad de cifras de n-1
    vector<string> vec;//vector para almacenar las posiciones de las letras
    vector<ZZ>vec1;
    string allpos;
    size_t t;
    for (int i = 0; i < message.size(); ++i) {
        size_t t=alfabeto.find(message[i]);
        cout << t << endl;
        vec.push_back(intToString(conv<ZZ>(t)));
    }
    //cout << "convert in blocks" << endl;
    allpos=stringConvertInBlocks(vec,2);
    cout << allpos << "k is "<< k <<  endl;
    vec1=numberConvertInBlocks(allpos,k);
    //cout << "vector in block";

    cout << "this is a number for encrypt" << endl;
    for (int i = 0; i < vec1.size(); ++i) {
        cout << vec1[i] << endl;
    }

    allpos="";//vaciar la lista de strings
    cout << "encriptacion" << endl;
    vec.clear();//vacia el vector
    for (int i = 0; i < vec1.size(); ++i) {
        ZZ ss;
        ss=expModule(conv<ZZ>(vec1[i]),this->e,this->N);//exp modular con nuestra clave publica
        vec.push_back(intToString(ss));//lo almacenamos como string
    }
    cout << "new vector" << endl;
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }

    allpos=stringConvertInBlocks(vec,k+1);//convierte el string en bloques y lo retorna como string

    this->encriptado=allpos;//inicializamos nuestro  encriptado
    cout <<"final allpos"  << allpos << endl;
    return allpos;
}
void RSA::decrypt()
{
    int k=size_number(this->N)-1;//el tamaño de los bloques sera cantidad de cifras de n-1

    vector<ZZ> vec1;//vector para ZZ
    vector<string> vec;//vector para strings
    string resultado;
    cout << "encriptado" << this->encriptado << endl;
    vec1=numberConvertInBlocks(this->encriptado,k+1);//en el vector 1 estan todos los numeros en zz
    cout << "1----" << vec1[0] << endl;
    for (int i = 0; i < vec1.size(); ++i) {//luego hacemos la exp mdular con nuestra clave privada
        ZZ ss;
        cout << "conv[0]>>>" << vec1[i] << endl;
        cout << "d--->" << this->d << endl;
        cout << "N--->" << this->N<< endl;
        ss=expModule(conv<ZZ>(vec1[i]),this->d,this->N);//exp modular
        cout << "SS-->"<<ss << endl;
        vec.push_back(intToString(ss));//el resultado lo almacenamos en otro vecto

    }
    //resultado=stringConvertInBlocks(vec,k);//le el vector y el k-1
    /*
    vec1.clear();//limpia el vector
    vec1=numberConvertInBlocks(resultado,2);//convierte al tamaño maximo de cifras del alfabeto
    for (int i = 0; i < vec1.size(); ++i) {
        cout << alfabeto[conv<int>(vec1[i])];
    }
    cout << endl;*/
}
