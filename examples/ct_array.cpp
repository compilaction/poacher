#include <cstddef>
#include <iostream>

#include <poacher/utility/ct_array.hpp>

int main()
{
  constexpr poacher::ct_array a = {1,2,3};
  constexpr poacher::ct_array b = {10,20,30,40,50};
  constexpr poacher::ct_array c = {100,200};

  constexpr auto m = poacher::aggregate(a,b,c);

  std::cout << "size(m) = " << m.size() << "\n";
  std::cout << "capa(m) = " << m.capacity() << "\n";
  for(auto t : m)
  {
    std::cout << "capa(t) = " << t.capacity() << "\n";
    for(auto x : t)
      std::cout << x << " ";
    std::cout << "\n";
  }
}
