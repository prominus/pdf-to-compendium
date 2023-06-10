// https://web.archive.org/web/20180713103036/https://chessprogramming.wikispaces.com/Shared%20Hash%20Table
#ifndef IMAGE
#define IMAGE

#include <array>
#include <memory>
#include <mutex>
#include <iostream>

/// @headerfile shared_array.h "/workspaces/pdf-images-to-foundry_dev/pdf-to-webp/components/shared_array/shared_array.h"
/// @brief TODO: Class to handle the image
/// @details
/// TODO
class Image
{
public:
   Image() = default;
   ~Image() = default;
};

/// @headerfile shared_array.h "/workspaces/pdf-images-to-foundry_dev/pdf-to-webp/components/shared_array/shared_array.h"
/// @brief A generic immutable key/value node
/// @tparam K the key type
/// @tparam V the value type
/// @details
/// By making it immutable, in theory, this will make it thread-safe if multiple workers read from it
struct ImageNode
{
   const std::string key;
   const Image value;
   ImageNode(std::string k, Image v) : key(k), value(v) {}
   ~ImageNode() = default;
};

#endif // IMAGE