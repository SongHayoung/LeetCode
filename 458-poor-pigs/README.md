<h2><a href="https://leetcode.com/problems/poor-pigs/">458. Poor Pigs</a></h2><h3>Hard</h3><hr><div><p><font papago-translate="cached" papago-id="14">There are </font><code>buckets</code><code>minutesToTest</code><font papago-translate="cached" papago-id="16"> minutes to determine which bucket is poisonous.</font></p>

<p papago-id="17" papago-translate="translated">You can feed the pigs according to these steps:</p>

<ol>
	<li papago-id="18" papago-translate="translated">Choose some live pigs to feed.</li>
	<li papago-id="19" papago-translate="translated">For each pig, choose which buckets to feed it. The pig will consume all the chosen buckets simultaneously and will take no time.</li>
	<li><font papago-translate="cached" papago-id="20">Wait for </font><code>minutesToDie</code></li>
	<li><font papago-translate="cached" papago-id="22">After </font><code>minutesToDie</code><font papago-translate="cached" papago-id="23"> minutes have passed, any pigs that have been fed the poisonous bucket will die, and all others will survive.</font></li>
	<li papago-id="24" papago-translate="translated">Repeat this process until you run out of time.</li>
</ol>

<p><font papago-translate="cached" papago-id="25">Given </font><code>buckets</code><font papago-translate="cached" papago-id="26">, </font><code>minutesToDie</code><font papago-translate="cached" papago-id="27">, and </font><code>minutesToTest</code></p>

<p>&nbsp;</p>
<p><strong papago-id="29" papago-translate="translated">Example 1:</strong></p>
<pre papago-id="30" papago-translate="cached"><strong papago-id="30-0">Input:</strong> buckets = 1000, minutesToDie = 15, minutesToTest = 60
<strong papago-id="30-2">Output:</strong> 5
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> buckets = 4, minutesToDie = 15, minutesToTest = 15
<strong>Output:</strong> 2
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> buckets = 4, minutesToDie = 15, minutesToTest = 30
<strong>Output:</strong> 2
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= buckets &lt;= 1000</code></li>
	<li><code>1 &lt;=&nbsp;minutesToDie &lt;=&nbsp;minutesToTest &lt;= 100</code></li>
</ul>
</div>