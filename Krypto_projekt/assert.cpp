#include "assert.h"
#include "ellipticCurve.h"


int SumTests = 0;

int FailedTests = 0;

void assertOutput(std::string expected, std::string current, std::string function, bool check)
{
	const std::string red("\033[0;31m");
	const std::string reset("\033[0m");

	const std::string green("\033[0;32m");
	const std::string resetGreen("\033[0m");
	SumTests++;
	if (check)
	{
		std::cout << green << function << " = " << current << reset << std::endl;
		std::cout << green << "Good Job!" << reset << std::endl;
	}
	else
	{
		FailedTests++;
		std::string expectedLabel("Expected Value: ");
		std::string currentLabel("Your value: ");
		std::cout << red << expectedLabel  << expected << reset << std::endl;
		std::cout << red << currentLabel << std::string(expectedLabel.length() - currentLabel.length(), ' ') << current << reset << std::endl;
		std::cout << red << "Please try again!" << reset << std::endl;
	}
	std::cout << "------------------------------------" << std::endl;
}

void outputTestResult()
{
	std::cout << std::endl << "------------------------------------" << std::endl;
	std::cout << std::endl << "Result: " << " Tests: " << SumTests << ", Failed: " << FailedTests << std::endl;
	std::cout << std::endl << "------------------------------------" << std::endl;
}

void assertEqual(int expected, int current, std::string function)
{
	bool check = expected == current;
	assertOutput(std::to_string(expected), std::to_string(current), function, check);
}

void assertEqual(double expected, double current, std::string function)
{
	bool check = (abs(expected - current) < 0.005);
	assertOutput(std::to_string(expected), std::to_string(current), function, check);
}

void assertEqual(std::string expected, std::string current, std::string function)
{
	bool check = expected == current;
	assertOutput(expected, current, function, check);
}

void assertEqual(bool expected,bool current, std::string function)
{
	bool check = expected == current;
	assertOutput(std::to_string(expected), std::to_string(current), function, check);
}

void assertEqual(POINT expected, POINT current, std::string function)
{
	bool check = (expected.x == current.x && expected.y == current.y);
	assertOutput("(" + std::to_string(expected.x) + ", " + std::to_string(expected.y) + ")", "(" + std::to_string(current.x) + ", " + std::to_string(current.y) + ")", function, check);
}

void assertEqual(std::tuple<int, int, int> expected, std::tuple<int, int, int> current, std::string function)
{

	std::string expectedString = "(" + std::to_string(std::get<0>(expected)) + ", " + std::to_string(std::get<1>(expected)) + ", " + std::to_string(std::get<2>(expected)) + ")" +
		" OR (" + std::to_string(std::get<0>(expected)) + ", " + std::to_string(std::get<2>(expected)) + ", " + std::to_string(std::get<1>(expected)) + ")";

	std::string currentString = "(" + std::to_string(std::get<0>(current)) + ", " + std::to_string(std::get<1>(current)) + ", " + std::to_string(std::get<2>(current)) + ")";

	bool check = std::get<0>(expected) == std::get<0>(current);

	if (check) {
		int xExpected = std::get<1>(expected);
		int yExpected = std::get<2>(expected);
		int xCurrent = std::get<1>(current);
		int yCurrent = std::get<2>(current);
		check = (xExpected == xCurrent && yExpected == yCurrent || xExpected == yCurrent && yExpected == xCurrent);
	}

	assertOutput(expectedString, currentString, function, check);
}

void assertEqual(std::tuple<int, int> expected, int current, std::string function)
{
		int xExpected = std::get<0>(expected);
		int yExpected = std::get<1>(expected);
		bool check = (xExpected == current || yExpected == current );

	assertOutput("("+ std::to_string(xExpected) + ", " + std::to_string(yExpected) + ")", std::to_string(current), function, check);
}
