本章思维导图
```markmap
---
markmap:
  height: 750
---
* 理想 (Ideals)
  * 基本定义与性质
    * 核心定义
    * 性质
    * 同态核
  * 理想的构造
    * 生成理想
      * 定义: 包含集合H的最小理想
      * 元素形式: 线性组合
    * 主理想
      * 由单个元素生成 (a)
      * 主理想整环 (PID)
    * 特殊理想
      * 零理想 {0}
      * 单位理想 (1) = R
      * 真理想 (I ≠ R)
      * 根理想与幂零基 (Nilradical)
  * 理想的运算
    * 和 (I + J)
      * 定义: {i + j : i∈I, j∈J}
    * 积 (IJ)
      * 定义: ∑aibi
      * 性质: IJ ⊆ I∩J
    * 交 (I ∩ J)
      * 性质: 仍是理想
    * 商理想 (I : J)
      * 定义: {a : aJ ⊆ I}
      * 歼灭元 (Ann J)
  * 商环 (Residue Class Rings)
  * 同态下的扩张与收缩
    * 收缩 (Contraction J^c)
    * 扩张 (Extension I^e)
    * 多项式环应用
  * 特殊环类
    * 欧几里得整环
      * 性质: 所有理想皆为主理想
    * 主理想整环 (PID)
      * 例子: Z, K[X], Z[i]
```

$\qquad$理想构成了环中最重要的子结构：对于交换环而言，理想的地位等同于群论中的正规子群。此外，素理想（prime ideal）和极大理想（maximal ideal）的概念对于交换环论在代数几何中的应用至关重要。
### 一、理想的定义与基本性质
 $\qquad$我们首先来充实上述论点，即理想之于交换环正如正规子群之于群：正如对于群 $G$，子集 $N$ 是 $G$ 的正规子群当且仅当存在一个群 $H$ 和群同态 $\theta : G \to H$ 使得其核等于 $N$。我们将看到，对于交换环 $R$，其子集 $I$ 是 $R$ 的理想当且仅当存在一个交换环 $S$ 和环同态 $f : R \to S$ 使得其核等于 $I$。因此，第一步是定义并考察交换环同态的核的性质。
>[!note] Definition 2.1 核
>设 $R$ 和 $S$ 是交换环，且 $f : R \to S$ 是环同态。我们定义 $f$ 的**核 (kernel)**，记作 $\text{Ker } f$，为：$$\text{Ker } f := \{r \in R : f(r) = 0_S\}$$

注意：
(i) $0_R \in \text{Ker } f$，故 $\text{Ker } f \neq \emptyset$；
(ii) 每当 $a, b \in \text{Ker } f$ 时，则 $a + b \in \text{Ker } f$；
(iii) 每当 $a \in \text{Ker } f$ 且 $r \in R$ 时，则 $ra \in \text{Ker } f$。
>[!Theorem] Lemma 2.2 
>设 $R$ 和 $S$ 是交换环，$f : R \to S$ 是环同态。则 $\text{Ker } f = \{0_R\}$ 当且仅当 $f$ 是单射。
#### 理想的定义
$\qquad$上述引理为交换环中的理想的定义提供了动机
>[!note] Definition 2.3 理想
>设 $R$ 是一个交换环。$R$ 的子集 $I$ 被称为 $R$ 的一个**理想 (ideal)**，当且仅当满足以下条件： 
>(i) $I \neq \emptyset$； 
>(ii) 每当 $a, b \in I$ 时，则 $a + b \in I$； 
>(iii) 每当 $a \in I$ 且 $r \in R$ 时，则 $ra \in I$。

交换环 $R$ 的理想在减法下也是封闭的。本节不讨论非交换环的理想，因此不需要左理想或右理想的概念。

 >[!question] Exercise 2.4 
 >设 $X$ 为一个未定元，考虑有理系数多项式环 $\mathbb{Q}[X]$。给出： 
 >(i) $\mathbb{Q}[X]$ 的一个子环但不是其理想的例子； 
 >(ii) $\mathbb{Q}[X]$ 的一个理想但不是其子环的例子。
 
 参见[[习题解答]]

>[!question] Exercise 2.5
>设 $R$ 是交换环，$I$ 是 $R$ 的理想。证明 $R$ 中所有幂零元（nilpotent elements）构成的集合 $N$ 是 $R$ 的一个理想（该理想 $N$ 通常被称为 $R$ 的**幂零根 (nilradical)**）。同时证明：$$\sqrt{I} := \{r \in R : \exists n \in \mathbb{N} \text{ s.t. } r^n \in I\}$$
也是 $R$ 的一个理想（我们称 $\sqrt{I}$ 为 $I$ 的**根 (radical)**；因此 $R$ 的幂零根 $N$ 仅仅是零理想 $\{0_R\}$ 的根 $\sqrt{\{0_R\}}$）。

