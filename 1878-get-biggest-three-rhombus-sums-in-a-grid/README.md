<h2><a href="https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/">1878. Get Biggest Three Rhombus Sums in a Grid</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="0">You are given an </font><code>m x n</code><font papago-translate="cached" papago-id="1"> integer matrix </font><code>grid</code><font papago-translate="cached" papago-id="2">​​​.</font></p>

<p> <code>grid</code></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/23/pc73-q4-desc-2.png" style="width: 385px; height: 385px;">
<p papago-id="16" papago-translate="translated">Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.</p>

<p><code>grid</code></p>

<p>&nbsp;</p>
<p><strong papago-id="19" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/23/pc73-q4-ex1.png" style="width: 360px; height: 361px;">
<pre papago-id="20" papago-translate="cached"><strong papago-id="20-0">Input:</strong> grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
<strong papago-id="20-2">Output:</strong> [228,216,211]
<strong papago-id="20-4">Explanation:</strong> The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211
</pre>

<p><strong papago-id="21" papago-translate="translated">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/23/pc73-q4-ex2.png" style="width: 217px; height: 217px;">
<pre papago-id="22" papago-translate="cached"><strong papago-id="22-0">Input:</strong> grid = [[1,2,3],[4,5,6],[7,8,9]]
<strong papago-id="22-2">Output:</strong> [20,9,8]
<strong papago-id="22-4">Explanation:</strong> The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)
</pre>

<p><strong papago-id="23" papago-translate="translated">Example 3:</strong></p>

<pre papago-id="24" papago-translate="cached"><strong papago-id="24-0">Input:</strong> grid = [[7,7,7]]
<strong papago-id="24-2">Output:</strong> [7]
<strong papago-id="24-4">Explanation:</strong> All three possible rhombus sums are the same, so return [7].
</pre>

<p>&nbsp;</p>
<p><strong papago-id="25" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>
</div>