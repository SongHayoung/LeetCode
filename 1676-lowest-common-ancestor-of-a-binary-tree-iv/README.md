<h2><a href="https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/">1676. Lowest Common Ancestor of a Binary Tree IV</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">Given the </font><code>root</code><font papago-translate="splitted"> of a binary tree and an array of </font><code>TreeNode</code><font papago-translate="splitted"> objects </font><code>nodes</code><code>nodes</code></p>

<p><code>n</code><font papago-translate="splitted"> nodes </font><code>p<sub>1</sub></code><font papago-translate="splitted">, </font><code>p<sub>2</sub></code><font papago-translate="splitted">, ..., </font><code>p<sub>n</sub></code><font papago-translate="splitted"> in a binary tree </font><code>T</code><font papago-translate="splitted"> is the lowest node that has every </font><code>p<sub>i</sub></code><code>i</code><code>x</code><font papago-translate="splitted"> is a node </font><code>y</code><font papago-translate="splitted"> that is on the path from node </font><code>x</code><font papago-translate="splitted"> to some leaf node.</font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [4,7]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The lowest common ancestor of nodes 4 and 7 is node 2.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The lowest common ancestor of a single node is the node itself.

</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [7,6,2,4]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The lowest common ancestor of the nodes 7, 6, 2, and 4 is node 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><font papago-translate="splitted">The number of nodes in the tree is in the range </font><code>[1, 10<sup>4</sup>]</code><font papago-translate="splitted">.</font></li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li><font papago-translate="splitted">All </font><code>Node.val</code><font papago-translate="splitted"> are <strong>unique</strong>.</font></li>
	<li><font papago-translate="splitted">All </font><code>nodes[i]</code><font papago-translate="splitted"> will exist in the tree.</font></li>
	<li><font papago-translate="splitted">All </font><code>nodes[i]</code><font papago-translate="splitted"> are distinct.</font></li>
</ul>
</div>