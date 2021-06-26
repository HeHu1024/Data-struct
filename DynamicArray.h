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
        }else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to update DynamicArray object..... ");
        }
    }

public:
    DynamicArray(int length)
    {
        this->m_array = new T[length];
        if( this->m_array != NULL )
        {
            this->m_length = length;
        }else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicArray object..... ");
        }
    }
    DynamicArray(const DynamicArray<T>& obj)
    {
        this->m_array = new T[obj.m_length];
        if( this->m_array != NULL )
        {
            this->m_length = length;
            for(int i=0; i<obj.m_length; i++)
            {
                this->m_array[i] = obj.m_array[i];
            }
        }else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicArray object..... ");
        }
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
            T* array = new T[length];

            if( array != NULL )
            {
                int size = (length < m_length) ? length : m_length;
                for( int i=0; i<size; i++ )
                {
                    array[i] = this->m_array[i];
                }

                T* temp = this->m_array;
                this->m_array = array;
                this->m_length = length;

                delete[] temp;
            }else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicArray object..... ");
            }
        }
    }
    ~DynamicArray()
    {
        delete[] this->m_array;
    }

};







}



#endif // DYNAMICARRAY_H
