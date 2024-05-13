<h2><a href="https://leetcode.com/problems/minimum-operations-to-write-the-letter-y-on-a-grid/">3071. Minimum Operations to Write the Letter Y on a Grid</a></h2><h3>Medium</h3><hr><div><p> <code>n x n</code><font papago-translate="splitted"> grid where </font><code>n</code><font papago-translate="splitted"> is odd, and </font><code>grid[r][c]</code><font papago-translate="splitted"> is </font><code>0</code><font papago-translate="splitted">, </font><code>1</code><font papago-translate="splitted">, or </font><code>2</code><font papago-translate="splitted">.</font></p>

<p>We say that a cell belongs to the Letter <strong>Y</strong> if it belongs to one of the following:</p>

<ul>
	<li>The diagonal starting at the top-left cell and ending at the center cell of the grid.</li>
	<li>The diagonal starting at the top-right cell and ending at the center cell of the grid.</li>
	<li>The vertical line starting at the center cell and ending at the bottom border of the grid.</li>
</ul>

<p>The Letter <strong>Y</strong> is written on the grid if and only if:</p>

<ul>
	<li>All values at cells belonging to the Y are equal.</li>
	<li>All values at cells not belonging to the Y are equal.</li>
	<li>The values at cells belonging to the Y are different from the values at cells not belonging to the Y.</li>
</ul>

<p> <code>0</code><font papago-translate="splitted"><em>,</em></font> <code>1</code> <font papago-translate="splitted"><em>,</em><em>or</em></font> <code>2</code><font papago-translate="splitted"><em>.</em></font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/22/y2.png" style="width: 461px; height: 121px;">
<pre><strong>Input:</strong> grid = [[1,2,2],[1,1,0],[0,1,0]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can write Y on the grid by applying the changes highlighted in blue in the image above. After the operations, all cells that belong to Y, denoted in bold, have the same value of 1 while those that do not belong to Y are equal to 0.
It can be shown that 3 is the minimum number of operations needed to write Y on the grid.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/22/y3.png" style="width: 701px; height: 201px;">
<pre><strong>Input:</strong> grid = [[0,1,0,1,0],[2,1,0,1,2],[2,2,2,0,1],[2,2,2,2,2],[2,1,2,2,2]]
<strong>Output:</strong> 12
<strong>Explanation:</strong> We can write Y on the grid by applying the changes highlighted in blue in the image above. After the operations, all cells that belong to Y, denoted in bold, have the same value of 0 while those that do not belong to Y are equal to 2. 
It can be shown that 12 is the minimum number of operations needed to write Y on the grid.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 49 </code></li>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 2</code></li>
	<li><code>n</code><font papago-translate="splitted"> is odd.</font></li>
</ul>
</div>