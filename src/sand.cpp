#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "sand.hpp"

#define PREFIX std::cout << "<<< ";

int main(int argc, char* argv[]) 
{
    Parser p; Interpreter it;
    if (argc == 1) {
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string timeStr = std::ctime(&t);
        timeStr.pop_back();
        std::cout << "Sand 1.0.0 (" << timeStr << ")" << std::endl;
        std::cout << "By IceFox99 (=^_^=), source code in https://github.com/IceFox99/Trashcan/tree/Sand" << std::endl;
        std::cout << "Type \"q\" to quit this program." << std::endl;
        std::cout << "<<< ";
        
        // Sand starts
        std::string stmnt, temp;
        std::stringstream ss;
        while (std::getline(std::cin, temp)) {
            if (temp == "q")
                return 0;

            if (temp.empty()) {
                PREFIX;
                continue;
            }

            if (temp.back() == '\\') {
                temp.pop_back();
                stmnt += temp;
                PREFIX;
                continue;
            }

            stmnt += temp;
            ss << stmnt;
            //std::cout << stmnt << std::endl;
            //std::cout << ss.str() << std::endl;
            try {
                Lexer l(ss);
                while (!l.peek(0)->isEOF())
                    it.inter(p.parse(l));
            }
            catch (const SandException& se) {
                std::cout << se.what() << std::endl;
            }

            // Clean the stringstream and statement
            ss.str(std::string()); ss.clear();
            stmnt.clear();
            PREFIX;
        }
    }
    else {
        std::string fileName = argv[1];
        std::ifstream input(fileName);
        Lexer lFile(input);
        while (!lFile.peek(0)->isEOF())
            it.inter(p.parse(lFile));
    }

    return 0;
}
