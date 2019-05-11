#include <variant>
#include <string>
#include <iostream>

using namespace std::literals;

int main()
{
	std::variant<int, std::string, double> var;
	std::cout << "index = " << var.index() << "\n";
	var = "neco"s;
	std::cout << "index = " << var.index() << "\n";
	var = 2.3;
	std::cout << "index = " << var.index() << "\n";
}
