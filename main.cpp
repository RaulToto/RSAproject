#include <iostream>
#include <NTL/ZZ.h>
#include "primalitytest.h"
#include "randomgenerator.h"
#include "rsa.h"
using namespace NTL;
using namespace std;
int main(int argc,int argv[])
{
    cout << "  ///////////////////" << endl;
    cout << " /////////RSA///////" << endl;
    cout <<"///////////////////"  << endl;
    //PrimalityTest primo;
    //RandomGenerator random;
    //random.SeedXorShift();
    //random.SeedBBS();
    //cout << random.BlumBlumShub(12000) << endl;
    RSA rsa(1024);
    //rsa.encrypt("comehere#");
    //cout << "el desifrado es" << endl;
    //rsa.decrypt();
}
