<h2><a href="https://leetcode.com/problems/move-sub-tree-of-n-ary-tree/">1516. Move Sub-Tree of N-Ary Tree</a></h2><h3>Hard</h3><hr><div><p><font papago-translate="translated" papago-id="0">Given the </font><code>root</code><font papago-translate="cached" papago-id="1"> of an <a href="https://leetcode.com/articles/introduction-to-n-ary-trees/" papago-id="1-1">N-ary tree</a> of unique values, and two nodes of the tree </font><code>p</code><font papago-translate="translated" papago-id="2"> and </font><code>q</code><font papago-translate="translated" papago-id="3">.</font></p>

<p><font papago-translate="cached" papago-id="11">You should move the subtree of the node </font><code>p</code><font papago-translate="cached" papago-id="12"> to become a direct child of node </font><code>q</code><font papago-translate="cached" papago-id="13">. If </font><code>p</code><font papago-translate="cached" papago-id="14"> is already a direct child of </font><code>q</code><font papago-translate="cached" papago-id="15">, do not change anything. Node </font><code>p</code> <code>q</code><font papago-translate="cached" papago-id="17">.</font></p>

<p papago-id="18" papago-translate="cached">Return <em papago-id="18-1">the root of the tree</em> after adjusting it.</p>

<p>&nbsp;</p>

<p><font papago-translate="cached" papago-id="19">There are 3 cases for nodes </font><code>p</code><font papago-translate="cached" papago-id="20"> and </font><code>q</code><font papago-translate="cached" papago-id="21">:</font></p>

<ol>
	<li><font papago-translate="cached" papago-id="22">Node </font><code>q</code><font papago-translate="cached" papago-id="23"> is in the sub-tree of node </font><code>p</code><font papago-translate="cached" papago-id="24">.</font></li>
	<li><font papago-translate="cached" papago-id="25">Node </font><code>p</code><font papago-translate="cached" papago-id="26"> is in the sub-tree of node </font><code>q</code><font papago-translate="cached" papago-id="27">.</font></li>
	<li><font papago-translate="cached" papago-id="28">Neither node </font><code>p</code><font papago-translate="cached" papago-id="29"> is in the sub-tree of node </font><code>q</code><font papago-translate="cached" papago-id="30"> nor node </font><code>q</code><font papago-translate="cached" papago-id="31"> is in the sub-tree of node </font><code>p</code><font papago-translate="cached" papago-id="32">.</font></li>
</ol>

<p><font papago-translate="cached" papago-id="33">In cases 2 and 3, you just need to move </font><code><span>p</span></code><font papago-translate="cached" papago-id="34"> (with its sub-tree) to be a child of </font><code>q</code></p>

<p>&nbsp;</p>

<p><em papago-id="36" papago-translate="translated">Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).</em></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="width: 296px; height: 241px;"></p>

<p><font papago-translate="translated" papago-id="28">For example, the above tree is serialized as </font><code>[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]</code><font papago-translate="translated" papago-id="29">.</font></p>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/13/move_e1.jpg" style="width: 450px; height: 188px;">
<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> root = [1,null,2,3,null,4,5,null,6,null,7,8], p = 4, q = 1
<strong papago-id="0-2">Output:</strong> [1,null,2,3,4,null,5,null,6,null,7,8]
<strong papago-id="0-4">Explanation:</strong> This example follows the second case as node p is in the sub-tree of node q. We move node p with its sub-tree to be a direct child of node q.
Notice that node 4 is the last child of node 1.</pre>

<p><strong papago-id="0" papago-translate="translated">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/13/move_e2.jpg" style="width: 281px; height: 281px;">
<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> root = [1,null,2,3,null,4,5,null,6,null,7,8], p = 7, q = 4
<strong papago-id="0-2">Output:</strong> [1,null,2,3,null,4,5,null,6,null,7,8]
<strong papago-id="0-4">Explanation:</strong> Node 7 is already a direct child of node 4. We don't change anything.
</pre>

<p><strong papago-id="0" papago-translate="translated">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/13/move_e3.jpg" style="width: 450px; height: 331px;">
<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> root = [1,null,2,3,null,4,5,null,6,null,7,8], p = 3, q = 8
<strong papago-id="0-2">Output:</strong> [1,null,2,null,4,5,null,7,8,null,null,null,3,null,6]
<strong papago-id="0-4">Explanation:</strong> This example follows case 3 because node p is not in the sub-tree of node q and vice-versa. We can move node 3 with its sub-tree and make it as node 8's child.
</pre>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><font papago-translate="translated" papago-id="30">The total number of nodes is between </font><code>[2, 1000]</code><font papago-translate="translated" papago-id="31">.</font></li>
	<li papago-id="1" papago-translate="cached">Each node has a <strong papago-id="1-1">unique</strong> value.</li>
	<li><code>p != null</code></li>
	<li><code>q != null</code></li>
	<li><code>p</code><font papago-translate="translated" papago-id="32"> and </font><code>q</code><font papago-translate="translated" papago-id="33"> are two different nodes (i.e. </font><code>p != q</code><font papago-translate="translated" papago-id="34">).</font></li>
</ul>
</div>