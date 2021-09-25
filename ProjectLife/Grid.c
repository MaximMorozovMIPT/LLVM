#include "Grid.h"

void PrintGrid(int grid[][WIDTH])
{
    for(int i = 0; i < HEIGHT; ++i)
    {
        for(int j = 0; j < WIDTH; ++j)
        {
            if(grid[i][j])
            {
                putchar('#');
            }
            else 
            {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

void GenerateRandomGrid(int grid[][WIDTH])
{
    srand(time(NULL));
    for(int i = 0; i < HEIGHT; ++i)
    {
        for(int j = 0; j < WIDTH; ++j)
        {
            int r = rand() % 2;
            grid[i][j] = r;
        }
    }
}

void GenerateEmptyGrid(int grid[][WIDTH])
{
    for(int i = 0; i < HEIGHT; ++i)
    {
        for(int j = 0; j < WIDTH; ++j)
        {
            grid[i][j] = 0;
        }
    }
}

void UpdateGrid(int grid[][WIDTH])
{
    int neighboursGrid[HEIGHT][WIDTH];
    for(int i = 0; i < HEIGHT; ++i)
    {
        for(int j = 0; j < WIDTH; ++j)
        {
            neighboursGrid[i][j] = CountNeighbours(grid, i, j);
        }
    }

    for(int i = 0; i < HEIGHT; ++i)
    {
        for(int j = 0; j < WIDTH; ++j)
        {
            if(grid[i][j] == 0 && neighboursGrid[i][j] == 3)
            {
                grid[i][j] = 1;
            }
            if(grid[i][j] == 1 && (neighboursGrid[i][j] > 3 || neighboursGrid[i][j] < 2))
            {
                grid[i][j] = 0;
            }
        }
    }
}

int CountNeighbours(int grid[][WIDTH], int y, int x)
{
    int neighboursNumber = 0;

    struct pair left_top = {x - 1, y - 1};
    struct pair mid_top = {x, y - 1};
    struct pair right_top = {x + 1, y - 1};
    struct pair left_middle = {x - 1, y};
    struct pair right_middle = {x + 1, y};
    struct pair left_bottom = {x - 1, y + 1};
    struct pair mid_bottom = {x, y + 1};
    struct pair right_bottom = {x + 1, y + 1};

    neighboursNumber += CheckNeighbour(grid, left_top);
    neighboursNumber += CheckNeighbour(grid, mid_top);
    neighboursNumber += CheckNeighbour(grid, right_top);
    neighboursNumber += CheckNeighbour(grid, left_middle);
    neighboursNumber += CheckNeighbour(grid, right_middle);
    neighboursNumber += CheckNeighbour(grid, left_bottom);
    neighboursNumber += CheckNeighbour(grid, mid_bottom);
    neighboursNumber += CheckNeighbour(grid, right_bottom);
    return neighboursNumber;
}

int CheckNeighbour(int grid[][WIDTH], struct pair cell)
{   
    if (cell.x < 0)
    {
        cell.x = WIDTH - 1;
    }

    if (cell.x >= WIDTH)
    {
        cell.x = 0;
    }

    if (cell.y < 0)
    {
        cell.y = HEIGHT - 1;
    }

    if (cell.y >= HEIGHT)
    {
        cell.y = 0;
    }

    return grid[cell.y][cell.x];
}

void CreatePlaner(int grid[][WIDTH])
{
    grid[0][0] = 1;
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[2][0] = 1;
    grid[2][1] = 1;
}