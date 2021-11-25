设 $f[x][y]$ 表示该点最终通向左边/上边的最大权值。

显然贪心的想一定是把每个点通向左边或上边。
$$
\begin{align}
f[x][y]\leftarrow f[x-1][y] \\
\leftarrow f[x][y-1]
\end{align}
$$
时间复杂度：$O(N^2)$。