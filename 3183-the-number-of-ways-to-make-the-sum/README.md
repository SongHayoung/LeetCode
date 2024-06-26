<h2><a href="https://leetcode.com/problems/the-number-of-ways-to-make-the-sum/">3183. The Number of Ways to Make the Sum</a></h2><h3>Medium</h3><hr><div><p>You have an <strong>infinite</strong> number of coins with values 1, 2, and 6, and <strong>only</strong> 2 coins with value 4.</p>

<p>Given an integer <code>n</code>, return the number of ways to make the sum of <code>n</code> with the coins you have.</p>

<p>Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p><strong>Note</strong> that the order of the coins doesn't matter and <code>[2, 2, 3]</code> is the same as <code>[2, 3, 2]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>Here are the four combinations: <code>[1, 1, 1, 1]</code>, <code>[1, 1, 2]</code>, <code>[2, 2]</code>, <code>[4]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 12</span></p>

<p><strong>Output:</strong> <span class="example-io">22</span></p>

<p><strong>Explanation:</strong></p>

<p>Note that <code>[4, 4, 4]</code> is <strong>not</strong> a valid combination since we cannot use 4 three times.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 5</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>Here are the four combinations: <code>[1, 1, 1, 1, 1]</code>, <code>[1, 1, 1, 2]</code>, <code>[1, 2, 2]</code>, <code>[1, 4]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>
</div>