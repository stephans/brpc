include(hunter_config)

hunter_config(abseil VERSION 20240722.0)
hunter_config(Boost VERSION 1.82.0 CMAKE_ARGS CMAKE_POSITION_INDEPENDENT_CODE=TRUE)
hunter_config(Catch VERSION 2.2.1)
hunter_config(OpenSSL VERSION 3.3.1 CMAKE_ARGS BUILD_SHARED_LIBS=ON)
hunter_config(Protobuf VERSION 27.3-p0)
hunter_config(CURL VERSION 7.60.0-p2)
hunter_config(benchmark VERSION 1.6.1)
hunter_config(gRPC VERSION 1.10.0-p2)
hunter_config(GTest VERSION 1.15.0 CMAKE_ARGS CMAKE_POSITION_INDEPENDENT_CODE=TRUE)
hunter_config(gflags VERSION 2.2.1 CMAKE_ARGS)
hunter_config(glog VERSION 0.4.0)
hunter_config(ZLIB VERSION 1.2.8-p3 CMAKE_ARGS CMAKE_POSITION_INDEPENDENT_CODE=TRUE)
hunter_config(c-ares VERSION 1.14.0-p0 CMAKE_ARGS CARES_STATIC=TRUE CARES_SHARED=FALSE CARES_STATIC_PIC=TRUE)
hunter_config(BZip VERSION 1.0.6-p4)
hunter_config(double-conversion VERSION 3.0.0)
hunter_config(jemalloc VERSION 5.2.1
  CONFIGURATION_TYPES Release
  CMAKE_ARGS EXTRA_FLAGS=--enable-prof
  )
hunter_config(brpc VERSION 2024.07.17.0)
hunter_config(braft VERSION 2023.12.12.0)
hunter_config(flatbuffers VERSION 22.11.23)
hunter_config(rocksdb VERSION 8.10.0 CMAKE_ARGS
  WITH_GFLAGS=OFF
  WITH_TESTS=OFF
  WITH_TOOLS=OFF
  WITH_BENCHMARK_TOOLS=OFF
  USE_RTTI=ON
  )
hunter_config(leveldb VERSION 1.20 CMAKE_ARGS
  CMAKE_CXX_STANDARD=11
  CMAKE_CXX_STANDARD_REQUIRED=ON
  CMAKE_CXX_EXTENSIONS=OFF
  )
hunter_config(CLI11 VERSION 1.8.0)
hunter_config(fu2 VERSION 4.1.0.1)
hunter_config(spdlog VERSION 1.11.0-p2)
hunter_config(crc32c VERSION 1.0.5)
hunter_config(tomlplusplus VERSION 2.5.0)
hunter_config(fmt VERSION 9.1.0)
