<h2><a href="https://leetcode.com/problems/moving-stones-until-consecutive/">1033. Moving Stones Until Consecutive</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">There are three stones in different positions on the X-axis. You are given three integers </font><code>a</code><font papago-translate="cached" papago-id="16">, </font><code>b</code><font papago-translate="cached" papago-id="17">, and </font><code>c</code><font papago-translate="cached" papago-id="18">, the positions of the stones.</font></p>

<p><font papago-translate="cached" papago-id="19">In one move, you pick up a stone at an endpoint (i.e., either the lowest or highest position stone), and move it to an unoccupied position between those endpoints. Formally, let's say the stones are currently at positions </font><code>x</code><font papago-translate="cached" papago-id="20">, </font><code>y</code><font papago-translate="cached" papago-id="21">, and </font><code>z</code><font papago-translate="cached" papago-id="22"> with </font><code>x &lt; y &lt; z</code><font papago-translate="cached" papago-id="23">. You pick up the stone at either position </font><code>x</code><font papago-translate="cached" papago-id="24"> or position </font><code>z</code><font papago-translate="cached" papago-id="25">, and move that stone to an integer position </font><code>k</code><font papago-translate="cached" papago-id="26">, with </font><code>x &lt; k &lt; z</code><font papago-translate="cached" papago-id="27"> and </font><code>k != y</code><font papago-translate="cached" papago-id="28">.</font></p>

<p papago-id="29" papago-translate="translated">The game ends when you cannot make any more moves (i.e., the stones are in three consecutive positions).</p>

<p><code>answer</code><font papago-translate="splited"><em papago-id="15" papago-translate="translated"> of length </em></font><code>2</code></p>

<ul>
	<li><code>answer[0]</code> <em papago-id="32" papago-translate="translated">is the minimum number of moves you can play, and</em></li>
	<li><code>answer[1]</code> </li>
</ul>

<p>&nbsp;</p>
<p><strong papago-id="34" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="35" papago-translate="cached"><strong papago-id="35-0">Input:</strong> a = 1, b = 2, c = 5
<strong papago-id="35-2">Output:</strong> [1,2]
<strong papago-id="35-4">Explanation:</strong> Move the stone from 5 to 3, or move the stone from 5 to 4 to 3.
</pre>

<p><strong papago-id="0" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> a = 4, b = 3, c = 2
<strong papago-id="0-2">Output:</strong> [0,0]
<strong papago-id="0-4">Explanation:</strong> We cannot make any moves.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> a = 3, b = 5, c = 1
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> Move the stone from 1 to 4; or move the stone from 1 to 2 to 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a, b, c &lt;= 100</code></li>
	<li><code>a</code><font papago-translate="translated" papago-id="18">, </font><code>b</code><font papago-translate="translated" papago-id="19">, and </font><code>c</code><font papago-translate="translated" papago-id="20"> have different values.</font></li>
</ul>
</div>