### 二、理想的构造
#### 商环构造
$\qquad$为了证明交换环 $R$ 的每一个理想都是从 $R$ 到某个其他交换环的环同态的核，我们现在将构造一种环论上的模拟，类似于群 $G$ 的正规子群 $N$ 构造商群 $G/N$ 的过程。
$\qquad$设 $I$ 是交换环 $R$ 的理想，且 $r \in R$。$I$ 在 $R$ 中由 $r$ 确定（或包含 $r$）的**陪集 (coset)** 是集合：
$$r + I = \{r + z : z \in I\}$$
注意，对于 $r, s \in R$，陪集 $r + I$ 与 $s + I$ 相等当且仅当 $r - s \in I$。事实上，$I$ 在 $R$ 中的陪集正是由 $R$ 上的等价关系 $\sim$ 定义的等价类：
$$a \sim b \iff a - b \in I \quad (a, b \in R)$$
我们将 $R$ 中 $I$ 的所有陪集构成的集合记为 $R/I$。
$\qquad$设 $I$ 和 $J$ 是交换环 $R$ 的理想，满足 $I \subseteq J$。$R$ 在加法下是一个阿贝尔群，$I, J$ 是 $R$ 的子群；因此 $I$ 是 $J$ 的子群，我们可以构造商群 $J/I$。该群的元素是 $I$ 在 $J$ 中的陪集：
$$J/I = \{a + I : a \in J\}$$
群 $J/I$ 中的加法定义为：
$$(a + I) + (b + I) = (a + b) + I$$
>[!note] Definition 2.6 商环的构造
>设 $I$ 是交换环 $R$ 的理想。$R$ 本身是其自身的一个理想，我们可以利用上文所述的构造形成商群 $R/I$。我们展示如何在这个阿贝尔群上建立环结构。假设 $r, r', s, s' \in R$ 使得：$$r + I = r' + I, \quad s + I = s' + I$$则有 $r - r', s - s' \in I$，从而：$$rs - r's' = rs - rs' + rs' - r's' = r(s - s') + (r - r')s' \in I$$这意味着 $rs + I = r's' + I$。因此我们可以无歧义地在 $R/I$ 上定义乘法运算：$$(r + I)(s + I) = rs + I$$对于所有 $r, s \in R$。现在可以很直接地验证，该运算使 $R/I$ 具有交换环的结构。该环的单位元是 $1 + I$，零元是 $0 + I = I$。
>环 $R/I$ 被称为 **剩余类环 (residue class ring)**，或 $R$ 对 $I$ 的 **商环 (factor ring)**。

>[!Theorem] Lemma 2.7
>设 $I$ 是交换环 $R$ 的理想。则定义为 $f(r) = r + I$ 的映射 $f : R \to R/I$ 是一个核为 $I$ 的满环同态。该同态 $f$ 通常被称为从 $R$ 到 $R/I$ 的**自然 (natural)** 或 **标准 (canonical)** 环同态。
  
>[!Theorem] Corollary 2.8
>设 $R$ 是交换环，$I$ 是 $R$ 的子集。则 $I$ 是 $R$ 的理想当且仅当存在一个交换环 $S$ 和环同态 $f : R \to S$ 使得 $I = \text{Ker } f$

>[!proof]+
>充分性 ($\Leftarrow$):
>(i) $\forall a, b \in I$ ，有 $f(a)=f(b)=0$，从而 $f(a-b)=f(a)-f(b)=0$，故  $a-b \in I$，从而 $I$ 是一个加法子群。
>(ii) 任取 $a \in I,r \in R$，$f(ra)=f(r)f(a)=f(r)\cdot 0 = 0$，从而 $ra\in I$。
>必要性 ($\Rightarrow$):
>令 $S= R/I$ 并构造自然同态即可。

#### 同构基本定理
>[!Theorem] Theorem 2.9 交换环的同构定理
>设 $R$ 和 $S$ 是交换环，$f : R \to S$ 是环同态。则 $f$ 诱导了一个环同构 $\bar{f} : R/\text{Ker } f \to \text{Im } f$，满足：$$\bar{f}(r + \text{Ker } f) = f(r) \quad (\forall r \in R)$$

同态第一定理，证明不再赘述
#### 特殊理想
一些定义的补充：
$\qquad$设 $R$ 为交换环。则 $R$ 自身总是 $R$ 的一个理想。我们说 $R$ 的理想 $I$ 是**真理想 (proper)**，当且仅当 $I \neq R$。 观察到对于 $R$ 的理想 $I$，商环 $R/I$ 是零环当且仅当 $1 + I = 0 + I$；这发生当且仅当 $1 \in I$，而这又恰好在 $I = R$ 时发生，即 $I$ 是**非真理想 (improper)**。（若 $1 \in I$，则对于所有 $r \in R$，有 $r = r \cdot 1 \in I$。） $R$ 的另一个理想例子是集合 $\{0_R\}$：这被称为 $R$ 的**零理想 (zero ideal)**，通常仅记作 $0$。

### 三、理想的生成与运算
#### 主理想
>[!example] Example 2.10
>设 $n \in \mathbb{N}$ 且 $n > 1$。则集合$$n\mathbb{Z} := \{nr : r \in \mathbb{Z}\}$$是整数环 $\mathbb{Z}$ 的一个理想。因此我们可以构造剩余类环 $\mathbb{Z}/n\mathbb{Z}$，这正是模 $n$ 整数剩余类环。

