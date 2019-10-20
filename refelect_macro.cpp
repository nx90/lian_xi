//
// Created by 23212 on 2019/10/20.
//




#include <c++/4.8.3/map>
#include <c++/4.8.3/iostream>
#include <c++/4.8.3/functional>
#include "for_each_tuple.cpp"

#define COUNT_HELPER     __COUNT/3
#define COUNT_HELPER_PLUS    __COUNT/3+1

#define REFLECT_CLASS_HEAD(type)    \
struct _##type##_helper{             \
    _##type##_helper(type & p) : pp(p){}    \
    type pp;                                \
    auto get_it(){                          \
        return make_tuple(

//member就把类型和名字都带过去就行
#define REFLECT_CLASS_MEMBER1()


#define REFLECT_CLASS_END(type)     \
tupleIndex.insert({#type, COUNT_HELPER});    \
auto tuple##COUNT_HELPER_PLUS = std::tuple_cat(tuple##COUNT_HELPER, make_tuple(std::declval<_##type##_helper>()));\


std::tuple<int> t{100};
std::map<std::string, int> tupleIndex{};

std::tuple<uint16_t , uint8_t , uint64_t > test{1,5,9};

template <size_t N>                                                         //重要4-1
struct go{
    template <typename Tuple>
    static inline auto gogo(Tuple t)
    -> decltype(std::get<N>(t))
    {
        return std::get<N>(t);
    }
};

/*
class _PceNeDcPhyPort_helper {
    explicit _PceNeDcPhyPort_helper()
};
*/

int main(){
    auto t3 = std::tie(t, test);
    auto t4 = std::make_tuple(9,6,"no");
    //makeMyTuple(t3, t4);
    auto t2 = std::tuple_cat(t3, make_tuple(t4));                           //重要3
    std::cout << std::tuple_size<decltype(t2)>::value << std::endl;
    auto tmp_tuple = make_tuple(std::make_tuple(9,9,6));
    auto t5 = std::tuple_cat(t2, tmp_tuple);
    std::cout << std::tuple_size<decltype(t5)>::value << std::endl;
    int i = 3;
    const size_t N = 3;
    auto xx0 = std::get<0>(t2);
    auto xx1 = std::get<1>(t2);
    auto xx2 = std::get<2>(t2);
    auto xx3 = go<N>::gogo(t5);                                             //重要4-2
    std::cout << std::get<0>(xx3) << std::endl;
    std::cout << std::get<1>(xx3) << std::endl;
    std::cout << std::get<2>(xx3) << std::endl;
    std::cout << 5/2 << std::endl;
    return 0;
}
