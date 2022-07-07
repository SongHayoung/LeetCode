<h2><a href="https://leetcode.com/problems/count-substrings-that-differ-by-one-character/">1638. Count Substrings That Differ by One Character</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">Given two strings </font><code>s</code><font papago-translate="cached" papago-id="16"> and </font><code>t</code><font papago-translate="cached" papago-id="17">, find the number of ways you can choose a non-empty substring of </font><code>s</code><code>t</code><font papago-translate="cached" papago-id="19">. In other words, find the number of substrings in </font><code>s</code><font papago-translate="cached" papago-id="20"> that differ from some substring in </font><code>t</code></p>

<p><font papago-translate="cached" papago-id="22">For example, the underlined substrings in </font><code>"<u>compute</u>r"</code><font papago-translate="cached" papago-id="23"> and </font><code>"<u>computa</u>tion"</code><font papago-translate="cached" papago-id="24"> only differ by the </font><code>'e'</code><font papago-translate="cached" papago-id="25">/</font><code>'a'</code><font papago-translate="cached" papago-id="26">, so this is a valid way.</font></p>

<p papago-id="27" papago-translate="cached">Return <em papago-id="27-1">the number of substrings that satisfy the condition above.</em></p>

<p papago-id="28" papago-translate="cached">A <strong papago-id="28-1">substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong papago-id="29" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="30" papago-translate="cached"><strong papago-id="30-0">Input:</strong> s = "aba", t = "baba"
<strong papago-id="30-2">Output:</strong> 6
<strong papago-id="30-4">Explanation:</strong> The following are the pairs of substrings from s and t that differ by exactly 1 character:
("<u papago-id="30-6">a</u>ba", "<u papago-id="30-8">b</u>aba")
("<u papago-id="30-10">a</u>ba", "ba<u papago-id="30-12">b</u>a")
("ab<u papago-id="30-14">a</u>", "<u papago-id="30-16">b</u>aba")
("ab<u papago-id="30-18">a</u>", "ba<u papago-id="30-20">b</u>a")
("a<u papago-id="30-22">b</u>a", "b<u papago-id="30-24">a</u>ba")
("a<u papago-id="30-26">b</u>a", "bab<u papago-id="30-28">a</u>")
The underlined portions are the substrings that are chosen from s and t.
</pre><font papago-translate="cached" papago-id="14">
​​<strong papago-id="14-1">Example 2:</strong></font>

<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> s = "ab", t = "bb"
<strong papago-id="0-2">Output:</strong> 3
<strong papago-id="0-4">Explanation:</strong> The following are the pairs of substrings from s and t that differ by 1 character:
("<u papago-id="0-6">a</u>b", "<u papago-id="0-8">b</u>b")
("<u papago-id="0-10">a</u>b", "b<u papago-id="0-12">b</u>")
("<u papago-id="0-14">ab</u>", "<u papago-id="0-16">bb</u>")
​​​​The underlined portions are the substrings that are chosen from s and t.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 100</code></li>
	<li><code>s</code><font papago-translate="translated" papago-id="12"> and </font><code>t</code><font papago-translate="translated" papago-id="13"> consist of lowercase English letters only.</font></li>
</ul>
</div>