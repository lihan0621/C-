#pragma once

template<class _Ty>
_Ty* _My_Allocate(size_t _N, _Ty*)
{
    if (_N < 0)
        _N = 0;
    //����_N��_T���͵Ŀռ�
    return((_Ty*)operator new((size_t)_N * sizeof(_Ty)));  //operator newֻ��������ռ�  
}
//�ռ�������
template<class _Ty>
class my_allocator
{
public:
    //��������
    typedef size_t   size_type;
    typedef _Ty      value_type;
    typedef _Ty* pointer_type;
    typedef _Ty& reference_type;
    typedef const _Ty* const _pointer_type;
    typedef const _Ty& const _reference_type;
    //1.��������ռ�
    pointer_type allocae(size_type _N, const void*)
    {
        return (_My_Allocate(_N, (pointer_type)0));   //����N��pointer_type���͵Ŀռ�
    }
    char* _Charalloc(size_type _N)
    {
        return(_My_Allocate((size_type)_N, (char*)0)); //����N���ռ�
    }
    //2.���������
    //3.������������
    //4.������տռ�
    void deallocate(void* _P, size_type)
    {
        operator delete(_P);
    }
};
