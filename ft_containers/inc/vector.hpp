#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <limits>
# include "VectorIterator.hpp"
# include "utils.hpp"

namespace ft
{
    template<typename T, class Allocator = std::allocator<T> >
	class Vector
	{
        public:
            typedef T                                           value_type;
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::reference		    reference; // same as "typedef T& reference"
            typedef typename allocator_type::const_reference    const_reference;// same as "typedef const T& const_reference"
            typedef typename allocator_type::pointer            pointer;// same as "typedef T* pointer"
            typedef typename allocator_type::const_pointer      const_pointer;// same as "typedef const T* const_pointer"
            typedef size_t                                      size_type;
            typedef ft::VectorIterator<T>                       iterator;
			typedef ft::ConstVectorIterator<T>                  const_iterator;
			typedef ft::ReverseVectorIterator<T>                reverse_iterator;
			typedef ft::ConstReverseVectorIterator<T>           const_reverse_iterator;
		private:
			size_type       _length;
			size_type       _capacity;
			pointer         _ptr;
			allocator_type  _allocator;
		public:
			explicit Vector(const allocator_type &allocator = allocator_type())
			 : _length(0), _capacity(0), _ptr(0), _allocator(allocator)
			{
				_ptr = _allocator.allocate(0);
			};
			template <class InputIterator>
			Vector(InputIterator begin, InputIterator end, const allocator_type &allocator = allocator_type())
			: _length(0), _capacity(0), _ptr(0), _allocator(allocator)
			{
				_ptr = _allocator.allocate(0);
				assign(begin, end);
			};
			Vector(size_type n, const_reference value = value_type(), const allocator_type &allocator = allocator_type())
			: _length(0), _capacity(0), _ptr(0), _allocator(allocator)
			{
				_ptr = _allocator.allocate(0);
				assign(n, value);
			};
			Vector(const Vector &other)
			: _length(0), _capacity(0), _ptr(0), _allocator(other._allocator)
			{
				*this = other;
			};
			~Vector(void)
			{
				_allocator.deallocate(_ptr, _capacity);
			};
			Vector &operator=(const Vector &other)
			{
				if (_ptr != 0)
					_allocator.deallocate(_ptr, _capacity);
				_allocator = other._allocator;
				_capacity = 0;
				_length = 0;
				_ptr = _allocator.allocate(0);
				assign(other.begin(), other.end());
				return (*this);
			};
			reference operator[](size_type n)
			{
				return (_ptr[n]);
			};
			const_reference operator[](size_type n) const
			{
				return (_ptr[n]);
			};
			iterator begin(void)
			{
				return (iterator(_ptr));
			};
			const_iterator begin(void) const
			{
				return (const_iterator(_ptr));
			};
			iterator end(void)
			{
				return (iterator(_ptr + _length));
			};
			const_iterator end(void) const
			{
				return (const_iterator(_ptr + _length));
			};
			reverse_iterator rbegin(void)
			{
				return (reverse_iterator(_ptr + _length - 1));
			};
			const_reverse_iterator rbegin(void) const
			{
				return (const_reverse_iterator(_ptr + _length - 1));
			};
			reverse_iterator rend(void)
			{
				return (reverse_iterator(_ptr - 1));
			};
			const_reverse_iterator rend(void) const
			{
				return (const_reverse_iterator(_ptr - 1));
			};
			void reserve(size_type n)
			{
				if (n > _capacity)
				{
					size_type i = -1;
					pointer	tmp;
					tmp  = _allocator.allocate(n);
					_capacity = n;
					while (++i < _length)
						tmp[i] = _ptr[i];
					_allocator.deallocate(_ptr, _capacity);
					_ptr = tmp;
				}
			};
			void push_back(const value_type &value)
			{
				if (_length + 1 > _capacity)
					reserve(_length + 1);
				_ptr[_length++] = value;
			};
			size_type size(void) const
			{
				return (_length);
			};
			size_type capacity(void) const
			{
				return (_capacity);
			};
			bool empty(void) const
			{
				return (_length == 0);
			};
			iterator insert(iterator position, const value_type &value)
			{
				size_type i = 0;
				iterator it = begin();
				while (it + i != position && i < _length)
					i++;
				if (_capacity < _length + 1)
					reserve(_length + 1);
				size_type j = _capacity - 1;
				while (j > i)
				{
					_ptr[j] = _ptr[j - 1];
					j--;
				}
				_ptr[i] = value;
				_length++;
				return (iterator(&_ptr[i]));
			};
			void insert(iterator position, size_type n, const value_type &value)
			{
				while (n--)
					position = insert(position, value);
			};
			template <class InputIterator>
			void insert(iterator position, InputIterator begin, InputIterator end)
			{
				while (begin != end)
				{
					position = insert(position, *begin) + 1;
					++begin;
				}
			};
			size_type max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(value_type));
			};
			reference at(size_type n)
			{
				if (n >= _length || n < 0)
					throw std::length_error("index out of range");
				return _ptr[n];
			};
			const_reference at(size_type n) const
			{
				if (n >= _length || n < 0)
					throw std::length_error("index put of range");
				return _ptr[n];
			};
			iterator erase(iterator position)
			{
				iterator temp = position;
				while (temp + 1 != end())
				{
					*temp = *(temp + 1);
					temp++;
				}
				_length--;
				return (iterator(position));
			};
			iterator erase(iterator begin, iterator end)
			{
				while (begin != end)
				{
					erase(begin);
					end--;
				}
				return (iterator(begin));
			};
			void clear(void)
			{
				erase(begin(), end());
			};
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				clear();
				insert(begin(), first, last);
			};
			void assign(size_type n, const value_type &value)
			{
				clear();
				insert(begin(), n, value);
			};
			reference front(void)
			{
				return _ptr[0];
			};
			const_reference front(void) const
			{
				return _ptr[0];
			};
			reference back(void)
			{
				return _ptr[_length - 1];
			};
			const_reference back(void) const
			{
				return _ptr[_length - 1];
			};
			void pop_back(void)
			{
				if (_length)
					_length--;
			};
			void resize(size_type n, value_type value = value_type())
			{
				while (n < _length)
					pop_back();
				while (n > _length)
					push_back(value);
			};
			void swap(Vector &other)
			{
				t_swap(_ptr, other._ptr);
				t_swap(_capacity, other._capacity);
				t_swap(_length, other._length);
			};
	};

	
    template <class T, class Alloc>
	void swap(Vector<T, Alloc> &x, Vector<T, Alloc> &y)
	{
		x.swap(y);
	};
	template<class T, class Alloc>
	bool operator==(const Vector<T, Alloc> &a, const Vector<T, Alloc> &b)
	{
		if (a.size() != b.size())
			return (false);
		unsigned long i = -1;
		while (++i < a.size())
		{
			if (a[i] != b[i])
				return (false);
		}
		return (true);
	};
	template<class T, class Alloc>
	bool operator!=(const Vector<T, Alloc> &a, const Vector<T, Alloc> &b)
	{
		return (!(a == b));
	};
	template <class T, class Alloc>
	bool operator<(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		size_t		i;
		size_t		n;

		if (a.size() > b.size())
			n = b.size();
		else
			n = a.size();
		i = 0;
		while (i < n)
		{
			if (a.at(i) != b.at(i))
				return (a.at(i) < b.at(i));
			i++;
		}
		return (a.size() < b.size());
	}

	template <class T, class Alloc>
	bool operator<=(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		return (a < b || a == b);
	}

	template <class T, class Alloc>
	bool operator>(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		return (!(a < b) && !(a == b));
	}

	template <class T, class Alloc>
	bool operator>=(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		return (!(a < b));
	}
};

#endif