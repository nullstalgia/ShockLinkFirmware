#include "CommandHandler.h"

#include "RFTransmitter.h"

#include <LittleFS.h>

#include <memory>

const char* const TAG = "CommandHandler";

using namespace ShockLink;

static std::unique_ptr<RFTransmitter> s_rfTransmitter = nullptr;

void CommandHandler::Init() {
  int rmtPin = 15;
  if (LittleFS.exists("/rmtPin")) {
    File rmtPinFile = LittleFS.open("/rmtPin", FILE_READ);
    rmtPin          = rmtPinFile.readString().toInt();
    rmtPinFile.close();
  }
  ESP_LOGD(TAG, "RMT pin is: %d", rmtPin);

  s_rfTransmitter = std::make_unique<RFTransmitter>(rmtPin, 32);
}

bool CommandHandler::HandleCommand(std::uint16_t shockerId,
                                   std::uint8_t method,
                                   std::uint8_t intensity,
                                   unsigned int duration,
                                   std::uint8_t shockerModel) {
  if (s_rfTransmitter == nullptr) return false;

  // Stop logic
  bool isStop = method == 0;
  if (isStop) {
    method    = 2;  // Vibrate
    intensity = 0;
    duration  = 300;

    s_rfTransmitter->ClearPendingCommands();
  }

  return s_rfTransmitter->SendCommand(shockerModel, shockerId, method, intensity, duration);
}