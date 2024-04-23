#include <iostream>



char getUserOperator() {
	char userOperator;
	do
	{
		std::cout << "Enter operator(+,-,* or /): ";
		std::cin >> userOperator;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');
		}
		

	} while (userOperator != '+' && userOperator != '-'&& userOperator != '*'&& userOperator != '/');
	return userOperator;
}

int getUserNum() {
	int userNum;
	do
	{
		std::cout << "Enter number: ";
		std::cin >> userNum;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return userNum;
		}

	} while (true);
	
}

int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}
int divide(int a, int b) {
	return a / b;
}

typedef int (*arithmeticFcn)(int, int);

struct arithmeticStruct
{
	char op;
	arithmeticFcn fcn;
};

static arithmeticStruct arithmeticArray[]{
	{ '+', add },
	{ '-', subtract },
	{ '*', multiply },
	{ '/', divide }
};

arithmeticFcn getArithmeticFcn(char op) {
	for (auto& arith : arithmeticArray)
	{
		if (arith.op == op)
			return arith.fcn;
	}
	return add;
}

int main()
{
	int a = getUserNum();
	char op = getUserOperator();
	int b = getUserNum();
	arithmeticFcn fcn = getArithmeticFcn(op);
	std::cout << a << ' ' << op << ' ' << b << " = " << fcn(a, b) << '\n';

	
}
