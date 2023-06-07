#ifndef TSQUEUE
#define TSQUEUE

// C++ implementation of the above approach
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <utility>
#include <jsoncpp/json/json.h>
#include "../image/image.h"

namespace libpdftowebp
{
    // Simplifying the node called in StaticMap
    typedef std::pair<std::string, Image> ImgNode;
    typedef std::shared_ptr<std::pair<std::string, Image>> ImgNodePtr;

    // Thread-safe queue
    template <typename T>
    class TSQueue
    {
    private:
        // Underlying queue
        std::queue<T> m_queue;

        // mutex for thread synchronization
        std::mutex m_mutex;

        // Condition variable for signaling
        std::condition_variable m_cond;

    public:
        // Pushes an element to the queue
        void push(T item)
        {

            // Acquire lock
            std::unique_lock<std::mutex> lock(m_mutex);

            // Add item
            m_queue.push(item);

            // Notify one thread that
            // is waiting
            m_cond.notify_one();
        }

        // Pops an element off the queue
        T pop()
        {

            // acquire lock
            std::unique_lock<std::mutex> lock(m_mutex);

            // wait until queue is not empty
            m_cond.wait(lock,
                        [this]()
                        { return !m_queue.empty(); });

            // retrieve item
            T item = m_queue.front();
            m_queue.pop();

            // return item
            return item;
        }
    };

    // typedef libpdftowebp::TSQueue<libpdftowebp::ImgNode> ImageQueue;

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
        std::shared_ptr<libpdftowebp::TSQueue<libpdftowebp::ImgNode>> queue;
        std::string file;
    };

}

#endif // TSQUEUE