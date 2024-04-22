<h2><a href="https://leetcode.com/problems/count-ways-to-distribute-candies/">1692. Count Ways to Distribute Candies</a></h2><h3>Hard</h3><hr><div><p><font papago-translate="splitted">There are </font><code>n</code> <code>1</code><font papago-translate="splitted"> through </font><code>n</code><font papago-translate="splitted">) and </font><code>k</code></p>

<p>There can be multiple ways to distribute the candies. Two ways are considered <strong>different</strong> if the candies in one bag in the first way are not all in the same bag in the second way. The order of the bags and the order of the candies within each bag do not matter.</p>

<p><font papago-translate="splitted">For example, </font><code>(1), (2,3)</code><font papago-translate="splitted"> and </font><code>(2), (1,3)</code><font papago-translate="splitted"> are considered different because candies </font><code>2</code><font papago-translate="splitted"> and </font><code>3</code><font papago-translate="splitted"> in the bag </font><code>(2,3)</code><font papago-translate="splitted"> in the first way are not in the same bag in the second way (they are split between the bags </font><code>(<u>2</u>)</code><font papago-translate="splitted"> and </font><code>(1,<u>3</u>)</code><font papago-translate="splitted">). However, </font><code>(1), (2,3)</code><font papago-translate="splitted"> and </font><code>(3,2), (1)</code><font papago-translate="splitted"> are considered the same because the candies in each bag are all in the same bags in both ways.</font></p>

<p><font papago-translate="splitted">Given two integers, </font><code>n</code><font papago-translate="splitted"> and </font><code>k</code> <code>10<sup>9</sup> + 7</code><font papago-translate="splitted">.</font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/12/16/candies-1.png" style="height: 248px; width: 600px;"></p>

<pre><strong>Input:</strong> n = 3, k = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> You can distribute 3 candies into 2 bags in 3 ways:
(1), (2,3)
(1,2), (3)
(1,3), (2)
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 4, k = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> You can distribute 4 candies into 2 bags in 7 ways:
(1), (2,3,4)
(1,2), (3,4)
(1,3), (2,4)
(1,4), (2,3)
(1,2,3), (4)
(1,2,4), (3)
(1,3,4), (2)
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> n = 20, k = 5
<strong>Output:</strong> 206085257
<strong>Explanation:</strong> You can distribute 20 candies into 5 bags in 1881780996 ways. 1881780996 modulo 10<sup>9</sup> + 7 = 206085257.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 1000</code></li>
</ul>
</div>