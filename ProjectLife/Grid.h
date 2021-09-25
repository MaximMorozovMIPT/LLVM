#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

struct pair
{
    int x;
    int y;
};

#define WIDTH 30
#define HEIGHT 30
#define WIDTH_BUFF 120
#define HEIGHT_BUFF 120

void GenerateRandomGrid(int grid[][WIDTH]);
void GenerateEmptyGrid(int grid[][WIDTH]);
void CreatePlaner(int grid[][WIDTH]);
void PrintGrid(int grid[][WIDTH]);
void UpdateGrid(int grid[][WIDTH]);
int CountNeighbours(int grid[][WIDTH], int y, int x);
int CheckNeighbour(int grid[][WIDTH], struct pair cell);
