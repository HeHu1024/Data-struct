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
    //d2[5] = 5;

    StaticArray<int,5> a1;
    StaticArray<int,5> a2;
    for( int i=0; i<a1.length(); i++ )
    {
        a1[i] = i;
    }
    a2 = a1;
    for( int i=0; i<a1.length(); i++ )
    {
        cout << a1[i] << endl;
    }
    cout << endl;
    for( int i=0; i<a2.length(); i++ )
    {
        cout << a2[i] << endl;
    }

    //a2[10] = 100;


   return 0;
}

