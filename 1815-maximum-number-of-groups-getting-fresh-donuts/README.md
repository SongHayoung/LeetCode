<h2><a href="https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/">1815. Maximum Number of Groups Getting Fresh Donuts</a></h2><h3>Hard</h3><hr><div><p><font papago-translate="splitted">There is a donuts shop that bakes donuts in batches of </font><code>batchSize</code><code>batchSize</code><font papago-translate="splitted"> and an integer array </font><code>groups</code><font papago-translate="splitted">, where </font><code>groups[i]</code><font papago-translate="splitted"> denotes that there is a group of </font><code>groups[i]</code><font papago-translate="splitted"> customers that will visit the shop. Each customer will get exactly one donut.</font></p>

<p>When a group visits the shop, all customers of the group must be served before serving any of the following groups. A group will be happy if they all get fresh donuts. That is, the first customer of the group does not receive a donut that was left over from the previous group.</p>

<p>You can freely rearrange the ordering of the groups. Return <em>the <strong>maximum</strong> possible number of happy groups after rearranging the groups.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> batchSize = 3, groups = [1,2,3,4,5,6]
<strong>Output:</strong> 4
<strong>Explanation:</strong> You can arrange the groups as [6,2,4,5,1,3]. Then the 1<sup>st</sup>, 2<sup>nd</sup>, 4<sup>th</sup>, and 6<sup>th</sup> groups will be happy.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> batchSize = 4, groups = [1,3,2,5,2,2,1,6]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= batchSize &lt;= 9</code></li>
	<li><code>1 &lt;= groups.length &lt;= 30</code></li>
	<li><code>1 &lt;= groups[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>