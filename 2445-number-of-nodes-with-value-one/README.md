<h2><a href="https://leetcode.com/problems/number-of-nodes-with-value-one/">2445. Number of Nodes With Value One</a></h2><h3>Medium</h3><hr><div><p>There is an <strong>undirected</strong> connected tree with <code>n</code> nodes labeled from <code>1</code> to <code>n</code> and <code>n - 1</code> edges. You are given the integer <code>n</code>. The parent node of a node with a label <code>v</code> is the node with the label <code>floor (v / 2)</code>. The root of the tree is the node with the label <code>1</code>.</p>

<ul>
	<li>For example, if <code>n = 7</code>, then the node with the label <code>3</code> has the node with the label <code>floor(3 / 2) = 1</code> as its parent, and the node with the label <code>7</code> has the node with the label <code>floor(7 / 2) = 3</code> as its parent.</li>
</ul>

<p>You are also given an integer array <code>queries</code>. Initially, every node has a value <code>0</code> on it. For each query <code>queries[i]</code>, you should flip all values in the subtree of the node with the label <code>queries[i]</code>.</p>

<p>Return <em>the total number of nodes with the value </em><code>1</code><em> <strong>after processing all the queries</strong></em>.</p>

<p><strong>Note</strong> that:</p>

<ul>
	<li>Flipping the value of a node means that the node with the value <code>0</code> becomes <code>1</code> and vice versa.</li>
	<li><code>floor(x)</code> is equivalent to rounding <code>x</code> down to the nearest integer.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/19/ex1.jpg" style="width: 600px; height: 297px;">
<pre><strong>Input:</strong> n = 5 , queries = [1,2,5]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The diagram above shows the tree structure and its status after performing the queries. The blue node represents the value 0, and the red node represents the value 1.
After processing the queries, there are three red nodes (nodes with value 1): 1, 3, and 5.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/19/ex2.jpg" style="width: 650px; height: 88px;">
<pre><strong>Input:</strong> n = 3, queries = [2,3,3]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The diagram above shows the tree structure and its status after performing the queries. The blue node represents the value 0, and the red node represents the value 1.
After processing the queries, there are one red node (node with value 1): 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries[i] &lt;= n</code></li>
</ul>
</div>