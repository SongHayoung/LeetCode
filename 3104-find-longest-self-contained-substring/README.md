<h2><a href="https://leetcode.com/problems/find-longest-self-contained-substring/">3104. Find Longest Self-Contained Substring</a></h2><h3>Hard</h3><hr><div><p>Given a string <code>s</code>, your task is to find the length of the <strong>longest self-contained</strong> <span data-keyword="substring-nonempty">substring</span> of <code>s</code>.</p>

<p>A substring <code>t</code> of a string <code>s</code> is called <strong>self-contained </strong>if <code>t != s</code> and for every character in <code>t</code>, it doesn't exist in the <em>rest</em> of <code>s</code>.</p>

<p>Return the length of the <em>longest<strong> </strong>self-contained </em>substring of <code>s</code> if it exists, otherwise, return -1.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "abba"</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong><br>
Let's check the substring <code>"bb"</code>. You can see that no other <code>"b"</code> is outside of this substring. Hence the answer is 2.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "abab"</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong><br>
Every substring we choose does not satisfy the described property (there is some character which is inside and outside of that substring). So the answer would be -1.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "abacd"</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong><br>
Let's check the substring <code>"<span class="example-io">abac</span>"</code>. There is only one character outside of this substring and that is <code>"d"</code>. There is no <code>"d"</code> inside the chosen substring, so it satisfies the condition and the answer is 4.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>
</div>