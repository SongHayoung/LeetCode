<h2><a href="https://leetcode.com/problems/lonely-pixel-ii/">533. Lonely Pixel II</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">Given an </font><code>m x n</code> <code>picture</code><font papago-translate="cached" papago-id="16"> consisting of black </font><code>'B'</code><font papago-translate="cached" papago-id="17"> and white </font><code>'W'</code></p>

<p><font papago-translate="cached" papago-id="19">A black lonely pixel is a character </font><code>'B'</code><font papago-translate="cached" papago-id="20"> that located at a specific position </font><code>(r, c)</code><font papago-translate="cached" papago-id="21"> where:</font></p>

<ul>
	<li><font papago-translate="cached" papago-id="22">Row </font><code>r</code><font papago-translate="cached" papago-id="23"> and column </font><code>c</code><font papago-translate="cached" papago-id="24"> both contain exactly </font><code>target</code><font papago-translate="cached" papago-id="25"> black pixels.</font></li>
	<li><font papago-translate="cached" papago-id="26">For all rows that have a black pixel at column </font><code>c</code><font papago-translate="cached" papago-id="27">, they should be exactly the same as row </font><code>r</code><font papago-translate="cached" papago-id="28">.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong papago-id="29" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/pixel2-1-grid.jpg" style="width: 493px; height: 333px;">
<pre><strong>Input:</strong> picture = [["W","B","W","B","B","W"],["W","B","W","B","B","W"],["W","B","W","B","B","W"],["W","W","B","W","B","W"]], target = 3
<strong>Output:</strong> 6
<strong>Explanation:</strong> All the green 'B' are the black pixels we need (all 'B's at column 1 and 3).
Take 'B' at row r = 0 and column c = 1 as an example:
 - Rule 1, row r = 0 and column c = 1 both have exactly target = 3 black pixels. 
 - Rule 2, the rows have black pixel at column c = 1 are row 0, row 1 and row 2. They are exactly the same as row r = 0.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/pixel2-2-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> picture = [["W","W","B"],["W","W","B"],["W","W","B"]], target = 1
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m ==&nbsp;picture.length</code></li>
	<li><code>n ==&nbsp;picture[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>picture[i][j]</code><font papago-translate="translated" papago-id="14"> is </font><code>'W'</code><font papago-translate="translated" papago-id="15"> or </font><code>'B'</code><font papago-translate="translated" papago-id="16">.</font></li>
	<li><code>1 &lt;= target &lt;= min(m, n)</code></li>
</ul>
</div>