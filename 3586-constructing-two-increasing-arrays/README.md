<h2><a href="https://leetcode.com/problems/constructing-two-increasing-arrays">3586. Constructing Two Increasing Arrays</a></h2><h3>Hard</h3><hr><p>Given 2 integer arrays <code>nums1</code> and <code>nums2</code> consisting only of 0 and 1, your task is to calculate the <strong>minimum</strong> possible <strong>largest</strong> number in arrays <code>nums1</code> and <code>nums2</code>, after doing the following.</p>

<p>Replace every 0 with an <em>even positive integer</em> and every 1 with an <em>odd positive integer</em>. After replacement, both arrays should be <strong>increasing</strong> and each integer should be used <strong>at most</strong> once.</p>

<p>Return the <em>minimum possible largest number</em> after applying the changes.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums1 = [], nums2 = [1,0,1,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p>After replacing, <code>nums1 = []</code>, and <code>nums2 = [1, 2, 3, 5]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums1 = [0,1,0,1], nums2 = [1,0,0,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">9</span></p>

<p><strong>Explanation:</strong></p>

<p>One way to replace, having 9 as the largest element is <code>nums1 = [2, 3, 8, 9]</code>, and <code>nums2 = [1, 4, 6, 7]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums1 = [0,1,0,0,1], nums2 = [0,0,0,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">13</span></p>

<p><strong>Explanation:</strong></p>

<p>One way to replace, having 13 as the largest element is <code>nums1 = [2, 3, 4, 6, 7]</code>, and <code>nums2 = [8, 10, 12, 13]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums1.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums2.length &lt;= 1000</code></li>
	<li><code>nums1</code> and <code>nums2</code> consist only of 0 and 1.</li>
</ul>
