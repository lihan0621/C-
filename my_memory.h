#pragma once

template<class _Ty>
_Ty* _My_Allocate(size_t _N, _Ty*)
{
    if (_N < 0)
        _N = 0;
    //申请_N个_T类型的空间
    return((_Ty*)operator new((size_t)_N * sizeof(_Ty)));  //operator new只负责申请空间  
}
//空间配置器
template<class _Ty>
class my_allocator
{
public:
    //定义类型
    typedef size_t   size_type;
    typedef _Ty      value_type;
    typedef _Ty* pointer_type;
    typedef _Ty& reference_type;
    typedef const _Ty* const _pointer_type;
    typedef const _Ty& const _reference_type;
    //1.负责申请空间
    pointer_type allocae(size_type _N, const void*)
    {
        return (_My_Allocate(_N, (pointer_type)0));   //申请N个pointer_type类型的空间
    }
    char* _Charalloc(size_type _N)
    {
        return(_My_Allocate((size_type)_N, (char*)0)); //申请N个空间
    }
    //2.负责构造对象
    //3.负责析构对象
    //4.负责回收空间
    void deallocate(void* _P, size_type)
    {
        operator delete(_P);
    }
};
