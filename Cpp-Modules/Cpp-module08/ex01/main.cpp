#include "Span.hpp"
#include <iostream>

int	main() {

	Span sp = Span(10000);

	// try {

	// 	sp.addNumber(6);
	// 	sp.addNumber(3);
	// 	sp.addNumber(17);
	// 	sp.addNumber(9);
	// 	sp.addNumber(11);

	// 	std::cout << sp.shortestSpan() << std::endl;
	// 	std::cout << sp.longestSpan() << std::endl;
	// }
	// catch ( std::exception &e ) {
	// 	std::cout << e.what() << std::endl;
	// }

	std::vector<int> v;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
	}
	try {
		sp.addNumber(v.begin(), v.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
}