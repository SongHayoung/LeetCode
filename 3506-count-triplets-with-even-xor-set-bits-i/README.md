<h2><a href="https://leetcode.com/problems/count-triplets-with-even-xor-set-bits-i">3506. Count Triplets with Even XOR Set Bits I</a></h2><h3>Easy</h3><hr>Given three integer arrays <code>a</code>, <code>b</code>, and <code>c</code>, return the number of triplets <code>(a[i], b[j], c[k])</code>, such that the bitwise <code>XOR</code> of the elements of each triplet has an <strong>even</strong> number of <span data-keyword="set-bit">set bits</span>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">a = [1], b = [2], c = [3]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The only triplet is <code>(a[0], b[0], c[0])</code> and their <code>XOR</code> is: <code>1 XOR 2 XOR 3 = 00<sub>2</sub></code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">a = [1,1], b = [2,3], c = [1,5]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>Consider these four triplets:</p>

<ul>
	<li><code>(a[0], b[1], c[0])</code>: <code>1 XOR 3 XOR 1 = 011<sub>2</sub></code></li>
	<li><code>(a[1], b[1], c[0])</code>: <code>1 XOR 3 XOR 1 = 011<sub>2</sub></code></li>
	<li><code>(a[0], b[0], c[1])</code>: <code>1 XOR 2 XOR 5 = 110<sub>2</sub></code></li>
	<li><code>(a[1], b[0], c[1])</code>: <code>1 XOR 2 XOR 5 = 110<sub>2</sub></code></li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length, c.length &lt;= 100</code></li>
	<li><code>0 &lt;= a[i], b[i], c[i] &lt;= 100</code></li>
</ul>
