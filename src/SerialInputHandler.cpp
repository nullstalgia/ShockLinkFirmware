#include "SerialInputHandler.h"

#include "FileUtils.h"

#include <Esp.h>
#include <HardwareSerial.h>

using namespace ShockLink;

int findChar(const char* buffer, std::size_t bufferSize, char c) {
  for (int i = 0; i < bufferSize; i++) {
    if (buffer[i] == c) {
      return i;
    }
  }

  return -1;
}
int findLineEnd(const char* buffer, int bufferSize) {
  for (int i = 0; i < bufferSize; i++) {
    if (buffer[i] == '\r' || buffer[i] == '\n' || buffer[i] == '\0') {
      return i;
    }
  }

  return -1;
}
int findLineStart(const char* buffer, int bufferSize, int lineEnd) {
  if (lineEnd < 0) return -1;

  for (int i = lineEnd; i < bufferSize - lineEnd; i++) {
    if (buffer[i] != '\r' && buffer[i] != '\n' && buffer[i] != '\0') {
      return i;
    }
  }

  return -1;
}

void handleSerialCommand(char* command, std::size_t commandLength) {
  if (strcmp(command, "restart") == 0) {
    Serial.println("Restarting ESP...");
    ESP.restart();
    return;
  }

  Serial.println("SYS|Error|Command not found");
}
void handleSerialCommand(char* command, std::size_t commandLength, char* arg, std::size_t argLength) {
  if (strcmp(command, "authtoken") == 0) {
    ShockLink::FileUtils::TryWriteFile("/authToken", arg, argLength);
    return;
  }

  if (strcmp(command, "rmtpin") == 0) {
    ShockLink::FileUtils::TryWriteFile("/rmtPin", arg, argLength);
    return;
  }

  if (strcmp(command, "networks") == 0) {
    ShockLink::FileUtils::TryWriteFile("/networks", arg, argLength);
    return;
  }

  Serial.println("SYS|Error|Command not found");
}
void processSerialLine(char* data, std::size_t length) {
  int delimiter = findChar(data, length, ' ');
  if (delimiter == 0) {
    Serial.println("SYS|Error|Command cannot start with a space");
    return;
  }

  // Handle arg-less commands
  if (delimiter <= 0) {
    handleSerialCommand(data, length);
    return;
  } else {
    length          = delimiter;
    data[delimiter] = '\0';
    handleSerialCommand(data, length, data + delimiter + 1, length - delimiter - 1);
  }
}

void SerialInputHandler::Init() {
  Serial.begin(115'200);
  Serial.setDebugOutput(true);
}

void SerialInputHandler::Update() {
  static char* buffer            = nullptr;  // TODO: Clean up this buffer every once in a while
  static std::size_t bufferSize  = 0;
  static std::size_t bufferIndex = 0;

  while (true) {
    int available = Serial.available();
    if (available <= 0) {
      break;
    }

    if (bufferIndex + available > bufferSize) {
      bufferSize = bufferIndex + available;
      buffer     = static_cast<char*>(realloc(buffer, bufferSize));
    }

    bufferIndex += Serial.readBytes(buffer + bufferIndex, available);

    int lineEnd = findLineEnd(buffer, bufferIndex);
    if (lineEnd == -1) {
      break;
    }

    buffer[lineEnd] = '\0';
    Serial.printf("> %s\n", buffer);

    processSerialLine(buffer, lineEnd);

    int nextLine = findLineStart(buffer, bufferIndex, lineEnd + 1);
    if (nextLine < 0) {
      bufferIndex = 0;
      break;
    }

    int remaining = bufferIndex - nextLine;
    if (remaining > 0) {
      memmove(buffer, buffer + nextLine, remaining);
      bufferIndex = remaining;
    } else {
      bufferIndex = 0;
    }
  }
}