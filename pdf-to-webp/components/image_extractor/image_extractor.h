#ifndef IMAGE_EXTRACTOR
#define IMAGE_EXTRACTOR

#include "../handler/handler.h"
#include "../tsqueue/tsqueue.h"

namespace libpdftowebp
{
    class ImageExtractor : public Handler
    {
    public:
        ImageExtractor(const std::string infile, std::shared_ptr<TSQueue<ImageNode>> queue, std::shared_ptr<Json::Value> schema);
        ~ImageExtractor();
        // void provideStreamData(QPDFObjGen const& og, Pipeline* pipeline) override;
        void HandleTask();
    };
}
#endif