这是交换环中“主理想”概念的一个特例，我们现在对其进行定义。
>[!note] Definition 2.11 主理想
>设 $R$ 为交换环；设 $a \in R$。则集合$$aR := \{ar : r \in R\}$$是 $R$ 的一个理想，称为由 $a$ 生成的 $R$ 的**主理想 (principal ideal)**。$aR$ 的其他记号为 $(a)$ 和 $Ra$（在国内教材常用 $\langle a \rangle$）。

主理想指环 $R$ 中由单个元素 $a$ 生成的理想。它由该元素与环中任意元素的乘积及加法组合构成。
$R$ 的主理想 $1_R R$ 就是 $R$ 自身，而 $R$ 的主理想 $0_R R$ 是零理想。
>[!question] Exercise 2.12
>设 $R$ 为交换环并设 $r \in R$。证明 $r$ 是 $R$ 的单位（可逆元）当且仅当 $(r) = (1_R)$。

#### 生成理想
现在是时候探讨 2.11中关于主理想定义所使用的“生成”一词了。
$\qquad$设 $R$ 为交换环，并设 $(I_\lambda)_{\lambda \in \Lambda}$ 是 $R$ 的理想的一个非空族。（这仅意味着 $\Lambda \neq \emptyset$ 且对于每个 $\lambda \in \Lambda$，$I_\lambda$ 是 $R$ 的理想。）根据理想的定义应该很清楚：
$$\bigcap_{\lambda \in \Lambda} I_\lambda$$
即我们理想族的交集，依然是 $R$ 的一个理想。在 $\Lambda = \emptyset$ 的情况下，我们将 $\bigcap_{\lambda \in \Lambda} I_\lambda$ 理解为 $R$ 自身。
$\qquad$设 $H \subseteq R$。我们定义由 $H$ **生成**的 $R$ 的**理想**，为所有包含 $H$ 的 $R$ 的理想的交集，记作 $(H)$ 或 $RH$ 或 $HR$，注意这个族肯定是非空的，因为 $R$ 自身就是包含 $H$ 的 $R$ 的理想。
$\qquad$(i) $(H)$ 是 $R$ 的理想且 $H \subseteq (H)$； 
$\qquad$(ii) $(H)$ 是包含 $H$ 的 $R$ 的**最小**理想，其含义是：若 $I$ 是 $R$ 的任何满足 $H \subseteq I$ 的理想，则 $(H) \subseteq I$，这仅仅是因为 $I$ 必定是用于定义 $(H)$ 的理想族中的一员。 
$\qquad$$(H)$ 看起来像什么？这是我们接下来要解决的问题。
>[!summary] Proposition 2.13
>设 $R$ 为交换环，并设 $\emptyset \neq H \subseteq R$。则$$(H) = \left\{ \sum_{i=1}^n r_i h_i : n \in \mathbb{N}, r_1, \dots, r_n \in R, h_1, \dots, h_n \in H \right\}$$此外，$(\emptyset)$，即由空子集生成的 $R$ 的理想，由 $(\emptyset) = 0$（零理想）给出。

证明与 Chapter 1 中的1.8类似。
#### 有限生成
$\qquad$当 H 是有限且非空时的特殊情况下，2.18 中描述的理论会发生简化。
(i) 假设 $H = \{h_1, \dots, h_t\} \subseteq R$（其中 $t > 0$）。由于对于 $r_1, \dots, r_t, s_1, \dots, s_t \in R$，我们有
$$\sum_{i=1}^t r_i h_i + \sum_{i=1}^t s_i h_i = \sum_{i=1}^t (r_i + s_i) h_i$$
可知在这种情况下
$$(H) = \left\{ \sum_{i=1}^t r_i h_i : r_1, \dots, r_t \in R \right\}$$
在这种情况下，$(H)$ 通常写作 $(h_1, \dots, h_t)$（而不是更繁琐的 $(\{h_1, \dots, h_t\})$），并被称为由 $h_1, \dots, h_t$ **生成的理想**。

(ii) 特别地，对于 $h \in R$，我们有$$(\{h\}) = \{rh : r \in R\}$$即我们在 2.11 中讨论的由 $h$ 生成的 $R$ 的主理想。因此我们对该理想的记号 $(h)$ 与 2.11 中对该记号的使用并不冲突。

(iii) 若 $R$ 的理想 $I$ 等于某个 $R$ 的有限子集 $H$ 的 $(H)$，则我们说 $I$ 是 $R$ 的一个**有限生成理想 (finitely generated ideal)**。

>[!question] Exercise 2.14
>考虑交换环 $R$ 上关于未定元 $X_1, \dots, X_n$ 的多项式环 $R[X_1, \dots, X_n]$。设 $\alpha_1, \dots, \alpha_n \in R$，并设$$f : R[X_1, \dots, X_n] \to R$$为在 $\alpha_1, \dots, \alpha_n$ 处的求值同态（见 1.13）。证明$$\text{Ker } f = (X_1 - \alpha_1, \dots, X_n - \alpha_n)$$

