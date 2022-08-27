<h2><a href="https://leetcode.com/problems/squirrel-simulation/">573. Squirrel Simulation</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">You are given two integers </font><code>height</code><font papago-translate="cached" papago-id="16"> and </font><code>width</code><font papago-translate="cached" papago-id="17"> representing a garden of size </font><code>height x width</code><font papago-translate="cached" papago-id="18">. You are also given:</font></p>

<ul>
	<li><font papago-translate="cached" papago-id="19">an array </font><code>tree</code><font papago-translate="cached" papago-id="20"> where </font><code>tree = [tree<sub>r</sub>, tree<sub>c</sub>]</code><font papago-translate="cached" papago-id="21"> is the position of the tree in the garden,</font></li>
	<li><font papago-translate="cached" papago-id="22">an array </font><code>squirrel</code><font papago-translate="cached" papago-id="23"> where </font><code>squirrel = [squirrel<sub>r</sub>, squirrel<sub>c</sub>]</code><font papago-translate="cached" papago-id="24"> is the position of the squirrel in the garden,</font></li>
	<li><font papago-translate="cached" papago-id="25">and an array </font><code>nuts</code><font papago-translate="cached" papago-id="26"> where </font><code>nuts[i] = [nut<sub>i<sub>r</sub></sub>, nut<sub>i<sub>c</sub></sub>]</code><font papago-translate="cached" papago-id="27"> is the position of the </font><code>i<sup>th</sup></code><font papago-translate="cached" papago-id="28"> nut in the garden.</font></li>
</ul>

<p papago-id="29" papago-translate="translated">The squirrel can only take at most one nut at one time and can move in four directions: up, down, left, and right, to the adjacent cell.</p>

<p papago-id="30" papago-translate="cached">Return <em papago-id="30-1">the <strong papago-id="30-1-1">minimal distance</strong> for the squirrel to collect all the nuts and put them under the tree one by one</em>.</p>

<p papago-id="31" papago-translate="cached">The <strong papago-id="31-1">distance</strong> is the number of moves.</p>

<p>&nbsp;</p>
<p><strong papago-id="32" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/squirrel1-grid.jpg" style="width: 573px; height: 413px;">
<pre><strong>Input:</strong> height = 5, width = 7, tree = [2,2], squirrel = [4,4], nuts = [[3,0], [2,5]]
<strong>Output:</strong> 12
<strong>Explanation:</strong> The squirrel should go to the nut at [2, 5] first to achieve a minimal distance.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/squirrel2-grid.jpg" style="width: 253px; height: 93px;">
<pre><strong>Input:</strong> height = 1, width = 3, tree = [0,1], squirrel = [0,0], nuts = [[0,2]]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= height, width &lt;= 100</code></li>
	<li><code>tree.length == 2</code></li>
	<li><code>squirrel.length == 2</code></li>
	<li><code>1 &lt;= nuts.length &lt;= 5000</code></li>
	<li><code>nuts[i].length == 2</code></li>
	<li><code>0 &lt;= tree<sub>r</sub>, squirrel<sub>r</sub>, nut<sub>i<sub>r</sub></sub> &lt;= height</code></li>
	<li><code>0 &lt;= tree<sub>c</sub>, squirrel<sub>c</sub>, nut<sub>i<sub>c</sub></sub> &lt;= width</code></li>
</ul>
</div>