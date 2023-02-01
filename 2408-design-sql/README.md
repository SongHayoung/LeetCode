<h2><a href="https://leetcode.com/problems/design-sql/">2408. Design SQL</a></h2><h3>Medium</h3><hr><div><p>You are given <code>n</code> tables represented with two arrays <code>names</code> and <code>columns</code>, where <code>names[i]</code> is the name of the <code>i<sup>th</sup></code> table and <code>columns[i]</code> is the number of columns of the <code>i<sup>th</sup></code> table.</p>

<p>You should be able to perform the following <strong>operations</strong>:</p>

<ul>
	<li><strong>Insert</strong> a row in a specific table. Each row you insert has an id. The id is assigned using an auto-increment method where the id of the first inserted row is 1, and the id of each other row inserted into the same table is the id of the last inserted row (even if it was deleted) plus one.</li>
	<li><strong>Delete</strong> a row from a specific table. <strong>Note</strong> that deleting a row does not affect the id of the next inserted row.</li>
	<li><strong>Select</strong> a specific cell from any table and return its value.</li>
</ul>

<p>Implement the <code>SQL</code> class:</p>

<ul>
	<li><code>SQL(String[] names, int[] columns)</code> Creates the <code>n</code> tables.</li>
	<li><code>void insertRow(String name, String[] row)</code> Adds a row to the table <code>name</code>. It is <strong>guaranteed</strong> that the table will exist, and the size of the array <code>row</code> is equal to the number of columns in the table.</li>
	<li><code>void deleteRow(String name, int rowId)</code> Removes the row <code>rowId</code> from the table <code>name</code>. It is <strong>guaranteed</strong> that the table and row will <strong>exist</strong>.</li>
	<li><code>String selectCell(String name, int rowId, int columnId)</code> Returns the value of the cell in the row <code>rowId</code> and the column <code>columnId</code> from the table <code>name</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input</strong>
["SQL", "insertRow", "selectCell", "insertRow", "deleteRow", "selectCell"]
[[["one", "two", "three"], [2, 3, 1]], ["two", ["first", "second", "third"]], ["two", 1, 3], ["two", ["fourth", "fifth", "sixth"]], ["two", 1], ["two", 2, 2]]
<strong>Output</strong>
[null, null, "third", null, null, "fifth"]

<strong>Explanation</strong>
SQL sql = new SQL(["one", "two", "three"], [2, 3, 1]); // creates three tables.
sql.insertRow("two", ["first", "second", "third"]); // adds a row to the table "two". Its id is 1.
sql.selectCell("two", 1, 3); // return "third", finds the value of the third column in the row with id 1 of the table "two".
sql.insertRow("two", ["fourth", "fifth", "sixth"]); // adds another row to the table "two". Its id is 2.
sql.deleteRow("two", 1); // deletes the first row of the table "two". Note that the second row will still have the id 2.
sql.selectCell("two", 2, 2); // return "fifth", finds the value of the second column in the row with id 2 of the table "two".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == names.length == columns.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= names[i].length, row[i].length, name.length &lt;= 20</code></li>
	<li><code>names[i]</code>, <code>row[i]</code>, and <code>name</code> consist of lowercase English letters.</li>
	<li><code>1 &lt;= columns[i] &lt;= 100</code></li>
	<li>All the strings of <code>names</code> are <strong>distinct</strong>.</li>
	<li><code>name</code> exists in the array <code>names</code>.</li>
	<li><code>row.length</code> equals the number of columns in the chosen table.</li>
	<li><code>rowId</code> and <code>columnId</code> will be valid.</li>
	<li>At most <code>250</code> calls will be made to <code>insertRow</code> and <code>deleteRow</code>.</li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>selectCell</code>.</li>
</ul>
</div>