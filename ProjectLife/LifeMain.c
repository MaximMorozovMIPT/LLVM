#include "Grid.h"
#include "Buffer.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Enter mode\n");
        exit(1);
    }
    int type = atoi(argv[1]);

    int grid[HEIGHT][WIDTH];
    if(type == 0)
    {
        GenerateRandomGrid(grid);
        PrintGrid(grid);
        for (int i = 0; i < 120; ++i)
        {
            sleep(1);
            printf("\x1b[30A");
            UpdateGrid(grid);
            PrintGrid(grid);
        }
    }

    if(type == 1)
    {
        GenerateEmptyGrid(grid);
        CreatePlaner(grid);
        PrintGrid(grid);
        for (int i = 0; i < 120; ++i)
        {
            sleep(1);
            printf("\x1b[30A");
            UpdateGrid(grid);
            PrintGrid(grid);
        }
    }
    if(type == 2)
    {
        struct RGBPoint* buff = (struct RGBPoint *)calloc(WIDTH_BUFF * HEIGHT_BUFF, sizeof(struct RGBPoint));
        GenerateRandomGrid(grid);
        GetBuff(grid, buff);
        flushBuff(buff);
        for (int i = 0; i < 120; ++i)
        {
            sleep(1);
            UpdateGrid(grid);
            GetBuff(grid, buff);
            flushBuff(buff);
        }
    }

    return 0;
}

