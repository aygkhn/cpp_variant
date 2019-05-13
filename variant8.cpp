#include <variant>
#include <string>
#include <iostream>

int main()
{
	auto f = [](const auto& val) {
		std::cout << "deger: " << val << '\n';
	};

	std::variant<bool, std::string> var;
	var = "necati";

	// bool ogeye atama yapildi
	std::cout << "index: " << var.index() << '\n';
	
	std::visit(f, var);

	var.emplace<1>("ekrem");
	std::visit(f, var);

	var.emplace<std::string>("elif"); 
	std::visit(f, var);

	using namespace std::literals;
	var = "sinan";
	std::visit(f, var);

}
