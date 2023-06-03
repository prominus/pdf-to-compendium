#include <array>
#include <memory>
#include <iostream>
#include "shared_array.h"

using namespace pdftowebp;


/// @brief main entrypoint
/// @param argc 
/// @param argv Expected arguments:
///                 filepath to PDF
///                 schema to use
/// @return 0 if it works...
int main(int argc, char *argv[])
{
    // TODO: Get schema for file. Pass this in as an argument
    const std::size_t number_of_images = 100; // TODO: This should be pulled from the schema

    // TODO: The shared memory map
    Node test = Node("key", 1);
    std::cout << "The key is: " << test.key << std::endl;
    std::cout << "The value is: " << test.value << std::endl;

    std::shared_ptr<Image> image;
    Node<std::string, std::shared_ptr<Image>> node;
    std::array<Node<std::string, std::shared_ptr<Image>>, 100> images{};
    auto map = pdftowebp::StaticMap<100>();
    // StaticMap map = StaticMap<number_of_images>();
    // auto map = new StaticMap<number_of_images>();

    // TODO: create the image extractor workers
    // auto *extractor = new ImageExtractor;
    // auto p = std::shared_ptr<QPDFObjectHandle::StreamDataProvider>(extractor);

    // TODO: create artwork handling workers

    // TODO: Wait for workers to finish and clear up

    return 0;
}