<h2><a href="https://leetcode.com/problems/find-the-index-of-permutation/">3109. Find the Index of Permutation</a></h2><h3>Medium</h3><hr><div><p>Given an array <code>perm</code> of length <code>n</code> which is a permutation of <code>[1, 2, ..., n]</code>, return the index of <code>perm</code> in the <span data-keyword="lexicographically-sorted-array">lexicographically sorted</span> array of all of the permutations of <code>[1, 2, ..., n]</code>.</p>

<p>Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup>&nbsp;+ 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">perm = [1,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>There are only two permutations in the following order:</p>

<p><code>[1,2]</code>, <code>[2,1]</code><br>
<br>
And <code>[1,2]</code> is at index 0.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">perm = [3,1,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>There are only six permutations in the following order:</p>

<p><code>[1,2,3]</code>, <code>[1,3,2]</code>, <code>[2,1,3]</code>, <code>[2,3,1]</code>, <code>[3,1,2]</code>, <code>[3,2,1]</code><br>
<br>
And <code>[3,1,2]</code> is at index 4.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == perm.length &lt;= 10<sup>5</sup></code></li>
	<li><code>perm</code> is a permutation of <code>[1, 2, ..., n]</code>.</li>
</ul>
</div>