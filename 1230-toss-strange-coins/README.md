<h2><a href="https://leetcode.com/problems/toss-strange-coins/">1230. Toss Strange Coins</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">You have some coins.&nbsp; The </font><code>i</code><font papago-translate="cached" papago-id="16">-th&nbsp;coin has a probability&nbsp;</font><code>prob[i]</code><font papago-translate="cached" papago-id="17"> of facing heads when tossed.</font></p>

<p><font papago-translate="cached" papago-id="18">Return the probability that the number of coins facing heads equals </font><code>target</code><font papago-translate="cached" papago-id="19"> if you toss every coin exactly once.</font></p>

<p>&nbsp;</p>
<p><strong papago-id="20" papago-translate="translated">Example 1:</strong></p>
<pre papago-id="21" papago-translate="cached"><strong papago-id="21-0">Input:</strong> prob = [0.4], target = 1
<strong papago-id="21-2">Output:</strong> 0.40000
</pre><p><strong papago-id="22" papago-translate="translated">Example 2:</strong></p>
<pre papago-id="23" papago-translate="cached"><strong papago-id="23-0">Input:</strong> prob = [0.5,0.5,0.5,0.5,0.5], target = 0
<strong papago-id="23-2">Output:</strong> 0.03125
</pre>
<p>&nbsp;</p>
<p><strong papago-id="24" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prob.length &lt;= 1000</code></li>
	<li><code>0 &lt;= prob[i] &lt;= 1</code></li>
	<li><code>0 &lt;= target&nbsp;</code><code>&lt;= prob.length</code></li>
	<li><font papago-translate="cached" papago-id="25">Answers will be accepted as correct if they are within </font><code>10^-5</code><font papago-translate="cached" papago-id="26"> of the correct answer.</font></li>
</ul>
</div>