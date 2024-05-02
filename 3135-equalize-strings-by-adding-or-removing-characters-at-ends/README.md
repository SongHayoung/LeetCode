<h2><a href="https://leetcode.com/problems/equalize-strings-by-adding-or-removing-characters-at-ends/">3135. Equalize Strings by Adding or Removing Characters at Ends</a></h2><h3>Medium</h3><hr><div><p>Given two strings <code>initial</code> and <code>target</code>, your task is to modify <code>initial</code> by performing a series of operations to make it equal to <code>target</code>.</p>

<p>In one operation, you can add or remove <strong>one character</strong> only at the <em>beginning</em> or the <em>end</em> of the string <code>initial</code>.</p>

<p>Return the <strong>minimum</strong> number of operations required to <em>transform</em> <code>initial</code> into <code>target</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">initial = "abcde", target = "cdef"</span></p>

<p><strong>Output:</strong> 3</p>

<p><strong>Explanation:</strong></p>

<p>Remove <code>'a'</code> and <code>'b'</code> from the beginning of <code>initial</code>, then add <code>'f'</code> to the end.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">initial = "axxy", target = "yabx"</span></p>

<p><strong>Output:</strong> 6</p>

<p><strong>Explanation:</strong></p>

<table border="1">
	<tbody>
		<tr>
			<th>Operation</th>
			<th>Resulting String</th>
		</tr>
		<tr>
			<td>Add <code>'y'</code> to the beginning</td>
			<td><code>"yaxxy"</code></td>
		</tr>
		<tr>
			<td>Remove from end</td>
			<td><code>"yaxx"</code></td>
		</tr>
		<tr>
			<td>Remove from end</td>
			<td><code>"yax"</code></td>
		</tr>
		<tr>
			<td>Remove from end</td>
			<td><code>"ya"</code></td>
		</tr>
		<tr>
			<td>Add <code>'b'</code> to the end</td>
			<td><code>"yab"</code></td>
		</tr>
		<tr>
			<td>Add <code>'x'</code> to the end</td>
			<td><code>"yabx"</code></td>
		</tr>
	</tbody>
</table>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">initial = "xyz", target = "xyz"</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>No operations are needed as the strings are already equal.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= initial.length, target.length &lt;= 1000</code></li>
	<li><code>initial</code> and <code>target</code> consist only of lowercase English letters.</li>
</ul>
</div>