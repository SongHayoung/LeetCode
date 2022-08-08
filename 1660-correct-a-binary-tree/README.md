<h2><a href="https://leetcode.com/problems/correct-a-binary-tree/">1660. Correct a Binary Tree</a></h2><h3>Medium</h3><hr><div><p papago-id="14" papago-translate="cached">You have a binary tree with a small defect. There is <strong papago-id="14-1">exactly one</strong> invalid node where its right child incorrectly points to another node at the <strong papago-id="14-3">same depth</strong> but to the <b papago-id="14-5">invalid node's right</b>.</p>

<p><font papago-id="13" papago-translate="translated">Given the root of the binary tree with this defect, </font><code>root</code><font papago-id="12" papago-translate="cached">, return <em papago-id="12-1">the root of the binary tree after <strong papago-id="12-1-1">removing</strong> this invalid node <strong papago-id="12-1-3">and every node underneath it</strong> (minus the node it incorrectly points to).</em></font></p>

<p><strong papago-id="11" papago-translate="translated">Custom testing:</strong></p>

<p papago-id="10" papago-translate="translated">The test input is read as 3 lines:</p>

<ul>
	<li><code>TreeNode root</code></li>
	<li><code>int fromNode</code><code>correctBinaryTree</code><font papago-id="9" papago-translate="translated">)</font></li>
	<li><code>int toNode</code><code>correctBinaryTree</code><font papago-id="8" papago-translate="translated">)</font></li>
</ul>

<p><font papago-id="6" papago-translate="translated">After the binary tree rooted at </font><code>root</code><font papago-id="7" papago-translate="translated"> is parsed, the </font><code>TreeNode</code><font papago-id="4" papago-translate="translated"> with value of </font><code>fromNode</code><font papago-id="5" papago-translate="translated"> will have its right child pointer pointing to the </font><code>TreeNode</code><font papago-id="0" papago-translate="translated"> with a value of </font><code>toNode</code><font papago-id="1" papago-translate="translated">. Then, </font><code>root</code><font papago-id="2" papago-translate="translated"> is passed to </font><code>correctBinaryTree</code><font papago-id="3" papago-translate="translated">.</font></p>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/10/22/ex1v2.png" style="width: 250px; height: 177px;"></strong></p>

<pre papago-id="1" papago-translate="cached"><strong papago-id="1-0">Input:</strong> root = [1,2,3], fromNode = 2, toNode = 3
<strong papago-id="1-2">Output:</strong> [1,null,3]
<strong papago-id="1-4">Explanation:</strong> The node with value 2 is invalid, so remove it.
</pre>

<p><strong papago-id="0" papago-translate="translated">Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/10/22/ex2v3.png" style="width: 350px; height: 255px;"></strong></p>

<pre papago-id="11" papago-translate="cached"><strong papago-id="11-0">Input:</strong> root = [8,3,1,7,null,9,4,2,null,null,null,5,6], fromNode = 7, toNode = 4
<strong papago-id="11-2">Output:</strong> [8,3,1,null,null,9,4,null,null,5,6]
<strong papago-id="11-4">Explanation:</strong> The node with value 7 is invalid, so remove it and the node underneath it, node 2.
</pre>

<p>&nbsp;</p>
<p><strong papago-id="12" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><font papago-id="13" papago-translate="translated">The number of nodes in the tree is in the range </font><code>[3, 10<sup>4</sup>]</code><font papago-id="14" papago-translate="translated">.</font></li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li><font papago-id="15" papago-translate="translated">All </font><code>Node.val</code><font papago-id="16" papago-translate="cached"> are <strong papago-id="16-1">unique</strong>.</font></li>
	<li><code>fromNode != toNode</code></li>
	<li><code>fromNode</code><font papago-id="17" papago-translate="translated"> and </font><code>toNode</code><font papago-id="18" papago-translate="translated"> will exist in the tree and will be on the same depth.</font></li>
	<li><code>toNode</code><font papago-id="19" papago-translate="cached"> is to the <strong papago-id="19-1">right</strong> of </font><code>fromNode</code><font papago-id="20" papago-translate="translated">.</font></li>
	<li><code>fromNode.right</code><font papago-id="21" papago-translate="translated"> is </font><code>null</code><font papago-id="22" papago-translate="translated"> in the initial tree from the test data.</font></li>
</ul></div>