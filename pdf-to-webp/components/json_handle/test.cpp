#include <array>
#include <memory>
#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>
#include "json_handle.h"

int main(int argc, char *argv[])
{
    // TODO: Get schema for file. Pass this in as an argument
    std::string file = "example.json";
    libpdftowebp::GetJsonHandle(file.c_str());
    return 0;
}