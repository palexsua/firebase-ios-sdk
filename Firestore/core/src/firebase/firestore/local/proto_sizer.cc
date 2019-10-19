/*
 * Copyright 2019 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Firestore/core/src/firebase/firestore/local/proto_sizer.h"

#include <utility>

#include "Firestore/Protos/nanopb/firestore/local/maybe_document.nanopb.h"
#include "Firestore/core/src/firebase/firestore/model/document_key.h"
#include "Firestore/core/src/firebase/firestore/model/maybe_document.h"
#include "Firestore/core/src/firebase/firestore/nanopb/byte_string.h"
#include "Firestore/core/src/firebase/firestore/nanopb/message.h"

namespace firebase {
namespace firestore {
namespace local {

using model::DocumentKey;
using model::MaybeDocument;
using nanopb::ByteString;
using nanopb::Message;

ProtoSizer::ProtoSizer(LocalSerializer serializer)
    : serializer_(std::move(serializer)) {
}

int64_t ProtoSizer::CalculateByteSize(const MaybeDocument& maybe_doc) const {
  // TODO(varconst): implement a version of `nanopb::Writer` that only
  // calculates sizes without actually doing the encoding (to the extent
  // possible). This isn't high priority as long as `ProtoSizer` is only used in
  // tests.
  return serializer_.EncodeMaybeDocument(maybe_doc).ToByteString().size();
}

int64_t ProtoSizer::CalculateByteSize(const model::MutationBatch& batch) const {
  return serializer_.EncodeMutationBatch(batch).ToByteString().size();
}

int64_t ProtoSizer::CalculateByteSize(const QueryData& query_data) const {
  return serializer_.EncodeQueryData(query_data).ToByteString().size();
}

}  // namespace local
}  // namespace firestore
}  // namespace firebase
