<h2><a href="https://leetcode.com/problems/shortest-path-in-a-hidden-grid/">1778. Shortest Path in a Hidden Grid</a></h2><h3>Medium</h3><hr><div><p>This is an <strong papago-id="0-1">interactive problem</strong>.</p>

<p><font>There is a robot in a hidden grid, and you are trying to get it from its starting cell to the target cell in this grid. The grid is of size </font><code>m x n</code></p>

<p><code>GridMaster</code><font> object.</font></p>

<p><font>Thr </font><code>GridMaster</code><font> class has the following functions:</font></p>

<ul>
	<li><code>boolean canMove(char direction)</code><font> Returns </font><code>true</code><font> if the robot can move in that direction. Otherwise, it returns </font><code>false</code><font>.</font></li>
	<li><code>void move(char direction)</code></li>
	<li><code>boolean isTarget()</code><font> Returns </font><code>true</code><font> if the robot is currently on the target cell. Otherwise, it returns </font><code>false</code><font>.</font></li>
</ul>

<p><font>Note that </font><code>direction</code><font> in the above functions should be a character from </font><code>{'U','D','L','R'}</code><font>, representing the directions up, down, left, and right, respectively.</font></p>

<p><code>-1</code><font>.</font></p>

<p><strong>Custom testing:</strong></p>

<p><font>The test input is read as a 2D matrix </font><code>grid</code><font> of size </font><code>m x n</code><font> where:</font></p>

<ul>
	<li><code>grid[i][j] == -1</code><font> indicates that the robot is in cell </font><code>(i, j)</code><font> (the starting cell).</font></li>
	<li><code>grid[i][j] == 0</code><font> indicates that the cell </font><code>(i, j)</code><font> is blocked.</font></li>
	<li><code>grid[i][j] == 1</code><font> indicates that the cell </font><code>(i, j)</code><font> is empty.</font></li>
	<li><code>grid[i][j] == 2</code><font> indicates that the cell </font><code>(i, j)</code><font> is the target cell.</font></li>
</ul>

<p><font>There is exactly one </font><code>-1</code><font> and </font><code>2</code><font> in </font><code>grid</code><font>. Remember that you will <strong papago-id="40-1">not</strong> have this information in your code.</font></p>

<p>&nbsp;</p>
<p><strong papago-id="11" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="12" papago-translate="cached"><strong papago-id="12-0">Input:</strong> grid = [[1,2],[-1,0]]
<strong papago-id="12-2">Output:</strong> 2
<strong papago-id="12-4">Explanation:</strong> One possible interaction is described below:
The robot is initially standing on cell (1, 0), denoted by the -1.
- master.canMove('U') returns true.
- master.canMove('D') returns false.
- master.canMove('L') returns false.
- master.canMove('R') returns false.
- master.move('U') moves the robot to the cell (0, 0).
- master.isTarget() returns false.
- master.canMove('U') returns false.
- master.canMove('D') returns true.
- master.canMove('L') returns false.
- master.canMove('R') returns true.
- master.move('R') moves the robot to the cell (0, 1).
- master.isTarget() returns true. 
We now know that the target is the cell (0, 1), and the shortest path to the target cell is 2.
</pre>

<p><strong papago-id="13" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="14" papago-translate="cached"><strong papago-id="14-0">Input:</strong> grid = [[0,0,-1],[1,1,1],[2,0,0]]
<strong papago-id="14-2">Output:</strong> 4
<strong papago-id="14-4">Explanation:</strong>&nbsp;The minimum distance between the robot and the target cell is 4.</pre>

<p><strong papago-id="15" papago-translate="translated">Example 3:</strong></p>

<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> grid = [[-1,0],[0,2]]
<strong papago-id="0-2">Output:</strong> -1
<strong papago-id="0-4">Explanation:</strong>&nbsp;There is no path from the robot to the target cell.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 500</code></li>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>grid[i][j]</code><font> is either </font><code>-1</code><font>, </font><code>0</code><font>, </font><code>1</code><font>, or </font><code>2</code><font>.</font></li>
	<li><font>There is <strong papago-id="5-1">exactly one</strong></font> <code>-1</code><font> in </font><code>grid</code><font>.</font></li>
	<li><font>There is <strong papago-id="41-1">exactly one</strong></font> <code>2</code><font> in </font><code>grid</code><font>.</font></li>
</ul>
</div>