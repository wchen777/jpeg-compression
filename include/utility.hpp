/*
Contains various utility functions for characters and strings.
*/

#ifndef JPEG_COMPRESSION_UTILITY_HPP
#define JPEG_COMPRESSION_UTILITY_HPP

#include <string>
#include <cctype>


// output into a log file
extern std::ofstream logFile;

namespace jpeg_compression
{

    inline const bool isValidChar(const char ch)
    {
        return isprint(ch) || ch != '/' || ch != '\\'; // valid characters in filepaths
    }

    inline const bool isValidFilename(const std::string &filename)
    {
        for (auto&& c : filename)
            if (!isValidChar(c)) // check for valid characters in filepath
                return false;

        std::size_t extPos = filename.find(".jpg"); // look for jpg extension

        if (extPos == std::string::npos)
            extPos = filename.find(".jpeg"); // if not found, look for jpeg extension

        else if (extPos + 4 == filename.size())
            return true; // if either are found return true

        if (extPos == std::string::npos)
            return false; // otherwise the filepath is not valid

        return false;
    }

    // check if a character is any form of whitespace (used in below function)
    inline const bool isWhiteSpace(const char ch)
    {
        return iscntrl(ch) || isblank(ch) || isspace(ch);
    }

    // check if a given string is entirely whitespace
    inline const bool isStringWhiteSpace(const std::string &str)
    {
        for (auto&& c : str)
            if (!isWhiteSpace(c))
                return false;
        return true;
    }

}

#endif //JPEG_COMPRESSION_UTILITY_HPP
