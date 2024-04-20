<h2><a href="https://leetcode.com/problems/parallel-courses-ii/">1494. Parallel Courses II</a></h2><h3>Hard</h3><hr><div><p><font papago-translate="splitted">You are given an integer </font><code>n</code><font papago-translate="splitted">, which indicates that there are </font><code>n</code><font papago-translate="splitted"> courses labeled from </font><code>1</code><font papago-translate="splitted"> to </font><code>n</code><font papago-translate="splitted">. You are also given an array </font><code>relations</code><font papago-translate="splitted"> where </font><code>relations[i] = [prevCourse<sub>i</sub>, nextCourse<sub>i</sub>]</code><font papago-translate="splitted">, representing a prerequisite relationship between course </font><code>prevCourse<sub>i</sub></code><font papago-translate="splitted"> and course </font><code>nextCourse<sub>i</sub></code><font papago-translate="splitted">: course </font><code>prevCourse<sub>i</sub></code><font papago-translate="splitted"> has to be taken before course </font><code>nextCourse<sub>i</sub></code><font papago-translate="splitted">. Also, you are given the integer </font><code>k</code><font papago-translate="splitted">.</font></p>

<p> <code>k</code></p>

<p>Return <em>the <strong>minimum</strong> number of semesters needed to take all courses</em>. The testcases will be generated such that it is possible to take every course.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/05/22/leetcode_parallel_courses_1.png" style="width: 269px; height: 147px;">
<pre><strong>Input:</strong> n = 4, relations = [[2,1],[3,1],[1,4]], k = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> The figure above represents the given graph.
In the first semester, you can take courses 2 and 3.
In the second semester, you can take course 1.
In the third semester, you can take course 4.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/05/22/leetcode_parallel_courses_2.png" style="width: 271px; height: 211px;">
<pre><strong>Input:</strong> n = 5, relations = [[2,1],[3,1],[4,1],[1,5]], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> The figure above represents the given graph.
In the first semester, you can only take courses 2 and 3 since you cannot take more than two per semester.
In the second semester, you can take course 4.
In the third semester, you can take course 1.
In the fourth semester, you can take course 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
	<li><code>0 &lt;= relations.length &lt;= n * (n-1) / 2</code></li>
	<li><code>relations[i].length == 2</code></li>
	<li><code>1 &lt;= prevCourse<sub>i</sub>, nextCourse<sub>i</sub> &lt;= n</code></li>
	<li><code>prevCourse<sub>i</sub> != nextCourse<sub>i</sub></code></li>
	<li><font papago-translate="splitted">All the pairs </font><code>[prevCourse<sub>i</sub>, nextCourse<sub>i</sub>]</code></li>
	<li>The given graph is a directed acyclic graph.</li>
</ul>
</div>