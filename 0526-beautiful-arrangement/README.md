<h2><a href="https://leetcode.com/problems/beautiful-arrangement/">526. Beautiful Arrangement</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">Suppose you have </font><code>n</code><font papago-translate="splitted"> integers labeled </font><code>1</code><font papago-translate="splitted"> through </font><code>n</code><font papago-translate="splitted">. A permutation of those </font><code>n</code><font papago-translate="splitted"> integers </font><code>perm</code><code>i</code><font papago-translate="splitted"> (</font><code>1 &lt;= i &lt;= n</code></p>

<ul>
	<li><code>perm[i]</code><font papago-translate="splitted"> is divisible by </font><code>i</code><font papago-translate="splitted">.</font></li>
	<li><code>i</code><font papago-translate="splitted"> is divisible by </font><code>perm[i]</code><font papago-translate="splitted">.</font></li>
</ul>

<p><font papago-translate="splitted">Given an integer </font><code>n</code></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 2
<b>Explanation:</b> 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
</ul>
</div>