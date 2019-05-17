#include <string>
#include <variant>
#include <iostream>

int main()
{
	try
	{
		using age_t	= int;
		using gender_t	= char;
		using name_t	= std::string;

		enum : size_t { idx_age, idx_gender, idx_name };

		std::variant<age_t, gender_t, name_t> person;

		person = 'F';

		if (auto pAge = std::get_if<age_t>(&person))
		{
			std::cout << "Age is " << *pAge << std::endl;
		}
		else if (auto pGender = std::get_if<gender_t>(&person))
		{
			std::cout << "Gender is " << *pGender << std::endl;
		}
		else if (auto pName = std::get_if<name_t>(&person))
		{
			std::cout << "Name is " << *pName << std::endl;
		}

		std::cout << std::endl;

		person = "Kelami Yilmaz";

		if (auto pAge = std::get_if<idx_age>(&person))
		{
			std::cout << "My age is " << *pAge << std::endl;
		}
		else if (auto pGender = std::get_if<idx_gender>(&person))
		{
			std::cout << "My gender is " << *pGender << std::endl;
		}
		else if (auto pName = std::get_if<idx_name>(&person))
		{
			std::cout << "Benim adim " << *pName << std::endl;
		}
	}
	catch (std::bad_variant_access& e)
	{
		std::cout << e.what() << std::endl;
	}
}
