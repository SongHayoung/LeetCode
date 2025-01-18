<h2><a href="https://leetcode.com/problems/minimum-operations-to-make-subarray-elements-equal">3698. Minimum Operations to Make Subarray Elements Equal</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>nums</code> and an integer <code>k</code>. You can perform the following operation any number of times:</p>

<ul>
	<li>Increase or decrease any element of <code>nums</code> by 1.</li>
</ul>

<p>Return the <strong>minimum</strong> number of operations required to ensure that <strong>at least</strong> one <span data-keyword="subarray">subarray</span> of size <code>k</code> in <code>nums</code> has all elements equal.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,-3,2,1,-4,6], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Use 4 operations to add 4 to <code>nums[1]</code>. The resulting array is <span class="example-io"><code>[4, 1, 2, 1, -4, 6]</code>.</span></li>
	<li><span class="example-io">Use 1 operation to subtract 1 from <code>nums[2]</code>. The resulting array is <code>[4, 1, 1, 1, -4, 6]</code>.</span></li>
	<li><span class="example-io">The array now contains a subarray <code>[1, 1, 1]</code> of size <code>k = 3</code> with all elements equal. Hence, the answer is 5.</span></li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [-2,-2,3,1,4], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>
	<p>The subarray <code>[-2, -2]</code> of size <code>k = 2</code> already contains all equal elements, so no operations are needed. Hence, the answer is 0.</p>
	</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>6</sup> &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>2 &lt;= k &lt;= nums.length</code></li>
</ul>
