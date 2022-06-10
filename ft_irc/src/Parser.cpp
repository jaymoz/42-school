#include "../include/Server.hpp"

std::vector<std::string>    str_split(std::string str, std::string delimiters)
{
	std::vector<std::string> parts;
	size_t pos_start = 0;
	size_t pos_end;

	while ((pos_end = str.find(delimiters, pos_start)) != std::string::npos)
	{
		std::string local = str.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delimiters.length();
		parts.push_back(local);
	}

	parts.push_back(str.substr(pos_start));
	return parts;
}

std::vector<std::string>    str_parse(std::string str)
{
	std::vector<std::string> parts;
	size_t i = 0;
	size_t j;

	while (i < str.length() && !(str[i] == ':' && i != 0))
	{
		if (std::isspace(str[i])) i++;
		else
		{
			j = i;
			while (j < str.length() && !std::isspace(str[j]))
				j++;
			parts.push_back(str.substr(i, j - i));
			i = j + 1;
		}
	}
	if (str[i] == ':')
		parts.push_back(str.substr(i + 1, str.length() - 1));
	return parts;
}

std::string     str_ltrim(std::string str, const char* charset)
{
	str.erase(0, str.find_first_not_of(charset));
	return str;
}

std::string     str_rtrim(std::string str, const char* charset)
{
	str.erase(str.find_last_not_of(charset) + 1);
	return str;
}

std::string     str_trim(std::string str, const char* charset)
{
	return str_ltrim(str_rtrim(str, charset), charset);
}

std::string     str_toupper(std::string str)
{
	std::stringstream ss;
	for (size_t i = 0; i < str.size(); i++)
		ss << (char) std::toupper(str[i]);
	return ss.str();
}

std::string     str_tolower(std::string str)
{
	std::stringstream ss;
	for (size_t i = 0; i < str.size(); i++)
		ss << (char) std::tolower(str[i]);
	return ss.str();
}

void	ft_replace(std::string& str, const std::string& from, const std::string& to)
{
    size_t start_pos = str.find(from);
	if(start_pos == std::string::npos)
		return;
	str.replace(start_pos, from.length(), to);
}
