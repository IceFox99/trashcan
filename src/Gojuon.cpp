#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Gojuon.h"

std::vector<Gojuon> gojuon = {
	Gojuon("a", "あ", "ア"), Gojuon("i", "い", "イ"), Gojuon("u", "う", "ウ"), Gojuon("e", "え", "エ"), Gojuon("o", "お", "オ"),
	Gojuon("ka", "か", "カ"), Gojuon("ki", "き", "キ"), Gojuon("ku", "く", "ク"), Gojuon("ke", "け", "ケ"), Gojuon("ko", "こ", "コ"),
	Gojuon("sa", "さ", "サ"), Gojuon("shi", "し", "シ"), Gojuon("su", "す", "ス"), Gojuon("se", "せ", "セ"), Gojuon("so", "そ", "ソ"),
	Gojuon("ta", "た", "タ"), Gojuon("chi", "ち", "チ"), Gojuon("tsu", "つ", "ツ"), Gojuon("te", "て", "テ"), Gojuon("to", "と", "ト"),
	Gojuon("na", "な", "ナ"), Gojuon("ni", "に", "ニ"), Gojuon("nu", "ぬ", "ヌ"), Gojuon("ne", "ね", "ネ"), Gojuon("no", "の", "ノ"),
	Gojuon("ha", "は", "ハ"), Gojuon("hi", "ひ", "ヒ"), Gojuon("fu", "ふ", "フ"), Gojuon("he", "へ", "ヘ"), Gojuon("ho", "ほ", "ホ"),
	Gojuon("ma", "ま", "マ"), Gojuon("mi", "み", "ミ"), Gojuon("mu", "む", "ム"), Gojuon("me", "め", "メ"), Gojuon("mo", "も", "モ"),
	Gojuon("ya", "や", "ヤ"), Gojuon("yu", "ゆ", "ユ"), Gojuon("yo", "よ", "ヨ"),
	Gojuon("ra", "ら", "ラ"), Gojuon("ri", "り", "リ"), Gojuon("ru", "る", "ル"), Gojuon("re", "れ", "レ"), Gojuon("ro", "ろ", "ロ"),
	Gojuon("wa", "わ", "ワ"), Gojuon("wo", "を", "ヲ"),
	Gojuon("n", "ん", "ン") };

std::vector<Gojuon> dakuon = {
	Gojuon("ga", "が", "ガ"), Gojuon("gi", "ぎ", "ギ"), Gojuon("gu", "ぐ", "グ"), Gojuon("ge", "げ", "ゲ"), Gojuon("go", "ご", "ゴ"),
	Gojuon("za", "ざ", "ザ"), Gojuon("ji", "じ", "ジ"), Gojuon("zu", "ず", "ズ"), Gojuon("ze", "ぜ", "ゼ"), Gojuon("zo", "ぞ", "ゾ"),
	Gojuon("da", "だ", "ダ"), Gojuon("ji", "ぢ", "ヂ"), Gojuon("zu", "づ", "ヅ"), Gojuon("de", "で", "デ"), Gojuon("do", "ど", "ド"),
	Gojuon("ba", "ば", "バ"), Gojuon("bi", "び", "ビ"), Gojuon("bu", "ぶ", "ブ"), Gojuon("be", "べ", "ベ"), Gojuon("bo", "ぼ", "ボ"),
	Gojuon("pa", "ぱ", "パ"), Gojuon("pi", "ぴ", "ピ"), Gojuon("pu", "ぷ", "プ"), Gojuon("pe", "ぺ", "ペ"), Gojuon("po", "ぽ", "ポ") };

std::vector<Gojuon> yoon = {
	Gojuon("kya", "きゃ", "キャ"), Gojuon("kyu", "きゅ", "キュ"), Gojuon("kyo", "きょ", "キョ"),
	Gojuon("gya", "ぎゃ", "ギャ"), Gojuon("gyu", "ぎゅ", "ギュ"), Gojuon("gyo", "ぎょ", "ギョ"),
	Gojuon("sha", "しゃ", "シャ"), Gojuon("shu", "しゅ", "シュ"), Gojuon("sho", "しょ", "ショ"),
	Gojuon("jya", "じゃ", "ジャ"), Gojuon("jyu", "じゅ", "ジュ"), Gojuon("jyo", "じょ", "ジョ"),
	Gojuon("cha", "ちゃ", "チャ"), Gojuon("chu", "ちゅ", "チュ"), Gojuon("cho", "ちょ", "チョ"),
	Gojuon("nya", "にゃ", "ニャ"), Gojuon("nyu", "にゅ", "ニュ"), Gojuon("nyo", "にょ", "ニョ"),
	Gojuon("hya", "ひゃ", "ヒャ"), Gojuon("hyu", "ひゅ", "ヒュ"), Gojuon("hyo", "ひょ", "ヒョ"),
	Gojuon("bya", "びゃ", "ビャ"), Gojuon("byu", "びゅ", "ビュ"), Gojuon("byo", "びょ", "ビョ"),
	Gojuon("pya", "ぴゃ", "ピャ"), Gojuon("pyu", "ぴゅ", "ピュ"), Gojuon("pyo", "ぴょ", "ピョ"),
	Gojuon("mya", "みゃ", "ミャ"), Gojuon("myu", "みゅ", "ミュ"), Gojuon("myo", "みょ", "ミョ"),
	Gojuon("rya", "りゃ", "リャ"), Gojuon("ryu", "りゅ", "リュ"), Gojuon("ryo", "りょ", "リョ") };

