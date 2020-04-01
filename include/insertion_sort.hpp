
#pragma once
#ifndef insertion_sort_h
#define insertion_sort_h

#include <algorithm>    // std::swap

template <typename ranIt>
void insertion_sort(ranIt first, ranIt last) {

	if (first == last)
		return;

    
	for (auto i = first + 1; i < last; ++i)	{
		
		while (i >= first && *i < *(i - 1)) {
			--i;
		}
	}


}


#endif // insertion_sort_h