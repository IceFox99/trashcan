#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

#include "token.hpp"

class SandException : public std::exception {
public:
    SandException(const std::string& msg);
    SandException(const std::string& msg, TokenPtr t);
    const char* what() const noexcept override;
//#ifdef __linux__
//    const char* what() const noexcept override;
//#elifdef __APPLE__
//    const char* what() const throw() override;
//#else
//    const char* what() const noexcept override;
//#endif
private:
    std::string errorMsg;
    TokenPtr token;
};

#endif
