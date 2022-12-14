#include "exception.hpp"

SandException::SandException(const std::string& msg) :
    std::exception()
{
    errorMsg = msg;
}

SandException::SandException(const std::string& msg, TokenPtr t) : 
    std::exception()
{
    token = t;
    errorMsg = "Error around token \"" + t->getText() + "\" at line "  
        + std::to_string(t->getLineNumber()) 
        + ": " + msg;
}

const char* SandException::what() const noexcept
{
    return errorMsg.c_str();
}
