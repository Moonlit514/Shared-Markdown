/**
 * @file mandelbrot.c
 * @brief Mandelbrot 集核心计算逻辑
 * @author Yang Zichen
 */

#include "mandelbrot.h"
#include <math.h>

/**
 * @brief 计算Mandelbrot迭代次数
 * @param real 复平面实部坐标
 * @param imag 复平面虚部坐标
 * @param max_iters 最大迭代次数
 * @return int 实际迭代次数 (达到max_iters时返回max_iters)
 */
int mandelbrot(double real, double imag, int max_iters)
{
    double z_real = 0.0, z_imag = 0.0;
    double z_real_sq = 0.0, z_imag_sq = 0.0;

    int i = 0;
    for (; i < max_iters; i++)
    {
        z_imag = 2 * z_real * z_imag + imag;
        z_real = z_real_sq - z_imag_sq + real;

        z_real_sq = z_real * z_real;
        z_imag_sq = z_imag * z_imag;

        if ((z_real_sq + z_imag_sq) > 4.0)
        {
            return i + 1;
        }
    }

    return max_iters;
}