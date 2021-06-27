#include "Object.h"
#include <cstdlib>
#include <iostream>

using namespace std;


namespace DTLib
{

// �����쳣����˵��������������������׳��쳣
void* Object::operator new(unsigned int size) throw()
{
    return malloc(size);
}

void Object::operator delete(void* p)
{
    free(p);
}
// new ʧ�ܵ�ʱ�򣬷��ؿ�ֵ���������׳��쳣
void* Object::operator new[](unsigned int size) throw()
{
    return malloc(size);
}

void Object::operator delete[](void* p)
{
    free(p);
}


bool Object::operator ==(const Object& obj)
{
    return (this == &obj);
}

bool Object::operator !=(const Object& obj)
{
    return (this != &obj);
}

Object::~Object()
{

}



}
