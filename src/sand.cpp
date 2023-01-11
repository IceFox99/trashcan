#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "sand.hpp"

#define VERSION "1.0.1"

int main(int argc, char* argv[]) 
{
    Parser p; Interpreter it;
    if (argc == 1) {
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string timeStr = std::ctime(&t);
        timeStr.pop_back();
        std::cout << "Sand " << VERSION << " (" << timeStr << ")" << std::endl;
        std::cout << "By IceFox99 (=^_^=), source code in https://github.com/IceFox99/Trashcan/tree/Sand" << std::endl;
        std::cout << "Type \"q\" or Ctrl-D (i.e. EOF) to quit this program." << std::endl;
        std::cout << "<<< ";
        
        // Sand starts
        std::string stmnt, temp;
        std::stringstream ss;
        while (std::getline(std::cin, temp)) {
            if (temp == "q")
                return 0;

            if (temp.empty()) {
                std::cout << "<<< ";
                continue;
            }

            if (temp.back() == '\\') {
                temp.pop_back();
                stmnt += temp;
                std::cout << "... ";
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
            std::cout << "<<< ";
        }
        std::cout << std::endl;
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
