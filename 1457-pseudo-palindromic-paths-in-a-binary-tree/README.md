<h2><a href="https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/">1457. Pseudo-Palindromic Paths in a Binary Tree</a></h2><h3>Medium</h3><hr><div><p papago-id="15" papago-translate="cached">Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be <strong papago-id="15-1">pseudo-palindromic</strong> if at least one permutation of the node values in the path is a palindrome.</p>

<p><em papago-id="16" papago-translate="cached">Return the number of <strong papago-id="16-1">pseudo-palindromic</strong> paths going from the root node to leaf nodes.</em></p>

<p>&nbsp;</p>
<p><strong papago-id="17" papago-translate="translated">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/05/06/palindromic_paths_1.png" style="width: 300px; height: 201px;"></p>

<pre papago-id="18" papago-translate="cached"><strong papago-id="18-0">Input:</strong> root = [2,3,1,3,1,null,1]
<strong papago-id="18-2">Output:</strong> 2 
<strong papago-id="18-4">Explanation:</strong> The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
</pre>

<p><strong papago-id="0" papago-translate="translated">Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/05/07/palindromic_paths_2.png" style="width: 300px; height: 314px;"></strong></p>

<pre><strong>Input:</strong> root = [2,1,1,1,3,null,null,null,null,null,1]
<strong>Output:</strong> 1 
<strong>Explanation:</strong> The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [9]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><font papago-translate="translated" papago-id="0">The number of nodes in the tree is in the range </font><code>[1, 10<sup>5</sup>]</code><font papago-translate="translated" papago-id="1">.</font></li>
	<li><code>1 &lt;= Node.val &lt;= 9</code></li>
</ul>
</div>