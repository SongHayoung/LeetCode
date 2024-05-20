<h2><a href="https://leetcode.com/problems/palindrome-removal/">1246. Palindrome Removal</a></h2><h3>Hard</h3><hr><div><p>You are given an integer array <code>arr</code>.</p>

<p>In one move, you can select a <strong>palindromic</strong> subarray <code>arr[i], arr[i + 1], ..., arr[j]</code> where <code>i &lt;= j</code>, and remove that subarray from the given array. Note that after removing a subarray, the elements on the left and on the right of that subarray move to fill the gap left by the removal.</p>

<p>Return <em>the minimum number of moves needed to remove all numbers from the array</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,2]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,3,4,1,5]
<strong>Output:</strong> 3
<b>Explanation: </b>Remove [4] then remove [1,3,1] then remove [5].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 100</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 20</code></li>
</ul>
</div>