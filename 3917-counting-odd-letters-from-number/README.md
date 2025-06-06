<h2><a href="https://leetcode.com/problems/counting-odd-letters-from-number">3917. Counting Odd Letters from Number</a></h2><h3>Easy</h3><hr><p><meta charset="UTF-8" /></p>

<p cid="n610" mdtype="paragraph">You are given an integer <code>N</code>. Your task is to convert each digit of <code>N</code> into its <em>english word</em> representation and concatenate all the digit-words <strong>in order</strong> to form a string <code>S</code>.</p>

<p cid="n611" mdtype="paragraph">Return the number of <strong>distinct characters</strong> in <code>S</code> that appear an <strong>odd number of times</strong>.</p>

<p cid="n612" mdtype="paragraph">Input:</p>

<ul cid="n613" data-mark="-" mdtype="list">
	<li cid="n614" mdtype="list_item">
	<p cid="n615" mdtype="paragraph">A single integer <code>N</code>.</p>
	</li>
</ul>

<p cid="n616" mdtype="paragraph">Output:</p>

<ul cid="n617" data-mark="-" mdtype="list">
	<li cid="n618" mdtype="list_item">
	<p cid="n619" mdtype="paragraph">An integer representing the count of distinct characters that appear an odd number of times in <code>S</code>.</p>
	</li>
</ul>

<p cid="n620" mdtype="paragraph">Examples:</p>

<p cid="n628" mdtype="paragraph"><strong>Example 1:</strong></p>

<pre cid="n629" lang="" mdtype="fences" spellcheck="false">
<code>Input: 41 
Output: 5
Explanation: 41 &rarr; &quot;fourone&quot; we have 5 odd counts &#39;f&#39;, &#39;u&#39;, &#39;r&#39;, &#39;n&#39;, &#39;e&#39;</code>
</pre>

<p cid="n623" mdtype="paragraph"> </p>

<p cid="n624" mdtype="paragraph"><strong>Example 2:</strong></p>

<pre cid="n625" lang="" mdtype="fences" spellcheck="false">
<code>Input: 20
Output: 5
</code></pre>

<p cid="n626" mdtype="paragraph"> </p>

<p cid="n628" mdtype="paragraph"><strong>Example 3:</strong></p>

<pre cid="n629" lang="" mdtype="fences" spellcheck="false">
<code>Input: 88 
Output: 0</code>
</pre>

<p cid="n631" mdtype="paragraph"> </p>

<p cid="n632" mdtype="paragraph"><strong>Constraints:</strong></p>

<ul cid="n633" data-mark="-" mdtype="list">
	<li cid="n634" mdtype="list_item">
	<p cid="n635" mdtype="paragraph"><code>1 &le; N &le; 10⁹</code></p>
	</li>
</ul>