不应认为交换环的每个理想都必须是有限生成的；
也不应认为这类环的每个有限生成理想都必须是主理想。
>[!question] Exercise 2.15
>设 $K$ 为域并设 $(X_i)_{i \in \mathbb{N}}$ 为一族未定元，使得对于所有 $n \in \mathbb{N}$，$X_1, \dots, X_n$ 在 $K$ 上代数无关。（在这种情况下，我们说族 $(X_i)_{i \in \mathbb{N}}$ 在 $K$ 上代数无关。） 
>对于每个 $n \in \mathbb{N}$，设 $R_n = K[X_1, \dots, X_n]$；设 $R_0 = K$。因此对于每个 $n \in \mathbb{N}_0$，我们可以按自然方式将 $R_n$ 视为 $R_{n+1}$ 的子环。
>(i)证明 $R_\infty := \bigcup_{n \in \mathbb{N}_0} R_n$ 可以被赋予交换环的结构，使得 $R_n$ 是 $R_\infty$ 的子环。
>(ii)证明 $R_\infty = K[\Gamma]$，其中 $\Gamma = \{X_i : i \in \mathbb{N}\}$。
>事实上，我们有时将 $R_\infty$ 记作 $K[X_1, \dots, X_n, \dots]$，并将其称为系数在 $K$ 中、关于可数无限未定元族 $(X_i)_{i \in \mathbb{N}}$ 的**多项式环**。 
>(iii)证明由 $\Gamma$ 生成的 $R_\infty$ 的理想不是有限生成的。

>[!question] Exercise 2.16
>设 $K$ 为域。证明交换环 $K[X_1, X_2]$（关于 $K$ 上未定元 $X_1, X_2$ 的多项式环）的理想 $(X_1, X_2)$ 不是主理想。

均参见[[习题解答]]
#### 理想的运算——和
交换环 $R$ 的一族理想之**和**的概念与由 $R$ 的子集生成理想的概念密切相关。我们接下来对此进行解释。
>[!note] Definition 2.17 理想的和
>设 $(I_\lambda)_{\lambda \in \Lambda}$ 为交换环 $R$ 的一族理想。我们定义该族的**和 (sum)** $\sum_{\lambda \in \Lambda} I_\lambda$ 为由 $\bigcup_{\lambda \in \Lambda} I_\lambda$ 生成的 $R$ 的理想：即$$\sum_{\lambda \in \Lambda} I_\lambda = \left( \bigcup_{\lambda \in \Lambda} I_\lambda \right)$$特别地，若 $\Lambda = \emptyset$，则 $\sum_{\lambda \in \Lambda} I_\lambda = 0$。

由于 $R$ 的任意理想在加法和 $R$ 的任意元素数乘下都是封闭的，由 2.13 可知，在 $\Lambda \neq \emptyset$ 的情况下，$\sum_{\lambda \in \Lambda} I_\lambda$ 的任一元素可以表示为形式 $\sum_{i=1}^n c_{\lambda_i}$，其中 $n \in \mathbb{N}$，$\lambda_1, \dots, \lambda_n \in \Lambda$， $i=1, \dots, n$，$c_{\lambda_i} \in I_{\lambda_i}$。表示和 $\sum_{\lambda \in \Lambda} I_\lambda$ 的另一种方式是 $\sum_{\lambda \in \Lambda} c_\lambda$，其中对于所有 $\lambda \in \Lambda$，$c_\lambda \in I_\lambda$，且除了有限多个 $\lambda \in \Lambda$ 之外，$c_\lambda = 0$。
理想的和 (Sum of Ideals) 是指两个或多个理想 $I$ 和 $J$ 的元素两两相加所构成的集合，即 $I+J = \{a+b \mid a \in I, b \in J\}$。
理想的并集 $I \cup J$ 通常不是理想，因为不满足加法封闭性；理想的和 $I+J$ 补充了这一缺陷。
我们将大量使用下一个练习的结果，但它们非常容易证明
>[!question] Exercise 2.18
>设 $R$ 为交换环。 
>(i) 证明由理想和给出的 $R$ 的所有理想集合上的二元运算既满足交换律也满足结合律。
>(ii)设 $I_1, \dots, I_n$ 为 $R$ 的理想。证明：$$\sum_{i=1}^n I_i = \left\{ \sum_{i=1}^n r_i : r_i \in I_i \text{ 对于 } i = 1, \dots, n \right\}$$我们经常将 $\sum_{i=1}^n I_i$ 记作 $I_1 + \dots + I_n$。
>(iii)设 $h_1, \dots, h_n \in R$。证明：$$(h_1, \dots, h_n) = Rh_1 + \dots + Rh_n$$即 $(h_1, \dots, h_n) = (h_1) + \dots + (h_n)$。

探讨根式理想的相关性质：
>[!question] Exercise 2.19
>设 $R$ 为交换环，并设 $I, J$ 为 $R$ 的理想。$I$ 的根 $\sqrt{I}$ 已在 2.5 中定义。证明： 
>(i) $\sqrt{I + J} = \sqrt{\sqrt{I} + \sqrt{J}}$； 
>(ii) $\sqrt{(\sqrt{I})} = \sqrt{I}$； 
>(iii) $\sqrt{I} = (1)$ 当且仅当 $I = (1)$； 
>(iv) 若 $\sqrt{I} + \sqrt{J} = (1)$，则 $I + J = (1)$。

