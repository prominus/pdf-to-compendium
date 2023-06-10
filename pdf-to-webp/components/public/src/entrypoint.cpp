#include <iostream>
#include <string>
#include "artwork_handler.h"
#include "image_extractor.h"
#include "json_ref.h"
#include "../include/entrypoint.h"

extern "C" void entrypoint(std::string infile, std::string schema, std::string output_folder)
{

    // Threading c++20
    // std::stop_source stop_source;
    // std::jthread jt;
    
    // Get schema for file. Pass this in as an argument
    auto json_ref = (strcmp(schema.c_str(), "") == 0) ? nullptr : GetJsonHandle(schema.c_str());

    // TODO: The shared queue
    std::shared_ptr<TSQueue<ImageNode>> queue = std::make_shared<TSQueue<ImageNode>>();

    // Create the image extractor workers
    ImageExtractor extractor = ImageExtractor(infile, queue, json_ref);
    // TODO: run extractor task

    // extractor.extractImages(json_ref, "test");
    // auto *extractor = new ImageExtractor;
    // auto p = std::shared_ptr<QPDFObjectHandle::StreamDataProvider>(extractor);

    // Create artwork handling workers
    ArtworkHandler artwork_handler = ArtworkHandler(output_folder, queue, json_ref);
    // TODO: run extractor task

    // TODO: Wait for workers to finish and clear up
    if (json_ref != nullptr)
    {
        json_ref.reset();
    }
    queue.reset();
}