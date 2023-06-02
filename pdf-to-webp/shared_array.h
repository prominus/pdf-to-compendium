// https://web.archive.org/web/20180713103036/https://chessprogramming.wikispaces.com/Shared%20Hash%20Table
#ifndef SHARED_HASHTABLE
#define SHARED_HASHTABLE

#include <iostream>
// #include <mutex>

template <typename K, typename V>
class Node
{
private:
   // std::mutex _lock;
   K _key;
   V _value;

public:
   Node<K, V>() = default;
   Node<K, V>(K, V);
   ~Node<K, V>() = default;
};

class Image
{
   public:
   Image() = default;
   ~Image() = default;
};

// https://stackoverflow.com/questions/14417907/fixed-size-unordered-map-how-to-define
class StaticMap
{
private:
   std::size_t capacity=0;
   std::size_t isValidIndex(std::size_t index)const;
// protected:
//    int* images;
public:
   StaticMap();
   StaticMap(std::size_t capacity);
   ~StaticMap();
   Image find(std::string key)const; 
};
#endif