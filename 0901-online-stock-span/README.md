<h2><a href="https://leetcode.com/problems/online-stock-span/">901. Online Stock Span</a></h2><h3>Medium</h3><hr><div><p>Design an algorithm that collects daily price quotes for some stock and returns <strong>the span</strong> of that stock's price for the current day.</p>

<p>The <strong>span</strong> of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.</p>

<ul>
	<li><font papago-translate="splitted">For example, if the prices of the stock in the last four days is </font><code>[7,2,1,2]</code><font papago-translate="splitted"> and the price of the stock today is </font><code>2</code><font papago-translate="splitted">, then the span of today is </font><code>4</code><font papago-translate="splitted"> because starting from today, the price of the stock was less than or equal </font><code>2</code><font papago-translate="splitted"> for </font><code>4</code><font papago-translate="splitted"> consecutive days.</font></li>
	<li><font papago-translate="splitted">Also, if the prices of the stock in the last four days is </font><code>[7,34,1,2]</code><font papago-translate="splitted"> and the price of the stock today is </font><code>8</code><font papago-translate="splitted">, then the span of today is </font><code>3</code><font papago-translate="splitted"> because starting from today, the price of the stock was less than or equal </font><code>8</code><font papago-translate="splitted"> for </font><code>3</code><font papago-translate="splitted"> consecutive days.</font></li>
</ul>

<p><font papago-translate="splitted">Implement the </font><code>StockSpanner</code><font papago-translate="splitted"> class:</font></p>

<ul>
	<li><code>StockSpanner()</code><font papago-translate="splitted"> Initializes the object of the class.</font></li>
	<li><code>int next(int price)</code><code>price</code><font papago-translate="splitted">.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input</strong>
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
<strong>Output</strong>
[null, 1, 1, 1, 2, 1, 4, 6]

<strong>Explanation</strong>
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= price &lt;= 10<sup>5</sup></code></li>
	<li><font papago-translate="splitted">At most </font><code>10<sup>4</sup></code><font papago-translate="splitted"> calls will be made to </font><code>next</code><font papago-translate="splitted">.</font></li>
</ul>
</div>