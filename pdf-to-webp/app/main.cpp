
#include <iostream>
#include <argparse/argparse.hpp>
#include "/workspaces/pdf-images-to-foundry_dev/pdf-to-webp/components/public/include/entrypoint.h"

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

    std::cout << "Hello World" << std::endl;
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

    entrypoint(
        program.get<std::string>("infile"),
        program.get<std::string>("schema"),
        program.get<std::string>("--output-folder")
    );
    
    return 0;
}