<h2><a href="https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/">1954. Minimum Garden Perimeter to Collect Enough Apples</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">In a garden represented as an infinite 2D grid, there is an apple tree planted at <strong>every</strong> integer coordinate. The apple tree planted at an integer coordinate </font><code>(i, j)</code><font papago-translate="splitted"> has </font><code>|i| + |j|</code><font papago-translate="splitted"> apples growing on it.</font></p>

<p><font papago-translate="splitted">You will buy an axis-aligned <strong>square plot</strong> of land that is centered at </font><code>(0, 0)</code><font papago-translate="splitted">.</font></p>

<p><font papago-translate="splitted">Given an integer </font><code>neededApples</code><font papago-translate="splitted">, return <em>the <strong>minimum perimeter</strong> of a plot such that <strong>at least</strong></em><strong> </strong></font><code>neededApples</code> <font papago-translate="splitted"><em>apples are <strong>inside or on</strong> the perimeter of that plot</em>.</font></p>

<p><font papago-translate="splitted">The value of </font><code>|x|</code><font papago-translate="splitted"> is defined as:</font></p>

<ul>
	<li><code>x</code><font papago-translate="splitted"> if </font><code>x &gt;= 0</code></li>
	<li><code>-x</code><font papago-translate="splitted"> if </font><code>x &lt; 0</code></li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/30/1527_example_1_2.png" style="width: 442px; height: 449px;">
<pre><strong>Input:</strong> neededApples = 1
<strong>Output:</strong> 8
<strong>Explanation:</strong> A square plot of side length 1 does not contain any apples.
However, a square plot of side length 2 has 12 apples inside (as depicted in the image above).
The perimeter is 2 * 4 = 8.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> neededApples = 13
<strong>Output:</strong> 16
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> neededApples = 1000000000
<strong>Output:</strong> 5040
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= neededApples &lt;= 10<sup>15</sup></code></li>
</ul>
</div>