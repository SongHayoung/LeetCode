<h2><a href="https://leetcode.com/problems/modify-graph-edge-weights/">2699. Modify Graph Edge Weights</a></h2><h3>Hard</h3><hr><div><p> <font papago-translate="splitted">You are given an <strong>undirected weighted</strong><strong>connected</strong> graph containing </font><code>n</code><font papago-translate="splitted"> nodes labeled from </font><code>0</code><font papago-translate="splitted"> to </font><code>n - 1</code><font papago-translate="splitted">, and an integer array </font><code>edges</code><font papago-translate="splitted"> where </font><code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>, w<sub>i</sub>]</code><font papago-translate="splitted"> indicates that there is an edge between nodes </font><code>a<sub>i</sub></code><font papago-translate="splitted"> and </font><code>b<sub>i</sub></code><font papago-translate="splitted"> with weight </font><code>w<sub>i</sub></code><font papago-translate="splitted">.</font></p>

<p><font papago-translate="splitted">Some edges have a weight of </font><code>-1</code><font papago-translate="splitted"> (</font><code>w<sub>i</sub> = -1</code><font papago-translate="splitted">), while others have a <strong>positive</strong> weight (</font><code>w<sub>i</sub> &gt; 0</code><font papago-translate="splitted">).</font></p>

<p><font papago-translate="splitted">Your task is to modify <strong>all edges</strong> with a weight of </font><code>-1</code><font papago-translate="splitted"> by assigning them <strong>positive integer values </strong>in the range </font><code>[1, 2 * 10<sup>9</sup>]</code><font papago-translate="splitted"> so that the <strong>shortest distance</strong> between the nodes </font><code>source</code><font papago-translate="splitted"> and </font><code>destination</code><font papago-translate="splitted"> becomes equal to an integer </font><code>target</code> <font papago-translate="splitted">. If there are <strong>multiple</strong><strong>modifications</strong> that make the shortest distance between </font><code>source</code><font papago-translate="splitted"> and </font><code>destination</code><font papago-translate="splitted"> equal to </font><code>target</code><font papago-translate="splitted">, any of them will be considered correct.</font></p>

<p><font papago-translate="splitted">Return <em>an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from </em></font><code>source</code><font papago-translate="splitted"><em> to </em></font><code>destination</code><font papago-translate="splitted"><em> equal to </em></font><code>target</code><font papago-translate="splitted"><em>, or an <strong>empty array</strong> if it's impossible.</em></font></p>

<p><strong>Note:</strong> You are not allowed to modify the weights of edges with initial positive weights.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/18/graph.png" style="width: 300px; height: 300px;"></strong></p>

<pre><strong>Input:</strong> n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
<strong>Output:</strong> [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
<strong>Explanation:</strong> The graph above shows a possible modification to the edges, making the distance from 0 to 1 equal to 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/18/graph-2.png" style="width: 300px; height: 300px;"></strong></p>

<pre><strong>Input:</strong> n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
<strong>Output:</strong> []
<strong>Explanation:</strong> The graph above contains the initial edges. It is not possible to make the distance from 0 to 2 equal to 6 by modifying the edge with weight -1. So, an empty array is returned.
</pre>

<p><strong class="example">Example 3:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/19/graph-3.png" style="width: 300px; height: 300px;"></strong></p>

<pre><strong>Input:</strong> n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
<strong>Output:</strong> [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
<strong>Explanation:</strong> The graph above shows a modified graph having the shortest distance from 0 to 2 as 6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code><font face="monospace">1 &lt;= edges.length &lt;= n * (n - 1) / 2</font></code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i&nbsp;</sub>&lt;&nbsp;n</code></li>
	<li><code><font face="monospace">w<sub>i</sub>&nbsp;= -1&nbsp;</font></code><font papago-translate="splitted">or </font><code><font face="monospace">1 &lt;= w<sub>i&nbsp;</sub>&lt;= 10<sup><span style="font-size: 10.8333px;">7</span></sup></font></code></li>
	<li><code>a<sub>i&nbsp;</sub>!=&nbsp;b<sub>i</sub></code></li>
	<li><code>0 &lt;= source, destination &lt; n</code></li>
	<li><code>source != destination</code></li>
	<li><code><font face="monospace">1 &lt;= target &lt;= 10<sup>9</sup></font></code></li>
	<li>The graph is connected, and there are no self-loops or repeated edges</li>
</ul>
</div>