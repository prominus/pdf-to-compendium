// static libraries located at /user/lib/x86_64-linux-gnu
// dynamic library located at /user/include/qpdf/*

// JSON streaming
#include <jsoncpp/json/json.h>

// PDF image
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
#include "image_extractor.h"

using namespace libpdftowebp;
// from pikepdf import Pdf, PdfImage

static char const* whoami = nullptr;

//     def extract_images(file:str):
void ImageExtractor::extractImages(char* arg, char const *infile)
{

    whoami = QUtil::getWhoami(arg);


    //         pdf = Pdf.open(file)
    // QPDF input_pdf;
    // input_pdf.processFile(infile);
    // int page_number = 1;

    // //         for pn, page in enumerate(pdf.pages, 1):
    // for (QPDFPageObjectHelper &page : QPDFPageDocumentHelper(input_pdf).getAllPages())
    // {
    //     //             for key in page.images.keys():
    //     // Get all images on the page.
    //     for (auto &iter : page.getImages())
    //     {
    //         QPDFObjectHandle &image = iter.second;
    //         QPDFObjectHandle image_dict = image.getDict();
    //         // QPDFObjectHandle color_space = image_dict.getKey("/ColorSpace");
    //         // QPDFObjectHandle bits_per_component = image_dict.getKey("/BitsPerComponent");

    //         ///                 name = str(key).replace('/', '')
    //         //                 raw_image = page.images[key]
    //         //                 pdf_image = PdfImage(raw_image)
    //         //                 pdf_image.extract_to(fileprefix=f'img/page-{pn}-{name}')
    //     }
    // }

}

// def __test():
//     file = r"C:/Users/Magenta/Documents/Starfinder/Starfinder - Alien Archive 1.pdf"

//     ImageExtractor.extract_images()

// if __name__ == '__main__':
//     __test()
