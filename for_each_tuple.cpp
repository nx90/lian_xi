//
// Created by 23212 on 2019/10/20.
//

#include <tuple>
#include <type_traits>
#include <utility>
#include <c++/4.8.3/iostream>

template<size_t N>
struct Apply {
    template<typename F, typename T0, typename T, typename... A>
    static inline auto apply(F && f, T0&& t0, T && t, A &&... a)
    -> decltype(Apply<N-1>::apply(
            ::std::forward<F>(f), ::std::forward<T0>(t0), ::std::forward<T>(t),
            ::std::get<N-1>(::std::forward<T>(t)),
            ::std::forward<A>(a)...
    ))
    {
        return Apply<N-1>::apply(::std::forward<F>(f), ::std::forward<T0>(t0),
                                 ::std::forward<T>(t),
                                 ::std::get<N-1>(::std::forward<T>(t)),
                                 ::std::forward<A>(a)...
        );
    }
};

template<>
struct Apply<0> {
    template<typename F, typename T0, typename T, typename... A>
    static inline auto apply(F && f, T0&& t0, T &&, A &&... a)
    -> decltype(::std::forward<F>(f)
            (::std::forward<T0>(t0), ::std::forward<A>(a)...))
    {
        return ::std::forward<F>(f)(::std::forward<T0>(t0), ::std::forward<A>
                                            (a)...);
    }
};

template<typename F, typename T0, typename T>
inline auto apply(F && f, T0 && t0, T && t)
-> decltype(Apply< ::std::tuple_size<
        typename ::std::decay<T>::type
>::value>::apply(::std::forward<F>(f),
                 ::std::forward<T0>(t0),
                 ::std::forward<T>(t)))
{
    return Apply< ::std::tuple_size<
            typename ::std::decay<T>::type
    >::value>::apply(::std::forward<F>(f),
                     ::std::forward<T0>(t0),
                     ::std::forward<T>(t));
}
/*
void one(int i, double d)
{
    std::cout << "function one(" << i << ", " << d <<
              ");\n";
}
int two(int i)
{
    std::cout << "function two(" << i << ");\n";
    return i;
}


//测试代码
int main14()
{
    std::tuple<int, double> tup(23, 4.5);
    apply(one, tup);

    int d = apply(two, std::make_tuple(2));

    return 0;
}
 */