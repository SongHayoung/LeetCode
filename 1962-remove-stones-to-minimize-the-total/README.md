<h2><a href="https://leetcode.com/problems/remove-stones-to-minimize-the-total/">1962. Remove Stones to Minimize the Total</a></h2><h3>Medium</h3><hr><div><p><code>piles</code><font papago-translate="cached" papago-id="12">, where </font><code>piles[i]</code><font papago-translate="cached" papago-id="13"> represents the number of stones in the </font><code>i<sup>th</sup></code><font papago-translate="cached" papago-id="14"> pile, and an integer </font><code>k</code> <code>k</code><font papago-translate="cached" papago-id="16"> times:</font></p>

<ul>
	<li><font papago-translate="cached" papago-id="17">Choose any </font><code>piles[i]</code> <code>floor(piles[i] / 2)</code><font papago-translate="cached" papago-id="19"> stones from it.</font></li>
</ul>

<p papago-id="20" papago-translate="cached"><strong papago-id="20-0">Notice</strong> that you can apply the operation on the <strong papago-id="20-2">same</strong> pile more than once.</p>

<p><code>k</code></p>

<p><code>floor(x)</code><code>x</code><font papago-translate="cached" papago-id="24"> (i.e., rounds </font><code>x</code><font papago-translate="cached" papago-id="25"> down).</font></p>

<p>&nbsp;</p>
<p><strong papago-id="26" papago-translate="translated">Example 1:</strong></p>

<pre papago-id="27" papago-translate="cached"><strong papago-id="27-0">Input:</strong> piles = [5,4,9], k = 2
<strong papago-id="27-2">Output:</strong> 12
<strong papago-id="27-4">Explanation:</strong>&nbsp;Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [5,4,<u papago-id="27-6">5</u>].
- Apply the operation on pile 0. The resulting piles are [<u papago-id="27-8">3</u>,4,5].
The total number of stones in [3,4,5] is 12.
</pre>

<p><strong papago-id="0" papago-translate="translated">Example 2:</strong></p>

<pre papago-id="0" papago-translate="cached"><strong papago-id="0-0">Input:</strong> piles = [4,3,6,7], k = 3
<strong papago-id="0-2">Output:</strong> 12
<strong papago-id="0-4">Explanation:</strong>&nbsp;Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [4,3,<u papago-id="0-6">3</u>,7].
- Apply the operation on pile 3. The resulting piles are [4,3,3,<u papago-id="0-8">4</u>].
- Apply the operation on pile 0. The resulting piles are [<u papago-id="0-10">2</u>,3,3,4].
The total number of stones in [2,3,3,4] is 12.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= piles.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= piles[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>
</div>