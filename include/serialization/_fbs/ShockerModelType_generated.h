// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SHOCKERMODELTYPE_OPENSHOCK_SERIALIZATION_TYPES_H_
#define FLATBUFFERS_GENERATED_SHOCKERMODELTYPE_OPENSHOCK_SERIALIZATION_TYPES_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 26,
             "Non-compatible flatbuffers version included");

namespace OpenShock {
namespace Serialization {
namespace Types {

enum class ShockerModelType : uint8_t {
  CaiXianlin = 0,
  PetTrainer = 1,
  MIN = CaiXianlin,
  MAX = PetTrainer
};

inline const ShockerModelType (&EnumValuesShockerModelType())[2] {
  static const ShockerModelType values[] = {
    ShockerModelType::CaiXianlin,
    ShockerModelType::PetTrainer
  };
  return values;
}

inline const char * const *EnumNamesShockerModelType() {
  static const char * const names[3] = {
    "CaiXianlin",
    "PetTrainer",
    nullptr
  };
  return names;
}

inline const char *EnumNameShockerModelType(ShockerModelType e) {
  if (::flatbuffers::IsOutRange(e, ShockerModelType::CaiXianlin, ShockerModelType::PetTrainer)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesShockerModelType()[index];
}

}  // namespace Types
}  // namespace Serialization
}  // namespace OpenShock

#endif  // FLATBUFFERS_GENERATED_SHOCKERMODELTYPE_OPENSHOCK_SERIALIZATION_TYPES_H_
