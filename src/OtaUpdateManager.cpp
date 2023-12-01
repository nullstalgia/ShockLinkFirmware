#include "OtaUpdateManager.h"

#include "config/Config.h"
#include "GatewayConnectionManager.h"
#include "Logging.h"
#include "wifi/WiFiManager.h"

#include <esp_ota_ops.h>

#include <LittleFS.h>
#include <WiFi.h>

/// @brief Stops initArduino() from handling OTA rollbacks
/// @todo Get rid of Arduino entirely. >:(
///
/// @see .platformio/packages/framework-arduinoespressif32/cores/esp32/esp32-hal-misc.c
/// @return true
bool verifyRollbackLater() {
  return true;
}

using namespace OpenShock;

const char* TAG = "OtaUpdateManager";

static OtaUpdateManager::BootMode s_bootMode = OtaUpdateManager::BootMode::NORMAL;
static OtaUpdateManager::UpdateState s_state = OtaUpdateManager::UpdateState::NONE;

void OtaUpdateManager::Init() {
  ESP_LOGD(TAG, "Fetching current partition");

  // Fetch current partition info.
  const esp_partition_t* partition = esp_ota_get_running_partition();

  ESP_LOGD(TAG, "Fetching partition state");

  // Get OTA state for said partition.
  esp_ota_img_states_t states;
  esp_ota_get_state_partition(partition, &states);

  ESP_LOGD(TAG, "Partition state: %u", states);

  // If the currently booting partition is being verified, set correct state.
  s_bootMode = OtaUpdateManager::BootMode::NORMAL;
  if (states == ESP_OTA_IMG_PENDING_VERIFY) {
    s_bootMode = OtaUpdateManager::BootMode::OTA_UPDATE;
  }
}

void OtaUpdateManager::LoadConfig() {
  // Mount LittleFS.
  if (!LittleFS.begin(true, "littlefs", 10U, "config")) {
    // Invalidate update partition and restart.
    ESP_PANIC_OTA(TAG, "Could not mount LittleFS");
  }

  // Load config while LittleFS is mounted.
  OpenShock::Config::Init();

  // Unmount LittleFS, as we will be reflashing that partition shortly.
  LittleFS.end();
}

bool OtaUpdateManager::SaveConfig() {
  return true;
}

bool OtaUpdateManager::IsPerformingUpdate() {
  return s_bootMode == OtaUpdateManager::BootMode::OTA_UPDATE;
}

OtaUpdateManager::BootMode OtaUpdateManager::GetBootMode() {
  return s_bootMode;
}

OtaUpdateManager::UpdateState OtaUpdateManager::GetState() {
  return s_state;
}
