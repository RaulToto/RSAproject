#include <iostream>
#include <NTL/ZZ.h>
#include "primalitytest.h"
#include "randomgeneration.h"
using namespace NTL;
using namespace std;
int main()
{
    cout << "  ///////////////////" << endl;
    cout << " /////////RSA///////" << endl;
    cout <<"///////////////////"  << endl;
    PrimalityTest primo;
    for (ZZ i= conv<ZZ>(1); i <100l;i++) {
        if(primo.Miller(i,5))
            cout << i << " " ;
    }
}
