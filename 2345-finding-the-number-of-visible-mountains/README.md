<h2><a href="https://leetcode.com/problems/finding-the-number-of-visible-mountains/">2345. Finding the Number of Visible Mountains</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="0">You are given a <strong papago-id="0-1">0-indexed</strong> 2D integer array </font><code>peaks</code><font papago-translate="translated" papago-id="1"> where </font><code>peaks[i] = [x<sub>i</sub>, y<sub>i</sub>]</code><font papago-translate="translated" papago-id="2"> states that mountain </font><code>i</code><font papago-translate="translated" papago-id="3"> has a peak at coordinates </font><code>(x<sub>i</sub>, y<sub>i</sub>)</code><font papago-translate="translated" papago-id="4">. A mountain can be described as a right-angled isosceles triangle, with its base along the </font><code>x</code><font papago-translate="cached" papago-id="5">-axis and a right angle at its peak. More formally, the <strong papago-id="5-1">gradients</strong> of ascending and descending the mountain are </font><code>1</code><font papago-translate="translated" papago-id="6"> and </font><code>-1</code><font papago-translate="translated" papago-id="7"> respectively.</font></p>

<p papago-id="0" papago-translate="cached">A mountain is considered <strong papago-id="0-1">visible</strong> if its peak does not lie within another mountain (including the border of other mountains).</p>

<p papago-id="1" papago-translate="cached">Return <em papago-id="1-1">the number of visible mountains</em>.</p>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/07/19/ex1.png" style="width: 402px; height: 210px;">
<pre papago-id="11" papago-translate="cached"><strong papago-id="11-0">Input:</strong> peaks = [[2,2],[6,3],[5,4]]
<strong papago-id="11-2">Output:</strong> 2
<strong papago-id="11-4">Explanation:</strong> The diagram above shows the mountains.
- Mountain 0 is visible since its peak does not lie within another mountain or its sides.
- Mountain 1 is not visible since its peak lies within the side of mountain 2.
- Mountain 2 is visible since its peak does not lie within another mountain or its sides.
There are 2 mountains that are visible.</pre>

<p><strong papago-id="12" papago-translate="translated">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/07/19/ex2new1.png" style="width: 300px; height: 180px;">
<pre papago-id="13" papago-translate="cached"><strong papago-id="13-0">Input:</strong> peaks = [[1,3],[1,3]]
<strong papago-id="13-2">Output:</strong> 0
<strong papago-id="13-4">Explanation:</strong> The diagram above shows the mountains (they completely overlap).
Both mountains are not visible since their peaks lie within each other.
</pre>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= peaks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>peaks[i].length == 2</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>
</div>