#### 理想的运算——积
另一个与理想生成概念相关的概念是交换环的两个理想之**积**。我们接下来解释这一点。
>[!note] Definition 2.20 理想的积
>设 $I$ 和 $J$ 是交换环 $R$ 的理想。$I$ 与 $J$ 的**积 (product)**，记作 $I \cdot J$，或更通常记作 $IJ$，定义为由集合 $\{ab : a \in I, b \in J\}$ 生成的 $R$ 的理想。

容易得到$$IJ = \left\{ \sum_{i=1}^n a_i b_i : n \in \mathbb{N}, a_1, \dots, a_n \in I, b_1, \dots, b_n \in J \right\}$$
注意：积理想 $IJ$ 通常不等于 $R$ 的子集 $\{ab : a \in I, b \in J\}$。接下来的练习说明了这一点。
>[!question] Exercise 2.21
>设 $K$ 为域，并设 $R = K[X_1, X_2, X_3, X_4]$ 是关于未定元 $X_1, X_2, X_3, X_4$ 的多项式环。令$$I = RX_1 + RX_2, \quad J = RX_3 + RX_4$$证明 $IJ \neq \{fg : f \in I, g \in J\}$。

接下来我们展开积理想的基本性质。
设 $R$ 为交换环，并设 $I, J, K, I_1, \dots, I_n$ 为 $R$ 的理想。
(i) 显然 $IJ = JI \subseteq I \cap J$。

(ii) 易于验证 $(IJ)K = I(JK)$，且两者都等于由集合
$$H = \{abc : a \in I, b \in J, c \in K\}$$
生成的 $R$ 的理想 $RH$。
因此，$(IJ)K = I(JK) =: IJK$ 的典型元素具有如下形式：
$$\sum_{i=1}^t a_i b_i c_i$$
其中 $t \in \mathbb{N}, a_1, \dots, a_t \in I, b_1, \dots, b_t \in J$ 且 $c_1, \dots, c_t \in K$。

(iii) 由 (i) 和 (ii) 可知，我们可以无歧义地定义 $R$ 的理想 $I_1, \dots, I_n$ 的积 $\prod_{i=1}^n I_i$：我们有
$$\prod_{i=1}^n I_i = I_1 \dots I_n = RL$$
其中
$$L = \{a_1 \dots a_n : a_1 \in I_1, \dots, a_n \in I_n\}$$
因此我们看到 $I_1 \dots I_n$ 的典型元素是 $L$ 中有限个元素的和。

(iv)$I(J + K) = IJ + IK$

(v) 特别注意，$I$ 的幂 $I^m$（对于 $m \in \mathbb{N}$）是已定义的；我们采用约定 $I^0 = R$。注意，根据 (iii)，$I^m$（对于正整数 $m$）的一般元素具有如下形式：
$$a_{11} a_{12} \dots a_{1m} + a_{21} a_{22} \dots a_{2m} + \dots + a_{n1} a_{n2} \dots a_{nm}$$
其中 $n \in \mathbb{N}$ 且对于所有 $i = 1, \dots, n$ 和 $j = 1, \dots, m$，有 $a_{ij} \in I$。

>[!question] Exercise 2.22
>设 $R$ 为交换环并设 $m \in \mathbb{N}$。描述多项式环 $R[X_1, \dots, X_n]$ 的理想 $(X_1, \dots, X_n)^m$。

>[!question] Exercise 2.23
>设 $I, J$ 为交换环 $R$ 的理想。证明：$$\sqrt{IJ} = \sqrt{I \cap J} = \sqrt{I} \cap \sqrt{J}$$

#### 理想的运算——商
对于 $R$ 的理想 $I$ 和 $a \in R$，记号 $aI$ 将表示集合 $\{ac : c \in I\}$。这依然是 $R$ 的一个理想，因为它恰好是积理想 $(a)I$。

>[!Note] Definition 2.24 理想商与零化子
>设 $I, J$ 是交换环 $R$ 的理想。我们定义**理想商 (ideal quotient)** $(I : J)$ 为：$$(I : J) = \{a \in R : aJ \subseteq I\}$$显然这是 $R$ 的另一个理想，且 $I \subseteq (I : J)$。
>在 $I = 0$ 的特殊情况下，理想商$$(0 : J) = \{a \in R : aJ = 0\} = \{a \in R : ab = 0 \text{ 对于所有 } b \in J\}$$被称为 $J$ 的**零化子 (annihilator)**，也记作 $\text{Ann } J$ 或 $\text{Ann}_R J$。

>[!question] Exercise 2.25
>设 $H$ 为交换环 $R$ 的子集，并设 $I$ 为 $R$ 的一个理想。证明：$$(I : RH) = \{a \in R : ah \in I ,\forall  h \in H\}$$

