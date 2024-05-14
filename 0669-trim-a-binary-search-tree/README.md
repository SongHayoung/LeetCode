<h2><a href="https://leetcode.com/problems/trim-a-binary-search-tree/">669. Trim a Binary Search Tree</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">Given the </font><code>root</code><font papago-translate="splitted"> of a binary search tree and the lowest and highest boundaries as </font><code>low</code><font papago-translate="splitted"> and </font><code>high</code><font papago-translate="splitted">, trim the tree so that all its elements lies in </font><code>[low, high]</code></p>

<p>Return <em>the root of the trimmed binary search tree</em>. Note that the root may change depending on the given bounds.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/09/trim1.jpg" style="width: 450px; height: 126px;">
<pre><strong>Input:</strong> root = [1,0,2], low = 1, high = 2
<strong>Output:</strong> [1,null,2]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/09/trim2.jpg" style="width: 450px; height: 277px;">
<pre><strong>Input:</strong> root = [3,0,4,null,2,null,null,1], low = 1, high = 3
<strong>Output:</strong> [3,2,null,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><font papago-translate="splitted">The number of nodes in the tree is in the range </font><code>[1, 10<sup>4</sup>]</code><font papago-translate="splitted">.</font></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>The value of each node in the tree is <strong>unique</strong>.</li>
	<li><code>root</code><font papago-translate="splitted"> is guaranteed to be a valid binary search tree.</font></li>
	<li><code>0 &lt;= low &lt;= high &lt;= 10<sup>4</sup></code></li>
</ul>
</div>