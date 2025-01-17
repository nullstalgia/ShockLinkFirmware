#pragma once

#include <nonstd/span.hpp>

#include <esp32-hal-rmt.h>

#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <freertos/task.h>

#include <cstdint>

namespace OpenShock {
  class RGBPatternManager {
  public:
    RGBPatternManager(std::uint8_t gpioPin);
    ~RGBPatternManager();

    struct RGBState {
      std::uint8_t red;
      std::uint8_t green;
      std::uint8_t blue;
      std::uint32_t duration;
    };

    void SetPattern(nonstd::span<const RGBState> pattern);
    void SetBrightness(std::uint8_t brightness);
    void ClearPattern();

  private:
    void ClearPatternInternal();
    void SendRGB(const RGBState state);
    static void RunPattern(void* arg);

    std::uint8_t m_rgbPin;
    std::uint8_t m_rgbBrightness;  // 0-255
    rmt_obj_t* m_rmtHandle;
    RGBState* m_pattern;
    std::size_t m_patternLength;
    TaskHandle_t m_taskHandle;
    SemaphoreHandle_t m_taskSemaphore;
  };
}  // namespace OpenShock
