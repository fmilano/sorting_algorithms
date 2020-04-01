/**
 * @file  main.cpp
 * @brief sample demonstrating how to use sorting algorithms
 *
 * Copyright (c) 2020 Federico E. Milano
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <vector>
#include <list>

#include "insertion_sort.hpp"

// C++ template to print vector container elements
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
  os << "[";
  for (typename std::vector<T>::size_type i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1)
      os << ", ";
  }
  os << "]";
  return os;
}

// C++ template to print list container elements
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& l)
{
  os << "[";
  auto it = l.begin();
  while (it != l.end()) {
    os << *it;
    if (++it != l.end())
      os << ", ";
  }

  os << "]";
  return os;
}

int main(void)
{
  std::vector<int> vecInt{ 5, 6, 8, 3, 7, 22, 1 };
  std::cout << "non sorted vector " << vecInt << std::endl;
  insertion_sort(begin(vecInt), end(vecInt));
  std::cout << "after insertion sort " << vecInt << std::endl << std::endl;

  std::list<double> vecDouble{ 4.5, 2.6, 1.8, 8.3, 5.7, 1.22, 9.1 };
  std::cout << "non sorted list " << vecDouble << std::endl;
  insertion_sort(begin(vecDouble), end(vecDouble));
  std::cout << "after insertion sort " << vecDouble << std::endl;


  return 0;
}
