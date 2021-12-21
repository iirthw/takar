#pragma once

#include <cstdlib>
#include <memory>
#include <string>

namespace tkr
{
    /// RAII wrapper for a row-major image.
    class Image
    {        
    public:
        /// Construct in-memory image of given dimensions and number of channels.
        Image(int width, int height, int numChannels);
        // Construct image from the given file.
        Image(int width, int height, int numChannels, const std::string& filename);

        int width() const { return mWidth; }
        int height() const { return mHeight; }
        int numChannels() const { return mNumChannels; }    

    private:

        int mWidth;
        int mHeight;
        int mNumChannels;
        std::string mFilename;

        // Data with the custom deleter. 
        std::unique_ptr<unsigned char, void(*)(unsigned char*)> mData;
    }; // class TkrImage
} // namespace tkr