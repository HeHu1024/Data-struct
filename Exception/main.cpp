#include <iostream>

using namespace std;

double divide(double a, double b)
{
    double ret = 0;
    const double delta = 0.0000000000000001;
    // 判断b 是否为0
    if( !(-delta < b) && (b < delta) )
    {
        ret = a / b;
    }else
    {
        throw 0; // 产生除0异常
    }

    return ret;
}

void demo1()
{
    try
    {
        throw 'c';
    }
    catch(int i)
    {
        cout << "catch(int i)" << endl;
    }
    catch(double d)
    {
        cout << "catch(double d)" << endl;
    }catch(char c)
    {
        cout << "catch(char c)" << endl;
    }
}

int main()
{
    cout << "main() begin " << endl;

    try
    {
        divide(1,0);
    }
    catch(...)
    {
        cout << "divide by zero......" << endl;
    }



    demo1();
    cout << "main() endl" << endl;


    cout << "Hello World!" << endl;
    return 0;
}

