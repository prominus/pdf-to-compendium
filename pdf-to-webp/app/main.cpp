#include <array>
#include <memory>
#include <iostream>
#include <stop_token>
#include <string>
#include <thread>
#include <argparse/argparse.hpp>
#include "../components/artwork_handler/artwork_handler.h"
#include "../components/image_extractor/image_extractor.h"
#include "../components/json_handle/json_handle.h"



/// @brief Create a argument parser
/// @return Return the argument parser to parse args in main
argparse::ArgumentParser GenerateArgParse()
{
    // TODO: Don't hardcode the version
    argparse::ArgumentParser program("pdftowebp", "0.0.1");

    program.add_description("A parser tool to convert a PDF file to webp images. The names of images are dictated by a schema layout.");

    // Optional output folder argument.
    program.add_argument("-o", "--output-folder")
        .help("The folder to place webp images")
        .default_value<std::string>("artwork");

    // JSON schema argument
    program.add_argument("-s", "--schema")
        .help("The input JSON file path")
        .default_value("");
    
    // PDF Filepath argument
    program.add_argument("infile")
        .required()
        .help("The input PDF file path");

    return program;
};

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
    // Parse arguments
    argparse::ArgumentParser program = GenerateArgParse();
    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err)
    {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        return 1;
    }

    // Extract parameters
    std::string infile = program.get<std::string>("infile");
    std::string schema = program.get<std::string>("schema");
    std::string output_folder = program.get<std::string>("--output-folder");

    // Threading c++20
    // std::stop_source stop_source;
    // std::jthread jt;
    
    // Get schema for file. Pass this in as an argument
    std::shared_ptr<Json::Value> json_ref = (strcmp(schema.c_str(), "") == 0) ? nullptr : libpdftowebp::GetJsonHandle(schema.c_str());

    // TODO: The shared queue
    std::shared_ptr<libpdftowebp::TSQueue<libpdftowebp::ImgNode>> queue = std::make_shared<libpdftowebp::TSQueue<libpdftowebp::ImgNode>>();

    // Create the image extractor workers
    libpdftowebp::ImageExtractor extractor = libpdftowebp::ImageExtractor(infile, queue, json_ref);
    // TODO: run extractor task

    // extractor.extractImages(json_ref, "test");
    // auto *extractor = new ImageExtractor;
    // auto p = std::shared_ptr<QPDFObjectHandle::StreamDataProvider>(extractor);

    // Create artwork handling workers
    libpdftowebp::ArtworkHandler artwork_handler = libpdftowebp::ArtworkHandler(output_folder, queue, json_ref);
    // TODO: run extractor task

    // TODO: Wait for workers to finish and clear up
    if (json_ref != nullptr)
    {
        json_ref.reset();
    }
    queue.reset();
    return 0;
}