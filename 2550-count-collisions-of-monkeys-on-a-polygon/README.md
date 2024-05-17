<h2><a href="https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/">2550. Count Collisions of Monkeys on a Polygon</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">There is a regular convex polygon with </font><code>n</code><font papago-translate="splitted"> vertices. The vertices are labeled from </font><code>0</code><font papago-translate="splitted"> to </font><code>n - 1</code><code>6</code><font papago-translate="splitted"> vertices.</font></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/01/22/hexagon.jpg" style="width: 300px; height: 293px;">
<p>Simultaneously, each monkey moves to a neighboring vertex. A <strong>collision</strong> happens if at least two monkeys reside on the same vertex after the movement or intersect on an edge.</p>

<p><code>10<sup>9 </sup>+ 7</code><font papago-translate="splitted">.</font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p><font papago-translate="splitted">There are 8 total possible movements.</font><br><font papago-translate="splitted">
Two ways such that they collide at some point are:</font></p>

<ul>
	<li>Monkey 1 moves in a clockwise direction; monkey 2 moves in an anticlockwise direction; monkey 3 moves in a clockwise direction. Monkeys 1 and 2 collide.</li>
	<li>Monkey 1 moves in an anticlockwise direction; monkey 2 moves in an anticlockwise direction; monkey 3 moves in a clockwise direction. Monkeys 1 and 3 collide.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">14</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>
</div>