#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "conway.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s width height rle_file[|rand]\n", argv[0]);
        return 1;
    }
    boundary = 0;    // 闭合边界
    initscr();       // 初始化curses库
    noecho();        // 关闭输入回显
    curs_set(FALSE); // 隐藏光标
    //    禁止行缓冲，使得getch立即返回
    cbreak();
    //    设置非阻塞模式
    nodelay(stdscr, TRUE);

    init_cells(atoi(argv[1]), atoi(argv[2])); // 初始化细胞状态
    if (argc < 4)
    {
        set_rand_cells();
    }
    else
    {
        load_pattern(0, 0, argv[3]);
    }

    int width = world.width;
    int height = world.height;
    int **cell = world.cell;

    while (1)
    {
        clear();        // 清除屏幕
        draw_cells();   // 绘制细胞
        refresh();      // 刷新屏幕，将绘制的细胞显示出来
        usleep(10000);  // 睡眠一段时间，控制游戏速度
        update_cells(); // 更新细胞状态
        usleep(10000);  // 睡眠一段时间，控制游戏速度
        if (getch() == 'q')
        {
            break;
        }
    }
    endwin(); // 结束curses模式

    free_cells(); // 释放细胞数组内存
    return 0;
}