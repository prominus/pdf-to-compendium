// https://web.archive.org/web/20180713103036/https://chessprogramming.wikispaces.com/Shared%20Hash%20Table
#ifndef SHARED_ARRAY
#define SHARED_ARRAY

#include <array>
#include <memory>
#include <mutex>
#include <iostream>

namespace libpdftowebp
{
   /// @headerfile shared_array.h "/workspaces/pdf-images-to-foundry_dev/pdf-to-webp/components/shared_array/shared_array.h"
   /// @brief A generic immutable key/value node
   /// @tparam K the key type
   /// @tparam V the value type
   /// @details
   /// By making it immutable, in theory, this will make it thread-safe if multiple workers read from it
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
      /// @brief Node Destructor
      ~Node<K, V>() = default;
   };

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

   // Simplifying the node called in StaticMap
   typedef Node<std::string, Image> ImgNode;
   typedef std::shared_ptr<Node<std::string, Image>> ImgNodePtr;

   /// @headerfile shared_array.h "/workspaces/pdf-images-to-foundry_dev/pdf-to-webp/components/shared_array/shared_array.h"
   /// @brief Holds the images in memory to share between workers.
   /// @tparam N the size of the array
   /// @details
   /// When initialized the appropriately sized array of images is instantiated. Got the idea from the following Stack Overflow discussion: https://stackoverflow.com/questions/14417907/fixed-size-unordered-map-how-to-define
   template <std::size_t N>
   class StaticMap
   {
   private:
      const std::size_t capacity = 0;
      bool isValidIndex(std::size_t index) const;
      std::array<ImgNodePtr, N> images{};
      std::mutex m;
      std::size_t counter = 0;

   public:
      StaticMap<N>();
      ~StaticMap<N>();
      std::size_t getCapacity() const;
      char *getImagesPtr();
      std::array<ImgNodePtr, N> getImages() const;
      ImgNodePtr indexImage(const int index) const;
      const Image *findImage(std::string key);
      void insertNode(const std::string key, const Image value);
      void insertNode(const ImgNode node);
   };
   /// @brief Constructor
   /// @tparam N the size of the array
   template <std::size_t N>
   inline StaticMap<N>::StaticMap() : capacity(N)
   {
      // images = new std::array<Node<std::string, std::shared_ptr<Image>>, N>();
   }
   /// @brief Destructor
   /// @tparam N the size of the array
   template <std::size_t N>
   inline StaticMap<N>::~StaticMap()
   {
      for (ImgNodePtr image : images)
      {
         if (image != nullptr)
         {
            image.reset();
         }
      } 
   }
   /// @brief Determine if the index is valid
   /// @tparam N the size of the array
   /// @param index index to check
   /// @return True if within range, False otherwise
   template <std::size_t N>
   inline bool StaticMap<N>::isValidIndex(std::size_t index) const
   {
      if (index >= 0 && index < capacity)
      {
         return true;
      }
      return false;
   }
   /// @brief Provide the max size of the image array
   /// @tparam N the size of the array
   /// @return the max size attribute
   template <std::size_t N>
   inline std::size_t StaticMap<N>::getCapacity() const
   {
      return capacity;
   }
   /// @brief Return the array pointer
   /// @tparam N the size of the array
   /// @return The pointer of the array
   template <std::size_t N>
   inline char *StaticMap<N>::getImagesPtr()
   {
      return images;
   }
   /// @brief Provide the `N` sized array of `libpdftowebp::Image`
   /// @tparam N the size of the array
   /// @return the array holding the images
   template <std::size_t N>
   inline std::array<ImgNodePtr, N> StaticMap<N>::getImages() const
   {
      return images;
   }
   /// @brief Retrieve the image by index
   /// @tparam N the size of the array
   /// @param index 
   /// @return the image at that index
   template <std::size_t N>
   inline ImgNodePtr StaticMap<N>::indexImage(const int index) const
   {
      if (isValidIndex(index))
      {
         return images[index];
      }
      throw std::out_of_range("The index must be between 0 and " + std::to_string(capacity));
   }
   /// @brief 
   /// @tparam N 
   /// @param key 
   /// @return 
   template <std::size_t N>
   inline const Image *StaticMap<N>::findImage(std::string key)
   {
      for (ImgNodePtr image : images)
      {
         if (image == nullptr)
         {
            continue;
         }
         else if (image->key == key)
         {
            return &(image->value);
            break;
         }
      }
      return nullptr;
   }
   /// @brief 
   /// @tparam N 
   /// @param key 
   /// @param value 
   template <std::size_t N>
   inline void StaticMap<N>::insertNode(const std::string key, const Image value)
   {
      // Adding lock so multiple workers will not write to array at the same time.
      std::lock_guard<std::mutex> lg(m);
      if (isValidIndex(counter) == false)
      {
         throw std::out_of_range("Cannot insert anymore values into this array");
      }
      
      ImgNodePtr i = std::make_shared<ImgNode>(key, value);
      images[counter] = i;
      counter++;
   }

   template <std::size_t N>
   inline void StaticMap<N>::insertNode(const ImgNode node)
   {
      // Adding lock so multiple workers will not write to array at the same time.
      std::lock_guard<std::mutex> lg(m);
      if (isValidIndex(counter) == false)
      {
         throw std::out_of_range("Cannot insert anymore values into this array");
      }
      
      ImgNodePtr i = std::make_shared<ImgNode>(node);
      images[counter] = i;
      counter++;
   }
}

#endif // SHARED_ARRAY