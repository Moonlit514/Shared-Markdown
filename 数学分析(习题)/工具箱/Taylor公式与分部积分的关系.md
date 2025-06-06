>[!NOTE] 例1 多阶可导可使用$Taylor$公式
 >设函数$f(x)$在$[a,b]$上二阶可导，$f\left( \frac{a+b}{2} \right)=0$.
 >记$M=\sup_{a\leqslant x\leqslant b}|f^{\prime\prime}(x)|$,证明
 >$$\int_a^bf(x)\mathrm{d}x\leqslant\frac{M(b-a)^3}{24}.$$

>[!PROOF]+
 >$f(x)$在$x=\frac{a+b}{2}$处的带$Lagrange$余项的$Taylor$公式为
 >$$\begin{aligned}f(x)&=f\left(\frac{a+b}{2}\right)+f^{\prime}\left(\frac{a+b}{2}\right)\left(x-\frac{a+b}{2}\right)+\frac{1}{2}f^{\prime\prime}(\xi)\left(x-\frac{a+b}{2}\right)^{2}\\&=f^{\prime}\left(\frac{a+b}{2}\right)\left(x-\frac{a+b}{2}\right)+\frac{1}{2}f^{\prime\prime}(\xi)\left(x-\frac{a+b}{2}\right)^{2},x\in\begin{bmatrix}a,b\end{bmatrix}\end{aligned}$$
 >其中$\xi \in [a,b]$.
 >对等式两边**求积分**，得
 >$$\begin{aligned}\int_a^bf(x)\mathrm{d}x&=f^{\prime}\left(\frac{a+b}{2}\right)\int_{a}^{b}\left(x-\frac{a+b}{2}\right)\mathrm{d}x+\frac{1}{2}\int_{a}^{b}f^{\prime\prime}(\xi)\left(x-\frac{a+b}{2}\right)^{2}\mathrm{d}x\\&=\frac{1}{2}\int_a^bf^{\prime\prime}(\xi)\left(x-\frac{a+b}{2}\right)^2\mathrm{d}x\end{aligned}$$
 >于是
 >$$\left|\int_{a}^{b}f(x)\mathrm{d}x\right|\leqslant\frac{1}{2}\int_{a}^{b}\left|f^{\prime\prime}(\xi)\left(x-\frac{a+b}{2}\right)^{2}\right|\mathrm{d}x\leqslant\frac{M}{2}\int_{a}^{b}\left(x-\frac{a+b}{2}\right)^{2}\mathrm{d}x=\frac{M(b-a)^{3}}{24}$$

泰勒公式的**带积分余项的Taylor公式**（或称为$Peaon$余项的积分形式）实际上就是通过多次分部积分推导出来的。
$$f(x)-f(a)=\int_a^xf^{\prime}(t)dt$$
$$\begin{aligned}\int_a^xf^{\prime}(t)dt&=[f^{\prime}(t)(t-x)]_a^x-\int_a^xf^{\prime\prime}(t)(t-x)dt\\&=f^{\prime}(x)(x-x)-f^{\prime}(a)(a-x)-\int_a^x(t-x)f^{\prime\prime}(t)dt\\&=f^{\prime}(a)(x-a)+\int_a^x(x-t)f^{\prime\prime}(t)dt\end{aligned}$$

 所以综上得到
 $$f(x)=f(a)+f^{\prime}(a)(x-a)+\int_a^x(x-t)f^{\prime\prime}(t)dt$$
 这就是带积分余项的Taylor公式 $n=1$ 的情况.
 对$\int_a^x(x-t)f^{\prime\prime}(t)dt$还可以继续分部积分
