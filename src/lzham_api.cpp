// File: lzham_api.cpp
// See Copyright Notice and license at the end of include/lzham.h
#include "lzham_core.h"
#include "lzham_decomp.h"
#include "lzham_comp.h"

extern "C" LZHAM_DLL_EXPORT lzham_uint32 lzham_get_version(void)
{
   return LZHAM_DLL_VERSION;
}

extern "C" LZHAM_DLL_EXPORT void lzham_set_memory_callbacks(lzham_realloc_func pRealloc, lzham_msize_func pMSize, void* pUser_data)
{
   lzham::lzham_lib_set_memory_callbacks(pRealloc, pMSize, pUser_data);
}

extern "C" LZHAM_DLL_EXPORT lzham_decompress_state_ptr lzham_decompress_init(const lzham_decompress_params *pParams)
{
   return lzham::lzham_lib_decompress_init(pParams);
}

extern "C" LZHAM_DLL_EXPORT lzham_uint32 lzham_decompress_deinit(lzham_decompress_state_ptr p)
{
   return lzham::lzham_lib_decompress_deinit(p);
}

extern "C" LZHAM_DLL_EXPORT lzham_decompress_status_t lzham_decompress(
   lzham_decompress_state_ptr p,
   const lzham_uint8 *pIn_buf, size_t *pIn_buf_size, 
   lzham_uint8 *pOut_buf, size_t *pOut_buf_size,
   lzham_bool no_more_input_bytes_flag)
{
   return lzham::lzham_lib_decompress(p, pIn_buf, pIn_buf_size, pOut_buf, pOut_buf_size, no_more_input_bytes_flag);
}   

extern "C" LZHAM_DLL_EXPORT lzham_decompress_status_t lzham_decompress_memory(const lzham_decompress_params *pParams, lzham_uint8* pDst_buf, size_t *pDst_len, const lzham_uint8* pSrc_buf, size_t src_len, lzham_uint32 *pAdler32)
{
   return lzham::lzham_lib_decompress_memory(pParams, pDst_buf, pDst_len, pSrc_buf, src_len, pAdler32);
}

extern "C" LZHAM_DLL_EXPORT lzham_compress_state_ptr lzham_compress_init(const lzham_compress_params *pParams)
{
   return lzham::lzham_lib_compress_init(pParams);
}

extern "C" LZHAM_DLL_EXPORT lzham_uint32 lzham_compress_deinit(lzham_compress_state_ptr p)
{
   return lzham::lzham_lib_compress_deinit(p);
}

extern "C" LZHAM_DLL_EXPORT lzham_compress_status_t lzham_compress(
   lzham_compress_state_ptr p,
   const lzham_uint8 *pIn_buf, size_t *pIn_buf_size, 
   lzham_uint8 *pOut_buf, size_t *pOut_buf_size,
   lzham_bool no_more_input_bytes_flag)
{
   return lzham::lzham_lib_compress(p, pIn_buf, pIn_buf_size, pOut_buf, pOut_buf_size, no_more_input_bytes_flag);
}   

extern "C" LZHAM_DLL_EXPORT lzham_compress_status_t lzham_compress_memory(const lzham_compress_params *pParams, lzham_uint8* pDst_buf, size_t *pDst_len, const lzham_uint8* pSrc_buf, size_t src_len, lzham_uint32 *pAdler32)
{
   return lzham::lzham_lib_compress_memory(pParams, pDst_buf, pDst_len, pSrc_buf, src_len, pAdler32);
}

