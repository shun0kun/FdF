エラー
1. libftとgnlで同じ名前の関数がある。→同じ名前はだめ！
2. INT_MIN, INT_MAX, M_PIは既にmath.hにあるから自分で定義しない！定義したいなら、
	#ifndef INT_MIN
	# define INT_MIN	-2147483648
   としよう。
3. convert_newline_to_nullとfree_tokensのプロトタイプが見えていない。→ヘッダーに追加