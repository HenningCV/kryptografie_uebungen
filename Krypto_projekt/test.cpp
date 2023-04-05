#include<iostream>
#include <tuple> 
#include <string>

#include "assert.h"
#include "test.h"
#include "gcd.h"
#include "historic.h"
#include "random.h"
#include "des.h"
#include "squareAndMultiply.h"
#include "rsa.h"
#include "hash.h"
#include "ellipticCurve.h"
#include "rabin.h"
#include "millerRabin.h"
#include "faktorisierung.h"




void runTests(int test) {
	switch (test) {
	case SERIE_1_AUFGABE_1:
		testGcd();
		break;
	case SERIE_1_AUFGABE_2:
		testExtendedEuclid();
		break;
	case SERIE_1:
		testGcd();
		testExtendedEuclid();
		break;
	case SERIE_2_AUFGABE_1:
		testVigenere();
		break;
	case SERIE_2_AUFGABE_2:
		testCoincidenceIndex();
		break;
	case SERIE_2:
		testVigenere();
		testCoincidenceIndex();
		break;
	case SERIE_3:
		testBBS();
		break;
	case SERIE_4_AUFGABE_1:
		testDESPermutation();
		break;
	case SERIE_4_AUFGABE_2:
		testDESSBoxSubstitution();
		break;
	case SERIE_4_AUFGABE_3:
		testDESGetKey();
		break;
	case SERIE_4_AUFGABE_4:
		testDESdesFunction();
		break;
	case SERIE_4:
		testDESdes();
		break;
	case SERIE_5_AUFGABE_1:
		testSquareAndMultiply();
		break;
	case SERIE_5:
		testRSA();
		break;
	case SERIE_6:
		testHash();
		break;
	case SERIE_7:
		testEllipticCurve();
		break;
	case SERIE_8:
		testRabin();
		break;
	case SERIE_9:
		testMillerRabin();
		break;
	case SERIE_10_AUFGABE_1:
		testPollardRho();
		break;
	case SERIE_10_AUFGABE_2:
		testFermat();
		break;
	}
}

//Serie 1
void testGcd()
{
	int test1 = gcd(25, 30);
	assertEqual(5, test1, "gcd(25,30)");
	
	int test2 = gcd(30, 25);
	assertEqual(5, test2, "gcd(30,25)");

	int test3 = gcd(123456, 654321);
	assertEqual(3, test3, "gcd(123456, 654321)");

}

void testExtendedEuclid()
{
	std::tuple<int, int, int> current = extendedEuclid(93, 42);
	std::tuple<int, int, int> expected(3, 5, -11);
	assertEqual(expected, current, "extendedEuclid(93,42)");


	current = extendedEuclid(30, 131);
	expected = std::tuple<int, int, int>(1, 11, -48);
	assertEqual(expected, current, "extendedEuclid(30, 131)");


	assertEqual("Test", "Test", "TestFunktion");

	assertEqual("Test1", "Test", "TestFunktion");

	outputTestResult();
}

//Serie 2
void testVigenere()
{
	std::string current = vigenere("ANGEWANDTEINFORMATIK", "KEY");
	assertEqual("KREOAYXHROMLPSPWERSO", current, "vigenere(ANGEWANDTEINFORMATIK, KEY)");

	current = vigenere("ICHHABEMIRIMMERGEWUENSCHTDASSMEINCOMPUTERSOLEICHTZUBEDIENENISTWIEMEINTELEFONMEINWUNSCHGINGINERFUELLUNGMEINTELEFONKANNICHJETZTAUCHNICHTMEHRBEDIENEN", "KEY");
	assertEqual("SGFREZOQGBMKWIPQIUEILCGFDHYCWKOMLMSKZYROVQYPCSGFDDSLIBSILORGCXUSIKOMLDIJOJMXQCSRUERQMLESRESRCBJSOPJEREWIGXXCVIDYRIKRLSGFTIRJXYEGFXMARXKOLPLIBSILOR", current, "vigenere(ICHHABEMIRIMMERGEWUENSCHTDASSMEINCOMPUTERSOLEICHTZUBEDIENENISTWIEMEINTELEFONMEINWUNSCHGINGINERFUELLUNGMEINTELEFONKANNICHJETZTAUCHNICHTMEHRBEDIENEN, KEY)");

}

void testCoincidenceIndex()
{
	double current = coincidenceIndex("KREOAYXHROMLPSPWERSO"); //ANGEWANDTEINFORMATIK - KEY
	assertEqual(0.047368f, current, "frequencyAnalysis(KREOAYXHROMLPSPWERSO)");

	current = coincidenceIndex("QVFTBAMVHJQQOWAZMDJETQBIOGOXQS");	//KRYPTOGRAFIEISTVERDAMMTWICHTIG - GEHEIM
	assertEqual(0.043678f, current, "frequencyAnalysis(QVFTBAMVHJQQOWAZMDJETQBIOGOXQS)");
}

//Serie 3
void testBBS()
{
	std::string current = bbs(30, 7, 19, 2);
	assertEqual("010110010110010110010110010110", current, "bbs(30, 7, 19, 2)");

	current = bbs(30, 47, 67, 6);
	assertEqual("011010010001100011000100010000", current, "bbs(30, 47, 67, 6)");
}

