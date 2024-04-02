<h2><a href="https://leetcode.com/problems/snakes-and-ladders/">909. Snakes and Ladders</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">You are given an </font><code>n x n</code><font papago-translate="splitted"> integer matrix </font><code>board</code><font papago-translate="splitted"> where the cells are labeled from </font><code>1</code><font papago-translate="splitted"> to </font><code>n<sup>2</sup></code><code>board[n - 1][0]</code><font papago-translate="splitted">) and alternating direction each row.</font></p>

<p><font papago-translate="splitted">You start on square </font><code>1</code><font papago-translate="splitted"> of the board. In each move, starting from square </font><code>curr</code><font papago-translate="splitted">, do the following:</font></p>

<ul>
	<li><font papago-translate="splitted">Choose a destination square </font><code>next</code><font papago-translate="splitted"> with a label in the range </font><code>[curr + 1, min(curr + 6, n<sup>2</sup>)]</code><font papago-translate="splitted">.

	</font><ul>
		<li>This choice simulates the result of a standard <strong>6-sided die roll</strong>: i.e., there are always at most 6 destinations, regardless of the size of the board.</li>
	</ul>
	</li>
	<li><font papago-translate="splitted">If </font><code>next</code><code>next</code><font papago-translate="splitted">.</font></li>
	<li><font papago-translate="splitted">The game ends when you reach the square </font><code>n<sup>2</sup></code><font papago-translate="splitted">.</font></li>
</ul>

<p><font papago-translate="splitted">A board square on row </font><code>r</code><font papago-translate="splitted"> and column </font><code>c</code><font papago-translate="splitted"> has a snake or ladder if </font><code>board[r][c] != -1</code><font papago-translate="splitted">. The destination of that snake or ladder is </font><code>board[r][c]</code><font papago-translate="splitted">. Squares </font><code>1</code><font papago-translate="splitted"> and </font><code>n<sup>2</sup></code><font papago-translate="splitted"> do not have a snake or ladder.</font></p>

<p>Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do <strong>not</strong> follow the subsequent&nbsp;snake or ladder.</p>

<ul>
	<li><font papago-translate="splitted">For example, suppose the board is </font><code>[[-1,4],[-1,3]]</code><font papago-translate="splitted">, and on the first move, your destination square is </font><code>2</code><font papago-translate="splitted">. You follow the ladder to square </font><code>3</code><code>4</code><font papago-translate="splitted">.</font></li>
</ul>

<p><code>n<sup>2</sup></code><font papago-translate="splitted"><em>. If it is not possible to reach the square, return </em></font><code>-1</code><font papago-translate="splitted">.</font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/09/23/snakes.png" style="width: 500px; height: 394px;">
<pre><strong>Input:</strong> board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> board = [[-1,-1],[-1,3]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == board.length == board[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 20</code></li>
	<li><code>board[i][j]</code><font papago-translate="splitted"> is either </font><code>-1</code><font papago-translate="splitted"> or in the range </font><code>[1, n<sup>2</sup>]</code><font papago-translate="splitted">.</font></li>
	<li><font papago-translate="splitted">The squares labeled </font><code>1</code><font papago-translate="splitted"> and </font><code>n<sup>2</sup></code><font papago-translate="splitted"> do not have any ladders or snakes.</font></li>
</ul>
</div>