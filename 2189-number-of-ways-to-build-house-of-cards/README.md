<h2><a href="https://leetcode.com/problems/number-of-ways-to-build-house-of-cards/">2189. Number of Ways to Build House of Cards</a></h2><h3>Medium</h3><hr><div><p><font papago-id="15" papago-translate="translated">You are given an integer </font><code>n</code><font papago-id="16" papago-translate="cached"> representing the number of playing cards you have. A <strong papago-id="16-1">house of cards</strong> meets the following conditions:</font></p>

<ul>
	<li papago-id="17" papago-translate="cached">A <strong papago-id="17-1">house of cards</strong> consists of one or more rows of <strong papago-id="17-3">triangles</strong> and horizontal cards.</li>
	<li papago-id="18" papago-translate="cached"><strong papago-id="18-0">Triangles</strong> are created by leaning two cards against each other.</li>
	<li papago-id="19" papago-translate="cached">One card must be placed horizontally between <strong papago-id="19-1">all adjacent</strong> triangles in a row.</li>
	<li papago-id="20" papago-translate="translated">Any triangle on a row higher than the first must be placed on a horizontal card from the previous row.</li>
	<li papago-id="21" papago-translate="cached">Each triangle is placed in the <strong papago-id="21-1">leftmost</strong> available spot in the row.</li>
</ul>

<p> <code>n</code></p>

<p>&nbsp;</p>
<p><strong papago-id="22" papago-translate="translated">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/02/27/image-20220227213243-1.png" style="width: 726px; height: 150px;">
<pre papago-id="23" papago-translate="cached"><strong papago-id="23-0">Input:</strong> n = 16
<strong papago-id="23-2">Output:</strong> 2
<strong papago-id="23-4">Explanation:</strong> The two valid houses of cards are shown.
The third house of cards in the diagram is not valid because the rightmost triangle on the top row is not placed on top of a horizontal card.
</pre>

<p><strong papago-id="0" papago-translate="translated">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/02/27/image-20220227213306-2.png" style="width: 96px; height: 80px;">
<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> n = 2
<strong papago-id="0-2">Output:</strong> 1
<strong papago-id="0-4">Explanation:</strong> The one valid house of cards is shown.
</pre>

<p><strong papago-id="0" papago-translate="translated">Example 3:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/02/27/image-20220227213331-3.png" style="width: 330px; height: 85px;">
<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> n = 4
<strong papago-id="0-2">Output:</strong> 0
<strong papago-id="0-4">Explanation:</strong> The three houses of cards in the diagram are not valid.
The first house of cards needs a horizontal card placed between the two triangles.
The second house of cards uses 5 cards.
The third house of cards uses 2 cards.
</pre>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
</ul>
</div>