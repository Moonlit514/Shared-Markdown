本章思维导图
```markmap
---
markmap:
  height: 489
---
* 交换环与子环
  * 环的定义与类型
    * 环 (Ring)
    * 交换环
    * 零环
  * 环的构造
    * 多项式环
    * 形式幂级数环
    * 多变元扩展
  * 子环与同态
    * 子环定义
    * 子环判别准则
    * 环同态
    * R-代数
  * 整环与域
    * 零因子 (Zerodivisor)
    * 整环 (Integral Domain)
    * 域 (Field)
    * 单位与幂零元
  * 因子分解理论
    * 不可约元素
    * 唯一分解整环 (UFD)
    * 欧几里得整环
````

### 一、环的定义与类型
#### 交换环与子环
>[!note] Definition 1.1 环
>设 $R$ 是一个非空集合，且假设在 $R$ 上定义了两个代数运算 “+”（加法）与 “·”（乘法）。若这两个运算具有如下性质：
>1．$R$ 对于加法 $(R,+)$ 是一个交换群，其恒等元记为 $0_R$，称为零元；
>2．$R$ 对于乘法 $(R,\cdot)$ 是一个半群；
>3．乘法对加法满足分配律：任取 $a,b,c\in R$$$a\cdot(b+c)=a\cdot b+a\cdot c,\quad (b+c)\cdot a=b\cdot a+c\cdot a.$$
>则称 $(R,+,\cdot)$ 是一个**环**，通常我们将其简记为 $R$。
>
>如果环 $R$ 满足 $(R,\cdot)$ 是有恒等元的半群，恒等元记为 $1_R$，称为单位元，则称 $R$ 是一个**有单位元 $1_R$ 的环**。
>
>如果环 $R$ 满足乘法交换律，即：任取 $a,b\in R$，$a\cdot b=b\cdot a$，则称 $R$ 是一个**交换环**。
>
>满足 $1_R = 0_R$ 的环 $R$ 是**零环**。因为这样的环仅由一个元素 $0_{R}$ 组成。

### 二、环的构造
$\qquad$令 $R$ 是一个交换环，可以从 $R$ 构造出两个新的交换环.
1.不定元 $X$ 系数在 $R$ 中的多项式环 $R[X]$ 
2.不定元 $X$ 系数在 $R$ 中的幂级数环 $R[[X]]$ 

#### 幂级数环
$\qquad$$R[[X]]$ 的典型元素是一个“形式幂级数”
$$a_0 + a_1 X + \dots + a_n X^n + \dots$$
$\qquad$其中系数 $a_0, a_1, \dots, a_n, \dots \in R$。（对于每个非负整数 $n$，我们将 $a_n$ 称为上述形式幂级数的第 $n$ 个系数。）尽管使用了符号 “$+$”，读者不应认为在这一初级阶段涉及到了加法：上述表达式实际上只是无穷序列
$$(a_0, a_1, \dots, a_n, \dots)$$
的一种简便记法，从某些观点来看，另一种记法 $\sum_{i=0}^\infty a_i X^i$ 更可取。

$\qquad$$R[[X]]$ 中的两个形式幂级数 $\sum_{i=0}^\infty a_i X^i$ 和 $\sum_{i=0}^\infty b_i X^i$ 被认为相等，当且仅当对于所有整数 $i \geq 0$ 都有 $a_i = b_i$。$R[[X]]$ 中的加法和乘法定义如下：对于所有 $\sum_{i=0}^\infty a_i X^i, \sum_{i=0}^\infty b_i X^i \in R[[X]]$，
$$\sum_{i=0}^\infty a_i X^i + \sum_{i=0}^\infty b_i X^i = \sum_{i=0}^\infty (a_i + b_i) X^i$$
以及
$$\left( \sum_{i=0}^\infty a_i X^i \right) \left( \sum_{j=0}^\infty b_j X^j \right) = \sum_{k=0}^\infty c_k X^k$$
其中，对于每个整数 $k \geq 0$，$c_k = a_0 b_k + a_1 b_{k-1} + \dots + a_k b_0$ .

#### 多项式环
$\qquad$ $R[[X]]$ 的子集，由其中只有**有限个**系数 $a_i$ 为非零的所有形式幂级数 $\sum_{i=0}^\infty a_i X^i$ 组成，对于上述运算也是一个交换环，且具有与 $R[[X]]$ 相同的单位元。它被称为系数在 $R$ 中的 $X$ 的**多项式环**（ring of polynomials），记为 $R[X]$。当系数 $a_n$ 为零时，习惯上从形式幂级数或多项式中省略 “$a_n X^n$” 项。因此，根据这一惯例，$R[X]$ 中的典型多项式具有以下形式：$$a_0 + a_1 X + \dots + a_d X^d$$
$\qquad$对于某些非负整数 $d$，其中 $a_0, \dots, a_d \in R$，此外，上述表达式中的 “$+$” 符号现在确实可以被解释为代表加法。如果我们这里有 $a_d \neq 0$，那么我们称 $d$ 是上述多项式的**次数**（degree）。我们定义零多项式的次数为 $-\infty$。

### 三、子环与同态
由多项式环是幂级数环的子集，$R$ 本身又同时被视为 $R[X]$ 和 $R[[X]]$ 的子集（只保留 $a_{0}$ 系数即可）。从而引入子环的概念。
#### 子环
>[!note] Definition 1.2 子环
>环 $R$ 的子集 $S$ 被称为 $R$ 的一个**子环**（subring），当且仅当 $S$ 本身关于 $R$ 中的运算是一个环，且 $1_S = 1_R$，即 $S$ 的乘法单位元等于 $R$ 的乘法单位元。

容易知道，如果 $R$ 是一个交换环，$X$ 是一个不定元，那么 $R$ 是 $R[X]$ 的子环，也是 $R[[X]]$ 的子环，并且 $R[X]$ 是 $R[[X]]$ 的子环。

对于环 $R$ 的子集 $S$ 成为 $R$ 的子环，有一个简单的判别准则。
>[!summary] Proposition 1.3 子环准则
>令 $R$ 为一个环，并令 $S$ 为 $R$ 的子集。那么 $S$ 是 $R$ 的子环，当且仅当以下条件成立： 
>(i) $1_R \in S$; 
>(ii) $\forall a, b \in S \implies a + b \in S$; 
>(iii) $\forall a \in S \implies -a \in S$; 
>(iv) $\forall a, b \in S \implies ab \in S$。
>注：(ii),(iii)常合并为 $\forall a, b \in S \implies a - b \in S$。

#### 同态
通过环到子环的映射，我们自然引入同态的概念：
>[!note] Definition 1.4 环同态
>令 $f : R \to S$ 是从环 $R$ 到环 $S$ 的映射。那么 $f$ 被称为一个**同态**（homomorphism）（或**环同态**），当且仅当 
>(i) 对于所有 $a, b \in R$，$f(a + b) = f(a) + f(b)$， 
>(ii) 对于所有 $a, b \in R$，$f(ab) = f(a)f(b)$，
>(iii) $f(1_R) = 1_S$。 
>双射环同态被称为**同构**（isomorphism）（或**环同构**）。
>若$f : R \to S$ 是环的一个同构。显然其逆映射$$f^{-1} : S \to R$$也是一个环同构。此时称 $R$ 和 $S$ 是**同构环**（isomorphic rings），我们写成 $R \cong S$。同构是一种等价关系。

$\qquad$例如，如果 $R'$ 是环 $R$ 的子环，那么包含映射 $i : R' \to R$ 是一个单射环同态。事实上，在很多情况下，我们使用单射环同态 $f : T \to R$ 从环 $T$ 到环 $R$ 来将 $T$ 的元素识别为 $R$ 的元素。

$\qquad$为了给出代数的定义，我们需要介绍一个引理:
>[!Theorem] Lemma 1.5 
>令 $f : R \to S$ 为环的一个同态。那么 $f$ 的像 $\text{Im} f$ 是 $S$ 的子环。

#### R-代数
$\qquad$R-代数本质是将环 $R$ 的元素“放入”环 $S$ 中进行操作。而由引理 $\mathrm{Im} f$ 就是 $S$ 的一个子环
>[!note] Definition 1.6 R-代数
>令 $R$ 为一个交换环。 **$R$-代数**（$R$-algebra）是指一个配备了环同态 $f : R \to S$ 的环 $S$。

因此，同态 $f$ 被视为 $R$-代数 $S$ 结构的一部分。
此时，$S$ 凭借包含同态自动成为其子环 $\text{Im } f$ 之上的一个代数。因为有**包含映射（Inclusion Map）**：$$\displaylines{\iota: \text{Im} f \hookrightarrow S\\\iota(x) = x, \quad \forall x \in \text{Im} f}$$是一个环同态。

>[!Theorem] Theorem 1.7 
>每一个环都是一个 $\mathbb{Z}$-代数。

设 $R$ 为一个环。那么由对于映射$$\displaylines{f: \mathbb{Z} \to R\\ \forall n \in \mathbb{Z}，f(n) = n(1_R)}$$是一个环同态，并且实际上是从 $\mathbb{Z}$ 到 $R$ 的唯一环同态。
这里，$$n(1_R) = \begin{cases} 1_R + \dots + 1_R \quad (n \text{ 项}) & \text{当 } n > 0 \text{ 时}, \\ 0_R & \text{当 } n = 0 \text{ 时}, \\ (-1_R) + \dots + (-1_R) \quad (-n \text{ 项}) & \text{当 } n < 0 \text{ 时}. \end{cases}$$

$\qquad$由于环 $R$ 的子环的任何非空族的交集仍然是 $R$ 的一个子环。这一观察引出了下面的引理。在陈述它之前，适当地指出一个惯例：对于 $a \in R$，符号 $a^0$ 被解释为 $1_R$。
$\qquad$设 $S$ 为环 $R$ 的一个子环，并设 $\Gamma$ 为 $R$ 的一个子集。那么定义 $S[\Gamma]$ 定义为 $R$ 的所有既包含 $S$ 又包含 $\Gamma$ 的子环的交集。（当然至少存在一个这样的子环，即 $R$ 本身。）
$\qquad$因此 $S[\Gamma]$ 是 $R$ 的一个包含 $S$ 和 $\Gamma$ 的子环，并且它是这种意义下最小的子环：它包含在 $R$ 的每一个既包含 $S$ 又包含 $\Gamma$ 的其他子环中。
$\qquad$在 $\Gamma$ 是有限集 $\{\alpha_1, \alpha_2, \dots, \alpha_n\}$ 的情况下，我们将 $S[\Gamma]$ 写为 $S[\alpha_1, \alpha_2, \dots, \alpha_n]$。
>[!Theorem] Lemma 1.8
>在 $S$ 是交换的，且 $\alpha \in R$ 满足 $\forall s \in S,\alpha s = s \alpha$ 时，我们有$$S[\alpha] = \left\{ \sum_{i=0}^t s_i \alpha^i : t \in \mathbb{N}_0, s_0, \dots, s_t \in S \right\}.$$

>[!proof]+
>令
$$H = \left\{ \sum_{i=0}^t s_i \alpha^i : t \in \mathbb{N}_0, s_0, \dots, s_t \in S \right\}.$$由于 $S$ 是交换的且对于所有 $s \in S$ 都有 $a s = s a$，从子环准则可以得到 $H$ 是 $R$ 的一个子环；
>它还包含 $S$ 且 $\alpha = (1_S)\alpha$。因此$$S[\alpha] \subseteq H.$$
>另一方面，设 $R'$ 是 $R$ 的任意一个子环，且满足 $S \subseteq R'$ 且 $\alpha \in R'$，既然 $\alpha \in R'$，那么根据子环准则 (iv)，$\alpha \cdot \alpha = \alpha^2$ 必须在 $R'$ 中。通过数学归纳法，对于任何 $i \in \mathbb{N}_0$，$\alpha^i$ 都必须在 $R'$ 中。既然 $s_i \in S \subseteq R'$ 且 $\alpha^i \in R'$，那么它们的乘积 $s_i \alpha^i$ 也必须在 $R'$ 中。它们的有限和 $\sum_{i=0}^{t} s_i \alpha^i$ 必然也落在 $R'$ 中，因此 $H \subseteq R'$， $S[\alpha] = H$。 $\square$

$\qquad$注意，当 $R$ 是一个交换环且 $X$ 是一个不定元时，我们早期使用 $R[X]$ 来表示多项式环，与现在使用 $R[X]$ 来表示上述定义（所有包含子环 $R$ 与子集 $X$ 的子环的交）是一致的。类似的评注也适用于我们早期对高斯整数环的记法 $\mathbb{Z}[i]$，所有复数的集合 $\mathbb{C}$ 关于复数的普通加法和乘法是一个环，并且由于 $i^2 = -1$，高斯整数环是 $\mathbb{C}$ 的既包含 $\mathbb{Z}$ 又包含 $i$ 的最小子环。 

>[!question] Exercise 1.9
>设 $S$ 为交换环 $R$ 的子环，并设 $\Gamma, \Delta$ 为 $R$ 的子集。证明 $$S[\Gamma \cup \Delta] = S[\Gamma][\Delta]$$且$$S[\Gamma] = \bigcup_{\Omega \subseteq \Gamma, |\Omega| < \infty} S[\Omega].$$

解答参见：[[习题解答]]

#### 多项式环的多变元扩展
$\qquad$多项式环 $R[X]$（其中 $R$ 是交换环）具有下述引理中描述的“泛性质”（universal property）。
>[!Theorem] Lemma 1.10 多项式的泛性
>设 $R$ 为一个交换环，并设 $X$ 为一个不定元；设 $T$ 为一个 $R$-代数，其结构环同态为 $f: R \to T$；并设 $\alpha \in T$。那么存在唯一的环同态 $f_1 : R[X] \to T$，它是 $f$ 的扩张（即满足 $f_1|_R = f$），并且满足 $f_1(X) = \alpha$。

$\qquad$这个引理本质上是在数学上严谨地定义了**多项式求值**操作。$f_{1}$ 也常被称为**代入映射**。简单来说，泛性质指出：你可以在多项式中用环 $T$ 的任意元素 $\alpha$ 代替变量 $X$，并且这种代入行为是自洽的（构成一个环同态）。
一个简单的例子：
$R$： 实数域 $\mathbb{R}$。
$T$： 复数域 $\mathbb{C}$。
$f$： 自然包含映射 $f: \mathbb{R} \hookrightarrow \mathbb{C}$，即把实数 $r$ 看作虚部为 $0$ 的复数 $r + 0i$。
$\alpha$： 虚数单位 $i \in \mathbb{C}$。
$f_1$： 唯一的环同态 $f_1: \mathbb{R}[X] \to \mathbb{C}$，它把多项式 $P(X)$ 中的 $X$ 替换为 $i$。

$\qquad$再次考虑不定元 $X$ 系数在交换环 $R$ 中的多项式环 $R[X]$（我们有时说“在 $R$ 上的多项式环”），如果我们再在另一个不定元 $Y$ 上形成多项式环，会发生什么？新环可以记为 $R[X][Y]$，根据1.9，也可以记为 $R[X, Y]$；
$\qquad$$R[X][Y]$ 的典型元素具有形式
$$f_0 + f_1 Y + \dots + f_n Y^n$$
对于某些 $n \in \mathbb{N}_0$ 且 $f_0, \dots, f_n \in R[X]$，因此可以表示为如下形式的表达式的有限和
$$r_{ij} X^i Y^j,$$
其中 $i, j \in \mathbb{N}_0$，$r_{ij} \in R$。此外，容易看出如下形式的表达式
$$\sum_{i=0}^n \sum_{j=0}^m s_{ij} X^i Y^j$$
（其中 $n, m \in \mathbb{N}_0$ 且 $i = 0, \dots, n, j = 0, \dots, m$，$s_{ij} \in R$）在 $R[X][Y]$ 中等于零，当且仅当对于所有 $i = 0, \dots, n, j = 0, \dots, m$ 都有 $s_{ij} = 0$。我们通过称 $X$ 和 $Y$ 在 $R$ 上是“**代数独立的**”来描述这一性质。
上述想法可以很容易地从 2 个不定元推广到任意有限个不定元。
>[!note] Definition 1.11 代数独立
>设 $R$ 为一个交换环，并设 $\alpha_1, \dots, \alpha_n \in R$；设 $R_0$ 为 $R$ 的一个子环。那么 $\alpha_1, \dots, \alpha_n$ 被称为在 $R_0$ 上**代数独立**（algebraically independent ）（严格来说，我们应该说族 $(\alpha_i)_{i=1}^n$ 在 $R_0$ 上代数独立），当且仅当满足以下条件：每当 $\Lambda$ 是 $\mathbb{N}_0^n$ 的有限子集且元素$$r_{i_1, \dots, i_n} \in R_0 \quad ((i_1, \dots, i_n) \in \Lambda)$$满足$$\sum_{(i_1, \dots, i_n) \in \Lambda} r_{i_1, \dots, i_n} \alpha_1^{i_1} \dots \alpha_n^{i_n} = 0,$$则对于所有 $i \in \Lambda$ 都有 $r_i = 0$。

设 $R$ 为一个交换环，并设 $n$ 为一个正整数。通过依次定义 $R_0 = R$，$R_i = R_{i-1}[X_i]$（对于 $i = 1, \dots, n$）来形成多项式环，其中 $X_1, \dots, X_n$ 是不定元。那么： 
(i) $R_n = R[X_1, \dots, X_n]$; 
(ii) $X_1, \dots, X_n$ 在 $R$ 上代数独立;
(iii) $R_n$ 的元素具有形式$$\sum_{(i_1, \dots, i_n) \in \Lambda} r_{i_1, \dots, i_n} X_1^{i_1} \dots X_n^{i_n}$$其中 $\Lambda$ 是 $\mathbb{N}_0^n$ 的某个有限子集，且 $r_{i_1, \dots, i_n} \in R \quad ((i_1, \dots, i_n) \in \Lambda)$，并且，如果它非零，那么它的（总）**次数**被定义为最大的 $d \in \mathbb{N}_0$，使得存在 $(i_1, \dots, i_n) \in \Lambda$ 满足 $i_1 + \dots + i_n = d$ 且 $r_{i_1, \dots, i_n} \neq 0$；
(iv) 与单变量的情况一样，零元素的（总）次数被定义为 $-\infty$。
我们将把 $R_n$ 称为系数在 $R$ 中的（或在 $R$ 上的）$n$ 个不定元 $X_1, \dots, X_n$ 的**多项式环**。

>[!question] Exercise 1.12
>设 $R'$ 为一个交换环，并设 $\xi_1, \dots, \xi_n \in R'$ 在 $R'$ 的子环 $R$ 上代数独立。设 $T$ 为一个交换 $R$-代数，其结构环同态为 $f: R \to T$，并设 $\alpha_1, \dots, \alpha_n \in T$。证明存在恰好一个环同态
>$$g: R[\xi_1, \dots, \xi_n] \to T$$
>它是 $f$ 的扩张（即满足 $g|_R = f$），并且满足对于所有 $i = 1, \dots, n$，$g(\xi_i) = \alpha_i$。
>由此推导出一个（唯一的）环同构
>$$h: R[\xi_1, \dots, \xi_n] \to R[X_1, \dots, X_n],$$
>其中 $R[X_1, \dots, X_n]$ 表示$X_1, \dots, X_n$ 的多项式环，使得对于所有 $i = 1, \dots, n$，$h(\xi_i) = X_i$，且 $h|_R: R \to R$ 是恒等映射。

这个练习展示了上述多项式环 $R[X_1, \dots, X_n]$ 具有一个类似于1.10中的泛性质。
$\qquad$上述练习引出了多项式的“求值”（evaluation）的想法。
>[!note] Definition 1.13 求值
>设 $R$ 为交换环 $S$ 的一个子环，并考虑 $R$ 上 $n$ 个不定元 $X_1, \dots, X_n$ 的多项式环 $R[X_1, \dots, X_n]$。令 $\alpha_1, \dots, \alpha_n \in S$。根据 1.12，存在唯一的环同态 $g: R[X_1, \dots, X_n] \to S$，具有如下性质:
>$$g(r) = r \quad \forall   r \in R$$以及
>$$g(X_i) = \alpha_i \quad \forall i = 1, \dots, n.$$这个同态 $g$ 被称为在 $\alpha_1, \dots, \alpha_n$ 处的**求值同态**（evaluation homomorphism），或简称为**求值**。

$\qquad$很明显，$g$ 对元素 $p \in R[X_1, \dots, X_n]$ 的作用，就是简单地通过将每一个出现的 $X_i$ 替换为 $\alpha_i$（对于每个 $i = 1, \dots, n$）来算得。由于这个原因，$g$ 有时被称为“将 $X_i = \alpha_i$（对于 $i = 1, \dots, n$）代入后的结果”。我们以后会将 $p$ 在求值同态 $g$ 下的像写为
$$p(\alpha_1, \dots, \alpha_n)$$
但在某些场合，不应该混淆多项式的概念与函数的概念。下面的练习说明了这一点。
>[!question] Exercise 1.14
>令 $p = X^7 - X \in \mathbb{Z}_7[X]$。证明对于所有 $\alpha \in \mathbb{Z}_7$，都有 $p(\alpha) = 0$。

参见[[习题解答]]

$\qquad$这个练习展示了一个在有限域中非常重要的概念：多项式和多项式函数是不同的对象。
多项式 (Polynomial)： 在 $\mathbb{Z}_7[X]$ 中，$p = X^7 - X$ 是一个**非零多项式**，因为它的系数（$1$ 和 $-1$）并不都是零。
多项式函数 (Polynomial Function)： 尽管 $p$ 是非零多项式，但它在整个 $\mathbb{Z}_7$ 上诱导出的函数却是零函数。
这种“非零多项式对应零函数”的情况只会在有限环中出现。如果你在实数域 $\mathbb{R}$ 中，一个非零多项式是不可能在所有点都取值为 $0$ 的。

>[!question] Exercise 1.15
>设 $K$ 为一个无限域，设 $\Lambda$ 为 $K$ 的一个有限子集，并设 $f \in K[X_1, \dots, X_n]$，即 $K$ 上不定元 $X_1, \dots, X_n$ 的多项式环。假设 $f \neq 0$。证明存在无限多种$$(\alpha_1, \dots, \alpha_n) \in (K \setminus \Lambda)^n$$的选择，使得 $f(\alpha_1, \dots, \alpha_n) \neq 0$。

#### 幂级数环的多变元扩展
$\qquad$设 $R$ 为一个交换环，并设 $X_1, \dots, X_n$ 为不定元。我们可以通过以下归纳程序连续地形成幂级数环：设定 $R_0 = R$，并且对于每一个满足 $0 < i \le n$ 的 $i \in \mathbb{N}$，设定$$R_i = R_{i-1}[[X_i]].$$
这样的幂级数环在交换代数中非常重要。
$\qquad$我们引入 $R[X_1, \dots, X_n]$ 中**齐次多项式**（homogeneous polynomial）的概念：如果该环中的一个多项式具有以下形式，则称其为齐次的，或称为一个**型**（form）：
$$\sum_{i_1 + \dots + i_n = d} r_{i_1, \dots, i_n} X_1^{i_1} \dots X_n^{i_n}$$
对于某个 $d \in \mathbb{N}_0$ 和某些 $r_{i_1, \dots, i_n} \in R$。 （因此，实际出现在该多项式中的任何非零项的次数均为 $d$。）注意，零多项式也被认为是齐次的。
$\qquad$我们可以使用齐次多项式的概念来描述环 $R_1 = R[[X_1]]$ 的元素：$R_1$ 的任意元素都可以表示为形式和
$$\sum_{i=0}^{\infty} f_i$$
其中 $f_i$ 是 $R[X_1]$ 中的齐次多项式，其要么为 0，要么次数为 $i$（对于每个 $i \in \mathbb{N}_0$）。
$\qquad$考虑到这一点，我们现在引入另一个可以由 $R$ 和上述不定元 $X_1, \dots, X_n$ 构造的环。这就是系数在 $R$ 中的 $X_1, \dots, X_n$ 的**形式幂级数环**（ring of formal power series），记作
$$R[[X_1, \dots, X_n]]$$
该环的元素是如下形式的形式和
$$\sum_{i=0}^{\infty} f_i$$
其中对于每个 $i \in \mathbb{N}_0$，$f_i$ 是 $R[X_1, \dots, X_n]$ 中的齐次多项式，其要么为 0，要么次数为 $i$。两个这样的“形式幂级数” $\sum_{i=0}^{\infty} f_i$ 和 $\sum_{i=0}^{\infty} g_i$ 被认为是相等的，当且仅当对于所有 $i \in \mathbb{N}_0$ 都有 $f_i = g_i$。加法和乘法运算定义为
$$\left( \sum_{i=0}^{\infty} f_i \right) + \left( \sum_{i=0}^{\infty} g_i \right) = \sum_{i=0}^{\infty} (f_i + g_i)$$
$$\left( \sum_{i=0}^{\infty} f_i \right) \left( \sum_{i=0}^{\infty} g_i \right) = \sum_{i=0}^{\infty} \left( \sum_{j=0}^{i} f_j g_{i-j} \right)$$
 对于所有 $\sum_{i=0}^{\infty} f_i, \sum_{i=0}^{\infty} g_i \in R[[X_1, \dots, X_n]]$。易知，这些定义确实赋予了 $R[[X_1, \dots, X_n]]$ 交换环的结构。
>[!question] Exercise 1.16
>设 $R$ 为一个交换环，并设 $X_1, \dots, X_n$（其中 $n > 1$）为不定元。定义映射$$\psi : R[[X_1, \dots, X_{n-1}]][[X_n]] \to R[[X_1, \dots, X_n]]$$如下：对于每个$$f = \sum_{i=0}^{\infty} f_{(i)} X_n^i \in R[[X_1, \dots, X_{n-1}]][[X_n]]$$其中$f_{(i)} = \sum_{j=0}^{\infty} f_{(i)j} \in R[[X_1, \dots, X_{n-1}]]$
>对于每个 $i \in \mathbb{N}_0$（使得每个 $f_{(i)j}$ 为 0 或为 $X_1, \dots, X_{n-1}$ 中的 $j$ 次齐次多项式），令$$\psi(f) = \sum_{k=0}^{\infty} \left( \sum_{j=0}^{k} f_{(k-j)j} X_n^{k-j} \right)$$证明 $\psi$ 是一个环同构。

### 四、整环与域
>[!note] Definition 1.17 零因子
>设 $R$ 为一个交换环。$R$ 中的一个**零因子**（zerodivisor）是指一个元素 $r \in R$，使得存在 $y \in R$ 且 $y \neq 0_R$，满足 $ry = 0_R$。$R$ 中不是零因子的元素称为**非零因子**（non-zerodivisor）。$R$ 中零因子的集合通常记作 $\text{Zdv}(R)$。

如果 $R$ 是非平凡的，那么显然 $0_R$ 是 $R$ 中的一个零因子。
>[!note] Definition 1.18 整环
>设 $R$ 为一个交换环。当且仅当满足以下条件时，称 $R$ 为一个**整环**（integral domain）：
> (i) $R$ 是非平凡的，即 $1_R \neq 0_R$ ；
> (ii) $0_R$ 是 $R$ 中唯一的零因子。

$\qquad$整数环 $\mathbb{Z}$ 和高斯整数环 $\mathbb{Z}[i]$ 都是整环，我们考虑如何从旧的整环中产生新的整环。
>[!summary] Proposition 1.19 构造整环
>设 $R$ 为一个整环，并设 $X$ 为一个不定元。那么多项式环 $R[X]$ 也是一个整环。

$\qquad$特别地，这一结果表明，在 $\mathbb{Z}$ 上的不定元 $X_1, \dots, X_n$ 的多项式环
$$\mathbb{Z}[X_1, \dots, X_n]$$
再次是一个整环。
$\qquad$并不是每个非平凡的交换环都是整环，模 6 的剩余类环 $\mathbb{Z}_6$ 不是整环（$2 \times 3 \equiv 0$）；此外，定义在闭区间 $[0, 1]$ 上的连续实值函数环 $C[0, 1]$ 也不是整环。

>[!note] Definition 1.20 单位
>设 $R$ 为一个交换环。$R$ 的一个**单位**（unit）是指一个元素 $r \in R$，使得存在 $u \in R$ 满足 $ru = 1_R$。当 $r \in R$ 是 $R$ 的一个单位时，恰好存在一个元素 $u \in R$ 具有性质 $ru = 1_R$；该元素称为 $r$ 的**逆**（inverse），记作 $r^{-1}$。

$\qquad$$R$ 中所有单位的集合关于 $R$ 的乘法构成一个阿贝尔群。
>[!note] Definition 1.21 域
>设 $R$ 为一个交换环。那么当且仅当满足以下条件时，我们称 $R$ 是一个**域**（field）： 
>(i) $R$ 是非平凡的（即 $1_R \neq 0_R$）
>(ii) $R$ 的每个非零元素都是单位。

#### 域与整环的一些初等关系
$\qquad$每个域都是一个整环。逆命题并不成立：$\mathbb{Z}$ 是一个整环但不是域的例子。
>[!Theorem] Lemma 1.21
>每个有限整环都是一个域。

>[!Theorem] Lemma 1.22
>设 $n \in \mathbb{N}$ 且 $n > 1$。那么关于模 $n$ 的剩余类环 $\mathbb{Z}_n$，下列命题是等价的： 
>(i) $\mathbb{Z}_n$ 是一个域； 
>(ii) $\mathbb{Z}_n$ 是一个整环；
>(iii) $n$ 是一个素数。

$\qquad$由1.19，如果 $K$ 是任意域，那么在 $K$ 上的 $n$ 个不定元 $X_1, \dots, X_n$ 的多项式环 $K[X_1, \dots, X_n]$ 自动是一个整环。
>[!question] Exercise 1.23
>设 $R$ 为一个交换环，并设 $X$ 为一个不定元。证明 $R[X]$ 不可能是一个域。同时也证明，如果 $R[X]$ 是一个整环，那么 $R$ 也是。

参见[[习题解答]]

>[!question] Exercise 1.24
>设 $R$ 为一个交换环。证明 $R$ 是一个整环，当且仅当在 $n$ 个不定元 $X_1, \dots, X_n$ 中的形式幂级数环 $R[[X_1, \dots, X_n]]$ 是一个整环。

充分性是容易的，$R$ 自然地同构于 $R[[X_1, \dots, X_n]]$ 中由所有常数项构成的子环。
必要性，采用是数学归纳法。

#### 整环的分式域
$\qquad$设 $R$ 为一个整环。那么存在一个域 $F$ 和一个单射环同态 $f : R \to F$，使得 $F$ 的每个元素都可以写成 $f(r)f(s)^{-1}$ 的形式，其中 $r, s \in R$ 且 $s \neq 0_R$。
$\qquad$令 $S = R \setminus \{0_R\}$。我们在 $R \times S$ 上定义一个等价关系 $\sim$ 如下：对于 $(a, b), (c, d) \in R \times S$，我们记
$$(a, b) \sim (c, d) \iff ad = bc$$
直接检查即可发现 $\sim$ 是 $R \times S$ 上的一个等价关系：对于 $(a, b) \in R \times S$，我们将包含 $(a, b)$ 的等价类记作 $a/b$ 或
$$\frac{a}{b}$$
所有 $\sim$ 等价类的集合 $F$ 可以在如下定义的加法和乘法运算下被赋予域的结构：
$$\frac{a}{b} + \frac{c}{d} = \frac{ad + bc}{bd}, \quad \frac{a}{b} \frac{c}{d} = \frac{ac}{bd}$$
对于所有 $a/b, c/d \in F$；该域的零元素是 $0/1$，单位元是 $1/1$（其等于每个 $a \in R \setminus \{0\}$ 的 $a/a$）。
映射
$$f : R \to F$$
由对于所有 $a \in R$，$f(a) = a/1$ 定义，是一个具有所有期望性质的单射环同态。
>[!note] Definition 1.25 分式域
>设 $R$ 是一个整环，其分式域 $F$ 是由所有形式为 $\frac{a}{b}$（其中 $a,b \in R,b \ne 0$的元素构成的域，且定义了封闭的加法和乘法。(如上述叙述所示)

#### 幂零元
>[!note] Definition 1.26 幂零元
>设 $R$ 为一个交换环。$R$ 的一个元素 $r$ 被称为是**幂零的**（nilpotent），当且仅当存在 $n \in \mathbb{N}$ 使得 $r^n = 0$。

>[!question] Exercise 1.27
> 确定环 $\mathbb{Z}_{12}$ 中所有的幂零元素和所有的单位。对于满足 $n > 1$ 的 $n \in \mathbb{N}$，确定环 $\mathbb{Z}_n$ 中所有的幂零元素和所有的单位。

在 $\mathbb{Z}_n$ 中，$x$ 是单位的充要条件是 $\gcd(x, n) = 1$。
在 $\mathbb{Z}_n$ 中，$x$ 是幂零元的充要条件是：$n$ 的所有质因子都能整除 $x$。
参见[[习题解答]]

>[!question] Exercise 1.28
>设 $R$ 为一个交换环，并设 $x, y \in R$。证明对于 $n \in \mathbb{N}$，$$(x + y)^n = \sum_{i=0}^n \binom{n}{i} x^{n-i} y^i$$由此推导出 $R$ 的两个幂零元素之和仍然是幂零的。

>[!question] Exercise 1.29
>设 $R$ 为一个交换环，并设 $X$ 为一个不定元；令$$f = r_0 + r_1 X + \dots + r_n X^n \in R[X]$$
>证明：
>(i) $f$ 是 $R[X]$ 的一个单位，当且仅当 $r_0$ 是 $R$ 的一个单位，且 $r_1, \dots, r_n$ 都是幂零的。
>(ii) $f$ 是幂零的，当且仅当 $r_0, \dots, r_n$ 都是幂零的。
>(iii) $f$ 是 $R[X]$ 中的一个零因子，当且仅当存在 $c \in R$ 且 $c \neq 0$ 使得 $cf = 0$。

提示(i)：如果 $n > 0$ 且 $f$ 是 $R[X]$ 的单位，其逆为 $a_0 + a_1 X + \dots + a_m X^m$，通过对 $i$ 进行归纳证明 $r_n^{i+1} a_{m-i} = 0$，对于 $i = 0, \dots, m$。
提示(iii)：如果 $f$ 是 $R[X]$ 中的一个零因子，选择一个$$0 \neq g = c_0 + c_1 X + \dots + c_k X^k \in R[X]$$具有最小次数 $k$ 使得 $fg = 0$，并通过归纳证明对于每个 $i = 0, \dots, n$ 都有 $r_{n-i} g = 0$。）
参见[[习题解答]]

>[!question] Exercise 1.30
>将 1.29 的结果推广到在交换环 $R$ 上的 $n$ 个不定元 $X_1, \dots, X_n$ 的多项式环$$R[X_1, \dots, X_n]$$

#### 整环中的因子分解理论
>[!note] Definition 1.31 不可约元
>设 $R$ 为一个整环。当且仅当满足以下条件时，称元素 $p \in R$ 是 $R$ 的一个**不可约元**（irreducible element）：
> (i) $p \neq 0$ 且 $p$ 不是 $R$ 的单位
>  (ii) 每当 $p$ 表示为 $p = ab$ 且 $a, b \in R$ 时，则 $a$ 或 $b$ 必有一个是 $R$ 的单位。

>[!note] Definition 1.32 唯一分解整环UFD
>设 $R$ 为一个整环。当且仅当满足以下条件时，我们称 $R$ 是一个**唯一分解整环**（unique factorization domain，简称 UFD）：
>(i) $R$ 的每个非零、非单位元素都可以表示为 $p_1 p_2 \dots p_s$ 的形式，其中 $p_1, \dots, p_s$ 是 $R$ 的不可约元素，且
>(ii) 每当 $s, t \in \mathbb{N}$ 且 $p_1, \dots, p_s, q_1, \dots, q_t$ 是 $R$ 的不可约元素使得$$p_1 p_2 \dots p_s = q_1 q_2 \dots q_t$$则 $s = t$，且存在单位 $u_1, \dots, u_s \in R$ 使得在对 $q_j$ 进行适当的重新编号后，有$$p_i = u_i q_i \quad  i = 1, \dots, s$$

>[!note] Definition 1.33 欧几里得整环
>整环 $R$ 被称为一个**欧几里得整环**（Euclidean domain），当且仅当
>存在一个函数 $\partial : R \setminus \{0\} \to \mathbb{N}_0$，称为 $R$ 的**度数函数**（degree function），使得：
>(i) 每当 $a, b \in R \setminus \{0\}$ 且 $a$ 是 $R$ 中 $b$ 的一个因子（即存在 $c \in R$ 满足 $ac = b$）时，有 $\partial(a) \le \partial(b)$
>(ii) 每当 $a, b \in R$ 且 $b \neq 0$ 时，则存在 $q, r \in R$ 使得$$a = qb + r $$其中要么 $r=0$，要么 $\partial(r) < \partial(b)$。

关于欧几里得整环和 UFD 的两个基本事实：
>[!Theorem] Theorem 1.34
>每个欧几里得整环都是唯一分解整环。

>[!Theorem] Theorem 1.35
>如果 $R$ 是一个唯一分解整环，那么在不定元 $X$ 上的多项式环 $R[X]$ 也是一个唯一分解整环。

从这两个定理可以立即推导出，如果 $K$ 是一个域，那么在 $n$ 个不定元 $X_1, \dots, X_n$ 上的多项式环 $K[X_1, \dots, X_n]$ 是一个 UFD；此外，环 $\mathbb{Z}[Y_1, \dots, Y_m]$ 也是 UFD 的另一个例子。

>[!question] Exercise 1.36
>设 $R$ 为一个交换环，并考虑在不定元 $X_1, \dots, X_n$ 上的 $R$ 上的形式幂级数环 $R[[X_1, \dots, X_n]]$。令$$f = \sum_{i=0}^{\infty} f_i \in R[[X_1, \dots, X_n]]$$其中 $f_i$ 是 $R[X_1, \dots, X_n]$ 中的零或 $i$ 次齐次多项式（对于每个 $i \in \mathbb{N}_0$）。证明 $f$ 是 $R[[X_1, \dots, X_n]]$ 的单位，当且仅当 $f_0$ 是 $R$ 的单位。

注：第一章的主要内容是在回顾抽象代数的环论相关知识，因此并不会在习题的解答与定理的阐述上讲的太详细。