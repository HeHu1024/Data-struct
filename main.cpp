#include <iostream>
#include "StaticList.h"
#include "DynamicList.h"

using namespace std;
using namespace DTLib;

int main()
{
    DynamicList<int> l(5);
    for( int i = 0;i < l.capacity();i++ )
    {
        l.insert(0,i);
    }
    for( int i = 0;i < l.length();i++ )
    {
        cout << l[i] << endl;
    }
    try
    {
        l[10] = 4;
    }
    catch(const Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
        l.resize(10);
        l.insert(5,50);
    }
    l[5] = 5;
    for(int i = 0;i < l.length();i++)
    {
        cout << l[i] << endl;
    }
    l.resize(3);
    for(int i = 0;i < l.length();i++)
    {
        cout << l[i] << endl;
    }


   return 0;
}

