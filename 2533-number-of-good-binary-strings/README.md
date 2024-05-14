<h2><a href="https://leetcode.com/problems/number-of-good-binary-strings/">2533. Number of Good Binary Strings</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">You are given four integers </font><code>minLength</code><font papago-translate="splitted">, </font><code>maxLength</code><font papago-translate="splitted">, </font><code>oneGroup</code><font papago-translate="splitted"> and </font><code>zeroGroup</code><font papago-translate="splitted">.</font></p>

<p>A binary string is <strong>good</strong> if it satisfies the following conditions:</p>

<ul>
	<li><font papago-translate="splitted">The length of the string is in the range </font><code>[minLength, maxLength]</code><font papago-translate="splitted">.</font></li>
	<li><font papago-translate="splitted">The size of each block of consecutive </font><code>1</code><font papago-translate="splitted">'s is a multiple of </font><code>oneGroup</code><font papago-translate="splitted">.
	</font><ul>
		<li><font papago-translate="splitted">For example in a binary string </font><code>00<u>11</u>0<u>1111</u>00</code><font papago-translate="splitted"> sizes of each block of consecutive ones are </font><code>[2,4]</code><font papago-translate="splitted">.</font></li>
	</ul>
	</li>
	<li><font papago-translate="splitted">The size of each block of consecutive </font><code>0</code><font papago-translate="splitted">'s is a multiple of </font><code>zeroGroup</code><font papago-translate="splitted">.
	</font><ul>
		<li><font papago-translate="splitted">For example, in a binary string </font><code><u>00</u>11<u>0</u>1111<u>00</u></code><font papago-translate="splitted"> sizes of each block of consecutive zeros are </font><code>[2,1,2]</code><font papago-translate="splitted">.</font></li>
	</ul>
	</li>
</ul>

<p> <code>10<sup>9</sup> + 7</code><font papago-translate="splitted">.</font></p>

<p><code>0</code><font papago-translate="splitted"> is considered a multiple of all the numbers.</font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> minLength = 2, maxLength = 3, oneGroup = 1, zeroGroup = 2
<strong>Output:</strong> 5
<strong>Explanation:</strong> There are 5 good binary strings in this example: "00", "11", "001", "100", and "111".
It can be proven that there are only 5 good strings satisfying all conditions.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> minLength = 4, maxLength = 4, oneGroup = 4, zeroGroup = 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is only 1 good binary string in this example: "1111".
It can be proven that there is only 1 good string satisfying all conditions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= minLength &lt;= maxLength &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= oneGroup, zeroGroup &lt;= maxLength</code></li>
</ul>
</div>