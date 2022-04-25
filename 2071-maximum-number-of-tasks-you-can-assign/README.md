<h2><a href="https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/">2071. Maximum Number of Tasks You Can Assign</a></h2><h3>Hard</h3><hr><div><p><font papago-translate="cached" papago-id="0">You have </font><code>n</code><font papago-translate="cached" papago-id="1"> tasks and </font><code>m</code><code>tasks</code><font papago-translate="cached" papago-id="3">, with the </font><code>i<sup>th</sup></code><font papago-translate="cached" papago-id="4"> task requiring </font><code>tasks[i]</code><code>workers</code><font papago-translate="cached" papago-id="6">, with the </font><code>j<sup>th</sup></code><font papago-translate="cached" papago-id="7"> worker having </font><code>workers[j]</code><code>workers[j] &gt;= tasks[i]</code><font papago-translate="cached" papago-id="9">).</font></p>

<p><font papago-translate="cached" papago-id="10">Additionally, you have </font><code>pills</code><code>strength</code></p>

<p><code>tasks</code><font papago-translate="cached" papago-id="14"> and </font><code>workers</code><font papago-translate="cached" papago-id="15"> and the integers </font><code>pills</code><font papago-translate="cached" papago-id="16"> and </font><code>strength</code></p>

<p>&nbsp;</p>
<p><strong papago-id="29" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="30" papago-translate="cached"><strong papago-id="30-0">Input:</strong> tasks = [<u papago-id="30-2"><strong papago-id="30-2-0">3</strong></u>,<u papago-id="30-4"><strong papago-id="30-4-0">2</strong></u>,<u papago-id="30-6"><strong papago-id="30-6-0">1</strong></u>], workers = [<u papago-id="30-8"><strong papago-id="30-8-0">0</strong></u>,<u papago-id="30-10"><strong papago-id="30-10-0">3</strong></u>,<u papago-id="30-12"><strong papago-id="30-12-0">3</strong></u>], pills = 1, strength = 1
<strong papago-id="30-14">Output:</strong> 3
<strong papago-id="30-16">Explanation:</strong>
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 2 (0 + 1 &gt;= 1)
- Assign worker 1 to task 1 (3 &gt;= 2)
- Assign worker 2 to task 0 (3 &gt;= 3)
</pre>

<p><strong papago-id="31" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="32" papago-translate="cached"><strong papago-id="32-0">Input:</strong> tasks = [<u papago-id="32-2"><strong papago-id="32-2-0">5</strong></u>,4], workers = [<u papago-id="32-4"><strong papago-id="32-4-0">0</strong></u>,0,0], pills = 1, strength = 5
<strong papago-id="32-6">Output:</strong> 1
<strong papago-id="32-8">Explanation:</strong>
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 0 (0 + 5 &gt;= 5)
</pre>

<p><strong papago-id="33" papago-translate="translated">Example 3:</strong></p>

<pre papago-id="34" papago-translate="cached"><strong papago-id="34-0">Input:</strong> tasks = [<u papago-id="34-2"><strong papago-id="34-2-0">10</strong></u>,<u papago-id="34-4"><strong papago-id="34-4-0">15</strong></u>,30], workers = [<u papago-id="34-6"><strong papago-id="34-6-0">0</strong></u>,<u papago-id="34-8"><strong papago-id="34-8-0">10</strong></u>,10,10,10], pills = 3, strength = 10
<strong papago-id="34-10">Output:</strong> 2
<strong papago-id="34-12">Explanation:</strong>
We can assign the magical pills and tasks as follows:
- Give the magical pill to worker 0 and worker 1.
- Assign worker 0 to task 0 (0 + 10 &gt;= 10)
- Assign worker 1 to task 1 (10 + 10 &gt;= 15)
The last pill is not given because it will not make any worker strong enough for the last task.
</pre>

<p>&nbsp;</p>
<p><strong papago-id="35" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>n == tasks.length</code></li>
	<li><code>m == workers.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= pills &lt;= m</code></li>
	<li><code>0 &lt;= tasks[i], workers[j], strength &lt;= 10<sup>9</sup></code></li>
</ul>
</div>