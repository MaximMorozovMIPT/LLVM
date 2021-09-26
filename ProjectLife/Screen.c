#include "Grid.h"


void PrintScreen(int grid[][WIDTH])
{
    int koef = 4;
    for(int i = 0; i < HEIGHT; ++i)
    {
        for(int j = 0; j < WIDTH; ++j)
        {
            if(grid[i][j] == 1)
            {
                for(int k = 0; k < koef; k++)
                {
                    putpixel(j * koef, koef * i + k, 2);
                    putpixel(j * koef + 1, koef * i + k, 2);
                    putpixel(j * koef + 2, koef * i + k, 2);
                    putpixel(j * koef + 3, koef * i + k, 2);
                }
            }
            // else
            // {
            //     for(int k = 0; k < koef; k++)
            //     {
            //         putpixel(j * koef, koef * i + k, 1);
            //         putpixel(j * koef + 1, koef * i + k, 1);
            //         putpixel(j * koef + 2, koef * i + k, 1);
            //         putpixel(j * koef + 3, koef * i + k, 1);
            //     }
            // }
            
        }
    }
}