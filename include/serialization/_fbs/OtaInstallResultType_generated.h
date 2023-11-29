// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_OTAINSTALLRESULTTYPE_OPENSHOCK_H_
#define FLATBUFFERS_GENERATED_OTAINSTALLRESULTTYPE_OPENSHOCK_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 26,
             "Non-compatible flatbuffers version included");

namespace OpenShock {

enum class OtaInstallResultType : uint8_t {
  OK = 0,
  FAIL_AND_ROLLBACK = 1,
  FAIL_CRITICALLY = 2,
  MIN = OK,
  MAX = FAIL_CRITICALLY
};

inline const OtaInstallResultType (&EnumValuesOtaInstallResultType())[3] {
  static const OtaInstallResultType values[] = {
    OtaInstallResultType::OK,
    OtaInstallResultType::FAIL_AND_ROLLBACK,
    OtaInstallResultType::FAIL_CRITICALLY
  };
  return values;
}

inline const char * const *EnumNamesOtaInstallResultType() {
  static const char * const names[4] = {
    "OK",
    "FAIL_AND_ROLLBACK",
    "FAIL_CRITICALLY",
    nullptr
  };
  return names;
}

inline const char *EnumNameOtaInstallResultType(OtaInstallResultType e) {
  if (::flatbuffers::IsOutRange(e, OtaInstallResultType::OK, OtaInstallResultType::FAIL_CRITICALLY)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesOtaInstallResultType()[index];
}

}  // namespace OpenShock

#endif  // FLATBUFFERS_GENERATED_OTAINSTALLRESULTTYPE_OPENSHOCK_H_