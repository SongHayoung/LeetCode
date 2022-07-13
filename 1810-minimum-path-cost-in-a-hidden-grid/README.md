<h2><a href="https://leetcode.com/problems/minimum-path-cost-in-a-hidden-grid/">1810. Minimum Path Cost in a Hidden Grid</a></h2><h3>Medium</h3><hr><div><p>This is an <strong>interactive problem</strong>.</p>

<p><font papago-translate="translated" papago-id="0">There is a robot in a hidden grid, and you are trying to get it from its starting cell to the target cell in this grid. The grid is of size </font><code>m x n</code><font papago-translate="cached" papago-id="1">, and each cell in the grid is either empty or blocked. It is <strong papago-id="1-1">guaranteed</strong> that the starting cell and the target cell are different, and neither of them is blocked.</font></p>

<p>Each cell has a <strong>cost</strong> that you need to pay each time you <strong>move</strong> to the cell. The starting cell's cost is <strong>not</strong> applied before the robot moves.</p>

<p><font papago-translate="cached" papago-id="2">You want to find the minimum total cost to move the robot to the target cell. However, you <strong papago-id="2-1">do not know</strong> the grid's dimensions, the starting cell, nor the target cell. You are only allowed to ask queries to the </font><code>GridMaster</code><font papago-translate="translated" papago-id="3"> object.</font></p>

<p><font papago-translate="translated" papago-id="4">The </font><code>GridMaster</code><font papago-translate="translated" papago-id="5"> class has the following functions:</font></p>

<ul>
	<li><code>boolean canMove(char direction)</code><font papago-translate="translated" papago-id="6"> Returns </font><code>true</code><font papago-translate="translated" papago-id="7"> if the robot can move in that direction. Otherwise, it returns </font><code>false</code><font papago-translate="translated" papago-id="8">.</font></li>
	<li><code>int move(char direction)</code><code>-1</code><font papago-translate="cached" papago-id="12">.</font></li>
	<li><code>boolean isTarget()</code><font papago-translate="cached" papago-id="13"> Returns </font><code>true</code><font papago-translate="cached" papago-id="14"> if the robot is currently on the target cell. Otherwise, it returns </font><code>false</code><font papago-translate="cached" papago-id="15">.</font></li>
</ul>

<p><font papago-translate="cached" papago-id="16">Note that </font><code>direction</code><font papago-translate="cached" papago-id="17"> in the above functions should be a character from </font><code>{'U','D','L','R'}</code><font papago-translate="cached" papago-id="18">, representing the directions up, down, left, and right, respectively.</font></p>

<p><code>-1</code><font papago-translate="cached" papago-id="20">.</font></p>

<p><strong papago-id="21" papago-translate="translated">Custom testing:</strong></p>

<p><font papago-translate="cached" papago-id="22">The test input is read as a 2D matrix </font><code>grid</code><font papago-translate="cached" papago-id="23"> of size </font><code>m x n</code><font papago-translate="cached" papago-id="24"> and four integers </font><code>r1</code><font papago-translate="cached" papago-id="25">, </font><code>c1</code><font papago-translate="cached" papago-id="26">, </font><code>r2</code><font papago-translate="cached" papago-id="27">, and </font><code><font face="monospace">c2</font></code><font papago-translate="cached" papago-id="28"> where:</font></p>

<ul>
	<li><code>grid[i][j] == 0</code><font papago-translate="cached" papago-id="29"> indicates that the cell </font><code>(i, j)</code><font papago-translate="cached" papago-id="30"> is blocked.</font></li>
	<li><code>grid[i][j] &gt;= 1</code><font papago-translate="cached" papago-id="31"> indicates that the cell </font><code>(i, j)</code><font papago-translate="cached" papago-id="32"> is empty and </font><code>grid[i][j]</code></li>
	<li><code>(r1, c1)</code><font papago-translate="cached" papago-id="34"> is the starting cell of the robot.</font></li>
	<li><code>(r2, c2)</code><font papago-translate="cached" papago-id="35"> is the target cell of the robot.</font></li>
</ul>

<p papago-id="36" papago-translate="cached">Remember that you will <strong papago-id="36-1">not</strong> have this information in your code.</p>

<p>&nbsp;</p>
<p><strong papago-id="37" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="38" papago-translate="cached"><strong papago-id="38-0">Input:</strong> grid = [[2,3],[1,1]], r1 = 0, c1 = 1, r2 = 1, c2 = 0
<strong papago-id="38-2">Output:</strong> 2
<strong papago-id="38-4">Explanation:</strong> One possible interaction is described below:
The robot is initially standing on cell (0, 1), denoted by the 3.
- master.canMove('U') returns false.
- master.canMove('D') returns true.
- master.canMove('L') returns true.
- master.canMove('R') returns false.
- master.move('L') moves the robot to the cell (0, 0) and returns 2.
- master.isTarget() returns false.
- master.canMove('U') returns false.
- master.canMove('D') returns true.
- master.canMove('L') returns false.
- master.canMove('R') returns true.
- master.move('D') moves the robot to the cell (1, 0) and returns 1.
- master.isTarget() returns true.
- master.move('L') doesn't move the robot and returns -1.
- master.move('R') moves the robot to the cell (1, 1) and returns 1.
We now know that the target is the cell (1, 0), and the minimum total cost to reach it is 2. </pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[0,3,1],[3,4,2],[1,2,0]], r1 = 2, c1 = 0, r2 = 0, c2 = 2
<strong>Output:</strong> 9
<strong>Explanation:</strong> The minimum cost path is (2,0) -&gt; (2,1) -&gt; (1,1) -&gt; (1,2) -&gt; (0,2).
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0],[0,1]], r1 = 0, c1 = 0, r2 = 1, c2 = 1
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no path from the robot to the target cell.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 100</code></li>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>
</div>