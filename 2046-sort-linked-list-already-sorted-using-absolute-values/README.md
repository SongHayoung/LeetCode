<h2><a href="https://leetcode.com/problems/sort-linked-list-already-sorted-using-absolute-values/">2046. Sort Linked List Already Sorted Using Absolute Values</a></h2><h3>Medium</h3><hr><div><font papago-translate="cached" papago-id="17">Given the </font><code>head</code><p>&nbsp;</p>
<p><strong papago-id="15" papago-translate="translated">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2021/10/17/image-20211017201240-3.png" style="width: 621px; height: 250px;">
<pre papago-id="16" papago-translate="cached"><strong papago-id="16-0">Input:</strong> head = [0,2,-5,5,10,-10]
<strong papago-id="16-2">Output:</strong> [-10,-5,0,2,5,10]
<strong papago-id="16-4">Explanation:</strong>
The list sorted in non-descending order using the absolute values of the nodes is [0,2,-5,5,10,-10].
The list sorted in non-descending order using the actual values is [-10,-5,0,2,5,10].
</pre>

<p><strong papago-id="0" papago-translate="translated">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2021/10/17/image-20211017201318-4.png" style="width: 338px; height: 250px;">
<pre><strong>Input:</strong> head = [0,1,2]
<strong>Output:</strong> [0,1,2]
<strong>Explanation:</strong>
The linked list is already sorted in non-decreasing order.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = [1]
<strong>Output:</strong> [1]
<strong>Explanation:</strong>
The linked list is already sorted in non-decreasing order.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><font papago-translate="translated" papago-id="0">The number of nodes in the list is the range </font><code>[1, 10<sup>5</sup>]</code><font papago-translate="translated" papago-id="1">.</font></li>
	<li><code>-5000 &lt;= Node.val &lt;= 5000</code></li>
	<li><code>head</code><font papago-translate="translated" papago-id="2"> is sorted in non-decreasing order using the absolute value of its nodes.</font></li>
</ul>

<p>&nbsp;</p>
<font papago-translate="splited"><strong papago-id="7" papago-translate="translated">Follow up:</strong></font>
<ul>
	<li><font papago-translate="translated" papago-id="3">Can you think of a solution with </font><code>O(n)</code><font papago-translate="translated" papago-id="4"> time complexity?</font></li>
</ul>
</div>