#include <iostream>
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "Linklist.h"

using namespace std;
using namespace DTLib;

class Test : public Object
{
public:
    Test(int v = 0)
    {
        m_i = v;
    }
    bool operator ==(const Test& t)
    {
        return (m_i == t.m_i);
    }

private:
    int m_i;


};

int main()
{
   Linklist<int> list;
   for( int i = 0;i < 5; i++ )
   {
       list.insert(i,i+1);
   }
   // ����list
   // ��0��ʼ��ÿ���ƶ�1����ֱ��list û�н���
   for( list.move(0);!list.end();list.next() )
   {
       cout << list.current() << " ";
   }
   cout << endl;

   for( list.move(0,2);!list.end();list.next() )
   {
       cout << list.current() << " ";
   }
   cout << endl;


   for( list.move(0,3);!list.end();list.next() )
   {
       cout << list.current() << " ";
   }
   cout << endl;

   return 0;
}

