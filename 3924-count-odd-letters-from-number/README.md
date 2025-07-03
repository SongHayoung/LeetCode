<h2><a href="https://leetcode.com/problems/count-odd-letters-from-number">3924. Count Odd Letters from Number</a></h2><h3>Easy</h3><hr><p>You are given an integer <code>n</code> perform the following steps:</p>

<ul>
	<li>Convert each digit of <code>n</code> into its <em>lowercase English word</em> (e.g., 4 &rarr; &quot;four&quot;, 1 &rarr; &quot;one&quot;).</li>
	<li><strong>Concatenate</strong> those words in the <strong>original digit order</strong> to form a string <code>s</code>.</li>
</ul>

<p>Return the number of <strong>distinct</strong> characters in <code>s</code> that appear an <strong>odd</strong> number of times.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 41</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p>41 &rarr; <code>&quot;fourone&quot;</code></p>

<p>Characters with odd frequencies: <code>&#39;f&#39;</code>, <code>&#39;u&#39;</code>, <code>&#39;r&#39;</code>, <code>&#39;n&#39;</code>, <code>&#39;e&#39;</code>. Thus, the answer is 5.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 20</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p>20 &rarr; <code>&quot;twozero&quot;</code></p>

<p>Characters with odd frequencies: <code>&#39;t&#39;</code>, <code>&#39;w&#39;</code>, <code>&#39;z&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;r&#39;</code>. Thus, the answer is 5.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>
