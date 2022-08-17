<h2><a href="https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/">1625. Lexicographically Smallest String After Applying Operations</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="14">You are given a string </font><code>s</code><code>0</code><font papago-translate="cached" papago-id="16"> to </font><code>9</code><font papago-translate="cached" papago-id="17">, and two integers </font><code>a</code><font papago-translate="cached" papago-id="18"> and </font><code>b</code><font papago-translate="cached" papago-id="19">.</font></p>

<p><font papago-translate="cached" papago-id="20">You can apply either of the following two operations any number of times and in any order on </font><code>s</code><font papago-translate="cached" papago-id="21">:</font></p>

<ul>
	<li><font papago-translate="cached" papago-id="22">Add </font><code>a</code><font papago-translate="cached" papago-id="23"> to all odd indices of </font><code>s</code> <code>9</code><font papago-translate="cached" papago-id="25"> are cycled back to </font><code>0</code><font papago-translate="cached" papago-id="26">. For example, if </font><code>s = "3456"</code><font papago-translate="cached" papago-id="27"> and </font><code>a = 5</code><font papago-translate="cached" papago-id="28">, </font><code>s</code><font papago-translate="cached" papago-id="29"> becomes </font><code>"3951"</code><font papago-translate="cached" papago-id="30">.</font></li>
	<li><font papago-translate="cached" papago-id="31">Rotate </font><code>s</code><font papago-translate="cached" papago-id="32"> to the right by </font><code>b</code><font papago-translate="cached" papago-id="33"> positions. For example, if </font><code>s = "3456"</code><font papago-translate="cached" papago-id="34"> and </font><code>b = 1</code><font papago-translate="cached" papago-id="35">, </font><code>s</code><font papago-translate="cached" papago-id="36"> becomes </font><code>"6345"</code><font papago-translate="cached" papago-id="37">.</font></li>
</ul>

<p> <code>s</code><font papago-translate="cached" papago-id="39">.</font></p>

<p><font papago-translate="cached" papago-id="40">A string </font><code>a</code><font papago-translate="cached" papago-id="41"> is lexicographically smaller than a string </font><code>b</code><font papago-translate="cached" papago-id="42"> (of the same length) if in the first position where </font><code>a</code><font papago-translate="cached" papago-id="43"> and </font><code>b</code><font papago-translate="cached" papago-id="44"> differ, string </font><code>a</code><font papago-translate="cached" papago-id="45"> has a letter that appears earlier in the alphabet than the corresponding letter in </font><code>b</code><font papago-translate="cached" papago-id="46">. For example, </font><code>"0158"</code><font papago-translate="cached" papago-id="47"> is lexicographically smaller than </font><code>"0190"</code><font papago-translate="cached" papago-id="48"> because the first position they differ is at the third letter, and </font><code>'5'</code><font papago-translate="cached" papago-id="49"> comes before </font><code>'9'</code><font papago-translate="cached" papago-id="50">.</font></p>

<p>&nbsp;</p>
<p><strong papago-id="51" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="52" papago-translate="cached"><strong papago-id="52-0">Input:</strong> s = "5525", a = 9, b = 2
<strong papago-id="52-2">Output:</strong> "2050"
<strong papago-id="52-4">Explanation:</strong> We can apply the following operations:
Start:  "5525"
Rotate: "2555"
Add:    "2454"
Add:    "2353"
Rotate: "5323"
Add:    "5222"
Add:    "5121"
Rotate: "2151"
​​​​​​​Add:    "2050"​​​​​​​​​​​​
There is no way to obtain a string that is lexicographically smaller then "2050".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "74", a = 5, b = 1
<strong>Output:</strong> "24"
<strong>Explanation:</strong> We can apply the following operations:
Start:  "74"
Rotate: "47"
​​​​​​​Add:    "42"
​​​​​​​Rotate: "24"​​​​​​​​​​​​
There is no way to obtain a string that is lexicographically smaller then "24".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "0011", a = 4, b = 2
<strong>Output:</strong> "0011"
<strong>Explanation:</strong> There are no sequence of operations that will give us a lexicographically smaller string than "0011".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s.length</code><font papago-translate="translated" papago-id="37"> is even.</font></li>
	<li><code>s</code><font papago-translate="translated" papago-id="38"> consists of digits from </font><code>0</code><font papago-translate="translated" papago-id="39"> to </font><code>9</code><font papago-translate="translated" papago-id="40"> only.</font></li>
	<li><code>1 &lt;= a &lt;= 9</code></li>
	<li><code>1 &lt;= b &lt;= s.length - 1</code></li>
</ul>
</div>