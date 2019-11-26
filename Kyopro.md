# Shuz* National Programming Contest

### 問題文

Shuz* 君の国では今度プログラミングコンテスト「SNPC」が行われることになりました。

SNPCに参加する競プロerは $N$ 人で、 $i$ 番目の競プロerのレートは $R_i$ 、SNPCでの予想問題正解数は $P_i$ です。

SNPCの主催者であるShuz* 君は、以下を満たすようにSNPCのチームを決めようと思っています。

- チームは $2$ 人以下の競プロerで構成される。
- すべてのチームについて、チーム内のレートの総和は $M$ 以下である。
- チーム $i$ 内での予想問題正解数の総和を $T_i$ とするとき、 $\displaystyle(\max_i\ T_i)-(\min_i\ T_i)$ が最小になるようにする。

適切にチーム分けしたときの $\displaystyle(\max_i\ T_i)-(\min_i\ T_i)$ を求めてください。

### 制約

- $1\le N,\ M\le 10^4=10000$
- $0\le R_i\le 5000$
- $0\le P_i\le 10$
- $\displaystyle(\max_i\ R_i)\le M$ 

