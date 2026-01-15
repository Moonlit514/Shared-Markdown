这里是Mathematics板块！
写了一些用于复习的自己编写的内容。结合书本使用！
所需书本：
数学分析：《数学分析》第三版 陈纪修
高等代数：《高等代数》第二版 丘维声
初等数论：《初等数论》第三版 闵嗣鹤 严士健
近世代数：《近世代数基础》第三版 刘绍学 彭联刚 （可以不需要）

建议配合**Obsidian**软件使用！因为里面有Obsidian软件独有的**callout**语法，会导致其中的latex语言无法直接预览！如果你能找到其他的插件那也可以。

习题选取原则：大致从易到难
事先声明：**不会**也**不可能**涉及所有题型与方法，只选取**对个人而言**较为有难度，有思考价值的题。（当然也有可能是课本习题、考试题、网上随便看到的题，某校考研题等等）
用于构建自己的工具箱.

《高等代数》 第二版 上册已上传
下册文件太大无法直接上传，以下为链接：
https://zh.z-library.sk/book/16870945/d59b81/%E9%AB%98%E7%AD%89%E4%BB%A3%E6%95%B0-%E4%B8%8B%E5%86%8C-%E7%AC%AC%E4%BA%8C%E7%89%88.html

一些重要的概念或命题会用这样的callout块:
>[!note] Def or Pro
>这是内容.

证明会用这样的callout块:
>[!proof] Proof
>这是证明.

(需要加载CSS文件，如果你想用Obsidian打开，请添加CSS文件并输入如下代码：）
```
/* 自定义 PROOF Callout 样式 */

.callout[data-callout="proof"] {

    --callout-color: 202, 93, 245; /* 紫色 (RGB值: 153红, 50绿, 204蓝) */

    --callout-icon: lucide-pencil-ruler; /* 双勾图标，您可以在 lucide.dev 查找更多图标 */

    background-color: rgba(var(--callout-color), 0.1); /* 背景色，透明度为 10% */

    border-left: 6px solid rgb(var(--callout-color)); /* 左侧边框，颜色与主色一致 */

    border-radius: 6px; /* 边框圆角 */

    padding: 15px; /* 内部填充 */

    box-shadow: 2px 2px 8px rgba(0, 0, 0, 0.1); /* 轻微阴影效果 */

    font-family: 'Segoe UI', sans-serif; /* 字体设置，可根据系统字体调整 */

    color: var(--text-normal); /* 文本颜色，使用 Obsidian 默认文本颜色变量 */

}

  

/* （可选）如果您希望PROOF标题的字体加粗或改变颜色，可以添加以下代码 */

.callout[data-callout="proof"] .callout-title {

    font-weight: bold; /* 标题加粗 */

    color: rgb(var(--callout-color)); /* 标题颜色与 Callout 主色一致 */

}
```

习题会用这样的callout块：
>[!example] Exa 
>这是习题.

习题不一定会给出答案，如果给出会在文末给出。