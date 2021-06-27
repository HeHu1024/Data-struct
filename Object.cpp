#include "Object.h"
#include <cstdlib>
#include <iostream>

using namespace std;


namespace DTLib
{

// 标上异常规则说明，表明这个函数不会抛出异常
void* Object::operator new(unsigned int size) throw()
{
    return malloc(size);
}

void Object::operator delete(void* p)
{
    free(p);
}
// new 失败的时候，返回空值，而不是抛出异常
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
