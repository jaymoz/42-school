#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <typename T, class Container = ft::Vector<T> >
	class Stack
	{
		public:
			typedef T                                   value_type;
			typedef Container                           container_type;
			typedef typename container_type::size_type  size_type;
		protected:
			container_type c;
		public:
			explicit Stack(const container_type &ctn = container_type()): c(ctn){};
			Stack(const Stack &other){*this = other; };
			~Stack(void)
			{};
			Stack &operator=(const Stack &other)
			{
				this->c = other.c;
				return (*this);
			};
			bool empty(void) const
			{
				return (c.empty());
			};
			size_type size(void) const
			{
				return (c.size());
			};
			value_type &top(void)
			{
				return (c.back());
			};
			const value_type &top(void) const
			{
				return (c.back());
			};
			void push(const value_type &value)
			{
				c.push_back(value);
			};
			void pop(void)
			{
				c.pop_back();
			};
		private:
			template <class A, class B>
			friend bool	operator==(const Stack<A, B> &left, const Stack<A, B> &right);
			template <class A, class B>
			friend bool	operator!=(const Stack<A, B> &left, const Stack<A, B> &right);
			template <class A, class B>
			friend bool	operator<(const Stack<A, B> &left, const Stack<A, B> &right);
			template <class A, class B>
			friend bool	operator<=(const Stack<A, B> &left, const Stack<A, B> &right);
			template <class A, class B>
			friend bool	operator>(const Stack<A, B> &left, const Stack<A, B> &right);
			template <class A, class B>
			friend bool	operator>=(const Stack<A, B> &left, const Stack<A, B> &right);
	};
	template <class T, class Container>
	bool operator==(const Stack<T, Container> &left, const Stack<T, Container> &right)
	{
		return (left.c == right.c);
	};
	template <class T, class Container>
	bool operator!=(const Stack<T, Container> &left, const Stack<T, Container> &right)
	{
		return (left.c != right.c);
	};
	template <class T, class Container>
	bool operator>(const Stack<T, Container> &left, const Stack<T, Container> &right)
	{
		return (left.c > right.c);
	};
	template <class T, class Container>
	bool operator<(const Stack<T, Container> &left, const Stack<T, Container> &right)
	{
		return (left.c < right.c);
	};
	template <class T, class Container>
	bool operator>=(const Stack<T, Container> &left, const Stack<T, Container> &right)
	{
		return (left.c >= right.c);
	};
	template <class T, class Container>
	bool operator<=(const Stack<T, Container> &left, const Stack<T, Container> &right)
	{
		return (left.c <= right.c);
	};
};

#endif