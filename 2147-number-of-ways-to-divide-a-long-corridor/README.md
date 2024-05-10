<h2><a href="https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/">2147. Number of Ways to Divide a Long Corridor</a></h2><h3>Hard</h3><hr><div><p><code>corridor</code><font papago-translate="splitted"> of length </font><code>n</code><font papago-translate="splitted"> consisting of letters </font><code>'S'</code><font papago-translate="splitted"> and </font><code>'P'</code><font papago-translate="splitted"> where each </font><code>'S'</code><font papago-translate="splitted"> represents a seat and each </font><code>'P'</code><font papago-translate="splitted"> represents a plant.</font></p>

<p><code>0</code><code>n - 1</code><font papago-translate="splitted">. Additional room dividers can be installed. For each position between indices </font><code>i - 1</code><font papago-translate="splitted"> and </font><code>i</code><font papago-translate="splitted"> (</font><code>1 &lt;= i &lt;= n - 1</code><font papago-translate="splitted">), at most one divider can be installed.</font></p>

<p>Divide the corridor into non-overlapping sections, where each section has <strong>exactly two seats</strong> with any number of plants. There may be multiple ways to perform the division. Two ways are <strong>different</strong> if there is a position with a room divider installed in the first way but not in the second way.</p>

<p> <code>10<sup>9</sup> + 7</code><font papago-translate="splitted">. If there is no way, return </font><code>0</code><font papago-translate="splitted">.</font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/04/1.png" style="width: 410px; height: 199px;">
<pre><strong>Input:</strong> corridor = "SSPPSPS"
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 different ways to divide the corridor.
The black bars in the above image indicate the two room dividers already installed.
Note that in each of the ways, <strong>each</strong> section has exactly <strong>two</strong> seats.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/04/2.png" style="width: 357px; height: 68px;">
<pre><strong>Input:</strong> corridor = "PPSPSP"
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is only 1 way to divide the corridor, by not installing any additional dividers.
Installing any would create some section that does not have exactly two seats.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/12/3.png" style="width: 115px; height: 68px;">
<pre><strong>Input:</strong> corridor = "S"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no way to divide the corridor because there will always be a section that does not have exactly two seats.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == corridor.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>corridor[i]</code><font papago-translate="splitted"> is either </font><code>'S'</code><font papago-translate="splitted"> or </font><code>'P'</code><font papago-translate="splitted">.</font></li>
</ul>
</div>