<h2><a href="https://leetcode.com/problems/design-a-file-sharing-system/">1500. Design a File Sharing System</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="translated" papago-id="0">We will use a file-sharing system to share a very large file which consists of </font><code>m</code><font papago-translate="cached" papago-id="1"> small <b papago-id="1-1">chunks</b> with IDs from </font><code>1</code><font papago-translate="translated" papago-id="2"> to </font><code>m</code><font papago-translate="translated" papago-id="3">.</font></p>

<p papago-id="11" papago-translate="cached">When users join the system, the system should assign <b papago-id="11-1">a unique</b> ID to them. The unique ID should be used <b papago-id="11-3">once</b> for each user, but when a user leaves the system, the ID can be <b papago-id="11-5">reused</b> again.</p>

<p papago-id="12" papago-translate="translated">Users can request a certain chunk of the file, the system should return a list of IDs of all the users who own this chunk. If the user receives a non-empty list of IDs, they receive the requested chunk successfully.</p>

<p><br><font papago-translate="cached" papago-id="13">
Implement the </font><code>FileSharing</code><font papago-translate="cached" papago-id="14"> class:</font></p>

<ul>
	<li><code>FileSharing(int m)</code><font papago-translate="cached" papago-id="15"> Initializes the object with a file of </font><code>m</code><font papago-translate="cached" papago-id="16"> chunks.</font></li>
	<li><code>int join(int[] ownedChunks)</code></li>
	<li><code>void leave(int userID)</code><font papago-translate="cached" papago-id="18">: The user with </font><code>userID</code><font papago-translate="cached" papago-id="19"> will leave the system, you cannot take file chunks from them anymore.</font></li>
	<li><code>int[] request(int userID, int chunkID)</code><font papago-translate="cached" papago-id="20">: The user </font><code>userID</code><font papago-translate="cached" papago-id="21"> requested the file chunk with </font><code>chunkID</code><font papago-translate="cached" papago-id="22">. Return a list of the IDs of all users that own this chunk sorted in ascending order.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong papago-id="23" papago-translate="translated">Example:</strong></p>

<pre papago-id="24" papago-translate="cached"><b papago-id="24-0">Input:</b>
["FileSharing","join","join","join","request","request","leave","request","leave","join"]
[[4],[[1,2]],[[2,3]],[[4]],[1,3],[2,2],[1],[2,1],[2],[[]]]
<b papago-id="24-2">Output:</b>
[null,1,2,3,[2],[1,2],null,[],null,1]
<b papago-id="24-4">Explanation:</b>
FileSharing fileSharing = new FileSharing(4); // We use the system to share a file of 4 chunks.

fileSharing.join([1, 2]);    // A user who has chunks [1,2] joined the system, assign id = 1 to them and return 1.

fileSharing.join([2, 3]);    // A user who has chunks [2,3] joined the system, assign id = 2 to them and return 2.

fileSharing.join([4]);       // A user who has chunk [4] joined the system, assign id = 3 to them and return 3.

fileSharing.request(1, 3);   // The user with id = 1 requested the third file chunk, as only the user with id = 2 has the file, return [2] . Notice that user 1 now has chunks [1,2,3].

fileSharing.request(2, 2);   // The user with id = 2 requested the second file chunk, users with ids [1,2] have this chunk, thus we return [1,2].

fileSharing.leave(1);        // The user with id = 1 left the system, all the file chunks with them are no longer available for other users.

fileSharing.request(2, 1);   // The user with id = 2 requested the first file chunk, no one in the system has this chunk, we return empty list [].

fileSharing.leave(2);        // The user with id = 2 left the system.

fileSharing.join([]);        // A user who doesn't have any chunks joined the system, assign id = 1 to them and return 1. Notice that ids 1 and 2 are free and we can reuse them.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= ownedChunks.length &lt;= min(100, m)</code></li>
	<li><code>1 &lt;= ownedChunks[i] &lt;= m</code></li>
	<li><font papago-translate="translated" papago-id="14">Values of </font><code>ownedChunks</code><font papago-translate="translated" papago-id="15"> are unique.</font></li>
	<li><code>1 &lt;= chunkID &lt;= m</code></li>
	<li><code>userID</code><font papago-translate="cached" papago-id="16"> is guaranteed to be a user in the system if you <strong papago-id="16-1">assign</strong> the IDs <strong papago-id="16-3">correctly</strong>.</font></li>
	<li><font papago-translate="translated" papago-id="17">At most </font><code>10<sup>4</sup></code><font papago-translate="translated" papago-id="18"> calls will be made to </font><code>join</code><font papago-translate="translated" papago-id="19">, </font><code>leave</code><font papago-translate="translated" papago-id="20"> and </font><code>request</code><font papago-translate="translated" papago-id="21">.</font></li>
	<li><font papago-translate="translated" papago-id="22">Each call to </font><code>leave</code><font papago-translate="translated" papago-id="23"> will have a matching call for </font><code>join</code><font papago-translate="translated" papago-id="24">.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow-up:</strong></p>

<ul>
	<li>What happens if the system identifies the user by their IP address instead of their unique ID and users disconnect and connect from the system with the same IP?</li>
	<li>If the users in the system join and leave the system frequently without requesting any chunks, will your solution still be efficient?</li>
	<li>If all users join the system one time, request all files, and then leave, will your solution still be efficient?</li>
	<li><font papago-translate="translated" papago-id="25">If the system will be used to share </font><code>n</code><font papago-translate="translated" papago-id="26"> files where the </font><code>ith</code><font papago-translate="translated" papago-id="27"> file consists of </font><code>m[i]</code><font papago-translate="translated" papago-id="28">, what are the changes you have to make?</font></li>
</ul>
</div>