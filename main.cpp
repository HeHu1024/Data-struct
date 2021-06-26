#include <iostream>
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"

using namespace std;
using namespace DTLib;

int main()
{
    DynamicArray<int> d1(5);

    for(int i=0; i<d1.length(); i++)
    {
        d1[i] = i;
    }

    for(int i=0; i<d1.length(); i++)
    {
        cout << d1[i] << endl;
    }
    DynamicArray<int> d2(10);
    d2 = d1;
    d2.resize(3);

    cout << endl;

    for(int i=0; i<d2.length(); i++)
    {
        cout << d2[i] << endl;
    }
    d2[5] = 5;

   return 0;
}

