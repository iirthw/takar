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
        Image(int width, int height, int numChannels = 1);
        // Construct image from the given file.
        Image(int width, int height, int numChannels, const std::string& filename);

        unsigned char getPixel(int i, int j, int channel = 0) const;
        void setPixel(int i, int j, unsigned char value, int channel = 0);

        int width() const { return mWidth; }
        int height() const { return mHeight; }
        int numChannels() const { return mNumChannels; } 

#ifndef NDEBUG
        void print() const;
#endif // !NDEBUG

    private:
        // Custom deleter.
        static void imageDeleter(void* ptr);

        int mWidth;
        int mHeight;
        int mNumChannels;
        std::string mFilename;

        // Data with the custom deleter. 
        std::unique_ptr<unsigned char, void(*)(unsigned char*)> mData;
    }; // class TkrImage
} // namespace tkr