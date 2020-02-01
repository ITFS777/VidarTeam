# 2020 VidarTeam Hgame Writeup By ITFS
## Misc

### 签到题

给了一串base64，解码之后得到了一串摩尔斯
![](http://106.15.72.2/imgbin/w1_m1_2.png)
找了摩尔斯的树状查找表
![](http://106.15.72.2/imgbin/w1_m1_3.png)
拿到flag
>hgame{W3LCOME_TO_2020_HGAM3}

---

### 壁纸

首先给了一个压缩包，解压之后是一张二次元的写真，binwalk看一下
![](http://106.15.72.2/imgbin/w1_m2_1.png)
可以看到是个图种，里面有个看起来像加密过的压缩包，有`flag.txt`还有注释
WinHex打开发现jpg文件尾`FF D9`后面跟了一个zip的数据头，剪切出来得到一个真加密的压缩包
![](http://106.15.72.2/imgbin/w1_m2_3.png)
一开始看这个`Picture ID`没什么头绪，identify分析了半天也没找出这个ID是什么
想到之前国庆的时候有道类似的题目是放到搜索引擎里搜索，于是就用了Google的图片搜索，找了半天发现这张图源自P站，并且找到了对应的ID`76953815`
试着当作密码输了进去，成功解密
把里面的`flag.txt`解压出来，得到了一串Unicode字符串
![](http://106.15.72.2/imgbin/w1_m2_6.png)
写了个转换脚本，拿到flag
> hgame{Do_y0u_KnOW_uNiC0d3?}

---

### 克苏鲁神话

拿到压缩包后打开，里面有一个`bacon.txt`和一个`Novel.zip`
![](http://106.15.72.2/imgbin/w1_m3_1.png)
解压出来，发现这个压缩包是经过加密的，里面也有一个`bacon.txt`和一个doc
![](http://106.15.72.2/imgbin/w1_m3_2.png)
打开txt发现里面是一段培根密码
![](http://106.15.72.2/imgbin/w1_m3_3.png)
找了个解密工具，拿到明文
![](http://106.15.72.2/imgbin/w1_m3_4.png)
由于有两个名称相同的文件，比较了一下`CRC校验码`发现一样，于是就想到了[明文攻击](https://www.cnblogs.com/ECJTUACM-873284962/p/9387711.html)，把明文调好压缩算法后放进AAPR里跑明文攻击，很快就得出了密钥
![](http://106.15.72.2/imgbin/w1_m3_5.png)
打开文档发现还是要密码，于是想到之前没用到的密码，提示说密码是大写，于是用了大写形式，顺利打开，大致看了下是篇小说，没有看到flag，于是设置里把隐藏文字打开
![](http://106.15.72.2/imgbin/w1_m3_10.png)
拿到flag
> hgame{Y0u_h@Ve_F0Und_mY_S3cRet}

---

### 签到题ProPlus

拿到压缩包后打开，里面有一个加密的压缩包`OK.zip`和`Password.txt`
![](http://106.15.72.2/imgbin/w1_m4_1.png)
打开txt看了下，发现有两段密码
![](http://106.15.72.2/imgbin/w1_m4_3.png)
下面hint给了栅栏密码和凯撒密码，然后这两个密码都需要key来加密，刚好有两个数字3和5
于是直接拿去栅栏解密和凯撒位移
![](http://106.15.72.2/imgbin/w1_m4_4.png)
![](http://106.15.72.2/imgbin/w1_m4_5.png)
然后再把解密结果直接拿去做凯撒位移
![](http://106.15.72.2/imgbin/w1_m4_6.png)
符合描述，一段英文句子，一个大写字母串(密码)
然后把得到的大写字母串拿去解压缩包，成功打开
![](http://106.15.72.2/imgbin/w1_m4_7.png)
打开之后发现有很多Ook，但是感觉有点熟悉(之前看的一篇介绍各种乱七八糟密码的博客)，然后就翻了翻发现这个是一个叫ook的密码，而且在博客里面也找到了对应的解密工具，这里放一下[Github.com/splitbrain/ook](https://github.com/splitbrain/ook)以防忘记
![](http://106.15.72.2/imgbin/w1_m4_8.png)
解密后发现是一段Base32，根据字段头看起来这个ook密文好像也是从这里生成的233
![](http://106.15.72.2/imgbin/w1_m4_9.png)
然后拿去在线Base32转码，又得到了一段Base64，继续转发现是张图片，然后找了找在线的Base64转PNG的工具
![](http://106.15.72.2/imgbin/w1_m4_11.png)
看起来是个二维码，拿手机扫一下
![](http://106.15.72.2/imgbin/w1_m4_12.png)
拿到flag
> hgame{3Nc0dInG_@lL_iN_0Ne!}

到此终于把web和misc两个方向全ak了，学到了挺多东西，感觉还是不错的，下一步试试看看哪个方向容易点。。毕竟人菜只能捡漏，不像同届霸榜的那几位才一天多就破千了，然后赶紧补一下php和sql准备下周的web，至少今晚可以安心的休息了233

---

### 每日推荐

首先拿到的是一个压缩包，解压得到WireShark的流量文件`Capture1.pacpng`，用WireShark打开过滤http看能不能发现什么
![](http://106.15.72.2/imgbin/w1_m5_2.png)
发现有一条报文POST了一个压缩包，应该跟flag有关，追踪下HTTP流看看
![](http://106.15.72.2/imgbin/w1_m5_3.png)
发现压缩包名称是`song.zip`，结合题目网易云每日推荐，可以断定flag应该就在这里面
![](http://106.15.72.2/imgbin/w1_m5_4.png)
找到对应的报文序号并导出资源，后缀是php，将其改为zip打开，里面有一个加密的mp3
![](http://106.15.72.2/imgbin/w1_m5_5.png)
根据密码提示为6位数字，直接进行AAPR爆破得到密码
用密码解压后得到一个纯音乐的mp3，听了两遍也没听出什么
用`Audacity`查看波形，没有找到跟摩尔斯比较像的波形
试着用`MP3Stego`解密文件，由于没有密码也没什么进展
`binwalk`分析，也没得到什么有价值的线索
然后Google音频隐写相关的博客发现了这个
[CTF中音频隐写的一些整理总结](https://www.sqlsec.com/2018/01/ctfwav.html)
其中提到flag有可能是在音频文件的频谱图中，于是`Audacity`看一下频谱，果然
![](http://106.15.72.2/imgbin/w1_m5_7.png)
拿到flag
> hgame{I_love_EDM233}

---

## Web
### Cosmos的博客

![](http://106.15.72.2/imgbin/w1_w1_1.png)
题目很明显提示了**版本管理工具** ***GitHub***，可以想到网页所在目录是一个git仓库，然后随便找了个自己电脑里的git仓库看了下内容
![](http://106.15.72.2/imgbin/w1_w1_2.png)
发现config文件里应该有需要的内容，于是修改URI
`http://cosmos.hgame.n3ko.co/.git/config`
访问一下，果然得到了远端仓库的信息
![](http://106.15.72.2/imgbin/w1_w1_3.png)
clone到本地，git show看一下提交信息
![](http://106.15.72.2/imgbin/w1_w1_4.png)
发现是Base64解码，复制到Python里
![](http://106.15.72.2/imgbin/w1_w1_5.png)
拿到flag
> hgame{g1t_le@k_1s_danger0us_!!!!}

---

### 接 头 霸 王 

这题虽然因为自己眼瞎卡了好久，不过确实对首部字段的作用有了更深入的了解
首先打开题目是张含有暴力血腥元素的图片(雾)和提示
![](http://106.15.72.2/imgbin/w1_w2_1.png)
既然是接头，又是web，那应该就跟请求头有关了，于是用chrome的插件Modify Header加了个`Referer`的字段
![](http://106.15.72.2/imgbin/w1_w2_2.png)
刷新一下看看，页面发生了变化，看来方向是对的
![](http://106.15.72.2/imgbin/w1_w2_3.png)
然后翻了翻之前做的有关首部字段的笔记，看起来应该再加一个XFF字段
![](http://106.15.72.2/imgbin/w1_w2_4.png)
又要改浏览器名称，这个简单，加个`User-Agent`字段即可
![](http://106.15.72.2/imgbin/w1_w2_5.png)
又要用POST方法，于是打开Postman(Burpsuite不会用呜呜呜)手动发包
![](http://106.15.72.2/imgbin/w1_w2_6.png)
看起来要修改某个跟时间有关的字段才行，试了`Date`、`If-Modified-Since`、`Cache-Control:max-age`等字段都没用，然后其他杂七杂八的方法也都是了也没什么用，卡了好久，于是厚着脸皮去找大🍆要了提示，让我再看看`If-Modified-Since`的有关内容

然后就去Google相关信息，在其中一篇博客中发现了这样的描述
![](http://106.15.72.2/imgbin/w1_w2_7.png)
发现`If-Modified-Since`字段对POST方法是无效的，然后在这篇博客下面的其他文章发现了有关`If-Unmodified-Since`的描述
![](http://106.15.72.2/imgbin/w1_w2_8.png)
可以看到这个字段适用于POST方法，于是在Postman里添加了这一项
![](http://106.15.72.2/imgbin/w1_w2_10.png)
拿到flag
> hgame{W0w!Your_heads_@re_s0_many!}

到此终于把web给ak了，虽然这题卡了很久，不过感觉每道题卡的地方都是自己知识点的漏洞，做完这四道题也算是对自己的web知识有了一个很大的补充，感觉还是很有收获的！

---

### Code World

![](http://106.15.72.2/imgbin/w1_w3_4.png)
打开发现403
![](http://106.15.72.2/imgbin/w1_w3_1.png)
然后由于比赛前刚把《图解HTTP》看完，知道403是拒绝访问的意思，想了想已经有人做出来了那肯定就是故意弄成这样的，既然GET不了，那我POST总可以吧，于是改了下方法重新发包
![](http://106.15.72.2/imgbin/w1_w3_2.png)
于是把参数改成`a=5+5`传进去，不行，然后突然发现忘记urlencode了，于是改成`a=5%2b5`
![](http://106.15.72.2/imgbin/w1_w3_5.png)
拿到flag
> hgame{C0d3_1s_s0_S@_sO_C0ol!}

---

### 🐔你太玫

打开题目后是一个HTML5和JS写的CXK打篮球的小游戏
![](http://106.15.72.2/imgbin/w1_w4_1.png)
当然玩是不可能玩的，肯定是要用console修改Js变量来达到目标，那就F12打开console，然后输入`dir(window)`查看所有对象
![](http://106.15.72.2/imgbin/w1_w4_2.png)
展开后发现一个Game类的对象canvas_g，成员变量名比较可疑
![](http://106.15.72.2/imgbin/w1_w4_3.png)
运行一下游戏，果然分数储存在这里
![](http://106.15.72.2/imgbin/w1_w4_4.png)
调试几次后发现`storageScore`储存的是当前回合得分，`globalScore`是总分，于是在console里直接赋值
![](http://106.15.72.2/imgbin/w1_w4_5.png)
拿到flag
> hgame{j4vASc1pt_w1ll_tel1_y0u_someth1n9_u5efu1?!}

---

## Crypto

### InfantRSA

虽然密码学毫无基础，既然说了是真·签到题，想来应该也不会太难，直接给出了一段代码
![](http://106.15.72.2/imgbin/w1_c1_1.png)
Google了一下RSA相关的算法，发现在没有密钥的情况下加密解密只跟p、q、e有关，好像有一个Python库`RSAtool`可以用，但是装了半天都没装上(蠢哭)

无奈继续Google，找到了这个博客
[CTF|玩转RSA加密算法(一)](https://cloud.tencent.com/developer/article/1076086)
于是根据这个博客还有题目所给的部分代码写了个Python脚本，跑出了d和明文m
![](http://106.15.72.2/imgbin/w1_c1_2.png)
于是审计一下题目所给代码，发现这段代码的作用是将flag(字节码)转换成十进制然后进行RSA运算得到了密码c，然后现在已经得到了m，接下来要做的就是将m转换成字节码便能得到flag了

改完代码，跑一下，然而flag并没有出现
![](http://106.15.72.2/imgbin/w1_c1_3.png)
不过看起来也不是什么大问题，Overflow要找什么，当然是[StackOverFlow](https://stackoverflow.com/questions/21017698/converting-int-to-bytes-in-python-3)23333
搜索一番后发现了解决办法
![](http://106.15.72.2/imgbin/w1_c1_4.png)
copy函数、运行 行云流水一气呵成(论程序员的自我修养233333)
![](http://106.15.72.2/imgbin/w1_c1_5.png)
顺利拿到flag
> hgame{t3Xt6O0k_R5A!!!}

---

### Affine

首先拿到的是一段Python代码，审计了一下发现就是将flag单字符加密后组成密文
![](http://106.15.72.2/imgbin/w1_c2_1.png)
刚开始还看不太懂第二行的
`from secret import A, B, flag`
然后谷歌半天也没找到类似的，后来想想应该是仿照Python语法声明的未知变量吧

首先用注释补充了一些相关信息(`cipher`的内容是题目给的)，方便分析，然后注意到跟加密有关的应该只有`else`块里的两行代码，于是根据已知flag的格式`hgame{...}`可以得到一段明文和对应的密文
> hgame ==> A8I5z

压个单行Python算一下索引
```
print("zxcvbnmasdfghjklqwertyuiop1234567890QWERTYUIOPASDFGHJKLZXCVBNM".find(input()))
```
于是可以列5个方程来求解未知数
![](http://106.15.72.2/imgbin/w1_c2_2.png)
很容易能够算出`A = 13, B = 14`，然后可以将flag每一位都用暴力算法求出来
![](http://106.15.72.2/imgbin/w1_c2_3.png)
编写解密脚本
![](http://106.15.72.2/imgbin/w1_c2_4.png)
拿到flag
> hgame{M4th_u5Ed_iN_cRYpt0}

---

### not_One-time

首先还是给了一个加密脚本，只不过是部署在远程服务器上，需要nc才能交互
![](http://106.15.72.2/imgbin/w1_c3_1.png)
审计了一下代码，发现是一个流密码，即对于一个明文，用多个密钥对其进行加密
> m ^ k1 = c1
> m ^ k2 = c2
> m ^ k3 = c3
> ...

其中k1,k2,k3,...是随机生成的密钥，题目所给的脚本每次运行都会随机生成一串范围为大小写字母+数字的长度为`flag`长度的字符串`keystream`，然后将其与`flag`按位异或，之后再转成`base64`编码打印出来
![](http://106.15.72.2/imgbin/w1_c3_2.png)
连上远端，果然输出了一串`base64`
于是放进改进后的Python脚本里看一下flag的长度
![](http://106.15.72.2/imgbin/w1_c3_3.png)
算上hgame{}一共有43个字符，然后把已知条件列一下
> flag长度: 43
> flag范围: string.printable
> keystream长度: 43
> keystream范围: string.ascii_letters+string.digits

然后想到可以多次访问获取多个加密后的序列，对于每个序列将其每个元素都与flag范围内的所有字符进行异或运算，如果结果映射ASCII后符合keystream的范围，则将其储存在临时列表中，最后再对所有的临时列表取交集以限定范围，多次运行后便能得到一个稳定的flag
理清思路后开始编写exp
![](http://106.15.72.2/imgbin/w1_c3_4.png)
其中对flag限定了128次，足够得到一个组成较为固定的flag了
![](http://106.15.72.2/imgbin/w1_c3_5.png)
运行脚本，拿到flag
> hgame{r3us1nG+M3$5age-&&~rEduC3d_k3Y-5P4Ce}

---

### Reorder

这题刚开始只给了个nc，于是远程连上随便输入了点东西看看
![](http://106.15.72.2/imgbin/w1_c4_1.png)
发现会把输入的东西随机排列，直接回车或者输入10次则会打印一个乱序的flag

研究了一下发现这个加密的算法一次只加密16位，如果是32位的话则分成两个16位的字符串分开加密然后再合并
![](http://106.15.72.2/imgbin/w1_c4_3.png)
然后看了看flag的长度，正好是32位，于是把16进制的字符输进去，将明文与密文进行对比，发现flag也是按照这样的顺序排列的
![](http://106.15.72.2/imgbin/w1_c4_4.png)
于是写了个能根据已知的明文和密文算出flag的exp
![](http://106.15.72.2/imgbin/w1_c4_5.png)
运行一下，拿到flag
> hgame{jU$t+5ImpL3_PeRmuTATi0n!!}

---

## Reverse

### maze

嗯。。第一次做Re方向的题，只有一点汇编基础，不过还好学长给了很多学习资料，首先看了关于maze的介绍，大概明白了解题思路就是通过逆向分析程序找到由限定字符组成的"行进方式"在预设的迷宫内找到路线，输入行进路线字符串即可通过迷宫

拿到文件后首先checksec了下发现是ELF，于是用wsl打开

![](http://106.15.72.2/imgbin/w1_r1_1.png)

第一次见到这种文字图，有点被惊艳到，不得不说这图还挺生动的233，随意打了几个字进去，
结果提示`You died`，看起来要把路径字符串输入到这里，于是打开IDA拖进去F5查看源码

![](http://106.15.72.2/imgbin/w1_r1_2.png)

嗯，大致看了下，行进的单位应该是一个`(char*)`类型的变量`v6`，然后根据代码列了一个映射表
> w ==> -64  
> s ==>  64  
> a ==> -4  
> d ==>  4

然后看到了一段跟flag有关的代码
![](http://106.15.72.2/imgbin/w1_r1_4.png)
![](http://106.15.72.2/imgbin/w1_r1_3.png)
源代码里把`v6`初始化为`0x6020C4`了，简单算了一下
> 0x60243C - 0x6020C4 = 888 = 64 * 14 - 4 * 2
>
看起来好像只要让`v6`等于`0x60243C`就可以了，然后上面的if语句给`v6`加了一个限制范围，不过刚开始第三个条件没怎么看懂，于是看了下第三个条件的汇编代码
![](http://106.15.72.2/imgbin/w1_r1_5.png)

发现作用是将`v6`放入`RAX`并且把`RAX`指向的内存空间的值赋值给`EAX`，然后与1进行与运算并把结果放入`EAX`，之后再自身进行与运算，如果EAX等于1则跳转到`loc_4008C6`处，也就是`You died`
然后发现从`v6`的初始值`0x6020C4`开始是一段0和1的序列
![](http://106.15.72.2/imgbin/w1_r1_7.png)
看来这个就是迷宫，前面算出的`888`是路径长度，于是把这段数据复制出来单独分析

一开始想的是手动寻路，但是拿计算器算了一会看的眼花，于是想写个Python脚本自动寻路
思路是先读入字段并格式化成一个类似指针的字典，`[Address]=0/1`，然后根据字典的键值(0/1)判断是通路还是堵路，然后再写具体的寻路算法，但是由于用了迭代算法而且字段实在太长，刚调试好就报错迭代次数过多，于是只好精简代码，手动寻路，但是由Python来帮我计算是否能够通行，我只需要输入wasd就可以了，虽然还是有点麻烦但是比拿计算器一个一个算还是快多了
![](http://106.15.72.2/imgbin/w1_r1_12.png)
于是就像这样一步一步的摸索
![](http://106.15.72.2/imgbin/w1_r1_9.png)
同时在纸上也画了条路出来
![](http://106.15.72.2/imgbin/w1_r1_10.jpg)
不过少画了一步，后来才发现添上去了
然后根据画出来的路径图又重新走了一遍全0的路线，得到路径字符串
`ssssddddddsssssddwwdddssssdssdd`
![](http://106.15.72.2/imgbin/w1_r1_11.png)
拿到flag
> hgame{ssssddddddsssssddwwdddssssdssdd}

(不得不说Python真是太好用了)

---

### bitwise_operation2

拿到的依然是一个ELF文件，拖进IDA然后F5
![](http://106.15.72.2/imgbin/w1_r2_2.png)
可以看到有大量的位运算和异或运算
于是打算重构一下代码，先从最上面的if开始
![](http://106.15.72.2/imgbin/w1_r2_3.png)
然后注意到中间有两行奇怪的函数
![](http://106.15.72.2/imgbin/w1_r2_4.png)
点进去看了下
![](http://106.15.72.2/imgbin/w1_r2_5.png)
看起来应该是对输入的两个参数进行了一些处理，于是重构一下
![](http://106.15.72.2/imgbin/w1_r2_6.png)
观察if语句可以看出对`str2`有一些限制条件，其只能是小写的16进制字符，然后将其转换成十进制并通过一些运算赋值给`str1`，然后根据基址偏移重构了一下数据类型，其中flag内容由两个16字节的字符串`flag_part1`、`flag_part2`组成，其经过函数运算后赋给`part1`和`part2`，然后对`part1`和`part2`进行操作
![](http://106.15.72.2/imgbin/w1_r2_7.png)
![](http://106.15.72.2/imgbin/w1_r2_8.png)
重构位+异或运算部分并解释，并且将之前那个函数的功能用Python描述了一下
![](http://106.15.72.2/imgbin/w1_r2_9.png)
观察异或运算部分
![](http://106.15.72.2/imgbin/w1_r2_10.png)
![](http://106.15.72.2/imgbin/w1_r2_11.png)
![](http://106.15.72.2/imgbin/w1_r2_12.png)
然后发现上面这部分有两个byte指针，然后点进去发现是两个8字节的字符串面量，于是继续重构
![](http://106.15.72.2/imgbin/w1_r2_13.png)
可以看到`part1`和`part2`在经过一系列的运算之后与`str1`、`str2`相等才能得到flag

现在整个源代码已经重构完毕，由于最后要跟`str1`和`str2`进行比较，所以从异或部分开始反推，根据下面的公式
> a ^ b = c  
> a = b ^ c

可知涉及到三个数的异或运算，只要知道其中两个便能求得第三个，然后观察上面两个异或运算，当等式成立时变换形式可以得到
> part1 = part1 ^ key = str1  
> part2 = part2 ^ (part1 ^ key) = str2

由于第一行改变了part1的值，所以要先从第二行开始逆运算

> part2 = str2 ^ (part1 ^ key)  
> part1 = str1 ^ key

于是这样就可以还原出异或运算之前的`part1`和`part2`了，然后开始逆推上面的位+异或运算

观察其的结构可知，除了第一行外，剩余三行均可用下面的形式表示
> a = b ^ a

然后可以得到下面的式子
> a(new) = b ^ a(old)  
> a(old) = b ^ a(new)

所以要想逆推，只需要从下往上再执行一次上面的代码即可，然后再将012位和34567位进行交换即可得到原始的`part1`和`part2`的值

理清思路后开始编写解密程序
![](http://106.15.72.2/imgbin/w1_r2_14.png)
编译运行，得到`part1`和`part2`的值
![](http://106.15.72.2/imgbin/w1_r2_15.png)
然后开始逆推最开始的func函数，由于已经用Python描述其功能了，那就直接用Python将每一位爆破出来
![](http://106.15.72.2/imgbin/w1_r2_16.png)
将解密程序所得到的`part1`和`part2`的值填进去爆破
![](http://106.15.72.2/imgbin/w1_r2_17.png)
拿到flag
> hgame{0f233e63637982d266cbf41ecb1b0102}

这道题虽然重构代码花了好久，不过对IDA的反编译代码格式和数据类型的底层又有了更深的理解，而且还拿到了150分，也算是收获颇丰

---

### advance

这次拿到的是一个exe，于是直接打开看看
![](http://106.15.72.2/imgbin/w1_r3_1.png)
看来又是一个直接将flag加密的程序，拖进IDA然后F5
![](http://106.15.72.2/imgbin/w1_r3_2.png)
重构一下
![](http://106.15.72.2/imgbin/w1_r3_3.png)
可以看到程序的作用是将输入的`flag`通过`encode`函数转化成字符串`str`并与`"0g371wvVy9qPztz7xQ+PxNuKxQv74B/5n/zwuPfX"`比较，但是这个字符串看起来有点像base64编码
于是重构一下`encode`函数
![](http://106.15.72.2/imgbin/w1_r3_4.png)
可以看到是一个换表Base64转码，于是在网上找了一个换表的Base64解码脚本
![](http://106.15.72.2/imgbin/w1_r3_5.png)
修改一下然后运行
![](http://106.15.72.2/imgbin/w1_r3_6.png)
拿到flag
> hgame{b45e6a_i5_50_eazy_6VVSQ}

---

## Pwn

### Hard_AAAAA

首先拿到的是一个二进制文件，checksec看了一下发现是一个32位的ELF文件而且开了栈保护，由于wsl不支持这个格式，所以用了ubuntu环境来调试
![](http://106.15.72.2/imgbin/w1_p1_1.png)
拖进IDA看一下汇编，发现有一个`backdoor`函数，由于开了栈保护，所以虽然有`gets`函数但是用溢出覆盖的方法是行不通的，于是继续往下看
发现有一个`memcmp`函数，这个函数会返回比较结果，而返回结果默认储存在寄存器`EAX`中，下面的`test`对`EAX`进行了判断，如果为0则跳转到`backdoor`函数
于是打开gdb，在`gets`和`memcmp`函数处下断点看一下传入参数的地址
![](http://106.15.72.2/imgbin/w1_p1_2.png)
看起来`gets`读入的内容储存在`0xffffd0cc`中
IDA里可以看到`memcmp`函数的三个参数分别是(`"0O0o"`,`0xffffd0cc+0x7b`,7)
第二个参数里进行了内存偏移，所以比较的实际是"0O0o"和gets读入字符串的123位开始往后7位
![](http://106.15.72.2/imgbin/w1_p1_3.png)
于是Python生成了123个`a`再加上`0O0o`，然后跳到下个断点，可以看到传入的参数正是`0xffffd0cc`偏移了`0x7b`的地址

但是比较完发现一个奇怪的事，`EAX`并不是预期的0
![](http://106.15.72.2/imgbin/w1_p1_4.png)
然后想到比较了7位但是传入的两个参数只有4位，于是看了下往后8位的地址的内容
![](http://106.15.72.2/imgbin/w1_p1_6.png)
可以看到`0x80486e0`第五位是`0x00`,但是第六位和第七位还有数据，但输入的字符串却是都是0，导致返回结果`EAX`的值非0
看了下后面的内容
![](http://106.15.72.2/imgbin/w1_p1_5.png)
说明比较的7位里包含了两个字符串，但是`gets`用键盘输入的方式并不能在字符串中间插入`'\0'`，不过还好Python的`pwntools`可以对nc直接传输数据，就可以传输'\0'过去了
编写exp
![](http://106.15.72.2/imgbin/w1_p1_8.png)
Pwn!的一声的敲下回车就直接拿到shell(虽然前面分析了好久，不过这一下还是挺爽的233)
![](http://106.15.72.2/imgbin/w1_p1_9.png)
拿到flag
> hgame{0OoO0oo0O0Oo}

---

### One_Shot

拿到的依旧是一个二进制文件，checksec看了下发现没有内存溢出保护，，于是想到这题应该要覆盖内存来拿到flag
直接拖进IDA，然后F5看源码
![](http://106.15.72.2/imgbin/w1_p3_1.png)
发现是将flag文件读入到变量`flag`中，然后读一个字符串，读一个指针，然后把这个指针指向的内容改为1，看来要找一个合法的能读写的地址

看一下静态内存分布
![](http://106.15.72.2/imgbin/w1_p3_2.png)
发现读入的`name`和文件指针`fd`是相连的，那只要覆盖这个文件指针的内容便能将flag连着一块打印出来，然后在本地生成了一个测试用的flag文件，然后名字输入32个a，指针就找一个合法地址，便取了`name`的首地址`0x006010c0`
![](http://106.15.72.2/imgbin/w1_p3_3.png)
但是预期的flag并没有出现，于是考虑到变量`flag`的首地址的内容可能是`\0`，所以程序识别成字符串结尾，然后源代码里刚好可以让指针指向的值改为1，于是输入`flag`的首地址`0x006010e0`试试
![](http://106.15.72.2/imgbin/w1_p3_4.png)
果然把flag打印出来了
![](http://106.15.72.2/imgbin/w1_p3_5.png)
然后写exp直接远程交互
![](http://106.15.72.2/imgbin/w1_p3_6.png)
拿到一个残缺的flag，修复一下即可
> hgame{On3_Sh0t_0ne_Fl4g}