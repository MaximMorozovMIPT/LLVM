#include "Buffer.h"

const char *bufferFileName = "/dev/fb0";

void GetBuff(int grid[][WIDTH], struct RGBPoint* buff)
{
    struct RGBPoint white = {200, 200, 200, 0};

    struct RGBPoint black = {0, 0, 0 , 0};

    int koef = 4;
    for(int i = 0; i < HEIGHT; ++i)
    {
        for(int j = 0; j < WIDTH; ++j)
        {
            if(grid[i][j] == 1)
            {
                for(int k = 0; k < koef; k++)
                {
                    buff[(koef * i + k) * WIDTH_BUFF + j * koef] = white;
                    buff[(koef * i + k) * WIDTH_BUFF + j * koef + 1] = white;
                    buff[(koef * i + k) * WIDTH_BUFF + j * koef + 2] = white;
                    buff[(koef * i + k) * WIDTH_BUFF + j * koef + 3] = white;
                }
            }
            else
            {
                for(int k = 0; k < koef; k++)
                {
                    buff[(koef * i + k) * WIDTH_BUFF + j * koef] = black;
                    buff[(koef * i + k) * WIDTH_BUFF + j * koef + 1] = black;
                    buff[(koef * i + k) * WIDTH_BUFF + j * koef + 2] = black;
                    buff[(koef * i + k) * WIDTH_BUFF + j * koef + 3] = black;
                }
            }
            
        }
    }
    // printf("%d %d %d %d \n", buff[0].blue, buff[0].green, buff[0].red, buff[0].alpha);
}


int flushBuff(struct RGBPoint* buff) {
    int bufferDescriptor = open(bufferFileName, O_WRONLY);
    if (bufferDescriptor == -1) {
        fprintf(stderr, "Failed to open /dev/fb0\n");
        return -1;
    }

    if (write(bufferDescriptor, (void*)(buff), WIDTH_BUFF * HEIGHT_BUFF * sizeof(struct RGBPoint)) != -1) {
        printf("Writed to buf");
    }
    // printf("Flushed on step %lld\n", controller->timeIndex);
    // if (close(bufferDescriptor)) {
    //     fprintf(stderr, "Failed to close /dev/fb0\n");
    //     return -2;
    // }
    return 0;
}