const auto gojuon_size = gojuon.size();
const auto dakuon_size = dakuon.size();
const auto yoon_size = yoon.size();

const Gojuon& getGojuon(GojuonIndex index) {
	if (index < gojuon_size)
		return gojuon[index];
	else if (index < gojuon_size + dakuon_size)
		return dakuon[index - gojuon_size];
	else
		return yoon[index - gojuon_size - dakuon_size];
}

GojuonIndex getRandomIndex() {
	GojuonIndex index = rand() % (gojuon_size + dakuon_size + yoon_size);
	return index;
}

const Gojuon& getRandomGojuon() {
	return getGojuon(getRandomIndex());
}

static std::string getGojuonCell(const Gojuon& g) {
	std::string romaji = g.getRomaji();
	return "| " + ((romaji.length() < 3) ? romaji.insert(0, 3 - romaji.length(), ' ') : romaji)
		+ " " + g.getHiragana() + " " + g.getKatakana() + " ";
}

void printGojuon()
{
	std::cout << "********** Gojuon **********" << std::endl;
	std::string chartLine(61, '-');
	std::string fillCell = '|' + std::string(11, ' ');
	auto iter = gojuon.cbegin();

	// First line (special)
	std::cout << chartLine << std::endl;
	for (int i = 0; i != 5; ++i) {
		std::cout << getGojuonCell(*iter++);
	}
	std::cout << "|" << std::endl;

	// Next six lines
	for (int i = 0; i != 6; ++i) {
		std::cout << chartLine << std::endl;
		for (int j = 0; j != 5; ++j) {
			std::cout << getGojuonCell(*iter++);
		}
		std::cout << "|" << std::endl;
	}

	// y line
	std::cout << chartLine << std::endl;
	std::cout << getGojuonCell(*iter++) << getGojuonCell(gojuon[1]);
	std::cout << getGojuonCell(*iter++) << getGojuonCell(gojuon[3]);
	std::cout << getGojuonCell(*iter++) << "|" << std::endl;

	// r line
	std::cout << chartLine << std::endl;
	for (int i = 0; i != 5; ++i)
		std::cout << getGojuonCell(*iter++);
	std::cout << "|" << std::endl;

	// w line
	std::cout << chartLine << std::endl;
	std::cout << getGojuonCell(*iter++) << getGojuonCell(gojuon[1]) << getGojuonCell(gojuon[2]) << getGojuonCell(gojuon[3]);
	std::cout << getGojuonCell(*iter++) << "|" << std::endl;

	// last line
	std::cout << chartLine << std::endl;
	std::cout << getGojuonCell(*iter++) << fillCell << fillCell << fillCell << fillCell << "|" << std::endl;

	std::cout << chartLine << std::endl << std::endl;
}

void printDakuon()
{
	std::cout << "********** Dakuon **********" << std::endl;
	std::string chartLine(61, '-');
	auto iter = dakuon.cbegin();
	for (int i = 0; i != 5; ++i) {
		std::cout << chartLine << std::endl;
		for (int j = 0; j != 5; ++j)
			std::cout << getGojuonCell(*iter++);
		std::cout << "|" << std::endl;
	}
	std::cout << chartLine << std::endl << std::endl;
}

void printYoon()
{
	std::cout << "********** Yoon **********" << std::endl;
	std::string chartLine(49, '-');
	auto iter = yoon.cbegin();
	for (int i = 0; i != 11; ++i) {
		std::cout << chartLine << std::endl;
		for (int j = 0; j != 3; ++j)
			std::cout << getGojuonCell(*iter++);
		std::cout << "|" << std::endl;
	}
	std::cout << chartLine << std::endl << std::endl;
}
