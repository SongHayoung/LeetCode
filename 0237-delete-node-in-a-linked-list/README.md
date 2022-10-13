<h2><a href="https://leetcode.com/problems/delete-node-in-a-linked-list/">237. Delete Node in a Linked List</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="translated" papago-id="0">There is a singly-linked list </font><code>head</code><font papago-translate="translated" papago-id="1"> and we want to delete a node </font><code>node</code><font papago-translate="translated" papago-id="2"> in it.</font></p>

<p><font papago-translate="cached" papago-id="11">You are given the node to be deleted </font><code>node</code><code>head</code><font papago-translate="cached" papago-id="13">.</font></p>

<p><code>node</code><font papago-translate="cached" papago-id="15"> is not the last node in the linked list.</font></p>

<p papago-id="16" papago-translate="translated">Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:</p>

<ul>
	<li papago-id="17" papago-translate="translated">The value of the given node should not exist in the linked list.</li>
	<li papago-id="18" papago-translate="translated">The number of nodes in the linked list should decrease by one.</li>
	<li><font papago-translate="cached" papago-id="19">All the values before </font><code>node</code><font papago-translate="cached" papago-id="20"> should be in the same order.</font></li>
	<li><font papago-translate="cached" papago-id="21">All the values after </font><code>node</code><font papago-translate="cached" papago-id="22"> should be in the same order.</font></li>
</ul>

<p><strong papago-id="23" papago-translate="translated">Custom testing:</strong></p>

<ul>
	<li><font papago-translate="cached" papago-id="24">For the input, you should provide the entire linked list </font><code>head</code><font papago-translate="cached" papago-id="25"> and the node to be given </font><code>node</code><font papago-translate="cached" papago-id="26">. </font><code>node</code><font papago-translate="cached" papago-id="27"> should not be the last node of the list and should be an actual node in the list.</font></li>
	<li papago-id="28" papago-translate="translated">We will build the linked list and pass the node to your function.</li>
	<li papago-id="29" papago-translate="translated">The output will be the entire list after calling your function.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example" papago-id="30" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/node1.jpg" style="width: 400px; height: 286px;">
<pre><strong>Input:</strong> head = [4,5,1,9], node = 5
<strong>Output:</strong> [4,1,9]
<strong>Explanation: </strong>You are given the second node with value 5, the linked list should become 4 -&gt; 1 -&gt; 9 after calling your function.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/node2.jpg" style="width: 400px; height: 315px;">
<pre><strong>Input:</strong> head = [4,5,1,9], node = 1
<strong>Output:</strong> [4,5,9]
<strong>Explanation: </strong>You are given the third node with value 1, the linked list should become 4 -&gt; 5 -&gt; 9 after calling your function.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><font papago-translate="translated" papago-id="16">The number of the nodes in the given list is in the range </font><code>[2, 1000]</code><font papago-translate="translated" papago-id="17">.</font></li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li>The value of each node in the list is <strong>unique</strong>.</li>
	<li><font papago-translate="translated" papago-id="18">The </font><code>node</code><font papago-translate="cached" papago-id="19"> to be deleted is <strong papago-id="19-1">in the list</strong> and is <strong papago-id="19-3">not a tail</strong> node.</font></li>
</ul>
</div>