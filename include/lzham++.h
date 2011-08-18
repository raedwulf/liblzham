#ifndef _LZHAMPP_H_
#define _LZHAMPP_H_
#include <lzham.h>
class lzham_impl : public ilzham
{
   lzham_impl(const lzham_impl &other);
   lzham_impl& operator= (const lzham_impl &rhs);

public:
   lzham_impl() : ilzham() { }

   virtual ~lzham_impl() { }
   
   virtual bool load()
   {
      this->lzham_get_version = ::lzham_get_version;
      this->lzham_set_memory_callbacks = ::lzham_set_memory_callbacks;
      this->lzham_compress_init = ::lzham_compress_init;
      this->lzham_compress_deinit = ::lzham_compress_deinit;
      this->lzham_compress = ::lzham_compress;
      this->lzham_compress_memory = ::lzham_compress_memory;
      this->lzham_decompress_init = ::lzham_decompress_init;
      this->lzham_decompress_deinit = ::lzham_decompress_deinit;
      this->lzham_decompress = ::lzham_decompress;
      this->lzham_decompress_memory = ::lzham_decompress_memory;
      return true;
   }
   
   virtual void unload()
   {
      clear();
   }
   
   virtual bool is_loaded() { return lzham_get_version != NULL; }
};
#endif
