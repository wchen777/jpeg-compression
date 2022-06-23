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
        return isprint(ch) || ch != '/' || ch != '\\';
    }

    inline const bool isValidFilename(const std::string& filename)
    {
        for (auto&& c : filename)
            if (!isValidChar(c))
                return false;

        std::size_t extPos = filename.find(".jpg");

        if (extPos == std::string::npos)
            extPos = filename.find(".jpeg");

        else if (extPos + 4 == filename.size())
            return true;

        if (extPos == std::string::npos)
            return false;

        return false;
    }

    inline const bool isWhiteSpace(const char ch)
    {
        return iscntrl(ch) || isblank(ch) || isspace(ch);
    }

    inline const bool isStringWhiteSpace(const std::string& str)
    {
        for (auto&& c : str)
            if (!isWhiteSpace(c))
                return false;
        return true;
    }

}

#endif //JPEG_COMPRESSION_UTILITY_HPP
