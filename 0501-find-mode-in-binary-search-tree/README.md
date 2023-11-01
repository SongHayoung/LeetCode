<h2><a href="https://leetcode.com/problems/find-mode-in-binary-search-tree/">501. Find Mode in Binary Search Tree</a></h2><h3>Easy</h3><hr><div><p><font papago-translate="cached" papago-id="10">Given the </font><code>root</code></p>

<p papago-id="12" papago-translate="cached">If the tree has more than one mode, return them in <strong papago-id="12-1">any order</strong>.</p>

<p papago-id="13" papago-translate="translated">Assume a BST is defined as follows:</p>

<ul>
	<li papago-id="14" papago-translate="cached">The left subtree of a node contains only nodes with keys <strong papago-id="14-1">less than or equal to</strong> the node's key.</li>
	<li papago-id="15" papago-translate="cached">The right subtree of a node contains only nodes with keys <strong papago-id="15-1">greater than or equal to</strong> the node's key.</li>
	<li papago-id="16" papago-translate="translated">Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example" papago-id="17" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/11/mode-tree.jpg" style="width: 142px; height: 222px;">
<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> root = [1,null,2,2]
<strong papago-id="0-2">Output:</strong> [2]
</pre>

<p><strong class="example" papago-id="1" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="2" papago-translate="cached"><strong papago-id="2-0">Input:</strong> root = [0]
<strong papago-id="2-2">Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><font papago-translate="translated" papago-id="4">The number of nodes in the tree is in the range </font><code>[1, 10<sup>4</sup>]</code><font papago-translate="translated" papago-id="5">.</font></li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<font papago-translate="cached" papago-id="6"><strong papago-id="6-0">Follow up:</strong> Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).</font></div>