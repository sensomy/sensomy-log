#ifndef SENSOMY_BASE_LOG_H_
#define SENSOMY_BASE_LOG_H_

#include <HardwareSerial.h>
#include <inttypes.h>

#define LOG_LEVEL_ALL 0
#define LOG_LEVEL_DEBUG 10
#define LOG_LEVEL_INFO 20
#define LOG_LEVEL_WARN 30
#define LOG_LEVEL_ERROR 40
#define LOG_LEVEL_FATAL 50
#define LOG_LEVEL_NONE 100

#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_ALL
#endif

#if LOG_LEVEL != LOG_LEVEL_NONE

#if defined(ESP8266)

#ifndef LOG_OBJECT
#define LOG_OBJECT Serial
#endif

#ifndef LOG_METHOD
#define LOG_METHOD printf_P
#endif

#define LOG_FUNCTION(format, ...) LOG_OBJECT.LOG_METHOD(PSTR(format), ##__VA_ARGS__)

#else  // __ESP8266__

#ifndef LOG_OBJECT
#define LOG_OBJECT Serial
#endif

#ifndef LOG_METHOD
#define LOG_METHOD printf
#endif

#define LOG_FUNCTION(format, ...) LOG_OBJECT.LOG_METHOD(F(format), ##__VA_ARGS__)

#endif  // ESP8266

#define LEVEL_LOG(level, tag, format, ...) \
  LOG_FUNCTION("%5S %S:%" PRIu16 " " format "\n", F(#level), F(#tag), __LINE__, ##__VA_ARGS__)

#endif  // LOG_LEVEL != LOG_LEVEL_NONE

#if LOG_LEVEL <= LOG_LEVEL_DEBUG
#define LOG_DEBUG(tag, format, ...) LEVEL_LOG(DEBUG, tag, format, ##__VA_ARGS__)
#else
#define LOG_DEBUG(tag, format, ...)
#endif

#if LOG_LEVEL <= LOG_LEVEL_INFO
#define LOG_INFO(tag, format, ...) LEVEL_LOG(INFO, tag, format, ##__VA_ARGS__)
#else
#define LOG_INFO(tag, format, ...)
#endif

#if LOG_LEVEL <= LOG_LEVEL_WARN
#define LOG_WARN(tag, format, ...) LEVEL_LOG(WARN, tag, format, ##__VA_ARGS__)
#else
#define LOG_WARN(tag, format, ...)
#endif

#if LOG_LEVEL <= LOG_LEVEL_ERROR
#define LOG_ERROR(tag, format, ...) LEVEL_LOG(ERROR, tag, format, ##__VA_ARGS__)
#else
#define LOG_ERROR(tag, format, ...)
#endif

#if LOG_LEVEL <= LOG_LEVEL_FATAL
#define LOG_FATAL(tag, format, ...) LEVEL_LOG(FATAL, tag, format, ##__VA_ARGS__)
#else
#define LOG_FATAL(tag, format, ...)
#endif

#define TAG_LOG(level, tag, format, ...) LOG_##level(tag, format, ##__VA_ARGS__)

#define LOG(level, format, ...) TAG_LOG(level, LOG_TAG, format, ##__VA_ARGS__)

#endif  // SENSOMY_BASE_LOG_H_
