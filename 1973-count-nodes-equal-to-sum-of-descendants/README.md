<h2><a href="https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/">1973. Count Nodes Equal to Sum of Descendants</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">Given the </font><code>root</code></p>

<p><code>x</code><font papago-translate="splitted"> is any node that is on the path from node </font><code>x</code><font papago-translate="splitted"> to some leaf node. The sum is considered to be </font><code>0</code><font papago-translate="splitted"> if the node has no descendants.</font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/17/screenshot-2021-08-17-at-17-16-50-diagram-drawio-diagrams-net.png" style="width: 250px; height: 207px;">
<pre><strong>Input:</strong> root = [10,3,4,2,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
For the node with value 10: The sum of its descendants is 3+4+2+1 = 10.
For the node with value 3: The sum of its descendants is 2+1 = 3.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/17/screenshot-2021-08-17-at-17-25-21-diagram-drawio-diagrams-net.png" style="height: 196px; width: 200px;">
<pre><strong>Input:</strong> root = [2,3,null,2,null]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
No node has a value that is equal to the sum of its descendants.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/17/screenshot-2021-08-17-at-17-23-53-diagram-drawio-diagrams-net.png" style="width: 50px; height: 50px;">
<pre><strong>Input:</strong> root = [0]
<strong>Output:</strong> 1
For the node with value 0: The sum of its descendants is 0 since it has no descendants.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><font papago-translate="splitted">The number of nodes in the tree is in the range </font><code>[1, 10<sup>5</sup>]</code><font papago-translate="splitted">.</font></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>
</div>