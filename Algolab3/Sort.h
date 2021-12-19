#pragma once
#include <type_traits>

template <class T>
void doMove(T& src, T& dest)
{
	if constexpr (std::is_move_constructible<T>::value)
	{
		new (&dest) T(std::move(src));
	}
	else
	{
		new (&dest) T(src);
	}
	src.~T();
}

template <class T>
void swap(T* a, T* b)
{
	if constexpr (std::is_move_constructible<T>::value)
	{
		T temp(std::move(*b));
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

template <class T, class Compare>
void insertion_sort(T* first, T* last, Compare comp)
{
	for (T* i = first; i < last - 1; ++i)
	{ 
#if std::is_move_constructible<T>::value
		T temp(std::move(i[1]));
# else
		T temp(i[1]);
#endif
		i[1].~T();

		T* j = i;
		for (; j >= first && comp(temp, *j); --j)
		{
			doMove(*j, j[1]);
		}

		doMove(temp, j[1]);
	}
}

template<class T, class Compare>
T getPivotVal(T* first, T* last, Compare comp)
{
	const int numElems = static_cast<int>(last - first);

	T pivot;
	{
		T* a = first;
		T* b = first + numElems / 2;
		T* c = last - 1;
		if (comp(*a, *b))
		{
			if (comp(*b, *c))
			{
				new (&pivot) T(*b);
			}
			else if (comp(*c, *a))
			{
				new (&pivot) T(*a);
			}
			else
			{
				new (&pivot) T(*c);
			}
		}
		else
		{
			if (comp(*c, *b))
			{
				new (&pivot) T(*b);
			}
			else if (comp(*a, *c))
			{
				new (&pivot) T(*a);
			}
			else
			{
				new (&pivot) T(*c);
			}
		}
	}
	return pivot;
}

template<class T, class Compare>
T* partition(T* first, T* last, Compare comp)
{
	T pivot = getPivotVal(first, last, comp);

	T* p1 = first - 1;
	T* p2 = last;

	while (true)
	{
		do
		{
			++p1;
		} while (comp(*p1, pivot));

		if (p1 >= p2)
		{
			return p1;
		}

		do 
		{
			--p2;
		} while (comp(pivot, *p2));

		if (p1 >= p2)
		{
			return p2;
		}

		swap(p1, p2);
	}
}

template <class T, class Compare>
void sort(T* first, T* last, Compare comp)
{
	while (last - first >= 23)
	{
		T* pivot = partition(first, last, comp);

		const size_t numElems1 = pivot - first;
		const size_t numElems2 = last - pivot;

		if (numElems1 < numElems2)
		{
			// if pivot is the first element it's important to include it in the first (smaller) partion
			// or the array won't be divided
			sort(first, pivot + 1, comp);
			first = pivot + 1;
		}
		else
		{
			// if pivot is the last - 1 element it's important to iinclude it in the first smaller partion
			sort(pivot, last, comp);
			last = pivot;
		}
	}

	insertion_sort(first, last, comp);
}