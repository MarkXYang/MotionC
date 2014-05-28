#ifndef SERIALMESSAGE_H
#define SERIALMESSAGE_H
#include "StreamOutput.h"
struct SerialMessage {
        StreamOutput* stream;
        std::string message;
};
#endif
