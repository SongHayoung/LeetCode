<h2><a href="https://leetcode.com/problems/sum-game/">1927. Sum Game</a></h2><h3>Medium</h3><hr><div><p papago-id="15" papago-translate="cached">Alice and Bob take turns playing a game, with <strong papago-id="15-1">Alice</strong><strong papago-id="15-2">&nbsp;starting first</strong>.</p>

<p><font papago-translate="cached" papago-id="16">You are given a string </font><code>num</code><code>'?'</code><font papago-translate="cached" papago-id="18"> characters. On each turn, a player will do the following if there is still at least one </font><code>'?'</code><font papago-translate="cached" papago-id="19"> in </font><code>num</code><font papago-translate="cached" papago-id="20">:</font></p>

<ol>
	<li><font papago-translate="cached" papago-id="21">Choose an index </font><code>i</code><font papago-translate="cached" papago-id="22"> where </font><code>num[i] == '?'</code><font papago-translate="cached" papago-id="23">.</font></li>
	<li><font papago-translate="cached" papago-id="24">Replace </font><code>num[i]</code><font papago-translate="cached" papago-id="25"> with any digit between </font><code>'0'</code><font papago-translate="cached" papago-id="26"> and </font><code>'9'</code><font papago-translate="cached" papago-id="27">.</font></li>
</ol>

<p><font papago-translate="cached" papago-id="28">The game ends when there are no more </font><code>'?'</code><font papago-translate="cached" papago-id="29"> characters in </font><code>num</code><font papago-translate="cached" papago-id="30">.</font></p>

<p><font papago-translate="cached" papago-id="31">For Bob&nbsp;to win, the sum of the digits in the first half of </font><code>num</code></p>

<ul>
	<li><font papago-translate="cached" papago-id="33">For example, if the game ended with </font><code>num = "243801"</code><font papago-translate="cached" papago-id="34">, then Bob&nbsp;wins because </font><code>2+4+3 = 8+0+1</code><font papago-translate="cached" papago-id="35">. If the game ended with </font><code>num = "243803"</code><font papago-translate="cached" papago-id="36">, then Alice&nbsp;wins because </font><code>2+4+3 != 8+0+3</code><font papago-translate="cached" papago-id="37">.</font></li>
</ul>

<p><code>true</code> <font papago-translate="splited"><em papago-id="23" papago-translate="translated">if Alice will win and </em></font><code>false</code> </p>

<p>&nbsp;</p>
<p><strong papago-id="40" papago-translate="translated">Example 1:</strong></p>

<pre><strong>Input:</strong> num = "5023"
<strong>Output:</strong> false
<strong>Explanation:</strong> There are no moves to be made.
The sum of the first half is equal to the sum of the second half: 5 + 0 = 2 + 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = "25??"
<strong>Output:</strong> true
<strong>Explanation: </strong>Alice can replace one of the '?'s with '9' and it will be impossible for Bob to make the sums equal.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num = "?3295???"
<strong>Output:</strong> false
<strong>Explanation:</strong> It can be proven that Bob will always win. One possible outcome is:
- Alice replaces the first '?' with '9'. num = "93295???".
- Bob replaces one of the '?' in the right half with '9'. num = "932959??".
- Alice replaces one of the '?' in the right half with '2'. num = "9329592?".
- Bob replaces the last '?' in the right half with '7'. num = "93295927".
Bob wins because 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num.length</code><font papago-translate="cached" papago-id="25"> is <strong papago-id="25-1">even</strong>.</font></li>
	<li><code>num</code><font papago-translate="translated" papago-id="26"> consists of only digits and </font><code>'?'</code><font papago-translate="translated" papago-id="27">.</font></li>
</ul>
</div>