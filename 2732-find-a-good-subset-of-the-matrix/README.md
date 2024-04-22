<h2><a href="https://leetcode.com/problems/find-a-good-subset-of-the-matrix/">2732. Find a Good Subset of the Matrix</a></h2><h3>Hard</h3><hr><div><p> <code>m x n</code><font papago-translate="splitted"> binary matrix </font><code>grid</code><font papago-translate="splitted">.</font></p>

<p>Let us call a <strong>non-empty</strong> subset of rows <strong>good</strong> if the sum of each column of the subset is at most half of the length of the subset.</p>

<p><font papago-translate="splitted">More formally, if the length of the chosen subset of rows is </font><code>k</code><font papago-translate="splitted">, then the sum of each column should be at most </font><code>floor(k / 2)</code><font papago-translate="splitted">.</font></p>

<p>Return <em>an integer array that contains row indices of a good subset sorted in <strong>ascending</strong> order.</em></p>

<p>If there are multiple good subsets, you can return any of them. If there are no good subsets, return an empty array.</p>

<p><code>grid</code><font papago-translate="splitted"> is any matrix that can be obtained by deleting some (possibly none or all) rows from </font><code>grid</code><font papago-translate="splitted">.</font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [[0,1,1,0],[0,0,0,1],[1,1,1,1]]
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> We can choose the 0<sup>th</sup> and 1<sup>st</sup> rows to create a good subset of rows.
The length of the chosen subset is 2.
- The sum of the 0<sup>th</sup>&nbsp;column is 0 + 0 = 0, which is at most half of the length of the subset.
- The sum of the 1<sup>st</sup>&nbsp;column is 1 + 0 = 1, which is at most half of the length of the subset.
- The sum of the 2<sup>nd</sup>&nbsp;column is 1 + 0 = 1, which is at most half of the length of the subset.
- The sum of the 3<sup>rd</sup>&nbsp;column is 0 + 1 = 1, which is at most half of the length of the subset.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[0]]
<strong>Output:</strong> [0]
<strong>Explanation:</strong> We can choose the 0<sup>th</sup> row to create a good subset of rows.
The length of the chosen subset is 1.
- The sum of the 0<sup>th</sup>&nbsp;column is 0, which is at most half of the length of the subset.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,1],[1,1,1]]
<strong>Output:</strong> []
<strong>Explanation:</strong> It is impossible to choose any subset of rows to create a good subset.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= n &lt;= 5</code></li>
	<li><code>grid[i][j]</code><font papago-translate="splitted"> is either </font><code>0</code><font papago-translate="splitted"> or </font><code>1</code><font papago-translate="splitted">.</font></li>
</ul>
</div>