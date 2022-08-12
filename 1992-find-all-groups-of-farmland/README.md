<h2><a href="https://leetcode.com/problems/find-all-groups-of-farmland/">1992. Find All Groups of Farmland</a></h2><h3>Medium</h3><hr><div><p> <code>m x n</code><font papago-translate="cached" papago-id="16"> binary matrix </font><code>land</code><font papago-translate="cached" papago-id="17"> where a </font><code>0</code><font papago-translate="cached" papago-id="18"> represents a hectare of forested land and a </font><code>1</code><font papago-translate="cached" papago-id="19"> represents a hectare of farmland.</font></p>

<p papago-id="20" papago-translate="cached">To keep the land organized, there are designated rectangular areas of hectares that consist <strong papago-id="20-1">entirely</strong> of farmland. These rectangular areas are called <strong papago-id="20-3">groups</strong>. No two groups are adjacent, meaning farmland in one group is <strong papago-id="20-5">not</strong> four-directionally adjacent to another farmland in a different group.</p>

<p><code>land</code><font papago-translate="cached" papago-id="21"> can be represented by a coordinate system where the top left corner of </font><code>land</code><font papago-translate="cached" papago-id="22"> is </font><code>(0, 0)</code><font papago-translate="cached" papago-id="23"> and the bottom right corner of </font><code>land</code><font papago-translate="cached" papago-id="24"> is </font><code>(m-1, n-1)</code><code>(r<sub>1</sub>, c<sub>1</sub>)</code><font papago-translate="cached" papago-id="26"> and a bottom right corner at </font><code>(r<sub>2</sub>, c<sub>2</sub>)</code><font papago-translate="cached" papago-id="27"> is represented by the 4-length array </font><code>[r<sub>1</sub>, c<sub>1</sub>, r<sub>2</sub>, c<sub>2</sub>].</code></p>

<p><code>land</code></p>

<p>&nbsp;</p>
<p><strong papago-id="30" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/screenshot-2021-07-27-at-12-23-15-copy-of-diagram-drawio-diagrams-net.png" style="width: 300px; height: 300px;">
<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> land = [[1,0,0],[0,1,1],[0,1,1]]
<strong papago-id="0-2">Output:</strong> [[0,0,0,0],[1,1,2,2]]
<strong papago-id="0-4">Explanation:</strong>
The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].
</pre>

<p><strong papago-id="0" papago-translate="translated">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/screenshot-2021-07-27-at-12-30-26-copy-of-diagram-drawio-diagrams-net.png" style="width: 200px; height: 200px;">
<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> land = [[1,1],[1,1]]
<strong papago-id="0-2">Output:</strong> [[0,0,1,1]]
<strong papago-id="0-4">Explanation:</strong>
The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].
</pre>

<p><strong papago-id="0" papago-translate="translated">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/screenshot-2021-07-27-at-12-32-24-copy-of-diagram-drawio-diagrams-net.png" style="width: 100px; height: 100px;">
<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> land = [[0]]
<strong papago-id="0-2">Output:</strong> []
<strong papago-id="0-4">Explanation:</strong>
There are no groups of farmland.
</pre>

<p>&nbsp;</p>
<p><strong papago-id="1" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>m == land.length</code></li>
	<li><code>n == land[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>land</code><font papago-translate="translated" papago-id="14"> consists of only </font><code>0</code><font papago-translate="translated" papago-id="15">'s and </font><code>1</code><font papago-translate="translated" papago-id="16">'s.</font></li>
	<li papago-id="0" papago-translate="cached">Groups of farmland are <strong papago-id="0-1">rectangular</strong> in shape.</li>
</ul>
</div>