#include <iostream>
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "Linklist.h"

using namespace std;
using namespace DTLib;

int main()
{
    Linklist<int> list;
    for(int i=0; i<5; i++)
    {
        list.insert(i);
    }

    for(int i=0; i<list.length(); i++)
    {
        cout << list.get(i) << " ";
    }
    cout << endl;

    list.remove(2);

    for(int i=0; i<list.length(); i++)
    {
        cout << list.get(i) << " ";
    }
    cout << endl;
    list.set(1,10);

    for(int i=0; i<list.length(); i++)
    {
        cout << list.get(i) << " ";
    }
    cout << endl;

    list.clear();
    cout << "after clear" << endl;
    for(int i=0; i<list.length(); i++)
    {
        cout << list.get(i) << " ";
    }
    cout << endl;




   return 0;
}

