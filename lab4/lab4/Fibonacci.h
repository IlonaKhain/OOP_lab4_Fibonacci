#pragma once
#include <algorithm>
#include <iterator>
template <typename T>
class fib_iterator;
using namespace std;
template <typename T>
class fibonacci {
private:
	T First_el;
	T Second_el;
	int Size;
public:
	friend class fib_iterator<T>;
	fibonacci(int size, T first_el, T second_el)
	{
		this->First_el = first_el;
		this->Second_el = second_el;
		this->Size = size;
	};

	fibonacci(int size)
	{
		this->First_el = 0;
		this->Second_el = 1;
		this->Size = size;
	};
	
	/*fibonacci<string>(int size) {
		this->First_el = "a";
		this->Second_el = "b";
		this->Size = size;
	};*/
	fib_iterator<T> cbegin() const
	{
		return fib_iterator<T>(*this);
	};
	fib_iterator<T> cend() const
	{
		return fib_iterator<T>(*this, this->Size);
	};
	T at(int index) const {
		switch (index) {
		case 0: return a;
		case 1: return b;
		default: 
		{
			T a = this->First_el;
			T b = this->Second_el;
			return calcFib(First_el, Second_el, index);
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
		while (shift-- > 0) {
			nextFib(a, b);
		}
		while (shift++ > -1) {
			prevFib(a, b);
		}
		return b;
	};
	void realize(int size) {
		this->Size = size;
	};
	int size() {
		return this->Size;
	};
	
};


template <typename T>
class fib_iterator : public std::iterator<std::bidirectional_iterator_tag,T> {
	fibonacci<T> const& f;
	T a, b;
	int calc_fib, it_index;
public:
	fib_iterator (fibonacci<T> const& F) :f(F) {
		a = f.First_el;
		b = f.Second_el;
		it_index = 0;
		calc_fib = 1;
	}
	fib_iterator(fibonacci<T> const& F, int index) :f(F) {
		a = f.First_el;
		b = f.Second_el;
		it_index = index;
		calc_fib =1;
	}
	
	fib_iterator& operator++() {
		this->it_index++;
		return *this;
	}
	fib_iterator operator++(int) {
		this->it_index--;		
	}
	fib_iterator& operator--() {
		this->it_index--;
		return *this;
		
	}
	fib_iterator operator--(int) {
		this->it_index--;
		return *this;
	}
	fib_iterator& operator-=(int index) {
		this->it_index-=index;
		return *this;

	}
	fib_iterator& operator+=(int index) {
		this->it_index += index;
		return *this;

	}
	T operator*() {
		int shift = (it_index)-(calc_fib);
		switch (shift)
		{
			case -1: return a;
			case 0: return b;
			default:  {
				calc_fib += shift;
				return 	f.calcFib(a, b, shift);
				/*calc_i++;
				f.calcFib(a, b, shift);*/
		 }
		}
	}
	T* operator ->() {
		return &operator*();
	}
	/*fib_iterator operator +(int x) const {

	}
	fib_iterator& operator +=(int x) {

	}*/
	bool operator>(fib_iterator &iterator)
	{
		return (this->it_index > iterator.it_index);
	}
	bool operator<(fib_iterator &iterator)
	{
		return (this->it_index < iterator.it_index);
	}
	bool operator>=(fib_iterator &iterator)
	{
		return (this->it_index >= iterator.it_index);
	}
	bool operator<=(fib_iterator &iterator)
	{
		return (this->it_index <= iterator.it_index);
	}
	bool operator==(fib_iterator &iterator)
	{
		return (this->it_index == iterator.it_index);
	}
	bool operator!=(fib_iterator &iterator)
	{
		return !(this->it_index == iterator.it_index);
	}
	fib_iterator& operator =(const fib_iterator& iterator)
	{
		this->it_index = iterator.it_index;
		this->calc_fib = iterator.calc_fib;
		this->a = iterator.a;
		this->b = iterator.b;
		return *this;
	}
};
template<>
fibonacci<string>::fibonacci(int size) {
	Size = size;
	First_el = "a";
	Second_el = "b";
}
template<>
void fibonacci<string>::prevFib(string& a,string& b) {
	string p = p.erase(0,a.length());
	b = a;
	a = p;
}
template<>
 void fibonacci<string>::nextFib(string& a, string&b) {
	string c =a.append(b);
	a = b;
	b = c;
};
