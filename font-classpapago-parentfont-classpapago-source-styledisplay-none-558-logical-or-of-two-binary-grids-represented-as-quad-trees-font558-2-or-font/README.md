<h2><a href="https://leetcode.com/problems/logical-or-of-two-binary-grids-represented-as-quad-trees/"><font class="papago-parent"><font class="papago-source" style="display:none;">558. Logical OR of Two Binary Grids Represented as Quad-Trees</font>제558조 쿼드 트리로 표시되는2개의 바이너리 그리드의 논리 OR</font></a></h2><h3>Medium</h3><hr><div><p papago-id="0" papago-translate="cached">A Binary Matrix is a matrix in which all the elements are either <strong papago-id="0-1">0</strong> or <strong papago-id="0-3">1</strong>.</p>

<p><font papago-translate="translated" papago-id="0">Given </font><code>quadTree1</code><font papago-translate="translated" papago-id="1"> and </font><code>quadTree2</code><font papago-translate="translated" papago-id="2">. </font><code>quadTree1</code><font papago-translate="translated" papago-id="3"> represents a </font><code>n * n</code><font papago-translate="translated" papago-id="4"> binary matrix and </font><code>quadTree2</code><font papago-translate="translated" papago-id="5"> represents another </font><code>n * n</code><font papago-translate="translated" papago-id="6"> binary matrix.</font></p>

<p><font papago-translate="cached" papago-id="7">Return <em papago-id="7-1">a Quad-Tree</em> representing the </font><code>n * n</code><font papago-translate="cached" papago-id="8"> binary matrix which is the result of <strong papago-id="8-1">logical bitwise OR</strong> of the two binary matrixes represented by </font><code>quadTree1</code><font papago-translate="translated" papago-id="9"> and </font><code>quadTree2</code><font papago-translate="translated" papago-id="10">.</font></p>

<p><font papago-translate="cached" papago-id="11">Notice that you can assign the value of a node to <strong papago-id="11-1">True</strong> or <strong papago-id="11-3">False</strong> when </font><code>isLeaf</code><font papago-translate="cached" papago-id="12"> is <strong papago-id="12-1">False</strong>, and both are <strong papago-id="12-3">accepted</strong> in the answer.</font></p>

<p papago-id="0" papago-translate="translated">A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:</p>

<ul>
	<li><code>val</code><font papago-translate="translated" papago-id="13">: True if the node represents a grid of 1's or False if the node represents a grid of 0's.</font></li>
	<li><code>isLeaf</code><font papago-translate="translated" papago-id="14">: True if the node is leaf node on the tree or False if the node has the four children.</font></li>
</ul>

<pre papago-id="1" papago-translate="translated">class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}</pre>

<p papago-id="0" papago-translate="translated">We can construct a Quad-Tree from a two-dimensional area using the following steps:</p>

<ol>
	<li><font papago-translate="translated" papago-id="15">If the current grid has the same value (i.e all </font><code>1's</code><font papago-translate="translated" papago-id="16"> or all </font><code>0's</code><font papago-translate="translated" papago-id="17">) set </font><code>isLeaf</code><font papago-translate="translated" papago-id="18"> True and set </font><code>val</code><font papago-translate="translated" papago-id="19"> to the value of the grid and set the four children to Null and stop.</font></li>
	<li><font papago-translate="translated" papago-id="20">If the current grid has different values, set </font><code>isLeaf</code><font papago-translate="translated" papago-id="21"> to False and set </font><code>val</code><font papago-translate="translated" papago-id="22"> to any value and divide the current grid into four sub-grids as shown in the photo.</font></li>
	<li papago-id="0" papago-translate="translated">Recurse for each of the children with the proper sub-grid.</li>
</ol>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/11/new_top.png" style="width: 777px; height: 181px;">
<p papago-id="11" papago-translate="cached">If you want to know more about the Quad-Tree, you can refer to the <a href="https://en.wikipedia.org/wiki/Quadtree" papago-id="11-1">wiki</a>.</p>

<p><strong papago-id="12" papago-translate="translated">Quad-Tree format:</strong></p>

<p><font papago-translate="cached" papago-id="13">The input/output represents the serialized format of a Quad-Tree using level order traversal, where </font><code>null</code><font papago-translate="cached" papago-id="14"> signifies a path terminator where no node exists below.</font></p>

<p><font papago-translate="cached" papago-id="15">It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list </font><code>[isLeaf, val]</code><font papago-translate="cached" papago-id="16">.</font></p>

<p><font papago-translate="cached" papago-id="17">If the value of </font><code>isLeaf</code><font papago-translate="cached" papago-id="18"> or </font><code>val</code><code>[isLeaf, val]</code><font papago-translate="cached" papago-id="20"> and if the value of </font><code>isLeaf</code><font papago-translate="cached" papago-id="21"> or </font><code>val</code></p>

<p>&nbsp;</p>
<p><strong papago-id="23" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/11/qt1.png" style="width: 550px; height: 196px;"> <img alt="" src="https://assets.leetcode.com/uploads/2020/02/11/qt2.png" style="width: 550px; height: 278px;">
<pre><font papago-translate="cached" papago-id="33"><strong papago-id="33-0">Input:</strong> quadTree1 = [[0,1],[1,1],[1,1],[1,0],[1,0]]
, quadTree2 = [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
<strong papago-id="33-2">Output:</strong> [[0,0],[1,1],[1,1],[1,1],[1,0]]
<strong papago-id="33-4">Explanation:</strong> quadTree1 and quadTree2 are shown above. You can see the binary matrix which is represented by each Quad-Tree.
If we apply logical bitwise OR on the two binary matrices we get the binary matrix below which is represented by the result Quad-Tree.
Notice that the binary matrices shown are only for illustration, you don't have to construct the binary matrix to get the result tree.
</font><img alt="" src="https://assets.leetcode.com/uploads/2020/02/11/qtr.png" style="width: 777px; height: 222px;">
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> quadTree1 = [[1,0]], quadTree2 = [[1,0]]
<strong>Output:</strong> [[1,0]]
<strong>Explanation:</strong> Each tree represents a binary matrix of size 1*1. Each matrix contains only zero.
The resulting matrix is of size 1*1 with also zero.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>quadTree1</code><font papago-translate="translated" papago-id="34"> and </font><code>quadTree2</code><font papago-translate="cached" papago-id="35"> are both <strong papago-id="35-1">valid</strong> Quad-Trees each representing a </font><code>n * n</code><font papago-translate="translated" papago-id="36"> grid.</font></li>
	<li><code>n == 2<sup>x</sup></code><font papago-translate="translated" papago-id="37"> where </font><code>0 &lt;= x &lt;= 9</code><font papago-translate="translated" papago-id="38">.</font></li>
</ul>
</div>