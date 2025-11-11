有限交换群是一类结构相对简单的群，人们已经能够将这类群进行完全分类。而有限非交换群的结构远比有限交换群复杂。本节将要介绍的 Sylow 定理是人们研究有限非交换群的结构非常核心的工具。
设 $G$ 是一个有限群，任取 $G$ 的子群 $H$，则由 Lagrange 定理知，$|H| \big| |G|$。反过来，人们会问 Lagrange 定理的逆命题是否也成立呢？即：任取 $|G|$ 的一个因子 $m$，是否存在子群 $H$ 使得 $|H| = m$？一般来讲，这是不成立的，例如，交错群 $A_n$ ($n \geqslant 5$) 不含阶为 $\frac{n!}{4}$ 的子群。
接下来，我们主要讨论：对于 $|G|$ 的一个因子 $m$，当 $m$ 满足什么条件是，我们能够找到 $G$ 的子群 $H$ 使得 $|H| = m$。

在此之前，先介绍一类特殊的群：
>[!note] Def 1.12.1 p-群
>设 $p$ 为一个素数，$G$ 是一个有限群。若存在正整数 $k$ 使得 $|G| = p^k$ 则称群 $G$ 是一个 **$p$-群** .

我们来探讨 $p$-群的性质，来研究前言所述的问题。
>[!summary] Property 1.12.1
>$p$-群必有非平凡的中心，即 $Z(G)\ne \{ e \}$ .

>[!proof]+
>假如 $Z(G)=\{ e \}$，对于不在中心的元素 $x_{i}$，其中心化子 $C_{G}(x_{i})$ 是 $G$ 的真子群 . 从而根据 Lagrange 定理，因此 $|C_{G}(x_{i})|=p^{m_{i}}\ (0<m_{i}<k)$ 
>从而根据群的类方程：$$|G|=|Z(G)|+\sum_{i \in I}|C_{G}(x_{i})|=1+\sum_{i \in I}p^{m_{i}} $$ 这与 $p \big||G|$ 矛盾，从而 $Z(G)\ne \{ e \}$ .


>[!summary] Property 1.12.2
>设 $G$ 是一个 $p$-群，$G$ 作用在一个有限集 $X$ 上，且假设 $|X| = n$。若 $t$ 为 $X$ 中在 $G$ 的作用下不动元素的个数，则 $t \equiv n \pmod{p}$ .

>[!proof]+
>由于 $X$ 中的轨道给定了集合 $X$ 的一个划分 . 从而 $$|X|=|\bigcup_{i \in I}\mathcal{O_{x_{i}}}|=\sum_{i \in I}|\mathcal{O_{x_{i}}}|=\sum_{i \in I}[G:S_{x_{i}}]$$其中 $S_{x_{i}}$ 是 $x_{i}$ 的稳定子群 .
>设 $|G|=p^{a}$，其子群的阶也是 $p$ 的幂次，设 $|S_{x_{i}}|=p^{b}$ ，则 $|\mathcal{O_{x_{i}}}|=[G:S_{x_{i}}]=\displaystyle\left|\frac{G}{S_{x_{i}}}\right|=p^{a-b}$ .
>我们将 $X$ 的轨道分为两类： 
>1. 不动点轨道 
>   对于 $x \in X$ ，若 $g.x=x$ 对任意 $g \in G$ 成立，则$\mathcal{O_{x}}=\{ x \}$，$|\mathcal{O_{x}}|=1$ . 此时不动点个数设为 $t$，则所有大小为1的轨道的个数也为 $t$ .
>2. 非平凡轨道
>   轨道大小大于 $1$ 的轨道。 对于 $x \in X$，如果 $|O(x)| > 1$，则 $p^{a-b} > 1 \implies a-b > 0$。 因此，对于所有非平凡轨道 $\mathcal{O_{x}}$，其大小 $|O(x)|$ 是 $p$ 的一个正幂次，故 $|\mathcal{O_{x}}|$ 是 $p$ 的倍数 .
>从而 $$n=|X|=\big|\bigcup_{|\mathcal{O_{x}}|=1} \mathcal{O_{x}}\big|+\big|\bigcup_{|\mathcal{O_{x}}|>1} \mathcal{O_{x}}\big|=t+p^{k}$$于是有 $t \equiv n \pmod{p}$ .

>[!summary] Property 1.12.3
>设 $G$ 是一个 $p-$群，若 $|G|=p^{n}$，则对任意整数 $m \in (0,n]$，存在子群 $H$ 使得 $|H|=p^{m}$ .

请读者自己证明。提示：运用归纳法

