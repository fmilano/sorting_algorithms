/**
 * @file  insertion_sort.hpp
 * @brief insertion sort implementation
 *
 * Copyright (c) 2020 Federico E. Milano
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#pragma once
#ifndef insertion_sort_h
#define insertion_sort_h

#include <algorithm>    // std::swap

template <typename bidirIt>
void insertion_sort(bidirIt first, bidirIt last) {

	if (first == last)
		return;
    
  auto i = first;
  ++i;
  for (; i != last; ++i)	{
		
    auto j = i;
    auto prev = i;
    while (j != first) {
      --prev;
      if (!(*j < *prev))
        break;

      std::swap(*j, *prev);
      --j;
    }
  }
}


#endif // insertion_sort_h
