// static libraries located at /user/lib/x86_64-linux-gnu
// dynamic library located at /user/include/qpdf/*

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

/// @brief 
/// @param infile 
/// @param schema 
/// @param queue 
libpdftowebp::ImageExtractor::ImageExtractor(const std::string infile, std::shared_ptr<TSQueue<ImgNode>> queue, std::shared_ptr<Json::Value> schema)
// : infile(infile), file(schema), queue(queue)
{
    this->file = infile;
    this->queue = queue;
    this->schema = schema;
}

/// @brief 
libpdftowebp::ImageExtractor::~ImageExtractor()
{
    queue.reset();
    if (schema != nullptr)
    {
        schema.reset();
    }
}

/// @brief 
void libpdftowebp::ImageExtractor::HandleTask()
{

    // whoami = QUtil::getWhoami(arg);


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