有了上述的简单讨论之后，我们要介绍一系列重要的定理——Sylow 定理，它揭示了我们能找到怎样的子群。
我们先给出 Sylow p-子群的定义
>[!note] Def 1.12.2 Sylow p-子群
>设 $p$ 是一个素数，$l$，$m$ 是正整数，$G$ 是一个有限群。当 $|G| = p^l m$，$(p, m) = 1$ 时，$G$ 有阶为 $p^l$ 的子群，此时，我们称 $G$ 中阶为 $p^l$ 的子群为 $G$ 的 Sylow $p$-子群 .

换句话说，$\mathrm{Sylow}$ $p-$子群的阶 $p^{l}$ 是整除有限群 $G$ 的阶的素数 $p$ 的最高幂次

在介绍 $\mathrm{Sylow}$ 定理之前，先要补充一个数论命题：
>[!Theorem] Lemma 1.12.1
>$p^r | m \Leftrightarrow \displaystyle p^r | \binom{p^\alpha m}{p^\alpha}$ . $p$ 是素数，$\alpha \geqslant 1$ 是整数，$m \geqslant 1$ 是整数

>[!proof]+
>首先有
>$$\binom{p^\alpha m}{p^\alpha} = \frac{p^\alpha m \cdot (p^\alpha m - 1) \cdots (p^\alpha m - (p^\alpha - 1))}{p^\alpha \cdot (p^\alpha - 1) \cdots 1}= m \cdot \frac{(p^\alpha m - 1) \cdots (p^\alpha m - (p^\alpha - 1))}{(p^\alpha - 1) \cdots 1}$$定义 $\nu_p(x)$ 为整除整数 $x$ 的最高次幂 $p^r$ 的指数 $r$ . 令$$K = \frac{(p^\alpha m - 1) \cdots (p^\alpha m - (p^\alpha - 1))}{(p^\alpha - 1) \cdots 1} = \frac{\prod_{k=1}^{p^\alpha-1} (p^\alpha m - k)}{\prod_{k=1}^{p^\alpha-1} (p^\alpha - k)}$$因此，我们有$$\nu_p\left(\binom{p^\alpha m}{p^\alpha}\right) = \nu_p(m) + \nu_p(K)$$
>我们的目标是证明 $\nu_p(K) = 0$，即证明 $p$ 不整除 $K$，或者说 $K$ 中分子和分母所包含的 $p$ 的幂次完全抵消。
>断言：对于每个 $k \in \{1, \ldots, p^\alpha - 1\}$，有$$\nu_p(p^\alpha m - k) = \nu_p(p^\alpha - k) = \nu_p(k)$$接下来证明这个命题：
>设 $s = \nu_p(k)$， 因为 $1 \leqslant k < p^\alpha$，所以 $p^s | k$，但 $p^{s+1} \nmid k$。并且 $s \leqslant \alpha - 1$（因为如果 $s = \alpha$，则 $p^\alpha | k$，与 $k < p^\alpha$ 矛盾）。 我们写 $k = p^s \cdot j$，其中 $p \nmid j$ .
>分析 $K$ 分母项：
>$$p^\alpha - k = p^\alpha - p^s j = p^s (p^{\alpha-s} - j)$$
因为 $s \leqslant \alpha - 1$，所以 $\alpha - s \geqslant 1$，因此 $p$ 整除 $p^{\alpha-s}$。
由于 $p$ 不整除 $j$，所以 $p$ 不整除 $(p^{\alpha-s} - j)$。
根据 $\nu_p(ab) = \nu_p(a) + \nu_p(b)$，我们得到：
$$\nu_p(p^\alpha - k) = \nu_p(p^s) + \nu_p(p^{\alpha-s} - j) = s + 0 = s = \nu_p(k)$$
>分析 $K$ 分子项：
>$$p^\alpha m - k = p^\alpha m - p^s j = p^s (p^{\alpha-s} m - j)$$
>同样，因为 $s \leqslant \alpha - 1$，所以 $\alpha - s \geqslant 1$，因此 $p$ 整除 $p^{\alpha-s} m$。 由于 $p$ 不整除 $j$，所以 $p$ 不整除 $(p^{\alpha-s} m - j)$。 我们得到 $$\nu_p(p^\alpha m - k) = \nu_p(p^s) + \nu_p(p^{\alpha-s} m - j) = s + 0 = s = \nu_p(k)$$
>因此$$\nu_p(K) = \sum_{k=1}^{p^\alpha-1} \nu_p(p^\alpha m - k) - \sum_{k=1}^{p^\alpha-1} \nu_p(p^\alpha - k) = \sum_{k=1}^{p^\alpha-1} s - \sum_{k=1}^{p^\alpha-1} s = 0$$
>即$$\nu_p\left(\binom{p^\alpha m}{p^\alpha}\right) = \nu_p(m) + \nu_p(K) = \nu_p(m) + 0 = \nu_p(m)$$
>从而 $p^r | m \Leftrightarrow \displaystyle p^r | \binom{p^\alpha m}{p^\alpha}$ .




