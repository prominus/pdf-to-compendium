// https://web.archive.org/web/20180713103036/https://chessprogramming.wikispaces.com/Shared%20Hash%20Table
#ifndef SHARED_HASHTABLE
#define SHARED_HASHTABLE

#include <iostream>

namespace libpdftowebp
{
   /* An immutable node. By making it immutable, in theory, this will make it thread-safe if multiple workers read from it*/
   template <typename K, typename V>
   struct Node
   {
      K const key;
      V const value;
      Node<K, V>() = default;
      /// @brief Node Constructor
      /// @param k The key
      /// @param v The value
      Node<K, V>(K k, V v) : key(k), value(v) {}
      ~Node<K, V>() = default;
   };

   /* TODO: Class to handle the image.*/
   class Image
   {
   public:
      Image() = default;
      ~Image() = default;
   };

   // https://stackoverflow.com/questions/14417907/fixed-size-unordered-map-how-to-define
   template<std::size_t N>
   class StaticMap
   {
   private:
      const std::size_t capacity = 0;
      std::size_t isValidIndex(std::size_t index) const;
      std::array<Node<std::string, std::shared_ptr<Image>>, N> images;
      // protected:
      //    int* images;
   public:
      StaticMap<N>();
      ~StaticMap<N>();
      int getCapacity()const;
      std::shared_ptr<Image> indexImage(int index) const;
      std::shared_ptr<Image> findImage(std::string key) const;
      void insert(const std::string key, const std::shared_ptr<Image> value) const;
   };
}
#endif