>[!question] Exercise 2.26
>设 $I, J, K$ 为交换环 $R$ 的理想，并设 $(I_\lambda)_{\lambda \in \Lambda}$ 为 $R$ 的一族理想。证明： 
>(i) $((I : J) : K) = (I : JK) = ((I : K) : J)$； 
>(ii) $(\bigcap_{\lambda \in \Lambda} I_\lambda : K) = \bigcap_{\lambda \in \Lambda} (I_\lambda : K)$； 
>(iii) $(J : \sum_{\lambda \in \Lambda} I_\lambda) = \bigcap_{\lambda \in \Lambda} (J : I_\lambda)$。

### 四、特殊环类型
#### 欧几里得整环
现在是时候在一些熟悉的交换环例子中考察理想的算术了。当人们开始研究这个课题时，脑海中浮现的许多交换环的初等例子实际上都是欧几里得整环 (Euclidean domains)。有一个事实极大地简化了欧几里得整环的理想理论。

>[!Theorem] Theorem 2.27
> 欧几里得整环 $R$ 中的每个理想 $I$ 都是主理想。

>[!proof]+
>$R$ 的零理想是主理想，因此我们可以（且确实）假设 $I \neq 0$。于是存在 $a \in I$ 且 $a \neq 0$。 我们用 $\partial : R \setminus \{0\} \to \mathbb{N}_0$ 表示欧几里得整环 $R$ 的次数函数（degree function）。集合$$\{\partial(a) : a \in I \setminus \{0\}\}$$是一个非负整数的非空集合，因此有一个最小元素：令其为 $\partial(h)$，其中 $h \in I \setminus \{0\}$。由于 $I$ 是 $R$ 的一个理想，显然 $hR \subseteq I$。为了确立反向包含关系，设 $b \in I$。根据欧几里得整环的定义，存在 $q, r \in R$ 使得$$b = qh + r$$其中要么 $r = 0$，要么 $r \neq 0$ 且 $\partial(r) < \partial(h)$。
>但是 $r = b - qh \in I$，因此我们必须有 $r = 0$，否则将产生与 $h$ 的定义相矛盾的结果。因此 $b = qh \in hR$，我们就证明了 $I \subseteq hR$。

#### 主理想整环
根据这个结论，我们自然引出主理想整环的定义
>[!Note] Definition 2.28 主理想整环
>一个整环 $R$ 被称为**主理想整环 (principal ideal domain)**（简称 PID），当且仅当 $R$ 的每个理想都是主理想。

因此由 2.34 可知，每个欧几里得整环都是 PID。因此 $\mathbb{Z}, \mathbb{Z}[i]$ 和 $K[X]$（其中 $K$ 是任意域且 $X$ 是 $K$ 上的未定元）都是主理想整环的例子。 能够描述商环的理想对我们来说很重要。

### 五、理想的对应与变迁
#### 商环中的理想对应
>[!summary] Proposition 2.29 商环中的理想
设 $I$ 为交换环 $R$ 的一个理想。
$\qquad$(i) 若 $J$ 是 $R$ 的理想且 $J \supseteq I$，则阿贝尔群 $J/I$ 是 $R/I$ 的一个理想，并且，对于 $r \in R$，有 $r + I \in J/I$ 当且仅当 $r \in J$。
$\qquad$(ii) $R/I$ 的每个理想 $\mathcal{J}$ 都可以表示为 $K/I$ 的形式，其中恰好有一个包含 $I$ 的 $R$ 的理想 $K$；事实上，满足这些条件的唯一理想 $K$ 由下式给出：$$K = \{a \in R : a + I \in \mathcal{J}\}$$

>[!proof]
>(i) 由 2.8 清楚可知，剩余类群$$J/I = \{a + I : a \in J\} \subseteq \{r + I : r \in R\} = R/I$$因此 $J/I$ 是加法群 $R/I$ 的一个子群。此外，由于对于所有 $r \in R$ 和 $a \in J$，我们有$$(r + I)(a + I) = ra + I \in J/I$$
可知 $J/I$ 是 $R/I$ 的一个理想。只需注意若 $r \in R$ 使得 $r + I = j + I$（对于某个 $j \in J$），则 $r = (r - j) + j$ 且 $r - j \in I \subseteq J$
>
>(ii)设 $\mathcal{J}$ 为 $R/I$ 的一个理想。令
>$$K = \{a \in R : a + I \in \mathcal{J}\}$$
>显然 $I \subseteq K$，因为对于所有 $a \in I$，$a + I = I \in \mathcal{J}$。
>设 $a, b \in K$ 且 $r \in R$。则我们有 $a + I, b + I \in \mathcal{J}$，从而 $(a + b) + I, ra + I \in \mathcal{J}$；因此 $a + b, ra \in K$，且 $K$ 是 $R$ 的一个理想。我们已经指出 $K \supseteq I$。从 $K$ 的定义清楚可知 $K/I = \mathcal{J}$。
>现在假设 $L$ 是 $R$ 的另一个理想，具有 $L \supseteq I$ 且 $L/I = \mathcal{J}$ 的性质。设 $a \in L$。则$$a + I \in L/I = \mathcal{J}$$故根据 $K$ 的定义有 $a \in K$。另一方面，若 $b \in K$，则 $b + I \in \mathcal{J} = L/I$，因此存在 $b' \in L$ 使得 $b + I = b' + I$，由 (i) 可知 $b \in L$。因此 $K = L$。

