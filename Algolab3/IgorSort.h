#pragma once

template<typename T>
void swap(T* a, T* b) {
	if constexpr (std::is_move_constructible<T>::value)
	{
		T temp = T(std::move(*b));
		b->~T();
		new (b) T(std::move(*a));
		a->~T();
		new (a) T(std::move(temp));
	}
	else
	{
		T temp(*b);
		b->~T();
		new (b) T(*a);
		a->~T();
		new (a) T(temp);
	}
}

template<typename T, typename Compare>
void insertion_sort(T* first, T* last, Compare comp) {
	T* i = first;
	T* j;
	while (i < last - 1) {
		j = i + 1;
		while (j > first && comp(*j, *(j - 1))) {
			swap(j, j - 1);
			--j;
		}
		++i;
	}
}

template<typename T, typename Compare>
void sort(T* first, T* last, Compare comp) {
	T* mid;
	T median;

	while (last - first >= 2) {

		mid = first + static_cast<int>(last - first) / 2;

		if (comp(*mid, *(last - 1))) {
			if (comp(*first, *mid)) {
				median = *mid;
			}
			else if (comp(*first, *(last - 1))) {
				median = *first;
			}
			else
				median = *(last - 1);
		}
		else {
			if (comp(*mid, *first)) {
				median = *mid;
			}
			else if (comp(*first, *(last - 1))) {
				median = *(last - 1);
			}
			else
				median = *first;
		}

		T* i = first;
		T* j = last - 1;

		while (i < j) {

			while (comp(*i, median)) {
				++i;
			}

			while (comp(median, *j)) {
				--j;
			}
			swap(i, j);
		}

		if (j - first < last - j) {
			sort(first, j, comp);
			first = j;
		}
		else {
			sort(j, last, comp);
			last = j;
		}
	}
}