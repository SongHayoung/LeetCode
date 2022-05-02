<h2><a href="https://leetcode.com/problems/number-of-distinct-islands-ii/">711. Number of Distinct Islands II</a></h2><h3>Hard</h3><hr><div><p><font papago-id="16" papago-translate="translated">You are given an </font><code>m x n</code><font papago-id="17" papago-translate="translated"> binary matrix </font><code>grid</code><font papago-id="18" papago-translate="translated">. An island is a group of </font><code>1</code></p>

<p papago-id="19" papago-translate="cached">An island is considered to be the same as another if they have the same shape, or have the same shape after <b papago-id="19-1">rotation</b> (90, 180, or 270 degrees only) or <b papago-id="19-3">reflection</b> (left/right direction or up/down direction).</p>

<p papago-id="20" papago-translate="cached">Return <em papago-id="20-1">the number of <b papago-id="20-1-1">distinct</b> islands</em>.</p>

<p>&nbsp;</p>
<p><strong papago-id="21" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/01/distinctisland2-1-grid.jpg" style="width: 413px; height: 334px;">
<pre><strong papago-id="23-0">Input:</strong> grid = [[1,1,0,0,0],[1,0,0,0,0],[0,0,0,0,1],[0,0,0,1,1]]
<strong papago-id="23-2">Output:</strong> 1
<strong papago-id="23-4">Explanation:</strong> The two islands are considered the same because if we make a 180 degrees clockwise rotation on the first island, then two islands will have the same shapes.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/01/distinctisland1-1-grid.jpg" style="width: 413px; height: 334px;">
<pre><strong papago-id="25-0">Input:</strong> grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
<strong papago-id="25-2">Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>grid[i][j]</code><font> is either </font><code>0</code><font> or </font><code>1</code><font>.</font></li>
</ul>
</div>