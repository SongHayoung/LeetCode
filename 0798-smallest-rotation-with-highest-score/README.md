<h2><a href="https://leetcode.com/problems/smallest-rotation-with-highest-score/">798. Smallest Rotation with Highest Score</a></h2><h3>Hard</h3><hr><div><p><font papago-translate="splitted">You are given an array </font><code>nums</code><font papago-translate="splitted">. You can rotate it by a non-negative integer </font><code>k</code><font papago-translate="splitted"> so that the array becomes </font><code>[nums[k], nums[k + 1], ... nums[nums.length - 1], nums[0], nums[1], ..., nums[k-1]]</code><font papago-translate="splitted">. Afterward, any entries that are less than or equal to their index are worth one point.</font></p>

<ul>
	<li><font papago-translate="splitted">For example, if we have </font><code>nums = [2,4,1,3,0]</code><font papago-translate="splitted">, and we rotate by </font><code>k = 2</code><font papago-translate="splitted">, it becomes </font><code>[1,3,0,2,4]</code><font papago-translate="splitted">. This is worth </font><code>3</code><font papago-translate="splitted"> points because </font><code>1 &gt; 0</code><font papago-translate="splitted"> [no points], </font><code>3 &gt; 1</code><font papago-translate="splitted"> [no points], </font><code>0 &lt;= 2</code><font papago-translate="splitted"> [one point], </font><code>2 &lt;= 3</code><font papago-translate="splitted"> [one point], </font><code>4 &lt;= 4</code><font papago-translate="splitted"> [one point].</font></li>
</ul>

<p><font papago-translate="splitted">Return <em>the rotation index </em></font><code>k</code><font papago-translate="splitted"><em> that corresponds to the highest score we can achieve if we rotated </em></font><code>nums</code><font papago-translate="splitted"><em> by it</em>. If there are multiple answers, return the smallest such index </font><code>k</code><font papago-translate="splitted">.</font></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,1,4,0]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Scores for each k are listed below: 
k = 0,  nums = [2,3,1,4,0],    score 2
k = 1,  nums = [3,1,4,0,2],    score 3
k = 2,  nums = [1,4,0,2,3],    score 3
k = 3,  nums = [4,0,2,3,1],    score 4
k = 4,  nums = [0,2,3,1,4],    score 3
So we should choose k = 3, which has the highest score.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,0,2,4]
<strong>Output:</strong> 0
<strong>Explanation:</strong> nums will always have 3 points no matter how it shifts.
So we will choose the smallest k, which is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt; nums.length</code></li>
</ul>
</div>