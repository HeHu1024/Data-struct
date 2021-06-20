#include <iostream>
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"

using namespace std;
using namespace DTLib;

int main()
{
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

    a2[10] = 100;


   return 0;
}

