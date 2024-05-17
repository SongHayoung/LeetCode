<h2><a href="https://leetcode.com/problems/expressive-words/">809. Expressive Words</a></h2><h3>Medium</h3><hr><div><p>Sometimes people repeat letters to represent extra feeling. For example:</p>

<ul>
	<li><code>"hello" -&gt; "heeellooo"</code></li>
	<li><code>"hi" -&gt; "hiiii"</code></li>
</ul>

<p><font papago-translate="splitted">In these strings like </font><code>"heeellooo"</code><font papago-translate="splitted">, we have groups of adjacent letters that are all the same: </font><code>"h"</code><font papago-translate="splitted">, </font><code>"eee"</code><font papago-translate="splitted">, </font><code>"ll"</code><font papago-translate="splitted">, </font><code>"ooo"</code><font papago-translate="splitted">.</font></p>

<p><font papago-translate="splitted">You are given a string </font><code>s</code><font papago-translate="splitted"> and an array of query strings </font><code>words</code><code>s</code><font papago-translate="splitted"> by any number of applications of the following extension operation: choose a group consisting of characters </font><code>c</code><font papago-translate="splitted">, and add some number of characters </font><code>c</code></p>

<ul>
	<li><font papago-translate="splitted">For example, starting with </font><code>"hello"</code><font papago-translate="splitted">, we could do an extension on the group </font><code>"o"</code><font papago-translate="splitted"> to get </font><code>"hellooo"</code><font papago-translate="splitted">, but we cannot get </font><code>"helloo"</code><font papago-translate="splitted"> since the group </font><code>"oo"</code><font papago-translate="splitted"> has a size less than three. Also, we could do another extension like </font><code>"ll" -&gt; "lllll"</code><font papago-translate="splitted"> to get </font><code>"helllllooo"</code><font papago-translate="splitted">. If </font><code>s = "helllllooo"</code><font papago-translate="splitted">, then the query word </font><code>"hello"</code><code>query = "hello" -&gt; "hellooo" -&gt; "helllllooo" = s</code><font papago-translate="splitted">.</font></li>
</ul>

<p>Return <em>the number of query strings that are <strong>stretchy</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "heeellooo", words = ["hello", "hi", "helo"]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "zzzzzyyyyy", words = ["zzyy","zy","zyy"]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>s</code><font papago-translate="splitted"> and </font><code>words[i]</code><font papago-translate="splitted"> consist of lowercase letters.</font></li>
</ul>
</div>