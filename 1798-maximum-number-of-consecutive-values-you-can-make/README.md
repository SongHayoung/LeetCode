<h2><a href="https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/">1798. Maximum Number of Consecutive Values You Can Make</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">You are given an integer array </font><code>coins</code><font papago-translate="cached" papago-id="16"> of length </font><code>n</code><font papago-translate="cached" papago-id="17"> which represents the </font><code>n</code><font papago-translate="cached" papago-id="18"> coins that you own. The value of the </font><code>i<sup>th</sup></code><font papago-translate="cached" papago-id="19"> coin is </font><code>coins[i]</code><code>x</code><font papago-translate="cached" papago-id="21"> if you can choose some of your </font><code>n</code><font papago-translate="cached" papago-id="22"> coins such that their values sum up to </font><code>x</code><font papago-translate="cached" papago-id="23">.</font></p>

<p><code>0</code><font papago-translate="cached" papago-id="25">.</font></p>

<p papago-id="26" papago-translate="translated">Note that you may have multiple coins of the same value.</p>

<p>&nbsp;</p>
<p><strong papago-id="27" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="28" papago-translate="cached"><strong papago-id="28-0">Input:</strong> coins = [1,3]
<strong papago-id="28-2">Output:</strong> 2
<strong papago-id="28-4">Explanation: </strong>You can make the following values:
- 0: take []
- 1: take [1]
You can make 2 consecutive integer values starting from 0.</pre>

<p><strong papago-id="29" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="30" papago-translate="cached"><strong papago-id="30-0">Input:</strong> coins = [1,1,1,4]
<strong papago-id="30-2">Output:</strong> 8
<strong papago-id="30-4">Explanation: </strong>You can make the following values:
- 0: take []
- 1: take [1]
- 2: take [1,1]
- 3: take [1,1,1]
- 4: take [4]
- 5: take [4,1]
- 6: take [4,1,1]
- 7: take [4,1,1,1]
You can make 8 consecutive integer values starting from 0.</pre>

<p><strong papago-id="0" papago-translate="translated">Example 3:</strong></p>

<pre papago-id="1" papago-translate="cached"><strong papago-id="1-0">Input:</strong> nums = [1,4,10,3,1]
<strong papago-id="1-2">Output:</strong> 20</pre>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>coins.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= coins[i] &lt;= 4 * 10<sup>4</sup></code></li>
</ul>
</div>