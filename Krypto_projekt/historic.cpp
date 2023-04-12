#include <iostream>
#include <string>

std::string vigenere(std::string word, std::string key)
{	
	std::string str = word;
	
	std::string keystr = "";

	int strCharNumber = 0;
	int keyCharNumber = 0;
	int newCharNumber = 0;

	while (keystr.length() < str.length())
	{
		keystr += key;
	}

	for (int i = 0; i < str.length(); i++)
	{
		strCharNumber = str[i] - 65;
		keyCharNumber = keystr[i] - 65;
		newCharNumber = strCharNumber + keyCharNumber + 65;
		if (newCharNumber > 90)
		{
			newCharNumber -= 26;
		}
		str[i] = newCharNumber;

	}

	

	return str;
}

double coincidenceIndex(std::string word)
{
	double indexOfCoincidence = 0;
	

	return indexOfCoincidence;
}