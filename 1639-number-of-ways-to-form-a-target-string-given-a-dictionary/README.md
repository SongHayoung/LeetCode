<h2><a href="https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/">1639. Number of Ways to Form a Target String Given a Dictionary</a></h2><h3>Hard</h3><hr><div><p> <code>words</code><font papago-translate="splitted"> and a string </font><code>target</code><font papago-translate="splitted">.</font></p>

<p><font papago-translate="splitted">Your task is to form </font><code>target</code><font papago-translate="splitted"> using the given </font><code>words</code><font papago-translate="splitted"> under the following rules:</font></p>

<ul>
	<li><code>target</code><font papago-translate="splitted"> should be formed from left to right.</font></li>
	<li><font papago-translate="splitted">To form the </font><code>i<sup>th</sup></code><code>target</code><font papago-translate="splitted">, you can choose the </font><code>k<sup>th</sup></code><font papago-translate="splitted"> character of the </font><code>j<sup>th</sup></code><font papago-translate="splitted"> string in </font><code>words</code><font papago-translate="splitted"> if </font><code>target[i] = words[j][k]</code><font papago-translate="splitted">.</font></li>
	<li><font papago-translate="splitted">Once you use the </font><code>k<sup>th</sup></code><font papago-translate="splitted"> character of the </font><code>j<sup>th</sup></code><font papago-translate="splitted"> string of </font><code>words</code><code>x<sup>th</sup></code><font papago-translate="splitted"> character of any string in </font><code>words</code><font papago-translate="splitted"> where </font><code>x &lt;= k</code><font papago-translate="splitted">. In other words, all characters to the left of or at index </font><code>k</code><font papago-translate="splitted"> become unusuable for every string.</font></li>
	<li><font papago-translate="splitted">Repeat the process until you form the string </font><code>target</code><font papago-translate="splitted">.</font></li>
</ul>

<p><code>words</code><font papago-translate="splitted"> provided the conditions above are met.</font></p>

<p> <code>10<sup>9</sup> + 7</code><font papago-translate="splitted">.</font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["acca","bbbb","caca"], target = "aba"
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are 6 ways to form target.
"aba" -&gt; index 0 ("<u>a</u>cca"), index 1 ("b<u>b</u>bb"), index 3 ("cac<u>a</u>")
"aba" -&gt; index 0 ("<u>a</u>cca"), index 2 ("bb<u>b</u>b"), index 3 ("cac<u>a</u>")
"aba" -&gt; index 0 ("<u>a</u>cca"), index 1 ("b<u>b</u>bb"), index 3 ("acc<u>a</u>")
"aba" -&gt; index 0 ("<u>a</u>cca"), index 2 ("bb<u>b</u>b"), index 3 ("acc<u>a</u>")
"aba" -&gt; index 1 ("c<u>a</u>ca"), index 2 ("bb<u>b</u>b"), index 3 ("acc<u>a</u>")
"aba" -&gt; index 1 ("c<u>a</u>ca"), index 2 ("bb<u>b</u>b"), index 3 ("cac<u>a</u>")
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["abba","baab"], target = "bab"
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 ways to form target.
"bab" -&gt; index 0 ("<u>b</u>aab"), index 1 ("b<u>a</u>ab"), index 2 ("ab<u>b</u>a")
"bab" -&gt; index 0 ("<u>b</u>aab"), index 1 ("b<u>a</u>ab"), index 3 ("baa<u>b</u>")
"bab" -&gt; index 0 ("<u>b</u>aab"), index 2 ("ba<u>a</u>b"), index 3 ("baa<u>b</u>")
"bab" -&gt; index 1 ("a<u>b</u>ba"), index 2 ("ba<u>a</u>b"), index 3 ("baa<u>b</u>")
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 1000</code></li>
	<li><font papago-translate="splitted">All strings in </font><code>words</code><font papago-translate="splitted"> have the same length.</font></li>
	<li><code>1 &lt;= target.length &lt;= 1000</code></li>
	<li><code>words[i]</code><font papago-translate="splitted"> and </font><code>target</code><font papago-translate="splitted"> contain only lowercase English letters.</font></li>
</ul>
</div>