#include "serializer.hpp"

int main()
{
	Data *data = new Data;

	std::cout << "adresse data: " << data << std::endl;
	std::cout << "serialization : " << serialize(data) << std::endl;
	std::cout << "deserialization: " << deserialize(serialize(data)) << std::endl;


	delete data;

	return (0);
}
