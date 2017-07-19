#include "gamal.h"

gamal::gamal(int n)
    :size(n)
{
    //con fines de utilizar las funciones del rsa
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
    cout << num << endl;
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
    this->private_key=random.BlumBlumShub(600);
    //cout << private_key << endl;
    public_key_B=rsa.expModule(raiz_primitiva,private_key,p);

}

ZZ gamal::RaizPrimitiva()
{
    ZZ q=(this->p-1)/2,g,dos=to_ZZ(2);
     for(int i=1;i<p-1;i++){
         g = i;
         if((rsa.expModule(g,dos,p)!=1) && (rsa.expModule(g,q,p)!= 1))
             return g;
     }
     return g;
}
