#ifndef IMAGE_EXTRACTOR
#define IMAGE_EXTRACTOR

#include <qpdf/QPDFObjectHandle.hh>

namespace libpdftowebp
{
    class ImageExtractor : public QPDFObjectHandle::StreamDataProvider
    {
    public:
        ~ImageExtractor() override = default;
        // void provideStreamData(QPDFObjGen const& og, Pipeline* pipeline) override;

        void extractImages(char * arg, char const *infile);

    private:
        std::map<QPDFObjGen, QPDFObjectHandle> copied_images;
    };
}
#endif