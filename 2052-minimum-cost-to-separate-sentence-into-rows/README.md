<h2><a href="https://leetcode.com/problems/minimum-cost-to-separate-sentence-into-rows/">2052. Minimum Cost to Separate Sentence Into Rows</a></h2><h3>Medium</h3><hr><div><p>You are given a string <code>sentence</code> containing words separated by spaces, and an integer <code>k</code>. Your task is to separate <code>sentence</code> into <strong>rows</strong> where the number of characters in each row is <strong>at most </strong><code>k</code>. You may assume that <code>sentence</code> does not begin or end with a space, and the words in <code>sentence</code> are separated by a single space.</p>

<p>You can split <code>sentence</code> into rows by inserting line breaks between words in <code>sentence</code>. A word <strong>cannot</strong> be split between two rows. Each word must be used exactly once, and the word order cannot be rearranged. Adjacent words in a row should be separated by a single space, and rows should not begin or end with spaces.</p>

<p>The <strong>cost</strong> of a row with length <code>n</code> is <code>(k - n)<sup>2</sup></code>, and the <strong>total cost</strong> is the sum of the <strong>costs</strong> for all rows <strong>except</strong> the last one.</p>

<ul>
	<li>For example if <code>sentence = "i love leetcode"</code> and <code>k = 12</code>:

	<ul>
		<li>Separating <code>sentence</code> into <code>"i"</code>, <code>"love"</code>, and <code>"leetcode"</code> has a cost of <code>(12 - 1)<sup>2</sup> + (12 - 4)<sup>2</sup> = 185</code>.</li>
		<li>Separating <code>sentence</code> into <code>"i love"</code>, and <code>"leetcode"</code> has a cost of <code>(12 - 6)<sup>2</sup> = 36</code>.</li>
		<li>Separating <code>sentence</code> into <code>"i"</code>, and <code>"love leetcode"</code> is not possible because the length of <code>"love leetcode"</code> is greater than <code>k</code>.</li>
	</ul>
	</li>
</ul>

<p>Return <em>the <strong>minimum</strong> possible total cost of separating</em><em> </em><code>sentence</code><em> into rows.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> sentence = "i love leetcode", k = 12
<strong>Output:</strong> 36
<strong>Explanation:</strong>
Separating sentence into "i", "love", and "leetcode" has a cost of (12 - 1)<sup>2</sup> + (12 - 4)<sup>2</sup> = 185.
Separating sentence into "i love", and "leetcode" has a cost of (12 - 6)<sup>2</sup> = 36.
Separating sentence into "i", "love leetcode" is not possible because "love leetcode" has length 13.
36 is the minimum possible total cost so return it.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> sentence = "apples and bananas taste great", k = 7
<strong>Output:</strong> 21
<strong>Explanation</strong>
Separating sentence into "apples", "and", "bananas", "taste", and "great" has a cost of (7 - 6)<sup>2</sup> + (7 - 3)<sup>2</sup> + (7 - 7)<sup>2</sup> + (7 - 5)<sup>2 </sup>= 21.
21 is the minimum possible total cost so return it.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> sentence = "a", k = 5
<strong>Output:</strong> 0
<strong>Explanation:</strong>
The cost of the last row is not included in the total cost, and since there is only one row, return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 5000</code></li>
	<li><code>1 &lt;= k &lt;= 5000</code></li>
	<li>The length of each word in <code>sentence</code> is at most <code>k</code>.</li>
	<li><code>sentence</code> consists of only lowercase English letters and spaces.</li>
	<li><code>sentence</code> does not begin or end with a space.</li>
	<li>Words in <code>sentence</code> are separated by a single space.</li>
</ul>
</div>