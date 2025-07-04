# Mandelbrot 集可视化项目

![Mandelbrot 示例图像](mandelbrot_example.bmp)

## 简介

基于C语言的 Mandelbrot 集计算以及可视化项目, 能够生成以(−1.5, −1), (1.5, 1) 为长方形两端顶点的 Mandelbrot 集图像并储存为`bmp`, `png`, `jpeg`文件 (默认`bmp`文件)。

本项目使用以下第三方资源：
- `stb_image_write.h` 来自 [stb](https://github.com/nothings/stb), 已内置在项目的`src/include/`文件夹下。

## 使用

### 使用Make构建
```bash
make                        # 编译项目
make help                   # 查看命令
make clean                  # 清理构建
make run                    # 运行项目, 默认生成bmp文件
make run FORMAT=png         # 运行项目, 并生成png文件
make run FORMAT=jpg         # 运行项目, 并生成jpeg文件
```
由于采样量较大, 生成需要花费一些时间。可以在 `src/test.c` 的图像参数部分 (line 75 - 78) 调整。

### 报告文件
```bash
cd report
make
make clean                  # 清理报告文件
```

## 文件组成
```
mandelbrot/
├── report/
|   ├── Makefile
|   ├── mandelbrot_ref.bib
|   └── report.tex
├── src/
|   ├── include/
|   |   └── stb_image_write.h
|   ├── mandelbrot.h
|   ├── mandelbrot.c
|   └── test.c
├── Makefile
└── README.md
```