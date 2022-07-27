<h2><a href="https://leetcode.com/problems/minimum-operations-to-convert-number/">2059. Minimum Operations to Convert Number</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="0">You are given a <strong papago-id="0-1">0-indexed</strong> integer array </font><code>nums</code><font papago-translate="cached" papago-id="1"> containing <strong papago-id="1-1">distinct</strong> numbers, an integer </font><code>start</code><font papago-translate="translated" papago-id="2">, and an integer </font><code>goal</code><font papago-translate="translated" papago-id="3">. There is an integer </font><code>x</code><font papago-translate="translated" papago-id="4"> that is initially set to </font><code>start</code><font papago-translate="translated" papago-id="5">, and you want to perform operations on </font><code>x</code><font papago-translate="translated" papago-id="6"> such that it is converted to </font><code>goal</code><font papago-translate="translated" papago-id="7">. You can perform the following operation repeatedly on the number </font><code>x</code><font papago-translate="translated" papago-id="8">:</font></p>

<p><font papago-translate="translated" papago-id="9">If </font><code>0 &lt;= x &lt;= 1000</code><font papago-translate="translated" papago-id="10">, then for any index </font><code>i</code><font papago-translate="translated" papago-id="11"> in the array (</font><code>0 &lt;= i &lt; nums.length</code><font papago-translate="translated" papago-id="12">), you can set </font><code>x</code><font papago-translate="translated" papago-id="13"> to any of the following:</font></p>

<ul>
	<li><code>x + nums[i]</code></li>
	<li><code>x - nums[i]</code></li>
	<li><code>x ^ nums[i]</code><font papago-translate="translated" papago-id="14"> (bitwise-XOR)</font></li>
</ul>

<p><font papago-translate="translated" papago-id="15">Note that you can use each </font><code>nums[i]</code><font papago-translate="translated" papago-id="16"> any number of times in any order. Operations that set </font><code>x</code><font papago-translate="translated" papago-id="17"> to be out of the range </font><code>0 &lt;= x &lt;= 1000</code><font papago-translate="translated" papago-id="18"> are valid, but no more operations can be done afterward.</font></p>

<p><code>x = start</code><font papago-translate="splited"><em papago-id="20" papago-translate="translated"> into </em></font><code>goal</code><font papago-translate="splited"><em papago-id="21" papago-translate="translated">, and </em></font><code>-1</code></p>

<p>&nbsp;</p>
<p><strong papago-id="13" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="14" papago-translate="cached"><strong papago-id="14-0">Input:</strong> nums = [2,4,12], start = 2, goal = 12
<strong papago-id="14-2">Output:</strong> 2
<strong papago-id="14-4">Explanation:</strong> We can go from 2 → 14 → 12 with the following 2 operations.
- 2 + 12 = 14
- 14 - 2 = 12
</pre>

<p><strong papago-id="15" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="16" papago-translate="cached"><strong papago-id="16-0">Input:</strong> nums = [3,5,7], start = 0, goal = -4
<strong papago-id="16-2">Output:</strong> 2
<strong papago-id="16-4">Explanation:</strong> We can go from 0 → 3 → -4 with the following 2 operations. 
- 0 + 3 = 3
- 3 - 7 = -4
Note that the last operation sets x out of the range 0 &lt;= x &lt;= 1000, which is valid.
</pre>

<p><strong papago-id="17" papago-translate="translated">Example 3:</strong></p>

<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> nums = [2,8,16], start = 0, goal = 1
<strong papago-id="0-2">Output:</strong> -1
<strong papago-id="0-4">Explanation:</strong> There is no way to convert 0 into 1.
</pre>

<p>&nbsp;</p>
<p><strong papago-id="1" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i], goal &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= start &lt;= 1000</code></li>
	<li><code>start != goal</code></li>
	<li><font papago-translate="translated" papago-id="23">All the integers in </font><code>nums</code><font papago-translate="translated" papago-id="24"> are distinct.</font></li>
</ul>
</div>