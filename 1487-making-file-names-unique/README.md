<h2><a href="https://leetcode.com/problems/making-file-names-unique/">1487. Making File Names Unique</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">Given an array of strings </font><code>names</code><font papago-translate="splitted"> of size </font><code>n</code><font papago-translate="splitted">. You will create </font><code>n</code><code>i<sup>th</sup></code><font papago-translate="splitted"> minute, you will create a folder with the name </font><code>names[i]</code><font papago-translate="splitted">.</font></p>

<p><code>(k)</code><font papago-translate="splitted">, where, </font><code>k</code></p>

<p><code>n</code><font papago-translate="splitted"> where </font><code>ans[i]</code><font papago-translate="splitted"> is the actual name the system will assign to the </font><code>i<sup>th</sup></code><font papago-translate="splitted"> folder when you create it.</font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> names = ["pes","fifa","gta","pes(2019)"]
<strong>Output:</strong> ["pes","fifa","gta","pes(2019)"]
<strong>Explanation:</strong> Let's see how the file system creates folder names:
"pes" --&gt; not assigned before, remains "pes"
"fifa" --&gt; not assigned before, remains "fifa"
"gta" --&gt; not assigned before, remains "gta"
"pes(2019)" --&gt; not assigned before, remains "pes(2019)"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> names = ["gta","gta(1)","gta","avalon"]
<strong>Output:</strong> ["gta","gta(1)","gta(2)","avalon"]
<strong>Explanation:</strong> Let's see how the file system creates folder names:
"gta" --&gt; not assigned before, remains "gta"
"gta(1)" --&gt; not assigned before, remains "gta(1)"
"gta" --&gt; the name is reserved, system adds (k), since "gta(1)" is also reserved, systems put k = 2. it becomes "gta(2)"
"avalon" --&gt; not assigned before, remains "avalon"
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> names = ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"]
<strong>Output:</strong> ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece(4)"]
<strong>Explanation:</strong> When the last folder is created, the smallest positive valid k is 4, and it becomes "onepiece(4)".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= names.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= names[i].length &lt;= 20</code></li>
	<li><code>names[i]</code><font papago-translate="splitted"> consists of lowercase English letters, digits, and/or round brackets.</font></li>
</ul>
</div>