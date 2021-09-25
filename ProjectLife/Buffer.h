#pragma once

#include "Grid.h"
#include <stdint.h>
#include <fcntl.h>

struct RGBPoint{
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t alpha;
};

void GetBuff(int grid[][WIDTH], struct RGBPoint* buff);
int flushBuff(struct RGBPoint* buff);