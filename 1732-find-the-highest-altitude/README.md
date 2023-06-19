<h2><a href="https://leetcode.com/problems/find-the-highest-altitude/">1732. Find the Highest Altitude</a></h2><h3>Easy</h3><hr><div><p><font papago-translate="cached" papago-id="14">There is a biker going on a road trip. The road trip consists of </font><code>n + 1</code><font papago-translate="cached" papago-id="15"> points at different altitudes. The biker starts his trip on point </font><code>0</code><font papago-translate="cached" papago-id="16"> with altitude equal </font><code>0</code><font papago-translate="cached" papago-id="17">.</font></p>

<p><font papago-translate="cached" papago-id="18">You are given an integer array </font><code>gain</code><font papago-translate="cached" papago-id="19"> of length </font><code>n</code><font papago-translate="cached" papago-id="20"> where </font><code>gain[i]</code><code>i</code><font papago-translate="cached" papago-id="22">​​​​​​ and </font><code>i + 1</code><font papago-translate="cached" papago-id="23"> for all (</font><code>0 &lt;= i &lt; n)</code></p>

<p>&nbsp;</p>
<p><strong class="example" papago-id="25" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="26" papago-translate="cached"><strong papago-id="26-0">Input:</strong> gain = [-5,1,5,0,-7]
<strong papago-id="26-2">Output:</strong> 1
<strong papago-id="26-4">Explanation:</strong> The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
</pre>

<p><strong class="example" papago-id="27" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="28" papago-translate="cached"><strong papago-id="28-0">Input:</strong> gain = [-4,-3,-2,-1,4,3,2]
<strong papago-id="28-2">Output:</strong> 0
<strong papago-id="28-4">Explanation:</strong> The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == gain.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>-100 &lt;= gain[i] &lt;= 100</code></li>
</ul>
</div>