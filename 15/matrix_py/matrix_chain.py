def matrix_chain_order(p):
	n = p.count(p) - 1
	m = [[0 for i in range(1, n+1)] for i in range(1, n+1)]
	s = [[0 for i in range(1, n)] for i in range(2, n+1)]
	for i in range(1, n):
		m[i][i] = 0
	for l in range(2, n):
		for i in range(1, n-l+1):
			j = i + l - 1
			m[i][j] = 51924361L
			for k in range(i, j-1):
				q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]
				if q < m[i][j]:
					m[i][j] = q;
					s[i][j] = k
	return m, s
	
