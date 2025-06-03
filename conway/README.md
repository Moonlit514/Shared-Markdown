# Conway 生命游戏

基于 C 语言的 Conway 生命游戏实现，使用 ncurses 库渲染。

## 快速使用

### 编译运行
1. 安装 `ncurse` 库
- Ubuntu/Debian
```bash
sudo apt update
sudo apt install libncurses5-dev libncursesw5-dev
```
- macOS
```bash
brew install ncurses
```
- Windows  
Windows 默认不支持 `ncurses`，但你可以通过 Cygwin 或 WSL（Windows Subsystem for Linux）来安装 `ncurses`。
2. 编译运行  
请确保工作目录位于 `conway`。
```bash
make
./conway [width] [height] [RLE]     # 示例: ./conway 40 20 pattern/1beacon.rle
```

### 退出程序
```bash
q
```

### 参数说明
- 必须参数
    - `width`: 世界水平方向细胞数
    - `height`: 世界竖直方向细胞数
- 可选参数
    - `RLE`: 初始化细胞图案文件路径（未提供则随机生成）
    
使用 `RLE` 文件初始化游戏时，需保证世界宽度与高度均不小于 `RLE`文件中的指定值。

## 生成文档（可选）
需安装 `Doxygen`。
```bash
sudo apt install graphviz
sudo apt install doxygen
apt install doxygen-gui     # 安装图形界面, 可选
```
安装完成后, 使用以下命令生成文档。
```bash
make doc
```
生成的文档位于 `doc` 文件夹下。

## 文件组成
```
conway/
├── pattern/    # 存放 RLE 文件
|   └── ...
├── conway.h
├── conway.c
├── main.c
├── Makefile
├── Doxyfile
├── conway.md   # 介绍 Conway 游戏
└── README.md
```