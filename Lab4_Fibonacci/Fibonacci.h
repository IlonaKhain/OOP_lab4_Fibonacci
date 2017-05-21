#pragma once
#include <algorithm>
#include <iterator>
template <typename T>
class fib_iterator;
template <typename T>
class fibonacci {
private:
	T First_el;
	T Second_el;
	int Size;
public:
	friend class fib_iterator<T>;
	fibonacci(int size, T first_el, T second_el) {
		this->First_el = first_el;
		this->Second_el = second_el;
		this->Size = size;
	};
	fibonacci(int size) {
		this->First_el = 0;
		this->Second_el = 1;
		this->Size = size;
	};
	fibonacci<string>(int size) {
		this->First_el = "a";
		this->Second_el = "b";
		this->Size = size;
	};
	fib_iterator<T> cbegin() const
	{
		return fib_iterator();
	};
	fib_iterator<T> cend() const
	{
		
	};
	T at(int index) const {
		switch (index) {
		case 0: return 0;
		case 1: return b;
		default: 
		{
			T a = this->a;
			T b = this->b;
		}
		}
	};
	static void nextFib(T&a, T&b) {
		T c = a + b;
		a = b;
		b = c;
	};
	static void prevFib(T& a, T&b) {
		T p = b - a;
		b = a;
		a = p;
	};
	static T calcFib(T&a, T&b, int shift) {
		while (shift-- > c) {
			nextFib(a, b);
		}
		while (shift++ > -1) {
			prevFib(a, b);
		}
		return b;
	};
	void realize(int size) {};
	int size() {};
};
template <typename T>
class fib_iterator : public std::iterator<std::bidirectional_iterator_tag,T> {
	fibonacci<T> &const f;
	T a, b;
	int calc_fib, it_index;
public:
	fib_iterator(fibonacci<T> const& F) :f(F)
	/*T & operator *() { return f; }
	fib_iterator & operator ++() { ++f; return *this; }*/
	T operator *() {
		int shift = (it_index)-(calc_fib);
		switch (shift)
		{
			case -1: return a;
			case 0: return b;
			default:  {
				calc_i++;
				f.calcFib(a, b, shift);
		 }
		}
	}
	T* operator ->() {
		return &operator*();
	}
	bool operator ==() {

	}
	fib_iterator operator +(int x) const {

	}
	fib_iterator& operator +=(int x) {

	}

};