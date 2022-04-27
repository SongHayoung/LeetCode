<h2><a href="https://leetcode.com/problems/find-array-given-subset-sums/">1982. Find Array Given Subset Sums</a></h2><h3>Hard</h3><hr><div><p><font papago-translate="cached" papago-id="0">You are given an integer </font><code>n</code><font papago-translate="cached" papago-id="1"> representing the length of an unknown array that you are trying to recover. You are also given an array </font><code>sums</code><font papago-translate="cached" papago-id="2"> containing the values of all </font><code>2<sup>n</sup></code> </p>

<p><code>ans</code><font papago-translate="splited"><em papago-id="5" papago-translate="cached"> of length </em></font><code>n</code></p>

<p><font papago-translate="cached" papago-id="7">An array </font><code>sub</code><code>arr</code><font papago-translate="cached" papago-id="9"> if </font><code>sub</code><font papago-translate="cached" papago-id="10"> can be obtained from </font><code>arr</code><font papago-translate="cached" papago-id="11"> by deleting some (possibly zero or all) elements of </font><code>arr</code><font papago-translate="cached" papago-id="12">. The sum of the elements in </font><code>sub</code><code>arr</code><font papago-translate="cached" papago-id="14">. The sum of an empty array is considered to be </font><code>0</code><font papago-translate="cached" papago-id="15">.</font></p>

<p papago-id="27" papago-translate="cached"><strong papago-id="27-0">Note:</strong> Test cases are generated such that there will <strong papago-id="27-2">always</strong> be at least one correct answer.</p>

<p>&nbsp;</p>
<p><strong papago-id="28" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="29" papago-translate="cached"><strong papago-id="29-0">Input:</strong> n = 3, sums = [-3,-2,-1,0,0,1,2,3]
<strong papago-id="29-2">Output:</strong> [1,2,-3]
<strong papago-id="29-4">Explanation: </strong>[1,2,-3] is able to achieve the given subset sums:
- []: sum is 0
- [1]: sum is 1
- [2]: sum is 2
- [1,2]: sum is 3
- [-3]: sum is -3
- [1,-3]: sum is -2
- [2,-3]: sum is -1
- [1,2,-3]: sum is 0
Note that any permutation of [1,2,-3] and also any permutation of [-1,-2,3] will also be accepted.
</pre>

<p><strong papago-id="30" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="31" papago-translate="cached"><strong papago-id="31-0">Input:</strong> n = 2, sums = [0,0,0,0]
<strong papago-id="31-2">Output:</strong> [0,0]
<strong papago-id="31-4">Explanation:</strong> The only correct answer is [0,0].
</pre>

<p><strong papago-id="32" papago-translate="translated">Example 3:</strong></p>

<pre papago-id="33" papago-translate="cached"><strong papago-id="33-0">Input:</strong> n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
<strong papago-id="33-2">Output:</strong> [0,-1,4,5]
<strong papago-id="33-4">Explanation:</strong> [0,-1,4,5] is able to achieve the given subset sums.
</pre>

<p>&nbsp;</p>
<p><strong papago-id="34" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
	<li><code>sums.length == 2<sup>n</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= sums[i] &lt;= 10<sup>4</sup></code></li>
</ul>
</div>