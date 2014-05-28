#ifndef HOOK_H
#define HOOK_H
#include "mbed.h"
#include "FPointer.h"

// Hook is just a glorified FPointer

class Hook : public FPointer {
    public:
        Hook();
        int     interval;
        int     countdown;
};

#endif
