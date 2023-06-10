#ifndef HANDLER
#define HANDLER

#include <iostream>
#include <memory>
#include <string>
// #include <jsoncpp/json/json.h>
#include <jsoncpp/json/json.h>
#include "image.h"
#include "tsqueue.h"

class Handler
{
public:
    ~Handler()
    {
        if (schema != nullptr)
        {
            schema.reset();
        }
        queue.reset();
    }
    virtual void HandleTask() = 0;

protected:
    std::shared_ptr<Json::Value> schema;
    std::shared_ptr<TSQueue<ImageNode>> queue;
    std::string file;
};

#endif