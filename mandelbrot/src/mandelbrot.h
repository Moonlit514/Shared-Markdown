/**
 * @file mandelbrot.h
 * @brief Mandelbrot 集计算函数声明
 * @author Yang Zichen
 */

#ifndef MANDELBROT_H
#define MANDELBROT_H

/**
 * @brief 计算Mandelbrot迭代次数
 *
 * @param real 复平面实部坐标
 * @param imag 复平面虚部坐标
 * @param max_iters 最大迭代次数
 * @return int 实际迭代次数 (达到max_iters时返回max_iters)
 */
int mandelbrot(double real, double imag, int max_iters);

#endif