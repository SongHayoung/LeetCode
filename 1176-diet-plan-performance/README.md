<h2><a href="https://leetcode.com/problems/diet-plan-performance/">1176. Diet Plan Performance</a></h2><h3>Easy</h3><hr><div><p><font papago-translate="splitted">A dieter consumes&nbsp;</font><code>calories[i]</code><font papago-translate="splitted">&nbsp;calories on the </font><code>i</code><font papago-translate="splitted">-th day.&nbsp;</font></p>

<p><font papago-translate="splitted">Given an integer </font><code>k</code><code>k</code><font papago-translate="splitted"> days (</font><code>calories[i], calories[i+1], ..., calories[i+k-1]</code><font papago-translate="splitted">&nbsp;for all </font><code>0 &lt;= i &lt;= n-k</code><code>k</code><font papago-translate="splitted"> days (</font><code>calories[i] + calories[i+1] + ... + calories[i+k-1]</code><font papago-translate="splitted">):</font></p>

<ul>
	<li><font papago-translate="splitted">If </font><code>T &lt; lower</code><font papago-translate="splitted">, they performed poorly on their diet and lose 1 point;&nbsp;</font></li>
	<li><font papago-translate="splitted">If </font><code>T &gt; upper</code><font papago-translate="splitted">, they performed well on their diet and gain 1 point;</font></li>
	<li>Otherwise, they performed normally and there is no change in points.</li>
</ul>

<p><font papago-translate="splitted">Initially, the dieter has zero points. Return the total number of points the dieter has after dieting for </font><code>calories.length</code><font papago-translate="splitted">&nbsp;days.</font></p>

<p>Note that the total points can be negative.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3
<strong>Output:</strong> 0
<strong>Explanation</strong>: Since k = 1, we consider each element of the array separately and compare it to lower and upper.
calories[0] and calories[1] are less than lower so 2 points are lost.
calories[3] and calories[4] are greater than upper so 2 points are gained.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> calories = [3,2], k = 2, lower = 0, upper = 1
<strong>Output:</strong> 1
<strong>Explanation</strong>: Since k = 2, we consider subarrays of length 2.
calories[0] + calories[1] &gt; upper so 1 point is gained.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> calories = [6,5,0,0], k = 2, lower = 1, upper = 5
<strong>Output:</strong> 0
<strong>Explanation</strong>:
calories[0] + calories[1] &gt; upper so 1 point is gained.
lower &lt;= calories[1] + calories[2] &lt;= upper so no change in points.
calories[2] + calories[3] &lt; lower so 1 point is lost.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= calories.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= calories[i] &lt;= 20000</code></li>
	<li><code>0 &lt;= lower &lt;= upper</code></li>
</ul>
</div>