>[!Theorem] Theorem 1.12.1 $\mathrm{Sylow}$第一定理
>设 $G$ 是有限群，若存在正整数 $k$ 和素数 $p$ 满足 $p^{k} \big||G|$，则 $G$ 中一定存在一个阶为 $p^{k}$ 的子群 .
 
>[!proof]+
>我们根据条件可以假设 $|G| =  p^k m$ ，其中设 $p^{r} \mid m$ 且 $p^{r+1} \nmid m$ 。令 $X = \{A \subset G \mid |A| = p^k\}$，从而知 $\displaystyle|X| =\binom{p^k m}{p^k}$。及 $\displaystyle p^{r+1} \nmid \binom{p^k m}{p^k}$ (由引理)，其中$\displaystyle \binom{p^k m}{p^k}$是一个二项式系数 . 
此处我们考虑它在组合数学中的意义，即「从 $p^{k}m$ 个相异元素选出 $p^k$ 个元素的方法数」，这等价于元素个数为 $p^k m$ 的集合 $G$ 中元素个数为 $p^k$ 的子集的个数，因此等于 $|X|$ .
>
>我们定义如下映射：
>$$f : G \times X \longrightarrow X$$
>$$(g, A) \longmapsto g.A := gA.$$
>从而，$f$ 决定了群 $G$ 在集合 $X$ 上的一个作用。
>由于$|X|=\sum_{A}​\mathcal{O}_{A}$ ，且 $p^{r+1} \nmid |X|$，可知存在子集 $A_{0} \in X$，使得其轨道 $\mathcal{O}_{A_{0}}$ 元素个数不被 $p^{r+1}$ 整除 ，即 $p^{r+1} \nmid |\mathcal{O}_{A_{0}}|$ . 由于 $$\displaystyle|\mathcal{O}_{A_{0}}|=[G:G_{A_{0}}]=\frac{|G|}{|G_{A_{0}}|}$$
>
因此 $p^k \mid |G_{A_{0}}|$ 故 $p^k \leqslant |G_{A_{0}}|$。注意在 $G_{A_{0}}$ 的作用下之于 $A_{0}$ 内的两个元素 $a$ 和 $ga$ 可能不同，所以 $|A_{0}| \geqslant |G_{A_{0}}|$。由上述 $p^k \leqslant |G_{A_{0}}|$ 和 $p^k = |A| \geqslant |G_{A_{0}}|$ 两结论可知 $|G_{A_{0}}| = p^k$ ，$G_{A_{0}}$ 即为所求的群。


>[!Theorem] Corollary 1.12.1 $\mathrm{Cauchy}$ 定理
>设 $G$ 是有限群，$p$ 是素数且 $p\big| ||G$，则 $G$ 中存在阶为 $p$ 的元素 .

>[!proof]+
>由 $\mathrm{Sylow}$ 第一定理，$G$ 有 $\mathrm{Sylow}$ $p$-子群 $H$，任取 $e \ne x \in H$，则 $|x| \big||H|$ ，不妨设 $|x|=p^{r}$，则 $|x^{r-1}|=p$ .


关于 $\mathrm{Sylow}$ $p-$子群的个数已经它们的关系，有下面的定理：
>[!Theorem] Theorem 1.12.2 $\mathrm{Sylow}$第二定理
>设有限群 $G$ 的阶为 $p^l m$，其中 $p$ 为素数，$l$ 是正整数且 $(p, m) = 1$。若 $P$ 为 $G$ 的一个 $\mathrm{Sylow}$ $p$-子群，则 $G$ 的任一阶为 $p^k$ ($k \leqslant l$) 的子群 $H$ 一定包含在一个与 $P$ 共轭的 $\mathrm{Sylow}$ $p$-子群中  .

>[!proof]+
>由于 $P$ 是群 $G$ 的一个 $\mathrm{Sylow}$ $p-$子群，所以 $|P|=p^{l}$ .
>令 $X=G/P=\{ gP \mid g \in G \}$，则 $|X|=[G:P]=\frac{|G|}{|P|}=m$ .
>设 $H$ 是群 $G$ 的任一子群，且 $|H|=p^{k},k\leqslant l$.
>定义如下映射：$$\displaylines{f:H \times X \to X\\(h,gP) \longmapsto h.(gP):=hgP}$$由此知 $f$ 决定了群 $H$ 在 $X$ 上的一个作用 .
>因为 $(|X|,|H|)=(m,p^{k})=1$，由Property 1.12.2 . 不动点元素的个数 $t \equiv m \pmod{p}$ . 从而 $X$ 中必有在 $H$ 作用下的不动元素，即：
>存在 $gP \in X$ 使得对任意 $h \in H$，均有 $h.gP=hgP=gP$ .
>从而可知，对任意 $h \in H$ 有 $h \in g Pg^{-1}$，即 $H \subset gPg^{-1}$ .

