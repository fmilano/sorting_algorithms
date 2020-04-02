/**
 * @file  merge_sort.hpp
 * @brief merge sort implementation
 *
 * Copyright (c) 2020 Federico E. Milano
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#pragma once
#ifndef merge_sort_h
#define merge_sort_h

#include <algorithm>    // std::swap
namespace {

  template <typename RandomIt>
  void merge(RandomIt first, RandomIt middle, RandomIt last) {

  }

}

template <typename RandomIt>
void merge_sort(RandomIt first, RandomIt last) {

  if (first == last || first + 1 == last)
    return;

  auto middle = first + (last - first) / 2;
  merge_sort(first, middle); // middle is not included in the range
  merge_sort(middle, last);
  merge(first, middle, last);

}


#endif // merge_sort_h
