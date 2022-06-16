<h2><a href="https://leetcode.com/problems/pour-water/">755. Pour Water</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="11">You are given an elevation map represents as an integer array </font><code>heights</code><font papago-translate="cached" papago-id="12"> where </font><code>heights[i]</code><font papago-translate="cached" papago-id="13"> representing the height of the terrain at index </font><code>i</code><font papago-translate="cached" papago-id="14">. The width at each index is </font><code>1</code><font papago-translate="cached" papago-id="15">. You are also given two integers </font><code>volume</code><font papago-translate="cached" papago-id="16"> and </font><code>k</code><font papago-translate="cached" papago-id="17">. </font><code>volume</code><font papago-translate="cached" papago-id="18"> units of water will fall at index </font><code>k</code><font papago-translate="cached" papago-id="19">.</font></p>

<p><font papago-translate="cached" papago-id="20">Water first drops at the index </font><code>k</code><font papago-translate="cached" papago-id="21"> and rests on top of the highest terrain or water at that index. Then, it flows according to the following rules:</font></p>

<ul>
	<li papago-id="22" papago-translate="translated">If the droplet would eventually fall by moving left, then move left.</li>
	<li papago-id="23" papago-translate="translated">Otherwise, if the droplet would eventually fall by moving right, then move right.</li>
	<li papago-id="24" papago-translate="translated">Otherwise, rise to its current position.</li>
</ul>

<p papago-id="25" papago-translate="cached">Here, <strong papago-id="25-1">"eventually fall"</strong> means that the droplet will eventually be at a lower level if it moves in that direction. Also, level means the height of the terrain plus any water in that column.</p>

<p papago-id="26" papago-translate="translated">We can assume there is infinitely high terrain on the two sides out of bounds of the array. Also, there could not be partial water being spread out evenly on more than one grid block, and each unit of water has to be in exactly one block.</p>

<p>&nbsp;</p>
<p><strong papago-id="27" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/12/pour11-grid.jpg" style="width: 450px; height: 303px;">
<pre><font papago-translate="cached" papago-id="11"><strong papago-id="11-0">Input:</strong> heights = [2,1,1,2,1,2,2], volume = 4, k = 3
<strong papago-id="11-2">Output:</strong> [2,2,2,3,2,2,2]
<strong papago-id="11-4">Explanation:</strong>
The first drop of water lands at index k = 3. When moving left or right, the water can only move to the same level or a lower level. (By level, we mean the total height of the terrain plus any water in that column.)
Since moving left will eventually make it fall, it moves left. (A droplet "made to fall" means go to a lower height than it was at previously.) Since moving left will not make it fall, it stays in place.
</font><img alt="" src="https://assets.leetcode.com/uploads/2021/06/12/pour12-grid.jpg" style="width: 400px; height: 269px;"><font papago-translate="translated" papago-id="12">
The next droplet falls at index k = 3. Since the new droplet moving left will eventually make it fall, it moves left. Notice that the droplet still preferred to move left, even though it could move right (and moving right makes it fall quicker.)
</font><img alt="" src="https://assets.leetcode.com/uploads/2021/06/12/pour13-grid.jpg" style="width: 400px; height: 269px;"><font papago-translate="translated" papago-id="13">
The third droplet falls at index k = 3. Since moving left would not eventually make it fall, it tries to move right. Since moving right would eventually make it fall, it moves right.
</font><img alt="" src="https://assets.leetcode.com/uploads/2021/06/12/pour14-grid.jpg" style="width: 400px; height: 269px;"><font papago-translate="translated" papago-id="14">
Finally, the fourth droplet falls at index k = 3. Since moving left would not eventually make it fall, it tries to move right. Since moving right would not eventually make it fall, it stays in place.
</font><img alt="" src="https://assets.leetcode.com/uploads/2021/06/12/pour15-grid.jpg" style="width: 400px; height: 269px;">
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> heights = [1,2,3,4], volume = 2, k = 2
<strong>Output:</strong> [2,3,3,4]
<strong>Explanation:</strong> The last droplet settles at index 1, since moving further left would not cause it to eventually fall to a lower height.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> heights = [3,1,3], volume = 5, k = 1
<strong>Output:</strong> [4,4,4]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= heights.length &lt;= 100</code></li>
	<li><code>0 &lt;= heights[i] &lt;= 99</code></li>
	<li><code>0 &lt;= volume &lt;= 2000</code></li>
	<li><code>0 &lt;= k &lt; heights.length</code></li>
</ul>
</div>