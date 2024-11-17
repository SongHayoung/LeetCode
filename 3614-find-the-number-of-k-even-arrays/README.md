<h2><a href="https://leetcode.com/problems/find-the-number-of-k-even-arrays">3614. Find the Number of K-Even Arrays</a></h2><h3>Medium</h3><hr><p>You are given three integers <code>n</code>, <code>m</code>, and <code>k</code>.</p>

<p>An array <code>arr</code> is called <strong>k-even</strong> if there are <strong>exactly</strong> <code>k</code> indices such that, for each of these indices <code>i</code> (<code>0 &lt;= i &lt; n - 1</code>):</p>

<ul>
	<li><code>(arr[i] * arr[i + 1]) - arr[i] - arr[i + 1]</code> is <em>even</em>.</li>
</ul>

<p>Return the number of possible <strong>k-even</strong> arrays of size <code>n</code> where all elements are in the range <code>[1, m]</code>.</p>

<p>Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3, m = 4, k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">8</span></p>

<p><strong>Explanation:</strong></p>

<p>The 8 possible 2-even arrays are:</p>

<ul>
	<li><code>[2, 2, 2]</code></li>
	<li><code>[2, 2, 4]</code></li>
	<li><code>[2, 4, 2]</code></li>
	<li><code>[2, 4, 4]</code></li>
	<li><code>[4, 2, 2]</code></li>
	<li><code>[4, 2, 4]</code></li>
	<li><code>[4, 4, 2]</code></li>
	<li><code>[4, 4, 4]</code></li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 5, m = 1, k = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The only 0-even array is <code>[1, 1, 1, 1, 1]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 7, m = 7, k = 5</span></p>

<p><strong>Output:</strong> <span class="example-io">5832</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 750</code></li>
	<li><code>0 &lt;= k &lt;= n - 1</code></li>
	<li><code>1 &lt;= m &lt;= 1000</code></li>
</ul>
