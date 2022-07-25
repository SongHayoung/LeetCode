<h2><a href="https://leetcode.com/problems/operations-on-tree/">1993. Operations on Tree</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="cached" papago-id="15">You are given a tree with </font><code>n</code><font papago-translate="cached" papago-id="16"> nodes numbered from </font><code>0</code><font papago-translate="cached" papago-id="17"> to </font><code>n - 1</code><font papago-translate="cached" papago-id="18"> in the form of a parent array </font><code>parent</code><font papago-translate="cached" papago-id="19"> where </font><code>parent[i]</code><font papago-translate="cached" papago-id="20"> is the parent of the </font><code>i<sup>th</sup></code><font papago-translate="cached" papago-id="21"> node. The root of the tree is node </font><code>0</code><font papago-translate="cached" papago-id="22">, so </font><code>parent[0] = -1</code><font papago-translate="cached" papago-id="23"> since it has no parent. You want to design a data structure that allows users to lock, unlock, and upgrade nodes in the tree.</font></p>

<p papago-id="24" papago-translate="translated">The data structure should support the following functions:</p>

<ul>
	<li papago-id="25" papago-translate="cached"><strong papago-id="25-0">Lock:</strong> <strong papago-id="25-2">Locks</strong> the given node for the given user and prevents other users from locking the same node. You may only lock a node using this function if the node is unlocked.</li>
	<li papago-id="26" papago-translate="cached"><strong papago-id="26-0">Unlock: Unlocks</strong> the given node for the given user. You may only unlock a node using this function if it is currently locked by the same user.</li>
	<li><ul>
		<li papago-id="27" papago-translate="translated">The node is unlocked,</li>
		<li papago-id="28" papago-translate="cached">It has at least one locked descendant (by <strong papago-id="28-1">any</strong> user), and</li>
		<li papago-id="29" papago-translate="translated">It does not have any locked ancestors.</li>
	</ul>
	</li>
</ul>

<p><font papago-translate="cached" papago-id="31">Implement the </font><code>LockingTree</code><font papago-translate="cached" papago-id="32"> class:</font></p>

<ul>
	<li><code>LockingTree(int[] parent)</code><font papago-translate="cached" papago-id="33"> initializes the data structure with the parent array.</font></li>
	<li><code>lock(int num, int user)</code><font papago-translate="translated" papago-id="13"> returns </font><code>true</code><font papago-translate="translated" papago-id="14"> if it is possible for the user with id </font><code>user</code><font papago-translate="translated" papago-id="15"> to lock the node </font><code>num</code><font papago-translate="translated" papago-id="16">, or </font><code>false</code><font papago-translate="translated" papago-id="17"> otherwise. If it is possible, the node </font><code>num</code><font papago-translate="cached" papago-id="18"> will become<strong papago-id="18-1"> locked</strong> by the user with id </font><code>user</code><font papago-translate="translated" papago-id="19">.</font></li>
	<li><code>unlock(int num, int user)</code><font papago-translate="translated" papago-id="20"> returns </font><code>true</code><font papago-translate="translated" papago-id="21"> if it is possible for the user with id </font><code>user</code><font papago-translate="translated" papago-id="22"> to unlock the node </font><code>num</code><font papago-translate="translated" papago-id="23">, or </font><code>false</code><font papago-translate="translated" papago-id="24"> otherwise. If it is possible, the node </font><code>num</code><font papago-translate="cached" papago-id="25"> will become <strong papago-id="25-1">unlocked</strong>.</font></li>
	<li><code>upgrade(int num, int user)</code><font papago-translate="translated" papago-id="26"> returns </font><code>true</code><font papago-translate="translated" papago-id="27"> if it is possible for the user with id </font><code>user</code><font papago-translate="translated" papago-id="28"> to upgrade the node </font><code>num</code><font papago-translate="translated" papago-id="29">, or </font><code>false</code><font papago-translate="translated" papago-id="30"> otherwise. If it is possible, the node </font><code>num</code><font papago-translate="cached" papago-id="31"> will be <strong papago-id="31-1">upgraded</strong>.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/29/untitled.png" style="width: 375px; height: 246px;">
<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input</strong>
["LockingTree", "lock", "unlock", "unlock", "lock", "upgrade", "lock"]
[[[-1, 0, 0, 1, 1, 2, 2]], [2, 2], [2, 3], [2, 2], [4, 5], [0, 1], [0, 1]]
<strong papago-id="0-2">Output</strong>
[null, true, false, true, true, true, false]

<strong papago-id="0-4">Explanation</strong>
LockingTree lockingTree = new LockingTree([-1, 0, 0, 1, 1, 2, 2]);
lockingTree.lock(2, 2);    // return true because node 2 is unlocked.
                           // Node 2 will now be locked by user 2.
lockingTree.unlock(2, 3);  // return false because user 3 cannot unlock a node locked by user 2.
lockingTree.unlock(2, 2);  // return true because node 2 was previously locked by user 2.
                           // Node 2 will now be unlocked.
lockingTree.lock(4, 5);    // return true because node 4 is unlocked.
                           // Node 4 will now be locked by user 5.
lockingTree.upgrade(0, 1); // return true because node 0 is unlocked and has at least one locked descendant (node 4).
                           // Node 0 will now be locked by user 1 and node 4 will now be unlocked.
lockingTree.lock(0, 1);    // return false because node 0 is already locked.
</pre>

<p>&nbsp;</p>
<p><strong papago-id="0" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>n == parent.length</code></li>
	<li><code>2 &lt;= n &lt;= 2000</code></li>
	<li><code>0 &lt;= parent[i] &lt;= n - 1</code><font papago-translate="translated" papago-id="32"> for </font><code>i != 0</code></li>
	<li><code>parent[0] == -1</code></li>
	<li><code>0 &lt;= num &lt;= n - 1</code></li>
	<li><code>1 &lt;= user &lt;= 10<sup>4</sup></code></li>
	<li><code>parent</code><font papago-translate="translated" papago-id="33"> represents a valid tree.</font></li>
	<li><font papago-translate="translated" papago-id="34">At most </font><code>2000</code><font papago-translate="cached" papago-id="35"> calls <strong papago-id="35-1">in total</strong> will be made to </font><code>lock</code><font papago-translate="translated" papago-id="36">, </font><code>unlock</code><font papago-translate="translated" papago-id="37">, and </font><code>upgrade</code><font papago-translate="translated" papago-id="38">.</font></li>
</ul>
</div>