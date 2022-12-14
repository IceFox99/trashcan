#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Gojuon.h"
#include "Test.h"

#ifdef _WIN32
#define CLEAR() std::system("cls");
#else 
#define CLEAR() std::system("clear");
#endif

static void PrintTestInfo(std::string testName) {
	std::cout << "********** " << testName << " **********" << std::endl << std::endl;
	std::cout << "Press Enter to next question, input q to quit this test." << std::endl << std::endl;
}

void WriteTest() {
	CLEAR();
	srand((unsigned)time(0));

	std::string testName = "Writing Test";
	PrintTestInfo(testName);

	Gojuon temp_syllable = getRandomGojuon();
	std::cout << "Please write \"" << temp_syllable.getRomaji() << "\":";

	std::string temp;
	while (std::getline(std::cin, temp, '\n')) {
		CLEAR();
		PrintTestInfo(testName);
		std::cout << "Please write \"" << temp_syllable.getRomaji() << "\":" << std::endl;
		std::cout << "The hiragana is \"" << temp_syllable.getHiragana()
			<< "\", the katakana is \"" << temp_syllable.getKatakana()
			<< "\"." << std::endl << std::endl;

		if (temp != "q") {
			temp_syllable = getRandomGojuon();
			std::cout << "Please write \"" << temp_syllable.getRomaji() << "\":";
		}
		else
			break;
	}
	std::cin.clear();
	CLEAR();
}

void ReadTest() {
	CLEAR();
	srand((unsigned)time(0));

	std::string testName = "Reading Test";
	PrintTestInfo(testName);

	bool isHiragana = rand() % 2;
	Gojuon temp_Gojuon = getRandomGojuon();
	std::cout << "Please read \"" << getRandomKana(temp_Gojuon, isHiragana) << "\":";

	std::string temp;
	while (std::getline(std::cin, temp, '\n')) {
		CLEAR();
		PrintTestInfo(testName);
		std::cout << "Please read \"" << getRandomKana(temp_Gojuon, isHiragana) << "\":" << std::endl;
		std::cout << "The romaji is \"" << temp_Gojuon.getRomaji()
			<< "\", the hiragana is \"" << temp_Gojuon.getHiragana()
			<< "\", the katakana is \"" << temp_Gojuon.getKatakana()
			<< "\"." << std::endl << std::endl;

		if (temp != "q") {
			isHiragana = rand() % 2;
			temp_Gojuon = getRandomGojuon();
			std::cout << "Please read \"" << getRandomKana(temp_Gojuon, isHiragana) << "\":";
		}
		else
			break;
	}
	std::cin.clear();
	CLEAR();
}

void HiraganaReadTest() {
	CLEAR();
	srand((unsigned)time(0));

	std::string testName = "Hiragana Reading Test";
	PrintTestInfo(testName);

	auto size = gojuon.size();
	GojuonIndex index = rand() % size;
	std::cout << "Please read \"" << gojuon[index].getHiragana() << "\":";

	std::string temp;
	while (std::getline(std::cin, temp, '\n')) {
		CLEAR();
		PrintTestInfo(testName);
		std::cout << "Please read \"" << gojuon[index].getHiragana() << "\":" << std::endl;
		std::cout << "The romaji is \"" << gojuon[index].getRomaji()
			<< "\", the hiragana is \"" << gojuon[index].getHiragana()
			<< "\", the katakana is \"" << gojuon[index].getKatakana()
			<< "\"." << std::endl << std::endl;

		if (temp != "q") {
			index = rand() % size;
			std::cout << "Please read \"" << gojuon[index].getHiragana() << "\":";
		}
		else
			break;
	}
	std::cin.clear();
	CLEAR();
}

void KatakanaReadTest() {
	CLEAR();
	srand((unsigned)time(0));

	std::string testName = "Katakana Reading Test";
	PrintTestInfo(testName);

	auto size = gojuon.size();
	GojuonIndex index = rand() % size;
	std::cout << "Please read \"" << gojuon[index].getKatakana() << "\":";

	std::string temp;
	while (std::getline(std::cin, temp, '\n')) {
		CLEAR();
		PrintTestInfo(testName);
		std::cout << "Please read \"" << gojuon[index].getKatakana() << "\":" << std::endl;
		std::cout << "The romaji is \"" << gojuon[index].getRomaji()
			<< "\", the hiragana is \"" << gojuon[index].getHiragana()
			<< "\", the katakana is \"" << gojuon[index].getKatakana()
			<< "\"." << std::endl << std::endl;

		if (temp != "q") {
			index = rand() % size;
			std::cout << "Please read \"" << gojuon[index].getKatakana() << "\":";
		}
		else
			break;
	}
	std::cin.clear();
	CLEAR();
}

