// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef TINK_HYBRID_HYBRID_DECRYPT_CATALOGUE_H_
#define TINK_HYBRID_HYBRID_DECRYPT_CATALOGUE_H_

#include "cc/hybrid_decrypt.h"
#include "cc/catalogue.h"
#include "cc/key_manager.h"
#include "cc/util/statusor.h"
#include "google/protobuf/stubs/stringpiece.h"

namespace crypto {
namespace tink {

///////////////////////////////////////////////////////////////////////////////
// A catalogue of Tink HybridDecrypt key mangers.
class HybridDecryptCatalogue : public Catalogue<HybridDecrypt> {
 public:
  HybridDecryptCatalogue() {}

  crypto::tink::util::StatusOr<std::unique_ptr<KeyManager<HybridDecrypt>>>
  GetKeyManager(google::protobuf::StringPiece type_url,
                google::protobuf::StringPiece primitive_name,
                uint32_t min_version) const;
};

}  // namespace tink
}  // namespace crypto

#endif  // TINK_HYBRID_HYBRID_DECRYPT_CATALOGUE_H_
