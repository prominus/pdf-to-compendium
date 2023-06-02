// static library /user/lib/x86_64-linux-gnu/libqpdf.so
// dynamic library /user/include/qpdf/*
#include <qpdf/Buffer.hh>
#include <qpdf/QIntC.hh>
#include <qpdf/QPDF.hh>
#include <qpdf/QPDFPageDocumentHelper.hh>
#include <qpdf/QPDFPageObjectHelper.hh>
#include <qpdf/QPDFWriter.hh>
#include <qpdf/QUtil.hh>
#include <cstdlib>
#include <cstring>
#include <iostream>

static char const *whoami = nullptr;

// from pikepdf import Pdf, PdfImage

// class ImageExtractor:
class ImageExtractor : public QPDFObjectHandle::StreamDataProvider
{
public:
    ~ImageExtractor() override = default;
    // void provideStreamData(QPDFObjGen const& og, Pipeline* pipeline) override;

    void extractImages(
        char const *whoami, char const *infile);

private:
    std::map<QPDFObjGen, QPDFObjectHandle> copied_images;
};

//     def extract_images(file:str):
void ImageExtractor::extractImages(char const *whoami, char const *infile)
{
    //         pdf = Pdf.open(file)
    QPDF input_pdf;
    input_pdf.processFile(infile);
    int page_number = 1;

    //         for pn, page in enumerate(pdf.pages, 1):
    for (QPDFPageObjectHelper &page : QPDFPageDocumentHelper(input_pdf).getAllPages())
    {
        //             for key in page.images.keys():
        // Get all images on the page.
        for (auto &iter : page.getImages())
        {
            QPDFObjectHandle &image = iter.second;
            QPDFObjectHandle image_dict = image.getDict();
            // QPDFObjectHandle color_space = image_dict.getKey("/ColorSpace");
            // QPDFObjectHandle bits_per_component = image_dict.getKey("/BitsPerComponent");

            ///                 name = str(key).replace('/', '')
            //                 raw_image = page.images[key]
            //                 pdf_image = PdfImage(raw_image)
            //                 pdf_image.extract_to(fileprefix=f'img/page-{pn}-{name}')
        }
    }
}


// def __test():
//     file = r"C:/Users/Magenta/Documents/Starfinder/Starfinder - Alien Archive 1.pdf"

//     ImageExtractor.extract_images()

// if __name__ == '__main__':
//     __test()

int main(int argc, char *argv[])
{
    whoami = QUtil::getWhoami(argv[0]);

    auto *extractor = new ImageExtractor;
    auto p = std::shared_ptr<QPDFObjectHandle::StreamDataProvider>(extractor);
}