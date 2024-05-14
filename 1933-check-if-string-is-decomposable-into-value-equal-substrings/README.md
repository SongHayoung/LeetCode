<h2><a href="https://leetcode.com/problems/check-if-string-is-decomposable-into-value-equal-substrings/">1933. Check if String Is Decomposable Into Value-Equal Substrings</a></h2><h3>Easy</h3><hr><div><p>A <strong>value-equal</strong> string is a string where <strong>all</strong> characters are the same.</p>

<ul>
	<li><font papago-translate="splitted">For example, </font><code>"1111"</code><font papago-translate="splitted"> and </font><code>"33"</code><font papago-translate="splitted"> are value-equal strings.</font></li>
	<li><font papago-translate="splitted">In contrast, </font><code>"123"</code><font papago-translate="splitted"> is not a value-equal string.</font></li>
</ul>

<p><font papago-translate="splitted">Given a digit string </font><code>s</code><code>2</code><code>3</code><font papago-translate="splitted">.</font></p>

<p><font papago-translate="splitted">Return </font><code>true</code><font papago-translate="splitted"><em> if you can decompose </em></font><code>s</code><font papago-translate="splitted"><em> according to the above rules. Otherwise, return </em></font><code>false</code><font papago-translate="splitted">.</font></p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "000111000"
<strong>Output:</strong> false
<strong>Explanation: </strong>s cannot be decomposed according to the rules because ["000", "111", "000"] does not have a substring of length 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "00011111222"
<strong>Output:</strong> true
<strong>Explanation: </strong>s can be decomposed into ["000", "111", "11", "222"].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "011100022233"
<strong>Output:</strong> false
<strong>Explanation: </strong>s cannot be decomposed according to the rules because of the first '0'.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code><font papago-translate="splitted"> consists of only digits </font><code>'0'</code><font papago-translate="splitted"> through </font><code>'9'</code><font papago-translate="splitted">.</font></li>
</ul>
</div>