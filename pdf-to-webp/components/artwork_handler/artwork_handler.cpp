
// WEBP image storing
#include <webp/decode.h>
#include <webp/encode.h>
#include <webp/types.h>
#include "artwork_handler.h"

/// @brief 
/// @param queue 
/// @param output_folder 
/// @param schema 
libpdftowebp::ArtworkHandler::ArtworkHandler(const std::string output_folder, std::shared_ptr<TSQueue<ImgNode>> queue, std::shared_ptr<Json::Value> schema)
// : queue(queue), file(output_folder), schema(schema)
{
    this->file = output_folder;
    this->queue = queue;
    this->schema = schema;
}

/// @brief 
libpdftowebp::ArtworkHandler::~ArtworkHandler()
{
    queue.reset();
    if (schema != nullptr)
    {
        schema.reset();
    }
}

/// @brief 
void libpdftowebp::ArtworkHandler::HandleTask()
{

}