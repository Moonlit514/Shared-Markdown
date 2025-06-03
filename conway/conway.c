/**
 * @file conway.c
 * @brief Conway 生命游戏核心逻辑实现
 * @author Yang Zichen
 */

#include "conway.h"
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

struct World world; /**< 全局世界实例 */
int boundary = 0;   /**< 边界模式（默认闭合） */

/**
 * @brief 初始化细胞世界
 * @param _w 世界宽度
 * @param _h 世界高度
 */
void init_cells(int _w, int _h)
{
    world.width = _w;
    world.height = _h;

    // 分配二维数组内存
    world.cell = (int **)malloc(_h * sizeof(int *));
    for (int i = 0; i < _h; i++)
    {
        world.cell[i] = (int *)calloc(_w, sizeof(int));
    }
}

/**
 * @brief 随机设置细胞状态（50% 存活率）
 */
void set_rand_cells()
{
    srand(time(NULL));
    for (int y = 0; y < world.height; y++)
    {
        for (int x = 0; x < world.width; x++)
        {
            world.cell[y][x] = rand() % 2;
        }
    }
}

/**
 * @brief 从 RLE 文件加载图案到指定坐标
 * @param _x 起始x坐标
 * @param _y 起始y坐标
 * @param rle_file RLE格式文件路径
 */
void load_pattern(int _x, int _y, char *rle_file)
{
    FILE *file = fopen(rle_file, "r");
    if (file == NULL)
    {
        exit(1);
    }
    int w, h;
    int k = 0;
    char pattern[1000];
    int **cell = world.cell;
    if (file != NULL)
    {
        char line[256];
        while (fgets(line, sizeof(line), file))
        {
            if (line[0] == '#')
            {
                continue;
            }
            else if (line[0] == 'x')
            {
                sscanf(line, "x = %d, y = %d", &w, &h);
            }
            else if (line[0] == 'b' ||
                     line[0] == 'o' ||
                     line[0] == '!' ||
                     line[0] == '$' ||
                     isdigit(line[0]))
            {
                for (int i = 0; i < strlen(line); i++)
                {
                    pattern[k] = line[i];
                    k++;
                }
            }
        }
    }
    else
    {
        printf("File not found\n");
    }
    pattern[k] = '\0';
    int px = _x;
    int py = _y;

    for (int i = 0; i < strlen(pattern); i++)
    {
        int count = 0;
        if (isdigit(pattern[i]))
        {
            while (isdigit(pattern[i]))
            {
                count = count * 10 + (pattern[i] - '0');
                i++;
            }
        }
        if (pattern[i] == 'b')
        {
            if (count == 0)
                count = 1;
            for (int j = 0; j < count; j++)
            {
                cell[py][px] = 0; // cell[x][y]
                py++;
            }
        }
        else if (pattern[i] == 'o')
        {
            if (count == 0)
                count = 1;
            for (int j = 0; j < count; j++)
            {
                cell[py][px] = 1; // cell[x][y]
                py++;
            }
        }
        else if (pattern[i] == '$')
        {
            px++;
            py = _y;
        }
        else if (pattern[i] == '!')
        {
            break;
        }
    }

    fclose(file);
}


/**
 * @brief 计算细胞周围存活邻居数
 * @param x 目标细胞x坐标
 * @param y 目标细胞y坐标
 * @return 存活邻居数量
 */
int count_neighbors(int x, int y)
{
    int count = 0;
    for (int dy = -1; dy <= 1; dy++)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            if (dx == 0 && dy == 0)
            {
                continue;
            }

            int nx = x + dx;
            int ny = y + dy;

            // 边界处理
            if (boundary == 1)
            { // 循环边界
                nx = (nx + world.width) % world.width;
                ny = (ny + world.height) % world.height;
            }
            else
            { // 闭合边界
                if (nx < 0 || nx >= world.width || ny < 0 || ny >= world.height)
                    continue;
            }

            count += world.cell[ny][nx];
        }
    }
    return count;
}

/**
 * @brief 更新细胞状态（遵循生命游戏规则）
 */
void update_cells()
{
    int **new = (int **)malloc(world.height * sizeof(int *));
    for (int i = 0; i < world.height; i++)
    {
        new[i] = (int *)malloc(world.width * sizeof(int));
    }

    for (int y = 0; y < world.height; y++)
    {
        for (int x = 0; x < world.width; x++)
        {
            int neighbors = count_neighbors(x, y);
            if (world.cell[y][x])
            {
                new[y][x] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            }
            else
            {
                new[y][x] = (neighbors == 3) ? 1 : 0;
            }
        }
    }

    // 替换旧细胞数组
    for (int i = 0; i < world.height; i++)
    {
        free(world.cell[i]);
        world.cell[i] = new[i];
    }
    free(new);
}

/**
 * @brief 释放细胞数组内存
 */
void free_cells()
{
    for (int i = 0; i < world.height; i++)
    {
        free(world.cell[i]);
    }
    free(world.cell);
}

/**
 * @brief 使用 ncurses 绘制细胞世界
 */
void draw_cells()
{
    clear();
    for (int y = 0; y < world.height; y++)
    {
        for (int x = 0; x < world.width; x++)
        {
            mvaddch(y, x, world.cell[y][x] ? '#' : ' '); // 绘制细胞（#表示存活）
        }
    }
    refresh();
}