<h2><a href="https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/">1637. Widest Vertical Area Between Two Points Containing No Points</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">Given </font><code>n</code> <code>points</code><font papago-translate="cached" papago-id="16"> on a 2D plane where </font><code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code></p>

<p papago-id="18" papago-translate="cached">A <strong papago-id="18-1">vertical area</strong> is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The <strong papago-id="18-3">widest vertical area</strong> is the one with the maximum width.</p>

<p papago-id="19" papago-translate="cached">Note that points <strong papago-id="19-1">on the edge</strong> of a vertical area <strong papago-id="19-3">are not</strong> considered included in the area.</p>

<p>&nbsp;</p>
<p><strong papago-id="20" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/19/points3.png" style="width: 276px; height: 371px;"><font papago-translate="cached" papago-id="21">​
</font><pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> points = [[8,7],[9,9],[7,4],[9,7]]
<strong papago-id="0-2">Output:</strong> 1
<strong papago-id="0-4">Explanation:</strong> Both the red and the blue area are optimal.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == points.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>
</div>