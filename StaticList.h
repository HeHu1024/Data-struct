#ifndef STATICLIST_H
#define STATICLIST_H

#include "SeqList.h"

namespace DTLib
{

template <typename T,int N>
class StaticList : public SeqList<T>
{
protected:
    T m_space[N];  // ˳��洢�ռ䣬NΪģ�����
public:
    StaticList()    // ָ�������Ա�ľ���ֵ
    {
        this->m_array = m_space;
        this->m_length = 0;
    }

    int capacity()const
    {
        return N;
    }
};



}



#endif // STATICLIST_H
