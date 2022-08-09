#ifndef UTILS_HPP
# define UTILS_HPP
# include "utils.hpp"

namespace ft
{
    template<typename InputIt1, typename InputtIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,  InputtIt2 first2, InputtIt2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 <* first1)
                return false;
            else if (*first1 <* first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    template<class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp) {
        for ( ; (first1 != last1) && (first2 != last2); first1++, (void) first2++ ) {
            if (comp(*first1, *first2))
                return true;
            if (comp(*first2, *first1))
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template<typename T1, typename T2>
	struct pair 
    {
		typedef T1	first_type;
		typedef T2	second_type;

		first_type first;
		second_type second;

		pair() : first(), second() {}
		pair(const first_type &a, const second_type &b) : first(a), second(b) {}
		pair(const pair<T1, T2>& copy) : first(copy.first), second(copy.second) {}

		template<typename U, typename V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}
		pair &operator=(const pair &copy) {
			if (this != &copy) {
				first = copy.first;
				second = copy.second;
			}
			return *this;
		}
		~pair() {}
	};

	template <typename T1, typename T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};
	template <typename T1, typename T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs == rhs);
	};
	template <typename T1, typename T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first < rhs.first || (!(lhs.first < rhs.first) && lhs.second < rhs.second));
	};
	template <typename T1, typename T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(rhs < lhs);
	};
	template <typename T1, typename T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (rhs < lhs);
	};
	template <typename T1, typename T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs < rhs);
	};
	template<typename T1, typename T2>
	pair<T1, T2> make_pair(T1 x, T2 y) {
		return (pair<T1, T2>(x, y));
	};
	template <typename T> 
    struct is_integral 
    { 
        static const bool value = false;
    };

	template <> 
    struct is_integral<bool> 
    { 
		static const bool value = true;
	};
	template <> 
    struct is_integral<char> 
    {
		static const bool value = true;
	};
	template <> 
    struct is_integral<short int> 
    {
		static const bool value = true;
	};
	template <> 
    struct is_integral<int> 
    {
		static const bool value = true;
	};
	template <> 
    struct is_integral<long int> 
    {
		static const bool value = true;
	};
	template <> 
    struct is_integral<long long int> 
    {
		static const bool value = true;
	};
	template <> 
    struct is_integral<unsigned char> 
    {
		static const bool value = true;
	};
	template <> 
    struct is_integral<unsigned short int> {
		static const bool value = true;
	};
	template <> 
    struct is_integral<unsigned int> {
		static const bool value = true;
	};
	template <> 
    struct is_integral<unsigned long int> {
		static const bool value = true;
	};
	template <> 
    struct is_integral<unsigned long long int> {
		static const bool value = true;
	};
	template <> 
    struct is_integral<const bool> { 
		static const bool value = true;
	};
	template <> 
    struct is_integral<const char> {
		static const bool value = true;
	};
	template <> 
    struct is_integral<const short int> {
		static const bool value = true;
	};
	template <> 
    struct is_integral<const int> {
		static const bool value = true;
	};
	template <> 
    struct is_integral<const long int> {
		static const bool value = true;
	};
	template <> 
    struct is_integral<const long long int> {
		static const bool value = true;
	};
	template <>
    struct is_integral<const unsigned char> {
		static const bool value = true;
	};
	template <> 
    struct is_integral<const unsigned short int> {
		static const bool value = true;
	};
	template <> 
    struct is_integral<const unsigned int> {
		static const bool value = true;
	};
	template <> 
    struct is_integral<const unsigned long int> {
		static const bool value = true;
	};
	template <> 
    struct is_integral<const unsigned long long int> {
		static const bool value = true;
	};

	template <typename T>
	void	t_swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};
	template <class Iterator> class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};
	template <class T> class iterator_traits<T*>{
		public:
			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;
	};
	template <class T> class iterator_traits<const T*>{
		public:
			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;
	};
	template <class Key, class T>
	struct Btree
	{
		pair<Key, T>	pair;
		Btree 				*left;
		Btree 				*right;
		Btree 				*parent;
		bool 				end;
	};

};

#endif