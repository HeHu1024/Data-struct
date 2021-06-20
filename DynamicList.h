#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include "SeqList.h"
#include "Exception.h"


namespace DTLib{

template <typename T>
class DynamicList : public SeqList<T>
{
protected:
    int m_capacity;     // ˳��洢�ռ��С
public:
    DynamicList(int capacity)
    {
        this->m_array = new T[capacity];
        if( this->m_array != NULL )
        {
            this->m_length = 0;
            this->m_capacity = capacity;
        }else       // �׳��쳣
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"NO memory to create Dynamic object.....");
        }
    }

    int capacity() const
    {
        return m_capacity;
    }

    // ��������˳��洢�ռ��С
    void resize(int capacity)
    {
        // �ж��µĴ洢�ռ��С�Ƿ�͵�ǰ�Ĵ�С��ͬ
        if( capacity != m_capacity )
        {
            // Ϊʲô����m_array
            T* array = new T[capacity];
            if( array != NULL )
            {
                int length = (this->m_length < capacity ? this->m_length : capacity);
                for( int i = 0;i < length;i++ )
                {
                    array[i] = this->m_array[i];
                }
                T* temp = this->m_array;

                this->m_array = array;
                this->m_length = length;
                this->m_capacity = capacity;

                delete[] temp;

            }else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"NO memory to create Dynamic object.....");
            }
        }
    }
    // �黹�ռ�
    ~DynamicList()
    {
        delete[] this->m_array;
    }
};










}



#endif // DYNAMICLIST_H
