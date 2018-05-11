if(BUILD_UNIT_TESTS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUNIT_TEST -DBVAR_NOT_LINK_DEFAULT_VARIABLES")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DUNIT_TEST")
elseif(NOT DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DNDEBUG")
endif()

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)

if (BRPC_BUILD_SHARED)
    add_library(brpc-shared SHARED ${SOURCES})
    set_property(TARGET brpc-shared PROPERTY POSITION_INDEPENDENT_CODE ON)
    target_link_libraries(brpc-shared PUBLIC
        ${DYNAMIC_LIB}
        gflags
        protobuf::libprotobuf
        leveldb::leveldb
        )
    if (APPLE)
        target_link_libraries(brpc-shared PUBLIC
            "-framework Foundation"
            "-framework CoreGraphics"
            "-framework CoreText"
            "-framework Security"
            )
    endif()
endif()

add_library(brpc-static STATIC ${SOURCES})
set_property(TARGET brpc-static PROPERTY POSITION_INDEPENDENT_CODE ON)

target_link_libraries(brpc-static PUBLIC
    gflags
    protobuf::libprotobuf
    leveldb::leveldb
    OpenSSL::SSL
    OpenSSL::Crypto
    )

if(BRPC_WITH_GLOG)
    if (BRPC_BUILD_SHARED)
        target_link_libraries(brpc-shared PUBLIC glog::glog)
    endif()
    target_link_libraries(brpc-static PUBLIC glog::glog)
endif()

SET_TARGET_PROPERTIES(brpc-static PROPERTIES OUTPUT_NAME brpc CLEAN_DIRECT_OUTPUT 1)

if (BRPC_BUILD_SHARED)
    SET_TARGET_PROPERTIES(brpc-shared PROPERTIES OUTPUT_NAME brpc CLEAN_DIRECT_OUTPUT 1)
endif()

if (BRPC_BUILD_GEN_MCPACK)
    # for protoc-gen-mcpack
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/output/bin)

    set(protoc_gen_mcpack_SOURCES
        ${CMAKE_SOURCE_DIR}/src/mcpack2pb/generator.cpp
        )
    add_executable(protoc-gen-mcpack ${protoc_gen_mcpack_SOURCES})
    target_link_libraries(protoc-gen-mcpack
        brpc-static
        protobuf::libprotobuf
        )
endif()

get_property(LIB64 GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS)
if ("${LIB64}" STREQUAL "TRUE")
    set(LIBSUFFIX 64)
else()
    set(LIBSUFFIX "")
endif()

#install directory
# cmake -DCMAKE_INSTALL_PREFIX=/usr
if (BRPC_BUILD_SHARED)
    install(TARGETS brpc-shared
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib${LIBSUFFIX}
            ARCHIVE DESTINATION lib${LIBSUFFIX}
            )
endif()

install(TARGETS brpc-static
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib${LIBSUFFIX}
        ARCHIVE DESTINATION lib${LIBSUFFIX}
        )
