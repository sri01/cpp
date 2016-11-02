/*
 * TestHeader.h
 *
 *  Created on: 02-Nov-2016
 *      Author: sirisha
 */
#ifndef TEST_HEADER_H_
#define TEST_HEADER_H_

#include <iostream>
#include <string>
#include <set>


#if 0
class Logger {

public:
    Logger();
    ~Logger();
    void info(string fileName, int lineNum, string msg);

private: // trial run to see logMessage properly handles it
    logMessage(string level, string fileName, int lineNum, string msg);

};

class LogMessages {
 public:
    LogMessages();
    ~LogMessages();

    static string InitLogMessages[] = \
                { "Initiating Logger...", \
                    "Second Logger Constructor message...",
                    "Destructor Initiated..."
                };

    static string MessageDelimitor = { ":", "(", ")", }; // check , is required at the end

};

Logger::Logger() {

    cout << "\t " << __func__ << "(" << __LINE__<< ")" << LogMessages::InitLogMessages[0] << endl;
}

Logger::~Logger() {
    cout << "\t " << __func__ << "(" << __LINE__<< ")" << LogMessages::InitLogMessages[2] << endl;
}

Logger::logMessage(string level, string methodName, int lineNum, string msg) {
    cout << level << \
            LogMessages::MessageDelimitor[0] << \
            LogMessages::MessageDelimitor[1] <<  methodName << LogMessages::MessageDelimitor[0] << lineNum << \
            << LogMessages::MessageDelimitor[2] << \
            msg << \
            << endl;
}

Logger::info(info(string methodName, int lineNum, string msg) {
    logMessage("INFO", methodName, lineNum, msg);
}
#endif

#endif // TEST_HEADER_H_