void DakuonReadTest() {
	CLEAR();
	srand((unsigned)time(0));

	std::string testName = "Dakuon Reading Test";
	PrintTestInfo(testName);

	auto dakuon_size = dakuon.size();
	bool isHiragana = rand() % 2;
	GojuonIndex index = rand() % dakuon_size;
	Gojuon temp_syllable = dakuon[index];
	std::cout << "Please read \"" << getRandomKana(temp_syllable, isHiragana) << "\":";

	std::string temp;
	while (std::getline(std::cin, temp, '\n')) {
		CLEAR();
		PrintTestInfo(testName);
		std::cout << "Please read \"" << getRandomKana(temp_syllable, isHiragana) << "\":" << std::endl;
		std::cout << "The romaji is \"" << dakuon[index].getRomaji()
			<< "\", the hiragana is \"" << dakuon[index].getHiragana()
			<< "\", the katakana is \"" << dakuon[index].getKatakana()
			<< "\"." << std::endl << std::endl;

		if (temp != "q") {
			isHiragana = rand() % 2;
			index = rand() % dakuon_size;
			temp_syllable = dakuon[index];
			std::cout << "Please read \"" << getRandomKana(temp_syllable, isHiragana) << "\":";
		}
		else
			break;
	}
	std::cin.clear();
	CLEAR();
}

void YoonReadTest() {
	CLEAR();
	srand((unsigned)time(0));

	std::string testName = "Yoon Reading Test";
	PrintTestInfo(testName);

	auto yoon_size = yoon.size();
	bool isHiragana = rand() % 2;
	GojuonIndex index = rand() % yoon_size;
	Gojuon temp_Gojuon = yoon[index];
	std::cout << "Please read \"" << getRandomKana(temp_Gojuon, isHiragana) << "\":";

	std::string temp;
	while (std::getline(std::cin, temp, '\n')) {
		CLEAR();
		PrintTestInfo(testName);
		std::cout << "Please read \"" << getRandomKana(temp_Gojuon, isHiragana) << "\":" << std::endl;
		std::cout << "The romaji is \"" << yoon[index].getRomaji()
			<< "\", the hiragana is \"" << yoon[index].getHiragana()
			<< "\", the katakana is \"" << yoon[index].getKatakana()
			<< "\"." << std::endl << std::endl;

		if (temp != "q") {
			isHiragana = rand() % 2;
			index = rand() % yoon_size;
			temp_Gojuon = yoon[index];
			std::cout << "Please read \"" << getRandomKana(temp_Gojuon, isHiragana) << "\":";
		}
		else
			break;

	}
	std::cin.clear();
	CLEAR();
}

void ShowGojuon()
{
	CLEAR();

	printGojuon();
	printDakuon();
	printYoon();

	std::string temp;
	std::cout << "Input q to quit this chart:";
	while (std::getline(std::cin, temp, '\n')) {
		if (temp == "q")
			break;
		std::cout << "Input q to quit this chart:";
	}
	std::cin.clear();
	CLEAR();
}

void Test() {
	CLEAR();
	std::cout << "Press 1 to enter writing test.\n"
		<< "Press 2 to enter reading test.\n"
		<< "Press 3 to enter hiragana reading test.\n"
		<< "Press 4 to enter katakana reading test.\n"
		<< "Press 5 to enter dakuon reading test.\n"
		<< "Press 6 to enter yoon reading test.\n"
		<< "Press 7 to check all gojuon.\n"
		<< "Press q to quit.\n" << std::endl << "Please enter the code:";
	std::string code;
	while (std::getline(std::cin, code, '\n')) {
		if (code == "q") {
			CLEAR();
			break;
		}
		else if (code == "1")
			WriteTest();
		else if (code == "2")
			ReadTest();
		else if (code == "3")
			HiraganaReadTest();
		else if (code == "4")
			KatakanaReadTest();
		else if (code == "5")
			DakuonReadTest();
		else if (code == "6")
			YoonReadTest();
		else if (code == "7")
			ShowGojuon();
		else {
			std::cout << "Please enter the code:";
			continue;
		}

		std::cout << "Press 1 to enter writing test.\n"
			<< "Press 2 to enter reading test.\n"
			<< "Press 3 to enter hiragana reading test.\n"
			<< "Press 4 to enter katakana reading test.\n"
			<< "Press 5 to enter dakuon reading test.\n"
			<< "Press 6 to enter yoon reading test.\n"
			<< "Press 7 to check all gojuon.\n"
			<< "Press q to quit.\n" << std::endl << "Please enter the code:";
	}
}
