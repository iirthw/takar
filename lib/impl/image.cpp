#include "image.h"

#include "stb_image.h"

namespace tkr
{
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

} // namespace tkr