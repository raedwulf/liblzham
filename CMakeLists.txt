cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE Release CACHE STRING
	"Build configuration (Debug, Release, RelWithDebInfo, MinSizeRel)")

project(lzham C CXX)

# Compile flags
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_C_FLAGS_DEBUG "-O0 -D_DEBUG")

# Sources
set(LZHAM_INC "include")
set(COMP_SRC
	"src/comp/lzham_lzbase.cpp"
	"src/comp/lzham_lzcomp.cpp"
	"src/comp/lzham_lzcomp_internal.cpp"
	"src/comp/lzham_match_accel.cpp"
	"src/comp/lzham_lzcomp_internal.h"
	"src/comp/lzham_threading.h")
if(WIN32)
	LIST(APPEND COMP_SRC
		"src/comp/lzham_win32_threading.cpp"
		"src/comp/lzham_win32_threading.h")
elseif(UNIX)
	LIST(APPEND COMP_SRC
		"src/comp/lzham_pthreads_threading.cpp"
		"src/comp/lzham_pthreads_threading.h")
endif()
set(DECOMP_SRC
	"src/decomp/lzham_assert.cpp"
	"src/decomp/lzham_assert.h"
	"src/decomp/lzham_checksum.cpp"
	"src/decomp/lzham_checksum.h"
	"src/decomp/lzham_config.h"
	"src/decomp/lzham_core.h"
	"src/decomp/lzham_decomp.h"
	"src/decomp/lzham_helpers.h"
	"src/decomp/lzham_huffman_codes.cpp"
	"src/decomp/lzham_huffman_codes.h"
	"src/decomp/lzham_lzdecomp.cpp"
	"src/decomp/lzham_lzdecompbase.cpp"
	"src/decomp/lzham_lzdecompbase.h"
	"src/decomp/lzham_math.h"
	"src/decomp/lzham_mem.cpp"
	"src/decomp/lzham_mem.h"
	"src/decomp/lzham_platform.cpp"
	"src/decomp/lzham_platform.h"
	"src/decomp/lzham_polar_codes.cpp"
	"src/decomp/lzham_polar_codes.h"
	"src/decomp/lzham_prefix_coding.cpp"
	"src/decomp/lzham_prefix_coding.h"
	"src/decomp/lzham_symbol_codec.cpp"
	"src/decomp/lzham_symbol_codec.h"
	"src/decomp/lzham_timer.cpp"
	"src/decomp/lzham_timer.h"
	"src/decomp/lzham_traits.h"
	"src/decomp/lzham_types.h"
	"src/decomp/lzham_utils.h"
	"src/decomp/lzham_vector.cpp"
	"src/decomp/lzham_vector.h")

set(LIB_SRC
	"include/lzham.h"
	"src/lzham_api.cpp")
set(CLI_SRC
	"cli/lzhamtest.cpp"
	"cli/timer.cpp"
	"cli/timer.h")

set(CMAKE_THREAD_PREFER_PTHREAD 1)
find_package(Threads REQUIRED)

include_directories(${LZHAM_INC} src/decomp src/comp)
add_library(lzham-shared SHARED ${LIB_SRC} ${COMP_SRC} ${DECOMP_SRC})
set_target_properties(lzham-shared
	PROPERTIES OUTPUT_NAME "lzham")
target_link_libraries(lzham-shared ${CMAKE_THREAD_LIBS_INIT})
add_library(lzham-static STATIC ${LIB_SRC} ${COMP_SRC} ${DECOMP_SRC})
set_target_properties(lzham-static
	PROPERTIES OUTPUT_NAME "lzham")
target_link_libraries(lzham-static ${CMAKE_THREAD_LIBS_INIT})
add_executable(lzham ${CLI_SRC})
set_target_properties(lzham
	PROPERTIES COMPILE_DEFINITIONS "LZHAM_STATIC_LIB")
target_link_libraries(lzham lzham-static)

