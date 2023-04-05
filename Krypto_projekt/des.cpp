#include <iostream>
#include <iomanip> 
#include "des.h"
#include <string>
#include <conio.h> 


void str_output(std::string input)
{
	int counter = 0;
	std::cout << input.length() << ": ";
	for (int i = 0; i < input.length(); i++)
	{
		if (counter < 7)
		{
			std::cout << input[i];
		}
		else
		{
			std::cout << input[i] << " ";
			counter = -1;
		}


		counter++;
	}
	std::cout << std::endl;
}

std::string shiftLeftOnce(std::string keyTmp)
{
	std::string shifted = "";
	
	return shifted;
}

std::string shiftLeftTwice(std::string keyTmp)
{
	std::string shifted = "";
	
	return shifted;
}

std::string getKey(std::string keyPerm56, int round)
{
	std::string keyCombined56 = "";

	return keyCombined56;
}

std::string Xor(std::string a, std::string b)
{
	std::string result;

	return result;
}

int binToDec(std::string num)
{
	int number = 0;
	int n = num.length();
	for (int i = n - 1; i >= 0; i--)
	{
		if (num[i] == '1')
		{
			number += pow(2, n - i - 1);
		}
	}

	return number;
}

std::string DecToBin(int number)
{
	std::string num = "0000";
	for (int i = 3; i >= 0; i--)
	{
		if (number % 2 == 1)
			num[i] = '1';
		number /= 2;
	}

	return num;
}

std::string sBoxSubstitution(std::string expXorKey48)
{

	std::string sBoxed32 = "";

	return sBoxed32;
}

std::string permutation(const int matrix[], size_t arrayLength, std::string input)
{
	std::string output = "";

	return output;
}

std::string desFunction(std::string right32, std::string key48)
{
	std::string expanded48 = "";
	std::string expXorKey48 = "";

	std::string sBoxed32 = "";
	std::string pPermuted32 = "";

	return pPermuted32;
}

std::string des(std::string input, std::string key)
{
	std::string input64 = input; //"0000000100100011010001010110011110001001101010111100110111101111";
	std::string key64 = key; //"0001001100110100010101110111100110011011101111001101111111110001";
	std::string keyPerm56 = "";
	std::string inputIp64 = "";
	std::string keyCompressed48 = "";
	std::string keyCombined56 = "";
	std::string pPermuted32 = "";
	std::string left32 = ""; //= inputIp64.substr(0, 32);
	std::string right32 = "";// = inputIp64.substr(32, 32);
	std::string leftTmp32 = ""; //= inputIp64.substr(0, 32);
	std::string finalRound64 = "";
	std::string output64 = "";

	std::cout << std::setiosflags(std::ios::left) << std::setfill(' ');

	std::cout << "initial input: "; str_output(input64);
	std::cout << "initial key:   "; str_output(key64);
	std::cout << "\n";

	// Initial Key Permutation
	keyPerm56 = permutation(keyPermutationMatrix, sizeof(keyPermutationMatrix), key64);

	// Initial Permutation
	inputIp64 = permutation(initialPermutationMatrix, sizeof(initialPermutationMatrix), input64);

	// Decomposition of permuted input vector  into L and R
	left32 = inputIp64.substr(0, 32);
	right32 = inputIp64.substr(32, 32);

	std::cout << "initial input permuted: "; str_output(inputIp64);
	std::cout << "initial key permuted:   "; str_output(keyPerm56);

	//16 Rounds
	for (int i = 0; i < 16; i++)
	{
		std::cout << std::endl << "Runde " << i + 1 << std::endl;

		//Create Round Key
		keyPerm56 = getKey(keyPerm56, i + 1);
		std::cout << std::setw(13) << "keyperm56:"; str_output(keyPerm56);

		keyCompressed48 = permutation(keyCompressionMatrix, sizeof(keyCompressionMatrix), keyPerm56);
		std::cout << std::setw(13) << "key:"; str_output(keyCompressed48);


		//Call f-Function
		pPermuted32 = desFunction(right32, keyCompressed48);

		leftTmp32 = left32;
		left32 = right32;
		right32 = Xor(pPermuted32, leftTmp32);
	}
	//Combine right32 and left32
	finalRound64 = finalRound64 + right32 + left32;

	
	//Final Permutation
	output64 = permutation(finalPermutationMatrix, sizeof(finalPermutationMatrix), finalRound64);
	std::cout << "------------------------------------" << std::endl;
	std::cout << std::setw(13) << "Ergebnis: "; str_output(output64);

	return output64;
}