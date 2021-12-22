#include "image.h"

#include <cassert>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace tkr
{
    void Image::imageDeleter(void* ptr)
    {
        assert(ptr);
        if (ptr)
            stbi_image_free(ptr);
    }

    Image::Image(int width, int height, int numChannels)
    : mWidth(width)
    , mHeight(height)
    , mNumChannels(numChannels)
    , mFilename("")
    , mData(new unsigned char[sizeof(unsigned char) * mWidth * mHeight * numChannels](), // value initialize to 0
        reinterpret_cast<void(*)(unsigned char*)>(&Image::imageDeleter)
    )
    {}

    Image::Image(int width, int height, int numChannels, const std::string& filename)
    : mWidth(width)
    , mHeight(height)
    , mNumChannels(numChannels)
    , mFilename(filename)
    , mData(
        static_cast<unsigned char*>(stbi_load(mFilename.c_str(), &mWidth, &mHeight, 
            &mNumChannels,
            mNumChannels)) // Desired num of channels.
        ,
        // Custom deleter
        [](unsigned char* p) {
            if (p)
                stbi_image_free(p);
        })
    {}

    unsigned char Image::getPixel(int i, int j, int channel) const
    {
        assert(mData);
        assert(mNumChannels > channel);

        if (mNumChannels == 1) {
            return mData.get()[i * mWidth + j];
        }
        else {
            return mData.get()[(i * mWidth + j) * mNumChannels + channel];
        }
    }

    void Image::setPixel(int i, int j, unsigned char value, int channel)
    {
        assert(mData);
        assert(mNumChannels > channel);

        if (mNumChannels == 1) {
            mData.get()[i * mWidth + j] = value;
        }
        else {
            mData.get()[(i * mWidth + j) * mNumChannels + channel] = value;
        }
    }

#ifndef NDEBUG
        void Image::print() const
        {
            for (int i = 0; i < mWidth; ++i) {
                for (int j = 0; j < mHeight; ++j) {
                    for (int c = 0; c < mNumChannels; ++c) {
                        std::cout << getPixel(i, j, c) << ", ";
                    }                    
                }
                std::cout << std::endl;
            }
        }
#endif // !NDEBUG

} // namespace tkr