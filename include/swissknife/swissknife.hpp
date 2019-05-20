#ifndef SWISSKNIFE_INCLUDE_SWISSKNIFE_HPP
#define SWISSKNIFE_INCLUDE_SWISSKNIFE_HPP

namespace swissknife
{
template<std::size_t Iter, std::size_t Last, template<class...> class Container,
         typename UnaryFunction, typename... Ts>
typename std::enable_if<Iter == Last, void>::type 
universal_for_each(Container<Ts...>& container, UnaryFunction f)
{ 
}

template<std::size_t Iter, std::size_t Last, template<class...> class Container = std::tuple,
         typename UnaryFunction, typename... Ts>
typename std::enable_if<Iter < Last, void>::type 
universal_for_each(Container<Ts...>& container, UnaryFunction f)
{
    f(std::get<Iter>(container));
    universal_for_each<Iter+1, Last, Container, UnaryFunction, Ts...>(container, f);
}

template<std::size_t Iter = 0, template<class...> class Container,
         typename UnaryFunction, typename... Ts>
void universal_for_each(Container<Ts...>& container, UnaryFunction f)
{
  universal_for_each<Iter, sizeof...(Ts), Container, UnaryFunction, Ts...>(container, f);
}

template<typename Iter, typename UnaryFunction> 
void universal_for_each(Iter first, Iter last, UnaryFunction f)
{
    for(; first != last; ++first)
    {
        f(*first);
    }
}
} //swissknife
#endif //SWISSKNIFE_INCLUDE_SWISSKNIFE_HPP
