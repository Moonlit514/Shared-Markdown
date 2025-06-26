# 功率控制 项目README
>
>author: Efold
>南科大ARTINX实验室硬件组
>2025.6.27
欢迎来到Efold的新坑（已完结），主要是我在学习功率控制的笔记，欢迎学习交流.

## 正式教程

- `Tutorial1.md`：详细介绍Buck、Boost及Buck-Boost变换器的工作原理、关键元器件选择。
- `Tutorial2.md`：深入讨论FSBB变换器的工作模式、驱动方法及自举驱动的应用。
- `Tutorial3.md`：介绍FSBB变换器的实际应用控制细节，包括闭环控制的实现方法。

## 目录结构

功率控制/
├── img/
│   ├── buck_circuit.png
│   ├── boost_circuit.png
│   ├── buck_boost_circuit.png
│   ├── FSBB.png
│   ├── drive_circuit.png
│   └── analog_circuit.png
├── README.md
├── src/
└── Tutorial1.md
└── Tutorial2.md
└── Tutorial3.md

## 文件内容概述

### 1. img/

- 存储与项目相关的电路图和示意图，包括Buck电路、Boost电路、Buck-Boost电路、FSBB电路、驱动电路以及模拟电路图，会在Tutorial文章中调用。

### 2. src/

- 存放源文件以及草稿，可以跟着草稿看我的心路历程（会更口语化orz）

### 3. Tutorial1.md

- **Buck、Boost及Buck-Boost电路原理及元器件选择**
  - 介绍选择这些DC-DC变换器的理由，包括高效率、可调性及滤波需求。
  - 分析Buck、Boost及Buck-Boost电路的原理图，并给出关键元器件选择建议。

### 4. Tutorial2.md

- **FSBB原理解析及自举驱动**
  - 解释FSBB（四开关Buck-Boost）的工作模式及常用的驱动方法。
  - 提供FSBB的驱动电路图，并说明其工作原理。

### 5. Tutorial3.md

- **FSBB实践控制细节**
  - 详细介绍实践中的元器件选择及控制细节。
  - 讨论功率闭环控制方法及自举驱动的应用。
  - 分析模拟电路图中的闭环控制过程。
