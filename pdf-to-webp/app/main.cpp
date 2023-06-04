#include <array>
#include <memory>
#include <iostream>
#include <string>
#include "../components/shared_array/shared_array.h"
#include "../components/json_handle/json_handle.h"
#include "../components/image_extractor/image_extractor.h"

/// @brief main entrypoint
/// @param argc 
/// @param argv Expected arguments:
///                 filepath to PDF
///                 schema to use
/// @return 0 if it works...
int main(int argc, char *argv[])
{
    // TODO: Get schema for file. Pass this in as an argument
    std::string file = "/workspaces/pdf-images-to-foundry_dev/pdf-to-webp/app/example.json";
    Json::Value* json_ref = libpdftowebp::GetJsonHandle(file.c_str()); 

    std::cout << "encoding: " << (*json_ref)["encoding"] <<std::endl;
    std::cout << "plug-ins: " << (*json_ref)["plug-ins"] <<std::endl;
    std::cout << "indent: " << (*json_ref)["indent"] <<std::endl;

    const std::size_t number_of_images = 2; // TODO: This should be pulled from the schema

    // TODO: The shared memory map


    libpdftowebp::StaticMap map = libpdftowebp::StaticMap<number_of_images>();
   

    // TODO: create the image extractor workers
    libpdftowebp::ImageExtractor extractor = libpdftowebp::ImageExtractor();

    extractor.extractImages(json_ref, "test");
    // auto *extractor = new ImageExtractor;
    // auto p = std::shared_ptr<QPDFObjectHandle::StreamDataProvider>(extractor);

    // TODO: create artwork handling workers

    // TODO: Wait for workers to finish and clear up
    delete json_ref;

    return 0;
}