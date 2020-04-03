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
#include <iterator>
#include <vector>

namespace {

  template <typename RandomIt>
  void merge(RandomIt first, RandomIt middle, RandomIt last) {
    std::vector<typename std::iterator_traits<RandomIt>::value_type> left(first, middle);
    std::vector<typename std::iterator_traits<RandomIt>::value_type> right(middle, last);

    auto leftIt = left.begin();
    auto rightIt = right.begin();

    while (leftIt < left.end() || rightIt < right.end()) {

      if (leftIt < left.end() && rightIt < right.end()) {
        if (*leftIt < *rightIt) {
          *first = *leftIt;
          ++leftIt;
        }
        else {
          *first = *rightIt;
          ++rightIt;
        }
      }
      else if (leftIt < left.end()){
        *first = *leftIt;
        ++leftIt;
      }
      else {
        *first = *rightIt;
        ++rightIt;
      }

      ++first;
    }
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
