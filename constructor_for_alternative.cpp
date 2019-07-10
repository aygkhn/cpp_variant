#include <iostream>

class A {
	int mx = 0;
public:
	A()
	{
		std::cout << "A()\n";
	}

	A(int val) : mx{ val }
	{
		std::cout << "A(int)\n";
	}

	~A()
	{
		std::cout << "~A()\n";
	}

	friend std::ostream &operator<<(std::ostream &os, const A &a)
	{
		return os << "(" << a.mx << ")";
	}
};

//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
class B {
	int mx = 0;
public:
	B()
	{
		std::cout << "B()\n";
	}

	B(int val) : mx{ val }
	{
		std::cout << "B(int)\n";
	}

	~B()
	{
		std::cout << "~B()\n";
	}

	friend std::ostream &operator<<(std::ostream &os, const B &b)
	{
		return os << "(" << b.mx << ")";
	}
};
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
#include <variant>

int main()
{
	std::cout.setf(std::ios::boolalpha);
	std::variant<A, B> var_ab(A{});

	std::cout << std::get<0>(var_ab) << "\n";
	std::cout << "A turunden nesne tutuyor: " << std::holds_alternative<A>(var_ab) << "\n";
	std::cout << "B turunden nesne tutuyor: " << std::holds_alternative<B>(var_ab) << "\n";

	std::cout << "index degeri : " << var_ab.index() << "\n";
	var_ab = B{ 12 };

	std::cout << "A turunden nesne tutuyor: " << std::holds_alternative<A>(var_ab) << "\n";
	std::cout << "B turunden nesne tutuyor: " << std::holds_alternative<B>(var_ab) << "\n";

	std::cout << "index degeri : " << var_ab.index() << "\n";
}
