<h2><a href="https://leetcode.com/problems/query-kth-smallest-trimmed-number/">2343. Query Kth Smallest Trimmed Number</a></h2><h3>Medium</h3><hr><div><p><code>nums</code></p>

<p><code>queries</code><font papago-translate="cached" papago-id="14"> where </font><code>queries[i] = [k<sub>i</sub>, trim<sub>i</sub>]</code><font papago-translate="cached" papago-id="15">. For each </font><code>queries[i]</code><font papago-translate="cached" papago-id="16">, you need to:</font></p>

<ul>
	<li><code>nums</code> <code>trim<sub>i</sub></code><font papago-translate="cached" papago-id="19"> digits.</font></li>
	<li><code>k<sub>i</sub><sup>th</sup></code><font papago-translate="cached" papago-id="21"> smallest trimmed number in </font><code>nums</code></li>
	<li><font papago-translate="cached" papago-id="23">Reset each number in </font><code>nums</code><font papago-translate="cached" papago-id="24"> to its original length.</font></li>
</ul>

<p><code>answer</code><font papago-translate="splited"><em papago-id="15" papago-translate="translated"> of the same length as </em></font><code>queries</code><code>answer[i]</code><font papago-translate="splited"><em papago-id="17" papago-translate="translated"> is the answer to the </em></font><code>i<sup>th</sup></code><font papago-translate="splited"><em papago-id="18" papago-translate="translated"> query.</em></font></p>

<p papago-id="27" papago-translate="cached"><strong papago-id="27-0">Note</strong>:</p>

<ul>
	<li><font papago-translate="cached" papago-id="28">To trim to the rightmost </font><code>x</code><font papago-translate="cached" papago-id="29"> digits means to keep removing the leftmost digit, until only </font><code>x</code><font papago-translate="cached" papago-id="30"> digits remain.</font></li>
	<li><font papago-translate="cached" papago-id="31">Strings in </font><code>nums</code><font papago-translate="cached" papago-id="32"> may contain leading zeros.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong papago-id="33" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="34" papago-translate="cached"><strong papago-id="34-0">Input:</strong> nums = ["102","473","251","814"], queries = [[1,1],[2,3],[4,2],[1,2]]
<strong papago-id="34-2">Output:</strong> [2,2,1,0]
<strong papago-id="34-4">Explanation:</strong>
1. After trimming to the last digit, nums = ["2","3","1","4"]. The smallest number is 1 at index 2.
2. Trimmed to the last 3 digits, nums is unchanged. The 2<sup papago-id="34-6">nd</sup> smallest number is 251 at index 2.
3. Trimmed to the last 2 digits, nums = ["02","73","51","14"]. The 4<sup papago-id="34-8">th</sup> smallest number is 73.
4. Trimmed to the last 2 digits, the smallest number is 2 at index 0.
   Note that the trimmed number "02" is evaluated as 2.
</pre>

<p><strong papago-id="0" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="1" papago-translate="cached"><strong papago-id="1-0">Input:</strong> nums = ["24","37","96","04"], queries = [[2,1],[2,2]]
<strong papago-id="1-2">Output:</strong> [3,0]
<strong papago-id="1-4">Explanation:</strong>
1. Trimmed to the last digit, nums = ["4","7","6","4"]. The 2<sup papago-id="1-6">nd</sup> smallest number is 4 at index 3.
   There are two occurrences of 4, but the one at index 0 is considered smaller than the one at index 3.
2. Trimmed to the last 2 digits, nums is unchanged. The 2<sup papago-id="1-8">nd</sup> smallest number is 24.
</pre>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 100</code></li>
	<li><code>nums[i]</code><font papago-translate="translated" papago-id="24"> consists of only digits.</font></li>
	<li><font papago-translate="translated" papago-id="25">All </font><code>nums[i].length</code><font papago-translate="cached" papago-id="26"> are <strong papago-id="26-1">equal</strong>.</font></li>
	<li><code>1 &lt;= queries.length &lt;= 100</code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>1 &lt;= k<sub>i</sub> &lt;= nums.length</code></li>
	<li><code>1 &lt;= trim<sub>i</sub> &lt;= nums[i].length</code></li>
</ul>
</div>