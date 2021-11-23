# POJ 2029 - Get Many Persimmon Trees

给定一个 $W\times H$ 的地图，上有 $N$ 个点，问用一个 $S\times T$ 的方框框住的最大点数是多少？

$N\leq 500,W,H\leq 100$。

### Sol

直接预处理前缀和后暴力枚举选取的左上角即可。

时间复杂度 $O(TWH)$。

