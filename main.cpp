#include <iostream>
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "Linklist.h"

using namespace std;
using namespace DTLib;

class Test
{
public:
    Test()
    {
        throw 0;
    }
};

int main()
{
    Linklist<Test> list;

    cout << "Hello Mr.He" << endl;


    Linklist<int> list1;
    for( int i=0; i<5; i++ )
    {
        list1.insert(i,i+1);
    }
    for( int i=0; i<list1.length();i++ )
    {
        cout << list1.get(i) << " ";
    }
    cout << endl;
   return 0;
}

