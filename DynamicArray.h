#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "Exception.h"
#include "Array.h"

namespace DTLib
{

template <typename T>
class DynamicArray : public Array<T>
{
protected:
    int m_length;


    T* copy(T* array,int len,int newlen)
    {
        T* ret = new T[newlen];
        if( ret != NULL )
        {
            int size = (len < newlen) ? len : newlen;

            for( int i=0; i<size; i++ )
            {
                ret[i] = array[i];
            }

        }else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to copy DynamicArray object..... ");
        }
        return ret;
    }
    void update(T* array, int length)
    {
        if( array != NULL )
        {
            T* temp = this->m_array;

            this->m_length = length;
            this->m_array = array;

            delete[] temp;
        }else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to update DynamicArray object..... ");
        }
    }
    void init(T* array,int length)
    {
        if(array != NULL)
        {
            this->m_array = array;
            this->m_length = length;
        }else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to init DynamicArray object..... ");
        }
    }

public:
    DynamicArray(int length)
    {
        init(new T[length],length);
    }
    DynamicArray(const DynamicArray<T>& obj)
    {

        init(copy(obj.m_array,obj.m_length,obj.m_length),length);
    }

    DynamicArray<T>& operator= (const DynamicArray<T>& obj)
    {
        if( this != &obj )
        {
            // 将obj 的元素全部拷贝到array里面去
            //T* array = copy(obj.m_array,obj.m_length,obj.m_length);
            //update(array,obj.m_length);
            // 先复制一个数组出来，然后将数组设置到成员变量里面
            update(copy(obj.m_array,obj.m_length,obj.m_length),obj.m_length);
        }
        return *this;
    }

    int length() const
    {
        return m_length;
    }
    void resize(int length)
    {
        if( length != m_length )
        {
            // 更新数组元素
            update(copy(this->m_array,m_length,length),length);
        }
    }
    ~DynamicArray()
    {
        delete[] this->m_array;
    }

};







}



#endif // DYNAMICARRAY_H
