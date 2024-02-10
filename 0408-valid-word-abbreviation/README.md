<h2><a href="https://leetcode.com/problems/valid-word-abbreviation/">408. Valid Word Abbreviation</a></h2><h3>Easy</h3><hr><div><p>A string can be <strong>abbreviated</strong> by replacing any number of <strong>non-adjacent</strong>, <strong>non-empty</strong> substrings with their lengths. The lengths <strong>should not</strong> have leading zeros.</p>

<p><font papago-translate="splitted">For example, a string such as </font><code>"substitution"</code><font papago-translate="splitted"> could be abbreviated as (but not limited to):</font></p>

<ul>
	<li><code>"s10n"</code><font papago-translate="splitted"> (</font><code>"s <u>ubstitutio</u> n"</code><font papago-translate="splitted">)</font></li>
	<li><code>"sub4u4"</code><font papago-translate="splitted"> (</font><code>"sub <u>stit</u> u <u>tion</u>"</code><font papago-translate="splitted">)</font></li>
	<li><code>"12"</code><font papago-translate="splitted"> (</font><code>"<u>substitution</u>"</code><font papago-translate="splitted">)</font></li>
	<li><code>"su3i1u2on"</code><font papago-translate="splitted"> (</font><code>"su <u>bst</u> i <u>t</u> u <u>ti</u> on"</code><font papago-translate="splitted">)</font></li>
	<li><code>"substitution"</code><font papago-translate="splitted"> (no substrings replaced)</font></li>
</ul>

<p>The following are <strong>not valid</strong> abbreviations:</p>

<ul>
	<li><code>"s55n"</code><font papago-translate="splitted"> (</font><code>"s <u>ubsti</u> <u>tutio</u> n"</code><font papago-translate="splitted">, the replaced substrings are adjacent)</font></li>
	<li><code>"s010n"</code><font papago-translate="splitted"> (has leading zeros)</font></li>
	<li><code>"s0ubstitution"</code><font papago-translate="splitted"> (replaces an empty substring)</font></li>
</ul>

<p><font papago-translate="splitted">Given a string </font><code>word</code><font papago-translate="splitted"> and an abbreviation </font><code>abbr</code></p>

<p>A <strong>substring</strong> is a contiguous <strong>non-empty</strong> sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> word = "internationalization", abbr = "i12iz4n"
<strong>Output:</strong> true
<strong>Explanation:</strong> The word "internationalization" can be abbreviated as "i12iz4n" ("i <u>nternational</u> iz <u>atio</u> n").
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> word = "apple", abbr = "a2e"
<strong>Output:</strong> false
<strong>Explanation:</strong> The word "apple" cannot be abbreviated as "a2e".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 20</code></li>
	<li><code>word</code><font papago-translate="splitted"> consists of only lowercase English letters.</font></li>
	<li><code>1 &lt;= abbr.length &lt;= 10</code></li>
	<li><code>abbr</code><font papago-translate="splitted"> consists of lowercase English letters and digits.</font></li>
	<li><font papago-translate="splitted">All the integers in </font><code>abbr</code><font papago-translate="splitted"> will fit in a 32-bit integer.</font></li>
</ul>
</div>