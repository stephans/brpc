# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

if(NOT DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DNDEBUG")
endif()

add_library(brpc-static STATIC
  ${SOURCES}
  ${BUTIL_SOURCES}
  )
set_target_properties(brpc-static PROPERTIES POSITION_INDEPENDENT_CODE 1)

target_include_directories(brpc-static
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
  PRIVATE ${PROJECT_SOURCE_DIR}/src
  PUBLIC ${PROJECT_BINARY_DIR}/output/include
  )

if(BRPC_WITH_THRIFT)
    target_link_libraries(brpc-static thrift)
endif()

target_link_libraries(brpc-static PUBLIC
  gflags
  protobuf::libprotobuf
  leveldb::leveldb
  OpenSSL::SSL
  OpenSSL::Crypto
  md5::md5
  )

SET_TARGET_PROPERTIES(brpc-static PROPERTIES OUTPUT_NAME brpc CLEAN_DIRECT_OUTPUT 1)

# for protoc-gen-mcpack
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/output/bin)

if (BRPC_BUILD_GEN_MCPACK)
  set(protoc_gen_mcpack_SOURCES
    ${PROJECT_SOURCE_DIR}/src/mcpack2pb/generator.cpp
    )
  add_executable(protoc-gen-mcpack ${protoc_gen_mcpack_SOURCES})
  target_link_libraries(protoc-gen-mcpack
    brpc-static
    protobuf::libprotobuf
    "-framework CoreFoundation"
    "-framework CoreGraphics"
    "-framework CoreData"
    "-framework CoreText"
    "-framework Security"
    "-framework Foundation"
    )
endif()
    
install(TARGETS brpc-static
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )
