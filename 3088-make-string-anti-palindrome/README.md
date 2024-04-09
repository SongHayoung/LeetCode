<h2><a href="https://leetcode.com/problems/make-string-anti-palindrome/">3088. Make String Anti-palindrome</a></h2><h3>Hard</h3><hr><div><p>We call a string <code>s</code> of <strong>even</strong> length <code>n</code> an <strong>anti-palindrome</strong> if for each index <code>0 &lt;= i &lt; n</code>, <code>s[i] != s[n - i - 1]</code>.</p>

<p>Given a string <code>s</code>, your task is to make <code>s</code> an <strong>anti-palindrome</strong> by doing <strong>any</strong> number of operations (including zero).</p>

<p>In one operation, you can select two characters from <code>s</code> and swap them.</p>

<p>Return <em>the resulting string. If multiple strings meet the conditions, return the <span data-keyword="lexicographically-smaller-string">lexicographically smallest</span> one. If it can't be made into an anti-palindrome, return </em><code>"-1"</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "abca"</span></p>

<p><strong>Output:</strong> <span class="example-io">"aabc"</span></p>

<p><strong>Explanation:</strong></p>

<p><code>"aabc"</code> is an anti-palindrome string since <code>s[0] != s[3]</code> and <code>s[1] != s[2]</code>. Also, it is a rearrangement of <code>"abca"</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "abba"</span></p>

<p><strong>Output:</strong> <span class="example-io">"aabb"</span></p>

<p><strong>Explanation:</strong></p>

<p><code>"aabb"</code> is an anti-palindrome string since <code>s[0] != s[3]</code> and <code>s[1] != s[2]</code>. Also, it is a rearrangement of <code>"abba"</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "cccd"</span></p>

<p><strong>Output:</strong> <span class="example-io">"-1"</span></p>

<p><strong>Explanation:</strong></p>

<p>You can see that no matter how you rearrange the characters of <code>"cccd"</code>, either <code>s[0] == s[3]</code> or <code>s[1] == s[2]</code>. So it can not form an anti-palindrome string.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s.length % 2 == 0</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>
</div>