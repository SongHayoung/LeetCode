<h2><a href="https://leetcode.com/problems/two-sum-bsts/">1214. Two Sum BSTs</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="0">Given the roots of two binary search trees, </font><code>root1</code><font papago-translate="cached" papago-id="1"> and </font><code>root2</code><font papago-translate="cached" papago-id="2">, return </font><code>true</code><font papago-translate="cached" papago-id="3"> if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer </font><code>target</code><font papago-translate="cached" papago-id="4">.</font></p>

<p>&nbsp;</p>
<p><strong papago-id="16" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/10/ex1.png" style="width: 369px; height: 169px;">
<pre papago-id="17" papago-translate="cached"><strong papago-id="17-0">Input:</strong> root1 = [2,1,4], root2 = [1,0,3], target = 5
<strong papago-id="17-2">Output:</strong> true
<strong papago-id="17-4">Explanation: </strong>2 and 3 sum up to 5.
</pre>

<p><strong papago-id="18" papago-translate="translated">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/10/ex2.png" style="width: 453px; height: 290px;">
<pre papago-id="19" papago-translate="cached"><strong papago-id="19-0">Input:</strong> root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
<strong papago-id="19-2">Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong papago-id="20" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><font papago-translate="cached" papago-id="5">The number of nodes in each tree is in the range </font><code>[1, 5000]</code><font papago-translate="cached" papago-id="6">.</font></li>
	<li><code>-10<sup>9</sup> &lt;= Node.val, target &lt;= 10<sup>9</sup></code></li>
</ul>
</div>