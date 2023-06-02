#include <qpdf/QUtil.hh>
#include <iostream>
#include "shared_array.h"
#include "image_extractor.h"
#include "artwork_handler.h"

static char const *whoami = nullptr;

int main(int argc, char *argv[])
{
    // Expected arguments:
    //  filepath to PDF
    //  schema to use


    // whoami = QUtil::getWhoami(argv[0]);

    std::cout << "Does this work?" << std::endl;

    // TODO: Get schema for file. Pass this in as an argument
    std::size_t number_of_images = 100; // TODO: This should be pulled from the schema

    // TODO: The shared memory map
    std::shared_ptr<Image> image;
    Node<std::string, std::shared_ptr<Image>> node;
    std::array<Node<std::string, std::shared_ptr<Image>>, 100> images{};
    auto map = StaticMap();

    // TODO: create the image extractor workers
    // auto *extractor = new ImageExtractor;
    // auto p = std::shared_ptr<QPDFObjectHandle::StreamDataProvider>(extractor);

    // TODO: create artwork handling workers

    // TODO: Wait for workers to finish and clear up

       
}