>[!Theorem] Corollary 1.12.2
>(1) 群 $G$ 中 的任意两个 $\mathrm{Sylow}$ $p-$子群共轭
>(2) 群 $G$ 中有唯一的 $\mathrm{Sylow}$ $p-$子群 $P$ $\Leftrightarrow$  $G$ 中的 $\mathrm{Sylow}$ $p-$子群 $P \triangleleft G$ .

该推论是 $\mathrm{Sylow}$ 第二定理的一种特殊情形 。

>[!note] Def 1.12.3 正规化子
>设 $H$ 是群 $G$ 的任一子群，我们令 $$N_G(H) := \{g \in G \mid gHg^{-1} = H\}$$则 $N_G(H)$ 也是 $G$ 的一个子群且 $H \subset N_G(H)$。进一步，$H \leqslant N_G(H)$。通常，我们将 $N_G(H)$ 称为为 $H$ 在 $G$ 中的**正规化子**。


>[!Theorem] Theorem 1.12.3 $\mathrm{Sylow}$ 第三定理
>设 $p$ 是一个素数，$G$ 是一个有限群且 $p$ 整除 $|G|$。若正整数 $k$ 为群 $G$ 的所有 $\mathrm{Sylow}$-$p$ 子群的个数，则 $k \equiv 1 \pmod p$ .

>[!proof]+
>设 $X$ 是由群 $G$ 所有 $\mathrm{Sylow}$ $p-$子群构成的集合，即 $X=\{ Q\leqslant G \mid Q 是 G的Sylow \ p-子群 \}$ ，任取 $P \in X$，定义如下映射 $$\displaylines{f:P \times X \to X\\(g,Q)\longmapsto g.Q:=gQg^{-1}}$$则 $f$ 决定了群 $P$ 在 $X$ 上的一个作用 .
>断言这个群作用的不动点集 $$X_{0}=\{ Q\in X\mid xQx^{-1}=Q,\forall x \in P\}$$只有一个元素 $P$ .
>假设 $Q \in X_{0}$，则有 $xQx^{-1}=Q,\forall x \in P$，即 $P \subset N_{G}(Q)$ .
>由于 $P,Q$ 是 $G$ 的 $\mathrm{Sylow}$ $p-$子群，自然也是 $N_{G}(Q)$ 的 $\mathrm{Sylow}$ $p-$子群(*因为 $|N_G(Q)|$ 整除 $|G|$，且 $Q$ 的阶是 $p$ 的最高幂次，又 $Q\leqslant N_{G}(Q)$*)，因此也在 $N_{G}(Q)$ 中互为共轭，由于 $Q \triangleleft N_{G}(Q)$ ，由 Corollary 1.12.1 可知若正规则只有一个 $\mathrm{Sylow}$ $p-$子群，从而 $P=Q$ .
>即 $|X_{0}|=1$，于是 $|X| \equiv |X_{0}|=1 \pmod{p}$ (*由 Property 1.12.2*) 

>[!Theorem] Corollary 1.12.2
>设 $p$ 是一个素数，$l$，$m$ 是正整数。若 $G$ 是一个有限群且 $|G| = p^l m$，$(p, m) = 1$，则 $G$ 的 $\mathrm{Sylow}$ $p-$子群个数 $k \mid m$  .

>[!proof]+
>设 $X$ 是由群 $G$ 所有 $\mathrm{Sylow}$ $p-$子群构成的集合，即 $X=\{ Q\leqslant G \mid Q 是 G的Sylow \ p-子群 \}$.  任取 $P \in X$ .
>由 $G$ 的所有的 $\mathrm{Sylow}$ $p-$子群彼此共轭知，$X$ 等于 $P$ 的 $G-$轨道，并且易知 $P$ 在 $G$ 中的稳定子群是正规化子 $N_{G}(P)$ ，即$X = \mathcal{O} _{G}(P)= \{ gPg^{-1} \mid g \in G \}$,$Stab_G(P) = N_G(P)$(*在 Theorem 1.12.3 证明中的群作用下*) . 故有
>$$|X|=|\mathcal{O}_{P}|=[G:Stab_G(P)]=[G:N_{G}(P)]$$
又由 $P \subseteq N_{G}(P)$ ，得到$$[G:P]=[G:N_{G}(P)][N_{G}(P):P]=\frac{|G|}{|P|}=m$$得到$|X| \big|m$ .
 
在有限群理论中，**Sylow 定理**是最为精彩和重要的结果，它包含有三个定理，分别回答了一群的某些素数的幂次阶群的存在性、唯一性（关系）、以及数量。

