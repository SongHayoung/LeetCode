<h2><a href="https://leetcode.com/problems/brick-wall/">554. Brick Wall</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">There is a rectangular brick wall in front of you with </font><code>n</code><font papago-translate="cached" papago-id="16"> rows of bricks. The </font><code>i<sup>th</sup></code><font papago-translate="cached" papago-id="17"> row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.</font></p>

<p papago-id="18" papago-translate="translated">Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.</p>

<p><font papago-translate="cached" papago-id="19">Given the 2D array </font><code>wall</code></p>

<p>&nbsp;</p>
<p><strong papago-id="21" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/cutwall-grid.jpg" style="width: 493px; height: 577px;">
<pre><strong>Input:</strong> wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> wall = [[1],[1],[1]]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == wall.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= wall[i].length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= sum(wall[i].length) &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>sum(wall[i])</code><font papago-translate="translated" papago-id="5"> is the same for each row </font><code>i</code><font papago-translate="translated" papago-id="6">.</font></li>
	<li><code>1 &lt;= wall[i][j] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>
</div>