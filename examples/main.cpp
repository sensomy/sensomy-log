#include <Arduino.h>
#include <sensomy/log.h>

#define LOG_TAG Main  // All log messages from this file will have the "Main" included

void setup() {
  Serial.begin(SERIAL_SPEED);
  Serial.println();

  LOG(INFO, "Hello!");

  LOG(WARN, "This is a warning");
  LOG(ERROR, "This is an error");
  LOG(INFO, "We can use printf args: %d %x %s", 1, 0xddee, "arg");

  // The message below not be visible if log level is set to LOG_LEVEL_INFO or higher
  LOG(DEBUG, "Debug", 1, 0xddee, "arg");
}

void loop() {}
