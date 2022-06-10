#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <exception>

template<typename T>
class Array
{
	private:
		T		*_arr;
		size_t	_size;
	public:
		Array(void) : _arr(NULL), _size(0){}
		~Array(void){ delete [] _arr; }
		Array(const Array &obj) : _arr(NULL), _size(0) { *this = obj; }
		Array(unsigned int n) : _arr(new T[n]), _size(n) { }

		Array	&operator=(const Array &rhs)
		{
			delete [] _arr;
			_size = rhs.size();
			_arr = new T[_size];
			for (size_t i = 0; i < rhs.size(); i++)
				_arr[i] = rhs[i];
			return *this;
		}

		T		&operator[](size_t i)
		{
			if (i >= _size)
				throw std::exception();
			return _arr[i];
		}
		T		operator[](size_t i) const
		{
			if (i >= _size)
				throw std::exception();
			return _arr[i];
		}
		
		size_t	size(void) const { return _size;}
};

#endif