//Serie 4
void testDESPermutation()
{
	std::string current = permutation(initialPermutationMatrix, sizeof(initialPermutationMatrix), "0000000100100011010001010110011110001001101010111100110111101111");
	assertEqual("1100110000000000110011001111111111110000101010101111000010101010", current, "permutation(initialPermutationMatrix, sizeof(initialPermutationMatrix), 0000000100100011010001010110011110001001101010111100110111101111");

	current = permutation(initialPermutationMatrix, sizeof(initialPermutationMatrix), "1010101010101010101010101010101010101010101010101010101010101010");
	assertEqual("0000000000000000000000000000000011111111111111111111111111111111", current, "permutation(initialPermutationMatrix, sizeof(initialPermutationMatrix), 1010101010101010101010101010101010101010101010101010101010101010");
}

void testDESSBoxSubstitution()
{
	std::string current = sBoxSubstitution("011000010001011110111010100001100110010100100111");
	assertEqual("01011100100000101011010110010111", current, "sBoxSubstitution(011000010001011110111010100001100110010100100111)");

	current = sBoxSubstitution("010101010101010101010101010101010101010101010101");
	assertEqual("11000001010100101111110101010110", current, "sBoxSubstitution(010101010101010101010101010101010101010101010101)");
}

void testDESGetKey()
{
	std::string current = "";
	for (int i = 1; i <= 16; i++)
	{
		std::cout << "round " << i << ": " << std::endl;
		current = getKey("01010101010101010101010101011111000011110000111100001111", i);
		if (i == 1 || i == 2 || i == 9 || i == 16)
		{
			assertEqual("10101010101010101010101010101110000111100001111000011111", current, "getKey(01010101010101010101010101011111000011110000111100001111)");
		}
		else
		{
			assertEqual("01010101010101010101010101011100001111000011110000111111", current, "getKey(01010101010101010101010101011111000011110000111100001111)");
		}
		
	}
}

void testDESdesFunction()
{
	std::string current = desFunction("11111111111111111111111111111111", "101010101010101010101010101010101010101010101010");
	assertEqual("00110111110101111110000010101000", current, "desFunction(11111111111111111111111111111111, 101010101010101010101010101010101010101010101010)");

	current = desFunction("11110000111100001111000011110000", "101011001110001111000011111000001111110000001010");
	assertEqual("01101001011100100011011010000111", current, "desFunction(11110000111100001111000011110000, 101011001110001111000011111000001111110000001010)");
}

void testDESdes()
{
	std::string current = des("0000000100100011010001010110011110001001101010111100110111101111", "0001001100110100010101110111100110011011101111001101111111110001");
	assertEqual("1000010111101000000100110101010000001111000010101011010000000101", current, "des(0000000100100011010001010110011110001001101010111100110111101111, 0001001100110100010101110111100110011011101111001101111111110001)");
}

//Serie 5
void testSquareAndMultiply()
{
	int current = squareAndMultiply(8, 27, 55);
	assertEqual(2, current, "squareAndMultiply(8, 27, 55)");
	
	current = squareAndMultiply(7, 23, 123);
	assertEqual(67, current, "squareAndMultiply(7, 23, 123)");
}

void testRSA()
{
	int current = rsa(11,13,15);
	assertEqual(115, current, "rsa(11, 13, 15)");

	current = rsa(23, 67, 15);
	assertEqual(1203, current, "rsa(23, 67, 15)");
}

//Serie 6
void testHash()
{
	int current = hashCHP(5692, 144);
	assertEqual(10967, current, "hashCHP(5692, 144)");

	current = hashCHP(212, 4214);
	assertEqual(10967, current, "hashCHP(212, 4214)");

	current = hashCHP(1220, 54);
	assertEqual(5739, current, "hashCHP(1220, 54)");
}

//Serie 7
void testEllipticCurve()
{
	POINT currentPoint = ellipticCurve(2, 2, 17, 5, 1, 2);
	POINT expectedPoint;
	expectedPoint.x = 6;
	expectedPoint.y = 3;
	assertEqual(expectedPoint, currentPoint, "ellipticCurve(2, 2, 17, 5, 1, 2)");

	currentPoint = ellipticCurve(2, 2, 17, 5, 1, 10);
	expectedPoint.x = 7;
	expectedPoint.y = 11;
	assertEqual(expectedPoint, currentPoint, "ellipticCurve(2, 2, 17, 5, 1, 10)");

	currentPoint = ellipticCurve(1, 0, 23, 16, 8, 10);
	expectedPoint.x = 9;
	expectedPoint.y = 18;
	assertEqual(expectedPoint, currentPoint, "ellipticCurve(1, 0, 23, 16, 8, 10)");
}

//Serie 8
void testRabin()
{
	int current = rabin(7, 11, 40);
	assertEqual(40, current, "rabin(7, 11, 40)");
}

//Serie 9
void testMillerRabin()
{
	bool current = millerRabin(5, 43);
	assertEqual(true, current, "millerRabin(5, 43)");

	current = millerRabin(5, 45);
	assertEqual(false, current, "millerRabin(5, 45)");

	current = millerRabin(5, 561);
	assertEqual(false, current, "millerRabin(5, 561)");

	current = millerRabin(5, 563);
	assertEqual(true, current, "millerRabin(5, 563)");
}

//Serie 10
void testPollardRho()
{
	int current = pollardRho(481);
	std::tuple <int, int> expected(13, 37);
	assertEqual(expected, current, "pollardRho(481)");

	current = pollardRho(2231);
	expected = std::tuple<int, int>(23, 97);
	assertEqual(expected, current, "pollardRho(2231)");
}

void testFermat()
{
	int current = fermat(481);
	std::tuple <int, int> expected(13,37);
	assertEqual(expected, current, "pollardRho(481)");

	current = fermat(2231);
	expected = std::tuple<int, int>(23, 97);
	assertEqual(expected, current, "pollardRho(2231)");
}