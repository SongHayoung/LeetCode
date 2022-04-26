<h2><a href="https://leetcode.com/problems/best-position-for-a-service-centre/">1515. Best Position for a Service Centre</a></h2><h3>Hard</h3><hr><div><p papago-id="11" papago-translate="cached">A delivery company wants to build a new service center in a new city. The company knows the positions of all the customers in this city on a 2D-Map and wants to build the new center in a position such that <strong papago-id="11-1">the sum of the euclidean distances to all customers is minimum</strong>.</p>

<p><font papago-translate="cached" papago-id="0">Given an array </font><code>positions</code><font papago-translate="cached" papago-id="1"> where </font><code>positions[i] = [x<sub>i</sub>, y<sub>i</sub>]</code><font papago-translate="cached" papago-id="2"> is the position of the </font><code>ith</code></p>

<p><font papago-translate="cached" papago-id="4">In other words, you need to choose the position of the service center </font><code>[x<sub>centre</sub>, y<sub>centre</sub>]</code><font papago-translate="cached" papago-id="5"> such that the following formula is minimized:</font></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/25/q4_edited.jpg">
<p><font papago-translate="cached" papago-id="6">Answers within </font><code>10<sup>-5</sup></code><font papago-translate="cached" papago-id="7"> of the actual value will be accepted.</font></p>

<p>&nbsp;</p>
<p><strong papago-id="20" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/25/q4_e1.jpg" style="width: 377px; height: 362px;">
<pre papago-id="21" papago-translate="cached"><strong papago-id="21-0">Input:</strong> positions = [[0,1],[1,0],[1,2],[2,1]]
<strong papago-id="21-2">Output:</strong> 4.00000
<strong papago-id="21-4">Explanation:</strong> As shown, you can see that choosing [x<sub papago-id="21-6">centre</sub>, y<sub papago-id="21-8">centre</sub>] = [1, 1] will make the distance to each customer = 1, the sum of all distances is 4 which is the minimum possible we can achieve.
</pre>

<p><strong papago-id="22" papago-translate="translated">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/25/q4_e3.jpg" style="width: 419px; height: 419px;">
<pre papago-id="23" papago-translate="cached"><strong papago-id="23-0">Input:</strong> positions = [[1,1],[3,3]]
<strong papago-id="23-2">Output:</strong> 2.82843
<strong papago-id="23-4">Explanation:</strong> The minimum possible sum of distances = sqrt(2) + sqrt(2) = 2.82843
</pre>

<p>&nbsp;</p>
<p><strong papago-id="24" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= positions.length &lt;= 50</code></li>
	<li><code>positions[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 100</code></li>
</ul>
</div>