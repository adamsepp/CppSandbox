#include "Logger.h"

void Logger::PushToBuffer(LogLevel level, const std::string& message)
{
    LogMessage logMessage(level, message);
    logBuffer.Push(logMessage);

    // Optional: immediate output for dev/debug
    // Write(logMessage);

    scrollToBottom.store(true);
}

void Logger::Write(const LogMessage& message)
{
    std::string prefix;

    switch (message.level)
    {
    case LogLevel::Info:
        prefix = "[INFO] ";
        break;
    case LogLevel::Warning:
        prefix = "[WARNING] ";
        break;
    case LogLevel::Error:
        prefix = "[ERROR] ";
        break;
    case LogLevel::Debug:
        prefix = "[DEBUG] ";
        break;
    }

    // TODO: write into file later...
    // std::cout << prefix << message.message << std::endl;
}
