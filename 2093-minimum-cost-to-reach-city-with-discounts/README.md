<h2><a href="https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/">2093. Minimum Cost to Reach City With Discounts</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">A series of highways connect </font><code>n</code><font papago-translate="cached" papago-id="16"> cities numbered from </font><code>0</code><font papago-translate="cached" papago-id="17"> to </font><code>n - 1</code><font papago-translate="cached" papago-id="18">. You are given a 2D integer array </font><code>highways</code><font papago-translate="cached" papago-id="19"> where </font><code>highways[i] = [city1<sub>i</sub>, city2<sub>i</sub>, toll<sub>i</sub>]</code><font papago-translate="cached" papago-id="20"> indicates that there is a highway that connects </font><code>city1<sub>i</sub></code><font papago-translate="cached" papago-id="21"> and </font><code>city2<sub>i</sub></code><font papago-translate="cached" papago-id="22">, allowing a car to go from </font><code>city1<sub>i</sub></code><font papago-translate="cached" papago-id="23"> to </font><code>city2<sub>i</sub></code> <code>toll<sub>i</sub></code><font papago-translate="cached" papago-id="25">.</font></p>

<p><font papago-translate="cached" papago-id="26">You are also given an integer </font><code>discounts</code><font papago-translate="cached" papago-id="27"> which represents the number of discounts you have. You can use a discount to travel across the </font><code>i<sup>th</sup></code><font papago-translate="cached" papago-id="28"> highway for a cost of </font><code>toll<sub>i</sub> / 2</code> </p>

<p><code>0</code><font papago-translate="splited"><em papago-id="16" papago-translate="translated"> to city </em></font><code>n - 1</code><font papago-translate="splited"><em papago-id="17" papago-translate="translated">, or </em></font><code>-1</code><font papago-translate="splited"><em papago-id="18" papago-translate="translated"> if it is not possible to go from city </em></font><code>0</code><font papago-translate="splited"><em papago-id="19" papago-translate="translated"> to city </em></font><code>n - 1</code><font papago-translate="splited"><em papago-id="20" papago-translate="translated">.</em></font></p>

<p>&nbsp;</p>
<p><strong papago-id="31" papago-translate="translated">Example 1:</strong><br>
<img src="https://assets.leetcode.com/uploads/2021/11/29/image-20211129222429-1.png" style="height: 250px; width: 404px;"></p>

<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> n = 5, highways = [[0,1,4],[2,1,3],[1,4,11],[3,2,3],[3,4,2]], discounts = 1
<strong papago-id="0-2">Output:</strong> 9
<strong papago-id="0-4">Explanation:</strong>
Go from 0 to 1 for a cost of 4.
Go from 1 to 4 and use a discount for a cost of 11 / 2 = 5.
The minimum cost to go from 0 to 4 is 4 + 5 = 9.
</pre>

<p><strong papago-id="0" papago-translate="translated">Example 2:</strong><br>
<img src="https://assets.leetcode.com/uploads/2021/11/29/image-20211129222650-4.png" style="width: 284px; height: 250px;"></p>

<pre><strong>Input:</strong> n = 4, highways = [[1,3,17],[1,2,7],[3,2,5],[0,1,6],[3,0,20]], discounts = 20
<strong>Output:</strong> 8
<strong>Explanation:</strong>
Go from 0 to 1 and use a discount for a cost of 6 / 2 = 3.
Go from 1 to 2 and use a discount for a cost of 7 / 2 = 3.
Go from 2 to 3 and use a discount for a cost of 5 / 2 = 2.
The minimum cost to go from 0 to 3 is 3 + 3 + 2 = 8.
</pre>

<p><strong>Example 3:</strong><br>
<img src="https://assets.leetcode.com/uploads/2021/11/29/image-20211129222531-3.png" style="width: 275px; height: 250px;"></p>

<pre><strong>Input:</strong> n = 4, highways = [[0,1,3],[2,3,2]], discounts = 0
<strong>Output:</strong> -1
<strong>Explanation:</strong>
It is impossible to go from 0 to 3 so return -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= highways.length &lt;= 1000</code></li>
	<li><code>highways[i].length == 3</code></li>
	<li><code>0 &lt;= city1<sub>i</sub>, city2<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>city1<sub>i</sub> != city2<sub>i</sub></code></li>
	<li><code>0 &lt;= toll<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= discounts &lt;= 500</code></li>
	<li>There are no duplicate highways.</li>
</ul>
</div>