#include "config/RootConfig.h"

#include "Logging.h"

const char* const TAG = "Config::RootConfig";

using namespace OpenShock::Config;

void RootConfig::ToDefault() {
  rf.ToDefault();
  wifi.ToDefault();
  captivePortal.ToDefault();
  backend.ToDefault();
}

bool RootConfig::FromFlatbuffers(const Serialization::Configuration::Config* config) {
  if (config == nullptr) {
    ESP_LOGE(TAG, "config is null");
    return false;
  }

  if (!rf.FromFlatbuffers(config->rf())) {
    ESP_LOGE(TAG, "Unable to load rf config");
    return false;
  }

  if (!wifi.FromFlatbuffers(config->wifi())) {
    ESP_LOGE(TAG, "Unable to load wifi config");
    return false;
  }

  if (!captivePortal.FromFlatbuffers(config->captive_portal())) {
    ESP_LOGE(TAG, "Unable to load captive portal config");
    return false;
  }

  if (!backend.FromFlatbuffers(config->backend())) {
    ESP_LOGE(TAG, "Unable to load backend config");
    return false;
  }

  return true;
}

flatbuffers::Offset<OpenShock::Serialization::Configuration::Config> RootConfig::ToFlatbuffers(flatbuffers::FlatBufferBuilder& builder) const {
  return Serialization::Configuration::CreateConfig(builder, rf.ToFlatbuffers(builder), wifi.ToFlatbuffers(builder), captivePortal.ToFlatbuffers(builder), backend.ToFlatbuffers(builder));
}

bool RootConfig::FromJSON(const cJSON* json) {
  if (json == nullptr) {
    ESP_LOGE(TAG, "json is null");
    return false;
  }

  if (!cJSON_IsObject(json)) {
    ESP_LOGE(TAG, "json is not an object");
    return false;
  }

  if (!rf.FromJSON(cJSON_GetObjectItemCaseSensitive(json, "rf"))) {
    ESP_LOGE(TAG, "Unable to load rf config");
    return false;
  }

  if (!wifi.FromJSON(cJSON_GetObjectItemCaseSensitive(json, "wifi"))) {
    ESP_LOGE(TAG, "Unable to load wifi config");
    return false;
  }

  if (!captivePortal.FromJSON(cJSON_GetObjectItemCaseSensitive(json, "captivePortal"))) {
    ESP_LOGE(TAG, "Unable to load captive portal config");
    return false;
  }

  if (!backend.FromJSON(cJSON_GetObjectItemCaseSensitive(json, "backend"))) {
    ESP_LOGE(TAG, "Unable to load backend config");
    return false;
  }

  return true;
}

cJSON* RootConfig::ToJSON() const {
  cJSON* root = cJSON_CreateObject();

  cJSON_AddItemToObject(root, "rf", rf.ToJSON());
  cJSON_AddItemToObject(root, "wifi", wifi.ToJSON());
  cJSON_AddItemToObject(root, "captivePortal", captivePortal.ToJSON());
  cJSON_AddItemToObject(root, "backend", backend.ToJSON());

  return root;
}
