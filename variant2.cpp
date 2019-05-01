#include <variant>
#include <string>
#include <iostream>

int main()
{
	std::cout.setf(std::ios::boolalpha);
	std::variant<int, std::string> v = "abc";
	std::cout << "variant int tutuyor   : " << std::holds_alternative<int>(v) << "\n";
	std::cout << "variant string tutuyor: " << std::holds_alternative<std::string>(v) << "\n";
	std::cout << "\n\n";

	v = 23;

	std::cout << "variant int tutuyor   : " << std::holds_alternative<int>(v) << "\n";
	std::cout << "variant string tutuyor: " << std::holds_alternative<std::string>(v) << "\n";
	std::cout << "\n\n";
}
