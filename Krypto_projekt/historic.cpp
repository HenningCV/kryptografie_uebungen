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
	const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int m_i[26];
	double summM_i = 0.0;
	int m = word.length();

	// Count number of characters
	for (int i = 0; i < alphabet.length(); i++)
	{
		int count = 0;
		for (int n = 0; n < word.length(); n++) {
			if (word[n] == alphabet[i]) 
			{
				count++;
			}
		}
		m_i[i] = count;
	}

	// Calculate summ m_i
	for (int i = 0; i < (sizeof(m_i)/sizeof(m_i[0])); i++)
	{
		summM_i += m_i[i] * (m_i[i] - 1);
	}
	
	// Calculate indexOfCoincidence

	indexOfCoincidence = summM_i / (m*(m - 1));

	return indexOfCoincidence;
}