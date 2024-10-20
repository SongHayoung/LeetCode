<h2><a href="https://leetcode.com/problems/minimize-connected-groups-by-inserting-interval">3565. Minimize Connected Groups by Inserting Interval</a></h2><h3>Medium</h3><hr><p>You are given a 2D array <code>intervals</code>, where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> represents the start and the end of interval <code>i</code>. You are also given an integer <code>k</code>.</p>

<p>You must add <strong>exactly one</strong> new interval <code>[start<sub>new</sub>, end<sub>new</sub>]</code> to the array such that:</p>

<ul>
	<li>The length of the new interval, <code>end<sub>new</sub> - start<sub>new</sub></code>, is at most <code>k</code>.</li>
	<li>After adding, the number of <strong>connected groups</strong> in <code>intervals</code> is <strong>minimized</strong>.</li>
</ul>

<p>A <strong>connected group</strong> of intervals is a maximal collection of intervals that, when considered together, cover a continuous range from the smallest point to the largest point with no gaps between them. Here are some examples:</p>

<ul>
	<li>A group of intervals <code>[[1, 2], [2, 5], [3, 3]]</code> is connected because together they cover the range from 1 to 5 without any gaps.</li>
	<li>However, a group of intervals <code>[[1, 2], [3, 4]]</code> is not connected because the segment <code>(2, 3)</code> is not covered.</li>
</ul>

<p>Return the <strong>minimum</strong> number of connected groups after adding <strong>exactly one</strong> new interval to the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">intervals = [[1,3],[5,6],[8,10]], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>After adding the interval <code>[3, 5]</code>, we have two connected groups: <code>[[1, 3], [3, 5], [5, 6]]</code> and <code>[[8, 10]]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">intervals = [[5,10],[1,1],[3,3]], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>After adding the interval <code>[1, 1]</code>, we have three connected groups: <code>[[1, 1], [1, 1]]</code>, <code>[[3, 3]]</code>, and <code>[[5, 10]]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>5</sup></code></li>
	<li><code>intervals[i] == [start<sub>i</sub>, end<sub>i</sub>]</code></li>
	<li><code>1 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>
