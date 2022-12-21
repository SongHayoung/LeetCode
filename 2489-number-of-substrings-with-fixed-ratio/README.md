<h2><a href="https://leetcode.com/problems/number-of-substrings-with-fixed-ratio/">2489. Number of Substrings With Fixed Ratio</a></h2><h3>Medium</h3><hr><div><p>You are given a binary string <code>s</code>, and two integers <code>num1</code> and <code>num2</code>. <code>num1</code> and <code>num2</code> are coprime numbers.</p>

<p>A <strong>ratio substring</strong> is a substring of s where the ratio between the number of <code>0</code>'s and the number of <code>1</code>'s in the substring is exactly <code>num1 : num2</code>.</p>

<ul>
	<li>For example, if <code>num1 = 2</code> and <code>num2 = 3</code>, then <code>"01011"</code> and <code>"1110000111"</code> are ratio substrings, while <code>"11000"</code> is not.</li>
</ul>

<p>Return <em>the number of <strong>non-empty</strong> ratio substrings of </em><code>s</code>.</p>

<p><strong>Note</strong> that:</p>

<ul>
	<li>A <strong>substring</strong> is a contiguous sequence of characters within a string.</li>
	<li>Two values <code>x</code> and <code>y</code> are <strong>coprime</strong> if <code>gcd(x, y) == 1</code> where <code>gcd(x, y)</code> is the greatest common divisor of <code>x</code> and <code>y</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "0110011", num1 = 1, num2 = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> There exist 4 non-empty ratio substrings.
- The substring s[0..2]: "<u>011</u>0011". It contains one 0 and two 1's. The ratio is 1 : 2.
- The substring s[1..4]: "0<u>110</u>011". It contains one 0 and two 1's. The ratio is 1 : 2.
- The substring s[4..6]: "0110<u>011</u>". It contains one 0 and two 1's. The ratio is 1 : 2.
- The substring s[1..6]: "0<u>110011</u>". It contains two 0's and four 1's. The ratio is 2 : 4 == 1 : 2.
It can be shown that there are no more ratio substrings.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "10101", num1 = 3, num2 = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no ratio substrings of s. We return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= num1, num2 &lt;= s.length</code></li>
	<li><code>num1</code> and <code>num2</code> are coprime integers.</li>
</ul>
</div>