#include <array>
#include <memory>
#include <iostream>
#include <string>
#include "../components/shared_array/shared_array.h"
#include "../components/json_handle/json_handle.h"
#include "../components/image_extractor/image_extractor.h"

static const char document[] =
    "NAME\r\n"
    "       pdftoweb - A PDF image to webp parsing tool\r\n"
    "\r\n"
    "SYNOPSIS\r\n"
    "       pdftoweb [OPTIONS] <infile> <schema>\r\n"
    "\r\n"
    "DESCRIPTION\r\n"
    "       A parser tool to convert a PDF file to webp images. The names of images are dictated by a schema layout.\r\n"
    "\r\n"
    "OPTIONS\r\n"
    "       -v\r\n"
    "       --version\r\n"
    "           Display the version of pdftoweb\r\n"
    "\r\n"
    "       -h\r\n"
    "       --help\r\n"
    "           Print a help message describing all of pdftoweb's command-line options\r\n"
    "\r\n"
    "       -o\r\n"
    "       --output_folder\r\n";

// It's deprecated to pass a string literal to a char *, so setting up these variables to
// Prevent this warning/error: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
const char * const h = "-h";
const char * const help = "--help";
const char * const v = "-v";
const char * const version = "--version";
const char * const o = "-o";
const char * const output_folder = "--output-folder";

/// @brief Making a small struct to avoid importing tuple library
struct indexTest
{
    bool is_passed;
    int index;
    indexTest(bool p, int i) : is_passed(p), index(i) {}
    ~indexTest() = default;
};

/// @brief Routine to see if the passed in arguments contain an element
/// @param args The arguments passed in
/// @param x The element we are checking for
/// @return True if element found, False otherwise
indexTest Contains(const std::vector<char *> &args, const char *const x)
{
    int index = 0;
    for (auto &&arg : args)
    {
        if (strcmp(arg, x) == 0)
        {
            return indexTest(true, index);
        }
        index++;
    }
    return indexTest(false, -1);
}

/// @brief 
/// @param args 
/// @return 
int run(std::vector<char*> args)
{
        // TODO: Get schema for file. Pass this in as an argument
        std::string file = "/workspaces/pdf-images-to-foundry_dev/pdf-to-webp/app/example.json";
    Json::Value *json_ref = libpdftowebp::GetJsonHandle(file.c_str());

    std::cout << "encoding: " << (*json_ref)["encoding"] << std::endl;
    std::cout << "plug-ins: " << (*json_ref)["plug-ins"] << std::endl;
    std::cout << "indent: " << (*json_ref)["indent"] << std::endl;

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

/// @brief main entrypoint
/// @param argc
/// @param argv Expected arguments:
///                 filepath to PDF
///                 schema to use
/// @details
/// Handles reading in and dealing with arguments. As long as help or versioning check
/// isn't called the run function will be called.
/// @return 0 if it works...
int main(int argc, char *argv[])
{
    // Copying char** over to a vector
    std::vector<char *> args(argv, argv + argc);
    
    auto o_test = Contains(args, o);
    auto output_folder_test = Contains(args, output_folder);

    if (argc == 1 || (Contains(args, help)).is_passed || (Contains(args, h).is_passed))
    {
        std::cout << document << std::endl;
        return 0;
    }
    else if ((Contains(args, v)).is_passed || (Contains(args, version)).is_passed)
    {
        // TODO: Don't hard code the version
        std::cout << "0.0.1" << std::endl;
        return 0;
    }
    else if (o_test.is_passed || output_folder_test.is_passed)
    {
        // TODO: deal with changing output folder
    }
    
    return run(args);
}