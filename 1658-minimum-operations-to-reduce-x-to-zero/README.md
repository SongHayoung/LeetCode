<h2><a href="https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/">1658. Minimum Operations to Reduce X to Zero</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">You are given an integer array </font><code>nums</code><font papago-translate="splitted"> and an integer </font><code>x</code><font papago-translate="splitted">. In one operation, you can either remove the leftmost or the rightmost element from the array </font><code>nums</code><font papago-translate="splitted"> and subtract its value from </font><code>x</code></p>

<p><code>x</code> <font papago-translate="splitted"><em>to <strong>exactly</strong></em></font> <code>0</code> <font papago-translate="splitted"><em>if it is possible</em><em>, otherwise, return </em></font><code>-1</code><font papago-translate="splitted">.</font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,4,2,3], x = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> The optimal solution is to remove the last two elements to reduce x to zero.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,6,7,8,9], x = 4
<strong>Output:</strong> -1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,20,1,1,3], x = 10
<strong>Output:</strong> 5
<strong>Explanation:</strong> The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= x &lt;= 10<sup>9</sup></code></li>
</ul>
</div>