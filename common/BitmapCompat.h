#ifndef COMMON_BITMAPCOMPAT_H
#ifndef _WIN32
#include <cstdint>

#define BI_RGB 0

#pragma pack(push, 1)
// Define the BITMAPFILEHEADER structure
struct BITMAPFILEHEADER {
    uint16_t bfType;        // Specifies the file type
    uint32_t bfSize;        // Specifies the size of the file
    uint16_t bfReserved1;   // Reserved; must be 0
    uint16_t bfReserved2;   // Reserved; must be 0
    uint32_t bfOffBits;     // Specifies the offset to the bitmap data
};

// Define the BITMAPINFOHEADER structure
struct BITMAPINFOHEADER {
    uint32_t biSize;          // Specifies the number of bytes required by the structure
    int32_t biWidth;          // Specifies the width of the image, in pixels
    int32_t biHeight;         // Specifies the height of the image, in pixels
    uint16_t biPlanes;        // Specifies the number of color planes, must be 1
    uint16_t biBitCount;      // Specifies the number of bits per pixel
    uint32_t biCompression;   // Specifies the type of compression
    uint32_t biSizeImage;     // Specifies the size of the image data, in bytes
    int32_t biXPelsPerMeter;  // Specifies the horizontal resolution, in pixels per meter
    int32_t biYPelsPerMeter;  // Specifies the vertical resolution, in pixels per meter
    uint32_t biClrUsed;       // Specifies the number of colors used by the bitmap
    uint32_t biClrImportant;  // Specifies the number of important colors
};
#pragma pack(pop)
#endif
#define COMMON_BITMAPCOMPAT_H
#endif
