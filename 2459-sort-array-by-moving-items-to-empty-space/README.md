<h2><a href="https://leetcode.com/problems/sort-array-by-moving-items-to-empty-space/">2459. Sort Array by Moving Items to Empty Space</a></h2><h3>Hard</h3><hr><div><p>You are given an integer array <code>nums</code> of size <code>n</code> containing <strong>each</strong> element from <code>0</code> to <code>n - 1</code> (<strong>inclusive</strong>). Each of the elements from <code>1</code> to <code>n - 1</code> represents an item, and the element <code>0</code> represents an empty space.</p>

<p>In one operation, you can move <strong>any</strong> item to the empty space. <code>nums</code> is considered to be sorted if the numbers of all the items are in <strong>ascending</strong> order and the empty space is either at the beginning or at the end of the array.</p>

<p>For example, if <code>n = 4</code>, <code>nums</code> is sorted if:</p>

<ul>
	<li><code>nums = [0,1,2,3]</code> or</li>
	<li><code>nums = [1,2,3,0]</code></li>
</ul>

<p>...and considered to be unsorted otherwise.</p>

<p>Return <em>the <strong>minimum</strong> number of operations needed to sort </em><code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,0,3,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
- Move item 2 to the empty space. Now, nums = [4,0,2,3,1].
- Move item 1 to the empty space. Now, nums = [4,1,2,3,0].
- Move item 4 to the empty space. Now, nums = [0,1,2,3,4].
It can be proven that 3 is the minimum number of operations needed.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,0]
<strong>Output:</strong> 0
<strong>Explanation:</strong> nums is already sorted so return 0.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,0,2,4,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
- Move item 2 to the empty space. Now, nums = [1,2,0,4,3].
- Move item 3 to the empty space. Now, nums = [1,2,3,4,0].
It can be proven that 2 is the minimum number of operations needed.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt; n</code></li>
	<li>All the values of <code>nums</code> are <strong>unique</strong>.</li>
</ul>
</div>