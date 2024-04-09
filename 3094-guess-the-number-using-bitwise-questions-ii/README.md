<h2><a href="https://leetcode.com/problems/guess-the-number-using-bitwise-questions-ii/">3094. Guess the Number Using Bitwise Questions II</a></h2><h3>Medium</h3><hr><div><p>There is a number <code>n</code> between <code>0</code> and <code>2<sup>30</sup> - 1</code> (both inclusive) that you have to find.</p>

<p>There is a pre-defined API <code>int commonBits(int num)</code> that helps you with your mission. But here is the challenge, every time you call this function, <code>n</code> changes in some way. But keep in mind, that you have to find the <strong>initial value of </strong><code>n</code>.</p>

<p><code>commonBits(int num)</code> acts as follows:</p>

<ul>
	<li>Calculate <code>count</code> which is the number of bits where both <code>n</code> and <code>num</code> have the same value in that position of their binary representation.</li>
	<li><code>n = n XOR num</code></li>
	<li>Return <code>count</code>.</li>
</ul>

<p>Return <em>the number</em> <code>n</code>.</p>

<p><strong>Note:</strong> In this world, all numbers are between <code>0</code> and <code>2<sup>30</sup> - 1</code> (both inclusive), thus for counting common bits, we see only the first 30 bits of those numbers.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1: </strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> n = 31 </span></p>

<p><strong>Output: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> 31 </span></p>

<p><strong>Explanation: </strong> It can be proven that it's possible to find 31 using the provided API.</p>
</div>

<p><strong class="example">Example 2: </strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> n = 33 </span></p>

<p><strong>Output: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> 33 </span></p>

<p><strong>Explanation: </strong> It can be proven that it's possible to find 33 using the provided API.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 2<sup>30</sup> - 1</code></li>
	<li><code>0 &lt;= num &lt;= 2<sup>30</sup> - 1</code></li>
	<li>If you ask for some <code>num</code> out of the given range, the output wouldn't be reliable.</li>
</ul>
</div>