>[!question] Exercise 2.30
>设 $I$ 为交换环 $R$ 的理想，并设 $J, K$ 为包含 $I$ 的 $R$ 的理想。令 $a_1, \dots, a_h \in R$。对于以下对 $R/I$ 理想 $\mathcal{J}$ 的每种选择，确定唯一的满足 $L \supseteq I$ 且 $L/I = \mathcal{J}$ 性质的 $R$ 理想 $L$。 
>(i) $\mathcal{J} = J/I + K/I$。 
>(ii) $\mathcal{J} = (J/I)(K/I)$。 
>(iii) $\mathcal{J} = (J/I : K/I)$。 
>(iv) $\mathcal{J} = (J/I)^n$，其中 $n \in \mathbb{N}$。 
>(v) $\mathcal{J} = (J/I) \cap (K/I)$。 
>(vi) $\mathcal{J} = 0$。 
>(vii) $\mathcal{J} = \sum_{i=1}^h (R/I)(a_i + I)$。 
>(viii) $\mathcal{J} = R/I$。

设 $R$ 为交换环并设 $I$ 为 $R$ 的理想。让我们用 $\mathcal{I}_R$ 表示 $R$ 的所有理想的集合，这样在这个记号下，$\mathcal{I}_{R/I}$ 表示 $R/I$ 的理想集。描述 2.29 结果的一种方式是说存在一个映射
$$\theta : \{J \in \mathcal{I}_R : J \supseteq I\} \longrightarrow \mathcal{I}_{R/I}$$
$$J \longmapsto J/I$$
它是双射的。注意 $\theta$ 及其逆映射都保持包含关系：这意味着对于 $J_1, J_2 \in \mathcal{I}_R$ 且 $J_i \supseteq I$（对于 $i = 1, 2$），我们有
$$J_1 \subseteq J_2 \iff  J_1/I \subseteq J_2/I$$

>[!question] Exercise 2.31
>设 $I, J$ 为交换环 $R$ 的理想使得 $J \supseteq I$。证明存在环同构
$$\xi : (R/I) / (J/I) \longrightarrow R/J$$使得对于所有 $r \in R$，$\xi((r + I) + J/I) = r + J$。

提示：尝试使用交换环的同构定理。

$\qquad$ 2.29 中描述的结果实际上涉及自然环同态 $f : R \to R/I$ 对理想产生的影响：它们表明若 $J$ 是包含 $I$ 的 $R$ 的理想，则 $f(J)$ 实际上是 $R/I$ 的一个理想，并且若 $\mathcal{J}$ 是 $R/I$ 的理想，则$$f^{-1}(\mathcal{J}) = \{r \in R : f(r) \in \mathcal{J}\}$$是包含 $I$ 的 $R$ 的一个理想。

$\qquad$我们之前也考虑过交换环特定理想在环同态下的原像：若 $R$ 和 $S$ 都是交换环且 $g : R \to S$ 是环同态，则我们可以将 $\text{Ker } g$ 视为 $S$ 的零理想在 $g$ 下的原像。当然，$\text{Ker } g$ 是 $R$ 的一个理想。前两段概述的事实自然地引导我们考虑一般现象，通常使用理想在环同态下的“扩张 (extension)”和“收缩 (contraction)”来描述。
#### 同态下的扩张与收缩
>[!note] Definition 2.32 扩张与收缩
>设 $R$ 和 $S$ 为交换环，并设 $f : R \to S$ 为环同态。 
>(i) 每当 $J$ 是 $S$ 的理想时，则 $f^{-1}(J) := \{r \in R : f(r) \in J\}$ 是 $R$ 的一个理想，称为 $J$ 到 $R$ 的**收缩 (contraction)**。当不会引起混淆时，$f^{-1}(J)$ 经常记作 $J^c$。 
>(ii) 对于 $R$ 的每个理想 $I$，由 $f(I)$ 生成的 $S$ 的理想 $f(I)S$ 称为 $I$ 到 $S$ 的**扩张 (extension)**。同样，在可能的情况下，$f(I)S$ 经常记作 $I^e$。

考虑$$g : R \xrightarrow{f} S \xrightarrow{\text{nat}} S/J$$
其中第二个映射是自然满射环同态。两个环同态的复合当然还是环同态，且 $\text{Ker } g = \{r \in R : f(r) \in J\} = f^{-1}(J)$；可得 $f^{-1}(J)$ 是 $R$ 的一个理想。

>[!question] Exercise 2.33
>设情形如 2.32 且假设 $R$ 的理想 $I$ 由集合 $H$ 生成。证明 $I$ 在 $f$ 下到 $S$ 的扩张 $I^e$ 由 $f(H) = \{f(h) : h \in H\}$ 生成。

>[!question] Exercise 2.34
>设情形如 2.32 并设 $I_1, I_2$ 为 $R$ 的理想且 $J_1, J_2$ 为 $S$ 的理想。证明：
>(i) $(I_1 + I_2)^e = I_1^e + I_2^e$；
>(ii) $(I_1 I_2)^e = I_1^e I_2^e$；
>(iii) $(J_1 \cap J_2)^c = J_1^c \cap J_2^c$；
>(iv) $(\sqrt{J_1})^c = \sqrt{J_1^c}$。

