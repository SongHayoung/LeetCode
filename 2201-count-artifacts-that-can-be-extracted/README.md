<h2><a href="https://leetcode.com/problems/count-artifacts-that-can-be-extracted/">2201. Count Artifacts That Can Be Extracted</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">There is an </font><code>n x n</code> <code>n</code><code>artifacts</code><font papago-translate="splitted"> describing the positions of the rectangular artifacts where </font><code>artifacts[i] = [r1<sub>i</sub>, c1<sub>i</sub>, r2<sub>i</sub>, c2<sub>i</sub>]</code><font papago-translate="splitted"> denotes that the </font><code>i<sup>th</sup></code><font papago-translate="splitted"> artifact is buried in the subgrid where:</font></p>

<ul>
	<li><code>(r1<sub>i</sub>, c1<sub>i</sub>)</code><code>i<sup>th</sup></code><font papago-translate="splitted"> artifact and</font></li>
	<li><code>(r2<sub>i</sub>, c2<sub>i</sub>)</code><code>i<sup>th</sup></code><font papago-translate="splitted"> artifact.</font></li>
</ul>

<p>You will excavate some cells of the grid and remove all the mud from them. If the cell has a part of an artifact buried underneath, it will be uncovered. If all the parts of an artifact are uncovered, you can extract it.</p>

<p><code>dig</code><font papago-translate="splitted"> where </font><code>dig[i] = [r<sub>i</sub>, c<sub>i</sub>]</code><font papago-translate="splitted"> indicates that you will excavate the cell </font><code>(r<sub>i</sub>, c<sub>i</sub>)</code></p>

<p>The test cases are generated such that:</p>

<ul>
	<li>No two artifacts overlap.</li>
	<li><font papago-translate="splitted">Each artifact only covers at most </font><code>4</code><font papago-translate="splitted"> cells.</font></li>
	<li><font papago-translate="splitted">The entries of </font><code>dig</code><font papago-translate="splitted"> are unique.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/09/16/untitled-diagram.jpg" style="width: 216px; height: 216px;">
<pre><strong>Input:</strong> n = 2, artifacts = [[0,0,0,0],[0,1,1,1]], dig = [[0,0],[0,1]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
The different colors represent different artifacts. Excavated cells are labeled with a 'D' in the grid.
There is 1 artifact that can be extracted, namely the red artifact.
The blue artifact has one part in cell (1,1) which remains uncovered, so we cannot extract it.
Thus, we return 1.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/09/16/untitled-diagram-1.jpg" style="width: 216px; height: 216px;">
<pre><strong>Input:</strong> n = 2, artifacts = [[0,0,0,0],[0,1,1,1]], dig = [[0,0],[0,1],[1,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Both the red and blue artifacts have all parts uncovered (labeled with a 'D') and can be extracted, so we return 2. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= artifacts.length, dig.length &lt;= min(n<sup>2</sup>, 10<sup>5</sup>)</code></li>
	<li><code>artifacts[i].length == 4</code></li>
	<li><code>dig[i].length == 2</code></li>
	<li><code>0 &lt;= r1<sub>i</sub>, c1<sub>i</sub>, r2<sub>i</sub>, c2<sub>i</sub>, r<sub>i</sub>, c<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>r1<sub>i</sub> &lt;= r2<sub>i</sub></code></li>
	<li><code>c1<sub>i</sub> &lt;= c2<sub>i</sub></code></li>
	<li>No two artifacts will overlap.</li>
	<li><font papago-translate="splitted">The number of cells covered by an artifact is <strong>at most</strong></font> <code>4</code><font papago-translate="splitted">.</font></li>
	<li><font papago-translate="splitted">The entries of </font><code>dig</code><font papago-translate="splitted"> are unique.</font></li>
</ul>
</div>