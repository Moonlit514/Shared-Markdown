/**
 * @file test.c
 * @brief Mandelbrot 集图像生成测试程序
 * @author Yang Zichen
 */

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "mandelbrot.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

/**
 * @brief HSV转RGB颜色空间
 * @param h 色相 [0-360]
 * @param s 饱和度 [0-1]
 * @param v 明度 [0-1]
 * @param rgb 输出RGB数组 (0-255)
 */
static void hsv2rgb(double h, double s, double v, unsigned char rgb[3])
{
    double c = v * s;
    double x = c * (1 - fabs(fmod(h / 60, 2) - 1));
    double m = v - c;

    double r, g, b;

    if (h < 60)
    {
        r = c;
        g = x;
        b = 0;
    }
    else if (h < 120)
    {
        r = x;
        g = c;
        b = 0;
    }
    else if (h < 180)
    {
        r = 0;
        g = c;
        b = x;
    }
    else if (h < 240)
    {
        r = 0;
        g = x;
        b = c;
    }
    else if (h < 300)
    {
        r = x;
        g = 0;
        b = c;
    }
    else
    {
        r = c;
        g = 0;
        b = x;
    }

    rgb[0] = (unsigned char)((r + m) * 255);
    rgb[1] = (unsigned char)((g + m) * 255);
    rgb[2] = (unsigned char)((b + m) * 255);
}

int main(int argc, char **argv)
{
    // 图像参数, 可调整
    const int width = 1920;     // 图像宽度
    const int height = 1080;    // 图像高度
    const int max_iters = 5000; // 最大迭代次数
    const int samples = 3;      // 抗锯齿采样, 数值越大越平滑

    unsigned char *image = malloc(width * height * 3);

    // 计算区域: 从 (-1.5, -1) 到 (1.5, 1)
    const double real_min = -1.5, real_max = 1.5;
    const double imag_min = -1.0, imag_max = 1.0;

    const char *format = "bmp"; // 输出格式, 可选择 "bmp", "png", "jpg", 默认使用 bmp 格式
    if (argc > 1 && argv[1] != NULL)
    {
        if (strcmp(argv[1], "png") == 0 || strcmp(argv[1], "jpg") == 0)
        {
            format = argv[1];
        }
        else if (strcmp(argv[1], "bmp") != 0)
        {
            printf("不支持的格式, 将使用 bmp 格式生成.\n");
        }
    }

#pragma omp parallel for
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            double total_iter = 0.0;

            for (int dy = 0; dy < samples; dy++)
            {
                for (int dx = 0; dx < samples; dx++)
                {
                    double sub_x = x + (dx + 0.5) / samples;
                    double sub_y = (height - 1 - y) + (dy + 0.5) / samples;

                    double real = real_min + sub_x * (real_max - real_min) / width;
                    double imag = imag_min + sub_y * (imag_max - imag_min) / height;

                    total_iter += mandelbrot(real, imag, max_iters);
                }
            }

            int avg_iter = total_iter / (samples * samples);
            int idx = (y * width + x) * 3;

            if (avg_iter == max_iters)
            {
                image[idx] = 0;
                image[idx + 1] = 0;
                image[idx + 2] = 255;
            }
            else
            {
                double hue = 360.0 * sqrt(avg_iter / (double)max_iters);
                unsigned char rgb[3];
                hsv2rgb(hue, 0.8, 1.0, rgb);
                image[idx] = rgb[0];
                image[idx + 1] = rgb[1];
                image[idx + 2] = rgb[2];
            }
        }
    }

    if (strcmp(format, "png") == 0)
    {
        stbi_write_png("mandelbrot.png", width, height, 3, image, width * 3);
    }
    else if (strcmp(format, "jpg") == 0)
    {
        stbi_write_jpg("mandelbrot.jpg", width, height, 3, image, 100);
    }
    else
    {
        stbi_write_bmp("mandelbrot.bmp", width, height, 3, image);
    }
    printf("图像已生成: mandelbrot.%s\n", format);

    free(image);
    return 0;
}