$$\begin{align*}
\int_a^x (x-t)f''(t)dt &= \left[f''(t)\left(-\frac{(x-t)^2}{2}\right)\right]_a^x - \int_a^x f'''(t)\left(-\frac{(x-t)^2}{2}\right)dt \\
&= f''(x)\left(-\frac{(x-x)^2}{2}\right) - f''(a)\left(-\frac{(x-a)^2}{2}\right) + \int_a^x \frac{(x-t)^2}{2}f'''(t)dt \\
&= f''(a)\frac{(x-a)^2}{2} + \int_a^x \frac{(x-t)^2}{2}f'''(t)dt
\end{align*}$$
 代回到原式，得
 $$f(x)=f(a)+f^{\prime}(a)(x-a)+f^{\prime\prime}(a)\frac{(x-a)^2}{2}+\int_a^x\frac{(x-t)^2}{2}f^{\prime\prime\prime}(t)dt$$这就是带积分余项的Taylor公式 $n=2$ 的情况.
 通过这种反复的分部积分，我们可以得到 $n$ 阶泰勒公式的积分余项形式：
 $$\color{yellow}f(x)=\sum_{k=0}^n\frac{f^{(k)}(a)}{k!}(x-a)^k+\frac{1}{n!}\int_a^x(x-t)^nf^{(n+1)}(t)dt$$不过此题运用分部积分比较麻烦。**问题的本质就是二阶导数到函数本身的积分关系。** 从 $f''(x)$ 到 $f(x)$ 必然要经历两次积分（或两次反导数运算）。每一次反导数运算，如果用分部积分来写，就会增加一个积分项，这就自然地产生了“多重积分”的结构。
 >[!PROOF]+
 >设$c=\frac{a+b}{2}$，则$f(c)=0$，$f(x)-f(c)=\int_c^xf^{\prime}(t)dt$
 >再设$f^{\prime}(t)-f^{\prime}(c)=\int_c^tf^{\prime\prime}(s)ds$，即$f^{\prime}(t)=f^{\prime}(c)+\int_c^tf^{\prime\prime}(s)ds$
 >代入上式中，得到
 >$$\begin{gathered}f(x)=\int_{c}^{x}\left(f^{\prime}(c)+\int_{c}^{t}f^{\prime\prime}(s)ds\right)dt\\\begin{aligned}f(x)=f^{\prime}(c)\int_c^xdt+\int_c^x\left(\int_c^tf^{\prime\prime}(s)ds\right)dt\end{aligned}\\f(x)=f^{\prime}(c)(x-c)+\int_{c}^{x}\left(\int_{c}^{t}f^{\prime\prime}(s)ds\right)dt\end{gathered}$$
 >处理双重积分$\int_{c}^{t} f^{\prime\prime}(s)dsdt$
 >设$u=\int_c^tf^{\prime\prime}(s)ds,$则$du=f^{\prime\prime}(t)dt$
 >$$\begin{align*} \int_c^x \left(\int_c^t f''(s)ds\right)dt &= \left[\left(\int_c^t f''(s)ds\right)(t-x)\right]_c^x - \int_c^x (t-x)f''(t)dt \\ &= -\int_c^x (t-x)f''(t)dt \\ &= \int_c^x (x-t)f''(t)dt \end{align*}$$
 >代回$f(x)$表达式，得
 >$$f(x)=f^{\prime}(c)(x-c)+\int_c^x(x-t)f^{\prime\prime}(t)dt$$
 >等式两边求积分，得
 >$$\begin{align*} \int_a^b f(x)dx &= \int_a^b \left[f'(c)(x-c) + \int_c^x (x-s)f''(s)ds \right] dx \\ &= f'(c) \int_a^b (x-c)dx + \int_a^b \left(\int_c^x (x-s)f''(s)ds \right) dx \end{align*}$$
 >计算第一项
 >$$f^{\prime}(c)\int_a^b(x-c)dx=f^{\prime}(c)\left[\frac{(x-c)^2}{2}\right]_a^b=f^{\prime}(c)\left(\frac{(b-c)^2}{2}-\frac{(a-c)^2}{2}\right)=0$$
 >从而$$\int_a^bf(x)dx=\int_a^b\left(\int_c^x(x-s)f^{\prime\prime}(s)ds\right)dx$$
 >进行分割
 >$$\int_a^bf(x)dx=\int_a^c\left(\int_c^x(x-s)f^{\prime\prime}(s)ds\right)dx+\int_c^b\left(\int_c^x(x-s)f^{\prime\prime}(s)ds\right)dx$$
 >对于第一部分
 >$$\int_c^x(x-s)f^{\prime\prime}(s)ds=-\int_x^c(x-s)f^{\prime\prime}(s)ds=\int_x^c(s-x)f^{\prime\prime}(s)ds$$
 >观察积分区域$D_1=\{(x,s)\mid a\leq x\leq c,x\leq s\leq c\}$，这个区域可以重新被描述为$D_1'=\{(x,s)\mid a\leq s\leq c,a\leq x\leq s\}$.
 >因此
 >$$\begin{aligned}\int_a^c\left(\int_x^c(s-x)f^{\prime\prime}(s)ds\right)dx&=\int_a^c\left(\int_a^s(s-x)f^{\prime\prime}(s)dx\right)ds=\int_a^cf^{\prime\prime}(s)\left(\int_a^s(s-x)dx\right)ds\end{aligned}$$
 >内层积分$\int_a^s(s-x)dx$
 >$$\int_{a}^{s}(s-x)dx=\left[ sx-\frac{x^{2}}{2}\right]_{a}^{s}
=\left(s\cdot s-\frac{s^{2}}{2}\right)-\left(s\cdot a-\frac{a^{2}}{2}\right)$$
$$=\frac{s^{2}}{2}-sa+\frac{a^{2}}{2}=\frac{1}{2}(s^{2}-2sa+a^{2})=\frac{1}{2}(s-a)^{2}$$
>代回原式，得
>$$\int_a^cf^{\prime\prime}(s)\cdot\frac{1}{2}(s-a)^2ds=\int_a^cf^{\prime\prime}(s)\frac{(s-a)^2}{2}ds$$
>同理，得到第二部分
>$$\int_c^bf^{\prime\prime}(s)\cdot\frac{1}{2}(b-s)^2ds=\int_c^bf^{\prime\prime}(s)\frac{(b-s)^2}{2}ds$$
>从而
>$$\int_a^bf(x)dx=\int_a^cf^{\prime\prime}(s)\frac{(s-a)^2}{2}ds+\int_c^bf^{\prime\prime}(s)\frac{(b-s)^2}{2}ds$$
>于是对其进行放缩
>$$\begin{gathered}\left|\int_a^bf(x)dx\right|\leq\left|\int_a^cf^{\prime\prime}(s)\frac{(s-a)^2}{2}ds\right|+\left|\int_c^bf^{\prime\prime}(s)\frac{(s-b)^2}{2}ds\right|\\\leq\int_a^c\left|f^{\prime\prime}(s)\right|\frac{(s-a)^2}{2}ds+\int_c^b\left|f^{\prime\prime}(s)\right|\frac{(s-b)^2}{2}ds\\\leq M\int_a^c\frac{(s-a)^2}{2}ds+M\int_c^b\frac{(s-b)^2}{2}ds\end{gathered}$$
>计算第一个积分
>$$M\int_a^c\frac{(s-a)^2}{2}ds=\frac{M}{2}\left[\frac{(s-a)^3}{3}\right]_a^c=\frac{M}{6}(c-a)^3=\frac{M(b-a)^3}{48}$$
>计算第二个积分
>$$M\int_c^b\frac{(s-b)^2}{2}ds=\frac{M}{2}\left[\frac{(s-b)^3}{3}\right]_c^b=\frac{M}{6}(c-b)^3$$
>从而
>$$\left|\int_a^bf(x)dx\right|\leq\frac{M(b-a)^3}{48}+\frac{M(b-a)^3}{48}=\frac{M(b-a)^3}{24}$$


 





