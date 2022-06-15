<h2><a href="https://leetcode.com/problems/partition-array-for-maximum-sum/">1043. Partition Array for Maximum Sum</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">Given an integer array </font><code>arr</code> <code>k</code><font papago-translate="cached" papago-id="17">. After partitioning, each subarray has their values changed to become the maximum value of that subarray.</font></p>

<p papago-id="18" papago-translate="cached">Return <em papago-id="18-1">the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a <strong papago-id="18-1-1">32-bit</strong> integer.</em></p>

<p>&nbsp;</p>
<p><strong papago-id="19" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="20" papago-translate="cached"><strong papago-id="20-0">Input:</strong> arr = [1,15,7,9,2,5,10], k = 3
<strong papago-id="20-2">Output:</strong> 84
<strong papago-id="20-4">Explanation:</strong> arr becomes [15,15,15,9,10,10,10]
</pre>

<p><strong papago-id="21" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="22" papago-translate="cached"><strong papago-id="22-0">Input:</strong> arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
<strong papago-id="22-2">Output:</strong> 83
</pre>

<p><strong papago-id="23" papago-translate="translated">Example 3:</strong></p>

<pre papago-id="24" papago-translate="cached"><strong papago-id="24-0">Input:</strong> arr = [1], k = 1
<strong papago-id="24-2">Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 500</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= arr.length</code></li>
</ul>
</div>