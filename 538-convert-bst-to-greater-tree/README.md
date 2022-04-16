<h2><a href="https://leetcode.com/problems/convert-bst-to-greater-tree/">538. Convert BST to Greater Tree</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">Given the </font><code>root</code><font papago-translate="cached" papago-id="16"> of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.</font></p>

<p papago-id="17" papago-translate="cached">As a reminder, a <em papago-id="17-1">binary search tree</em> is a tree that satisfies these constraints:</p>

<ul>
	<li papago-id="18" papago-translate="cached">The left subtree of a node contains only nodes with keys <strong papago-id="18-1">less than</strong> the node's key.</li>
	<li papago-id="19" papago-translate="cached">The right subtree of a node contains only nodes with keys <strong papago-id="19-1">greater than</strong> the node's key.</li>
	<li papago-id="20" papago-translate="translated">Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>
<p><strong papago-id="21" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/05/02/tree.png" style="width: 500px; height: 341px;">
<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
<strong papago-id="0-2">Output:</strong> [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [0,null,1]
<strong>Output:</strong> [1,null,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><font papago-translate="translated" papago-id="2">The number of nodes in the tree is in the range </font><code>[0, 10<sup>4</sup>]</code><font papago-translate="translated" papago-id="3">.</font></li>
	<li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>All the values in the tree are <strong>unique</strong>.</li>
	<li><code>root</code><font papago-translate="translated" papago-id="4"> is guaranteed to be a valid binary search tree.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong>Note:</strong> This question is the same as 1038: <a href="https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/" target="_blank">https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/</a></p>
</div>