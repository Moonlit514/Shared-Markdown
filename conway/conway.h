/**
 * @file conway.h
 * @brief Conway 生命游戏的核心数据结构和函数声明
 * @author Yang Zichen
 */

#ifndef CONWAY_H
#define CONWAY_H

#include <ncurses.h> // 用于绘制函数声明（如 mvaddch）

//-----------------------------------------------------------------------------
// 数据结构定义
//-----------------------------------------------------------------------------

/**
 * @brief 表示生命游戏的世界状态
 * @struct World
 *
 * 包含世界的尺寸和细胞状态二维数组。
 */
struct World
{
    int width;  /**< 世界宽度 */
    int height; /**< 世界高度 */
    int **cell; /**< 二维数组每一个元素都代表一个细胞，0 表示死亡，1 表示存活 */
};

//-----------------------------------------------------------------------------
// 全局变量声明
//-----------------------------------------------------------------------------

/**
 * @brief 全局世界实例，定义在 conway.c 中
 */
extern struct World world;

/**
 * @brief 边界模式，0 表示边界闭合，1表示边界循环
 * @note 默认值为 0，定义在 conway.c 中
 */
extern int boundary;

//-----------------------------------------------------------------------------
// 函数声明
//-----------------------------------------------------------------------------

/**
 * @brief 初始化细胞世界
 * @param width 世界宽度（必须 > 0）
 * @param height 世界高度（必须 > 0）
 */
void init_cells(int width, int height);

/**
 * @brief 随机设置细胞状态（存活率 50%）
 * @note 依赖 srand 初始化随机种子
 */
void set_rand_cells();

/**
 * @brief 从 RLE 文件加载图案
 * @param start_x 起始x坐标（相对于世界左上角）
 * @param start_y 起始y坐标（相对于世界左上角）
 * @param rle_file RLE格式文件路径
 */
void load_pattern(int _x, int _y, char *rle_file);

/**
 * @brief 使用 ncurses 绘制当前细胞状态
 * @note 需先初始化 ncurses 环境
 */
void draw_cells();

/**
 * @brief 计算目标细胞的存活邻居数
 * @param x 目标细胞x坐标（0 ≤ x < width）
 * @param y 目标细胞y坐标（0 ≤ y < height）
 * @return 存活邻居数量（范围 0-8）
 * @note 自动处理边界条件（依赖 boundary 全局变量）
 */
int count_neighbors(int x, int y);

/**
 * @brief 更新所有细胞状态（遵循Conway规则）
 * @details 通过比较当前状态与邻居数量决定生死：
 * - 存活细胞：2-3个邻居时存活，否则死亡
 * - 死亡细胞：恰好3个邻居时复活
 */
void update_cells();

/**
 * @brief 释放细胞数组内存
 * @note 必须在程序结束前调用
 */
void free_cells();

#endif // CONWAY_H