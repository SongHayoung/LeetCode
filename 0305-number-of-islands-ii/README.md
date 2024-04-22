<h2><a href="https://leetcode.com/problems/number-of-islands-ii/">305. Number of Islands II</a></h2><h3>Hard</h3><hr><div><p><font papago-translate="splitted">You are given an empty 2D binary grid </font><code>grid</code><font papago-translate="splitted"> of size </font><code>m x n</code><font papago-translate="splitted">. The grid represents a map where </font><code>0</code><font papago-translate="splitted">'s represent water and </font><code>1</code><font papago-translate="splitted">'s represent land. Initially, all the cells of </font><code>grid</code><font papago-translate="splitted"> are water cells (i.e., all the cells are </font><code>0</code><font papago-translate="splitted">'s).</font></p>

<p><font papago-translate="splitted">We may perform an add land operation which turns the water at position into a land. You are given an array </font><code>positions</code><font papago-translate="splitted"> where </font><code>positions[i] = [r<sub>i</sub>, c<sub>i</sub>]</code><font papago-translate="splitted"> is the position </font><code>(r<sub>i</sub>, c<sub>i</sub>)</code><font papago-translate="splitted"> at which we should operate the </font><code>i<sup>th</sup></code><font papago-translate="splitted"> operation.</font></p>

<p> <code>answer</code> <font papago-translate="splitted"><em>where</em></font> <code>answer[i]</code> <font papago-translate="splitted"><em>is the number of islands after turning the cell</em></font> <code>(r<sub>i</sub>, c<sub>i</sub>)</code> </p>

<p>An <strong>island</strong> is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/10/tmp-grid.jpg" style="width: 500px; height: 294px;">
<pre><strong>Input:</strong> m = 3, n = 3, positions = [[0,0],[0,1],[1,2],[2,1]]
<strong>Output:</strong> [1,1,2,3]
<strong>Explanation:</strong>
Initially, the 2d grid is filled with water.
- Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land. We have 1 island.
- Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land. We still have 1 island.
- Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land. We have 2 islands.
- Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land. We have 3 islands.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> m = 1, n = 1, positions = [[0,0]]
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n, positions.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
	<li><code>positions[i].length == 2</code></li>
	<li><code>0 &lt;= r<sub>i</sub> &lt; m</code></li>
	<li><code>0 &lt;= c<sub>i</sub> &lt; n</code></li>
</ul>

<p>&nbsp;</p>
<p><font papago-translate="splitted"><strong>Follow up:</strong> Could you solve it in time complexity </font><code>O(k log(mn))</code><font papago-translate="splitted">, where </font><code>k == positions.length</code><font papago-translate="splitted">?</font></p>
</div>