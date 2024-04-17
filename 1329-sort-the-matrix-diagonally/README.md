<h2><a href="https://leetcode.com/problems/sort-the-matrix-diagonally/">1329. Sort the Matrix Diagonally</a></h2><h3>Medium</h3><hr><div><p><code>mat[2][0]</code><font papago-translate="splitted">, where </font><code>mat</code><font papago-translate="splitted"> is a </font><code>6 x 3</code><font papago-translate="splitted"> matrix, includes cells </font><code>mat[2][0]</code><font papago-translate="splitted">, </font><code>mat[3][1]</code><font papago-translate="splitted">, and </font><code>mat[4][2]</code><font papago-translate="splitted">.</font></p>

<p><font papago-translate="splitted">Given an </font><code>m x n</code><font papago-translate="splitted"> matrix </font><code>mat</code></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/01/21/1482_example_1_2.png" style="width: 500px; height: 198px;">
<pre><strong>Input:</strong> mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
<strong>Output:</strong> [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
<strong>Output:</strong> [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 100</code></li>
</ul>
</div>