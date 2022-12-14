#pragma once
#include <iostream>
#include <string>
#include <vector>

class Gojuon {
private:
	std::string romaji;
	std::string hiragana;
	std::string katakana;
public:
	Gojuon(const std::string& romaji, const std::string& hiragana, const std::string& katakana) :
		romaji(romaji), hiragana(hiragana), katakana(katakana) {}
	const std::string& getRomaji() const {
		return this->romaji;
	}
	const std::string& getHiragana() const {
		return this->hiragana;
	}
	const std::string& getKatakana() const {
		return this->katakana;
	}
};

extern std::vector<Gojuon> gojuon;
extern std::vector<Gojuon> dakuon;
extern std::vector<Gojuon> yoon;
typedef decltype(gojuon.size()) GojuonIndex;

const Gojuon& getGojuon(GojuonIndex index);
GojuonIndex getRandomIndex();
const Gojuon& getRandomGojuon();
inline const std::string& getRandomKana(const Gojuon& g, bool isHiragana) {
	return (isHiragana) ? g.getHiragana() : g.getKatakana();
}

void printGojuon();
void printDakuon();
void printYoon();