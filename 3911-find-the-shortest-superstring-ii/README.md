<h2><a href="https://leetcode.com/problems/find-the-shortest-superstring-ii">3911. Find the Shortest Superstring II</a></h2><h3>Easy</h3><hr><p>You are given <strong>two</strong> strings, <code>s1</code> and <code>s2</code>. Return the <strong>shortest</strong> <em>possible</em> string that contains both <code>s1</code> and <code>s2</code> as substrings. If there are multiple valid answers, return <em>any </em>one of them.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s1 = &quot;aba&quot;, s2 = &quot;bab&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;abab&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p><code>&quot;abab&quot;</code> is the shortest string that contains both <code>&quot;aba&quot;</code> and <code>&quot;bab&quot;</code> as substrings.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s1 = &quot;aa&quot;, s2 = &quot;aaa&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;aaa&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p><code>&quot;aa&quot;</code> is already contained within <code>&quot;aaa&quot;</code>, so the shortest superstring is <code>&quot;aaa&quot;</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li data-end="23" data-start="2"><code>1 &lt;= s1.length &lt;= 100</code></li>
	<li data-end="47" data-start="26"><code>1 &lt;= s2.length &lt;= 100</code></li>
	<li data-end="102" data-is-last-node="" data-start="50"><code>s1</code> and <code>s2</code> consist of lowercase English letters only.</li>
</ul>
