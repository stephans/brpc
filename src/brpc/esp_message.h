// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef BRPC_ESP_MESSAGE_H
#define BRPC_ESP_MESSAGE_H

#include <string>

#include <google/protobuf/message.h>
#include <google/protobuf/generated_message_reflection.h>   // dynamic_cast_if_available
#include <google/protobuf/reflection_ops.h>     // ReflectionOps::Merge

#include "brpc/esp_head.h"
#include "butil/iobuf.h"       
#include "brpc/proto_base.pb.h"
#include "brpc/pb_compat.h"

namespace brpc {

class EspMessage : public ::google::protobuf::Message {
public:
    EspHead head;
    butil::IOBuf body;

public:
    EspMessage();
    virtual ~EspMessage();

    EspMessage(const EspMessage& from);

    inline EspMessage& operator=(const EspMessage& from) {
        CopyFrom(from);
        return *this;
    }

    static const ::google::protobuf::Descriptor* descriptor();
    static const EspMessage& default_instance();

    void Swap(EspMessage* other);

    // implements Message ----------------------------------------------

    EspMessage* New() const PB_319_OVERRIDE;
#if GOOGLE_PROTOBUF_VERSION >= 3006000
    EspMessage* New(::google::protobuf::Arena* arena) const override;

    const ::google::protobuf::MessageLite::ClassData *
    GetClassData() const override;
#endif
        void CopyFrom(const ::google::protobuf::Message &from) PB_321_OVERRIDE;
    void MergeFrom(const ::google::protobuf::Message& from) PB_321_OVERRIDE;
    void CopyFrom(const EspMessage& from);
    void MergeFrom(const EspMessage& from);
    void Clear() override;
    bool IsInitialized() const PB_321_OVERRIDE;

    int ByteSize() const;
    bool MergePartialFromCodedStream(
            ::google::protobuf::io::CodedInputStream* input) PB_310_OVERRIDE;
    void SerializeWithCachedSizes(
            ::google::protobuf::io::CodedOutputStream* output) const PB_310_OVERRIDE;
    ::google::protobuf::uint8* SerializeWithCachedSizesToArray(
            ::google::protobuf::uint8* output) const PB_310_OVERRIDE;
    int GetCachedSize() const PB_422_OVERRIDE { return ByteSize(); }

protected:
    ::google::protobuf::Metadata GetMetadata() const PB_422_OVERRIDE;

private:
    void SharedCtor();
    void SharedDtor();
};

} // namespace brpc

#endif  // BRPC_ESP_MESSAGE_H
