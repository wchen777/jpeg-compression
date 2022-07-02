/*
 * Contains custom type definitions
 */

#ifndef TYPES_HPP
#define TYPES_HPP

#include <vector>
#include <array>
#include <utility>
#include <memory>

namespace jpeg_compression {

    typedef unsigned char  uint8;
    typedef unsigned short uint16;

    typedef char  int8;
    typedef short int16;

    enum RGBComponents
    {
        RED,
        GREEN,
        BLUE
    };

    struct Pixel
    {
        Pixel()
        {
            comp[0] = comp[1] = comp[2]  = 0;
        }

        Pixel(const int16 comp1,
              const int16 comp2,
              const int16 comp3)
        {
            comp[0] = comp1;
            comp[1] = comp2;
            comp[2] = comp3;
        }

        // Store the intensity of the pixel
        int16 comp[3];
    };

    typedef std::shared_ptr<std::vector<std::vector<Pixel>>>  PixelPtr;
    typedef std::array<std::pair<int, std::vector<uint8>>, 16> HuffmanTable;

// Identifiers used to access a Huffman table based on
// the class and ID. E.g., To access the Huffman table
// for the DC coefficients of the CbCr component, we
// use `huff_table[HT_DC][HT_CbCr]`.
    const int HT_DC   = 0;
    const int HT_AC   = 1;
    const int HT_Y    = 0;
    const int HT_CbCr = 1;

}


#endif //TYPES_HPP
