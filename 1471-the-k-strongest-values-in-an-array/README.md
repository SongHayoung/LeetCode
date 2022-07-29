<h2><a href="https://leetcode.com/problems/the-k-strongest-values-in-an-array/">1471. The k Strongest Values in an Array</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">Given an array of integers </font><code>arr</code><font papago-translate="cached" papago-id="16"> and an integer </font><code>k</code><font papago-translate="cached" papago-id="17">.</font></p>

<p><font papago-translate="cached" papago-id="18">A value </font><code>arr[i]</code><font papago-translate="cached" papago-id="19"> is said to be stronger than a value </font><code>arr[j]</code><font papago-translate="cached" papago-id="20"> if </font><code>|arr[i] - m| &gt; |arr[j] - m|</code><font papago-translate="cached" papago-id="21"> where </font><code>m</code><br><font papago-translate="cached" papago-id="23">
If </font><code>|arr[i] - m| == |arr[j] - m|</code><font papago-translate="cached" papago-id="24">, then </font><code>arr[i]</code><font papago-translate="cached" papago-id="25"> is said to be stronger than </font><code>arr[j]</code><font papago-translate="cached" papago-id="26"> if </font><code>arr[i] &gt; arr[j]</code><font papago-translate="cached" papago-id="27">.</font></p>

<p papago-id="28" papago-translate="cached">Return <em papago-id="28-1">a list of the strongest <code papago-id="28-1-1">k</code></em> values in the array. return the answer <strong papago-id="28-3">in any arbitrary order</strong>.</p>

<p><code>((n - 1) / 2)</code></p>

<ul>
	<li><font papago-translate="cached" papago-id="31">For </font><code>arr = [6, -3, 7, 2, 11]</code><font papago-translate="cached" papago-id="32">, </font><code>n = 5</code><font papago-translate="cached" papago-id="33"> and the median is obtained by sorting the array </font><code>arr = [-3, 2, 6, 7, 11]</code><font papago-translate="cached" papago-id="34"> and the median is </font><code>arr[m]</code><font papago-translate="cached" papago-id="35"> where </font><code>m = ((5 - 1) / 2) = 2</code><font papago-translate="cached" papago-id="36">. The median is </font><code>6</code><font papago-translate="cached" papago-id="37">.</font></li>
	<li><font papago-translate="cached" papago-id="38">For </font><code>arr = [-7, 22, 17, 3]</code><font papago-translate="cached" papago-id="39">, </font><code>n = 4</code><font papago-translate="cached" papago-id="40"> and the median is obtained by sorting the array </font><code>arr = [-7, 3, 17, 22]</code><font papago-translate="cached" papago-id="41"> and the median is </font><code>arr[m]</code><font papago-translate="cached" papago-id="42"> where </font><code>m = ((4 - 1) / 2) = 1</code><font papago-translate="cached" papago-id="43">. The median is </font><code>3</code><font papago-translate="cached" papago-id="44">.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong papago-id="45" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> arr = [1,2,3,4,5], k = 2
<strong papago-id="0-2">Output:</strong> [5,1]
<strong papago-id="0-4">Explanation:</strong> Median is 3, the elements of the array sorted by the strongest are [5,1,4,2,3]. The strongest 2 elements are [5, 1]. [1, 5] is also <strong papago-id="0-6">accepted</strong> answer.
Please note that although |5 - 3| == |1 - 3| but 5 is stronger than 1 because 5 &gt; 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,1,3,5,5], k = 2
<strong>Output:</strong> [5,5]
<strong>Explanation:</strong> Median is 3, the elements of the array sorted by the strongest are [5,5,1,1,3]. The strongest 2 elements are [5, 5].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [6,7,11,7,6,8], k = 5
<strong>Output:</strong> [11,8,6,6,7]
<strong>Explanation:</strong> Median is 7, the elements of the array sorted by the strongest are [11,8,6,6,7,7].
Any permutation of [11,8,6,6,7] is <strong>accepted</strong>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= arr.length</code></li>
</ul>
</div>