>[!Theorem] Lemma 2.35 扩张与收缩的关系
>设 $R$ 和 $S$ 为交换环，并设 $f : R \to S$ 为环同态。设 $I$ 为 $R$ 的理想，$J$ 为 $S$ 的理想。使用 2.32 的记号 $I^e$ 和 $J^c$。则 
>(i) $I \subseteq I^{ec}$； 
>(ii) $J^{ce} \subseteq J$； 
>(iii) $I^e = I^{ece}$，
>(iv) $J^{cec} = J^c$。

>[!proof]
>证明：(i) 设 $r \in I$。由于 $f(r) \in f(I) \subseteq f(I)S = I^e$，立即得 $r \in I^{ec}$。 
>(ii) 根据定义，$J^{ce}$ 是由 $f(f^{-1}(J))$ 生成的 $S$ 的理想。但 $f(f^{-1}(J)) \subseteq J$，且 $J$ 是 $S$ 的理想，所以我们必须有 $J^{ce} \subseteq J$。 
>(iii) 由 (i) 有 $I \subseteq I^{ec}$。取扩张得到 $I^e \subseteq I^{ece}$。反向包含关系通过对理想 $I^e$ 应用 (ii) 获得。 
>(iv) 证明方式与刚才用于 (iii) 的方式类似。由 (ii) 有 $J^{ce} \subseteq J$，故收缩回 $R$ 得到 $J^{cec} \subseteq J^c$。另一方面，对 $R$ 的理想 $J^c$ 应用 (i) 得到 $J^c \subseteq J^{cec}$

>[!Theorem] Corollary 2.36
>设情形如 2.35，并使用 记号 $\mathcal{I}_R$ 表示 $R$ 的所有理想的集合。此外，令$$\mathcal{C}_R = \{J^c : J \in \mathcal{I}_S\}, \quad \mathcal{E}_S = \{I^e : I \in \mathcal{I}_R\}$$
由 2.35(iv) 可知 $I^{ec} = I$ 对于所有 $I \in \mathcal{C}_R$ 成立，由 2.35(iii) 可知 $J^{ce} = J$ 对于所有 $J \in \mathcal{E}_S$ 成立。因此扩张与收缩给出了互为逆映射的双射：$$\mathcal{C}_R \longleftrightarrow \mathcal{E}_S$$$$I \longmapsto I^e \quad \text{和} \quad J \longmapsto J^c$$

我们有时称 $\mathcal{C}_R$ 为 $R$ 的在 $f$ 下从 $S$ 收缩得到的理想集，或者简称为收缩理想集；类似地，$\mathcal{E}_S$ 是 $S$ 的在 $f$ 下从 $R$ 扩张得到的理想集，或称为扩张理想集。

#### 多项式环中的理想
我们关于理想扩张与收缩的想法可以阐明多项式环中的一些理想。
>[!question] Exercise 2.37
>设 $R$ 为交换环，并设 $X$ 为 $R$ 上的未定元。令 $f : R \to R[X]$ 表示自然环同态。设 $I$ 为 $R$ 的一个理想，对于 $r \in R$，用 $\bar{r}$ 表示 $r$ 在 $R/I$ 中的自然像。根据 1.10 存在一个环同态$$\eta : R[X] \longrightarrow (R/I)[X]$$对于它，有$$\eta \left( \sum_{i=0}^n r_i X^i \right) = \sum_{i=0}^n \bar{r}_i X^i$$对于所有 $n \in \mathbb{N}_0$ 和 $r_0, r_1, \dots, r_n \in R$。证明：
>(i) $I^e = \text{Ker } \eta$，即$$I^e = \left\{ \sum_{i=0}^n r_i X^i \in R[X] : n \in \mathbb{N}_0, r_i \in I \text{ 对于所有 } i = 0, \dots, n \right\}$$(ii) $I^{ec} = I$，故 $\mathcal{C}_R = \mathcal{I}_R$；
>(iii) $R[X]/I^e = R[X]/IR[X] \cong (R/I)[X]$；以及
>(iv) 若 $I_1, \dots, I_n$ 是 $R$ 的理想，则$$(I_1 \cap \dots \cap I_n) R[X] = I_1 R[X] \cap \dots \cap I_n R[X]$$

>[!question] Exercise 2.38
>将练习 2.37 的结果推广到交换环 $R$ 上关于未定元 $X_1, \dots, X_n$ 的多项式环 $R[X_1, \dots, X_n]$。

>[!question] Exercise 2.39
>设 $R$ 为交换环，并设 $f : R \to R[[X]]$ 为自然环同态，其中 $X$ 是未定元。你在多大程度上能模仿这个环同态的 2.37 的结果？

>[!question] Exercise 2.40
>找一个 $\mathbb{Z}[X]$（其中 $X$ 是未定元）的理想，它不是在自然环同态下从 $\mathbb{Z}$ 扩张得到的。 $\mathbb{Z}[X]$ 的每个理想都是主理想吗？$\mathbb{Z}[X]$ 是欧几里得整环吗？请给出理由。