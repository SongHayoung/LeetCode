<h2><a href="https://leetcode.com/problems/maximum-number-of-books-you-can-take/">2355. Maximum Number of Books You Can Take</a></h2><h3>Hard</h3><hr><div><p><code>books</code><font papago-translate="cached" papago-id="1"> of length </font><code>n</code><font papago-translate="cached" papago-id="2"> where </font><code>books[i]</code><font papago-translate="cached" papago-id="3"> denotes the number of books on the </font><code>i<sup>th</sup></code><font papago-translate="cached" papago-id="4"> shelf of a bookshelf.</font></p>

<p><code>l</code><font papago-translate="cached" papago-id="6"> to </font><code>r</code><font papago-translate="cached" papago-id="7"> where </font><code>0 &lt;= l &lt;= r &lt; n</code><font papago-translate="cached" papago-id="8">. For each index </font><code>i</code><font papago-translate="cached" papago-id="9"> in the range </font><code>l &lt;= i &lt; r</code><code>i</code><font papago-translate="cached" papago-id="11"> than shelf </font><code>i + 1</code><font papago-translate="cached" papago-id="12">.</font></p>

<p papago-id="24" papago-translate="cached">Return <em papago-id="24-1">the <strong papago-id="24-1-1">maximum</strong> number of books you can take from the bookshelf.</em></p>

<p>&nbsp;</p>
<p><strong papago-id="25" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="26" papago-translate="cached"><strong papago-id="26-0">Input:</strong> books = [8,5,2,7,9]
<strong papago-id="26-2">Output:</strong> 19
<strong papago-id="26-4">Explanation:</strong>
- Take 1 book from shelf 1.
- Take 2 books from shelf 2.
- Take 7 books from shelf 3.
- Take 9 books from shelf 4.
You have taken 19 books, so return 19.
It can be proven that 19 is the maximum number of books you can take.
</pre>

<p><strong papago-id="27" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="28" papago-translate="cached"><strong papago-id="28-0">Input:</strong> books = [7,0,3,4,5]
<strong papago-id="28-2">Output:</strong> 12
<strong papago-id="28-4">Explanation:</strong>
- Take 3 books from shelf 2.
- Take 4 books from shelf 3.
- Take 5 books from shelf 4.
You have taken 12 books so return 12.
It can be proven that 12 is the maximum number of books you can take.
</pre>

<p><strong papago-id="29" papago-translate="translated">Example 3:</strong></p>

<pre papago-id="30" papago-translate="cached"><strong papago-id="30-0">Input:</strong> books = [8,2,3,7,3,4,0,1,4,3]
<strong papago-id="30-2">Output:</strong> 13
<strong papago-id="30-4">Explanation:</strong>
- Take 1 book from shelf 0.
- Take 2 books from shelf 1.
- Take 3 books from shelf 2.
- Take 7 books from shelf 3.
You have taken 13 books so return 13.
It can be proven that 13 is the maximum number of books you can take.
</pre>

<p>&nbsp;</p>
<p><strong papago-id="31" papago-translate="translated">Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= books.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= books[i] &lt;= 10<sup>5</sup></code></li>
</ul>
</div>