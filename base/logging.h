#ifndef BASE_LOGGING_H__
#define BASE_LOGGING_H__

#include <iostream>
#include "base/basictypes.h"

namespace logging {

#define ERROR_LOG \
  std::cerr << "[" << __FILE__ << "(" << "__LINE__" << ")] "

#define ERROR_LOG_IF(condition) \
  !(condition) ? (void) 0 : logging::LogMessageVoidify() & ERROR_LOG

#define DCHECK(condition) \
  ERROR_LOG_IF(!(condition)) << "Check failed: " #condition ". "

#define NOTREACHED() DCHECK(false)

class LogMessageVoidify {
  public:
    LogMessageVoidify() {}
    void operator&(std::ostream&) {}
};

} // namespace Logging

#endif  // BASE_LOGGING_H__
