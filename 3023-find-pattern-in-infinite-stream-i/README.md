<h2><a href="https://leetcode.com/problems/find-pattern-in-infinite-stream-i/">3023. Find Pattern in Infinite Stream I</a></h2><h3>Medium</h3><hr><div><p>You are given a binary array <code>pattern</code> and an object <code>stream</code> of class <code>InfiniteStream</code> representing a <strong>0-indexed</strong> infinite stream of bits.</p>

<p>The class <code>InfiniteStream</code> contains the following function:</p>

<ul>
	<li><code>int next()</code>: Reads a <strong>single</strong> bit (which is either <code>0</code> or <code>1</code>) from the stream and returns it.</li>
</ul>

<p>Return <em>the <strong>first starting</strong> index where the pattern matches the bits read from the stream</em>. For example, if the pattern is <code>[1, 0]</code>, the first match is the highlighted part in the stream <code>[0, <strong><u>1, 0</u></strong>, 1, ...]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> stream = [1,1,1,0,1,1,1,...], pattern = [0,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The first occurrence of the pattern [0,1] is highlighted in the stream [1,1,1,<strong><u>0,1</u></strong>,...], which starts at index 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> stream = [0,0,0,0,...], pattern = [0]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The first occurrence of the pattern [0] is highlighted in the stream [<strong><u>0</u></strong>,...], which starts at index 0.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> stream = [1,0,1,1,0,1,1,0,1,...], pattern = [1,1,0,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The first occurrence of the pattern [1,1,0,1] is highlighted in the stream [1,0,<strong><u>1,1,0,1</u></strong>,...], which starts at index 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length &lt;= 100</code></li>
	<li><code>pattern</code> consists only of <code>0</code> and <code>1</code>.</li>
	<li><code>stream</code> consists only of <code>0</code> and <code>1</code>.</li>
	<li>The input is generated such that the pattern's start index exists in the first <code>10<sup>5</sup></code> bits of the stream.</li>
</ul>
</div>