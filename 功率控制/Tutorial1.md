# Buck、Boost与Buck-Boost电路原理推导及器件选型

## 一、为什么要选用这几种DC-DC电路？

- 电路效率高，电源到负载的功率几乎没有理论上的损耗。
- 电路升降压可以通过一个PWM方波简单控制。
- 可以引入比较器闭环控制以调节电压。

## 二、电路分析

### Buck电路分析

<img src="..\img\buck_circuit.png", alt="Buck Circuit", width="500",format="svg">

这三种电路的核心元件都是线圈（L）。线圈电流不可突变，且其两端电压$V_L = L \cdot \frac{di}{dt}$，积分后得到伏秒平衡定理：
$\int_0^{T_s} V_L dt = L \cdot \Delta i = 0$

**开关状态分析：**

- **开**：环路 $V_i \rightarrow Q \rightarrow L \rightarrow R_L \rightarrow V_i$
  $V_L = V_i - V_o$
- **关**：环路 $D \rightarrow L \rightarrow R_L \rightarrow D$
  $V_L = -V_o$（假设D无明显压降）

**伏秒平衡：**
$(V_i - V_o) \cdot T_{on} = (-V_o) \cdot T_{off}$
$\Rightarrow \frac{V_i}{V_o} = D \text{（占空比）}$

> 线圈（L）影响电流纹波，可以通过选型减小其影响。电容用于滤除输出电压纹波。

---

### Boost电路分析

<img src="..\img\boost_circuit.png", alt="Boost Circuit", width="500",format="svg">

**伏秒平衡定理：**
$\int_0^{T_s} V_L dt = L \cdot \Delta i = 0$

**开关状态分析：**

- **开**：$V_i \rightarrow L \rightarrow Q \rightarrow \text{GND}$
  $V_L = V_i$（忽略开关压降）
- **关**：$V_i \rightarrow L \rightarrow D \rightarrow C // R_L \rightarrow \text{GND}$
  $V_L = V_i - V_o \approx -V_o$

**伏秒平衡：**
$V_i \cdot T_{on} + (-V_o) \cdot T_{off} = 0$
$\Rightarrow \frac{V_o}{V_i} = \frac{1}{1-D} \quad (D = \frac{T_{on}}{T_s})$

---

### Buck-Boost电路分析

<img src="..\img\buck_boost_circuit.png", alt="Buck-Boost Circuit", width="500",format="svg">

**伏秒平衡：**
$\int_0^{T_s} V_L dt = 0$

**开关状态分析：**

- **开**：$V_i \rightarrow Q \rightarrow L \rightarrow \text{GND}$
  $V_L = V_i$
- **关**：$L \rightarrow D \rightarrow C // R_L \rightarrow \text{GND}$
  $V_L = -V_o$（输出电压极性反转）

**伏秒平衡方程：**
$V_i \cdot T_{on} = V_o \cdot T_{off}$
$\Rightarrow \frac{V_o}{V_i} = \frac{D}{1-D} \quad (D = \text{占空比})$

---

## 三、选型要点（以Buck电路为例）

### 电感选择

削减电流纹波（控制纹波在$I_o$的±20%）：
$L = \frac{V_o \cdot (1-D)}{f_s \cdot \Delta I}$

### 电容选择

滤除输出三角波纹波：
$C = \frac{\Delta I_o}{8 \cdot f_s \cdot \Delta V_o}$

### 续流二极管选择

- 低正向压降
- 快速反向恢复时间
- 选用肖特基二极管
- 注意最高限流

### MOSFET选择

- 低开启时间
- 低开启阻抗
- 低开启电压
