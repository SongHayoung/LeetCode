<h2><a href="https://leetcode.com/problems/number-of-orders-in-the-backlog/">1801. Number of Orders in the Backlog</a></h2><h3>Medium</h3><hr><div><p><font papago-id="15" papago-translate="translated">You are given a 2D integer array </font><code>orders</code><font papago-id="16" papago-translate="translated">, where each </font><code>orders[i] = [price<sub>i</sub>, amount<sub>i</sub>, orderType<sub>i</sub>]</code><font papago-id="17" papago-translate="translated"> denotes that </font><code>amount<sub>i</sub></code><font papago-id="18" papago-translate="cached"><sub papago-id="18-0"> </sub>orders have been placed of type </font><code>orderType<sub>i</sub></code><font papago-id="19" papago-translate="translated"> at the price </font><code>price<sub>i</sub></code><font papago-id="20" papago-translate="translated">. The </font><code>orderType<sub>i</sub></code><font papago-id="21" papago-translate="translated"> is:</font></p>

<ul>
	<li><code>0</code><font papago-id="22" papago-translate="translated"> if it is a batch of </font><code>buy</code><font papago-id="23" papago-translate="translated"> orders, or</font></li>
	<li><code>1</code><font papago-id="24" papago-translate="translated"> if it is a batch of </font><code>sell</code><font papago-id="25" papago-translate="translated"> orders.</font></li>
</ul>

<p><font papago-id="26" papago-translate="translated">Note that </font><code>orders[i]</code><font papago-id="27" papago-translate="translated"> represents a batch of </font><code>amount<sub>i</sub></code><font papago-id="28" papago-translate="translated"> independent orders with the same price and order type. All orders represented by </font><code>orders[i]</code><font papago-id="29" papago-translate="translated"> will be placed before all orders represented by </font><code>orders[i+1]</code><font papago-id="30" papago-translate="translated"> for all valid </font><code>i</code><font papago-id="31" papago-translate="translated">.</font></p>

<p papago-id="32" papago-translate="cached">There is a <strong papago-id="32-1">backlog</strong> that consists of orders that have not been executed. The backlog is initially empty. When an order is placed, the following happens:</p>

<ul>
	<li><font papago-id="33" papago-translate="translated">If the order is a </font><code>buy</code><font papago-id="34" papago-translate="translated"> order, you look at the </font><code>sell</code><font papago-id="35" papago-translate="cached"> order with the <strong papago-id="35-1">smallest</strong> price in the backlog. If that </font><code>sell</code><font papago-id="36" papago-translate="cached"> order's price is <strong papago-id="36-1">smaller than or equal to</strong> the current </font><code>buy</code><font papago-id="37" papago-translate="translated"> order's price, they will match and be executed, and that </font><code>sell</code><font papago-id="38" papago-translate="translated"> order will be removed from the backlog. Else, the </font><code>buy</code><font papago-id="39" papago-translate="translated"> order is added to the backlog.</font></li>
	<li><font papago-id="40" papago-translate="translated">Vice versa, if the order is a </font><code>sell</code><font papago-id="41" papago-translate="translated"> order, you look at the </font><code>buy</code><font papago-id="42" papago-translate="cached"> order with the <strong papago-id="42-1">largest</strong> price in the backlog. If that </font><code>buy</code><font papago-id="43" papago-translate="cached"> order's price is <strong papago-id="43-1">larger than or equal to</strong> the current </font><code>sell</code><font papago-id="44" papago-translate="translated"> order's price, they will match and be executed, and that </font><code>buy</code><font papago-id="45" papago-translate="translated"> order will be removed from the backlog. Else, the </font><code>sell</code><font papago-id="46" papago-translate="translated"> order is added to the backlog.</font></li>
</ul>

<p><font papago-id="47" papago-translate="cached">Return <em papago-id="47-1">the total <strong papago-id="47-1-1">amount</strong> of orders in the backlog after placing all the orders from the input</em>. Since this number can be large, return it <strong papago-id="47-3">modulo</strong></font> <code>10<sup>9</sup> + 7</code><font papago-id="48" papago-translate="translated">.</font></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/11/ex1.png" style="width: 450px; height: 479px;">
<pre><strong>Input:</strong> orders = [[10,5,0],[15,2,1],[25,1,1],[30,4,0]]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Here is what happens with the orders:
- 5 orders of type buy with price 10 are placed. There are no sell orders, so the 5 orders are added to the backlog.
- 2 orders of type sell with price 15 are placed. There are no buy orders with prices larger than or equal to 15, so the 2 orders are added to the backlog.
- 1 order of type sell with price 25 is placed. There are no buy orders with prices larger than or equal to 25 in the backlog, so this order is added to the backlog.
- 4 orders of type buy with price 30 are placed. The first 2 orders are matched with the 2 sell orders of the least price, which is 15 and these 2 sell orders are removed from the backlog. The 3<sup>rd</sup> order is matched with the sell order of the least price, which is 25 and this sell order is removed from the backlog. Then, there are no more sell orders in the backlog, so the 4<sup>th</sup> order is added to the backlog.
Finally, the backlog has 5 buy orders with price 10, and 1 buy order with price 30. So the total number of orders in the backlog is 6.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/11/ex2.png" style="width: 450px; height: 584px;">
<pre><strong papago-id="11-0">Input:</strong> orders = [[7,1000000000,1],[15,3,0],[5,999999995,0],[5,1,1]]
<strong papago-id="11-2">Output:</strong> 999999984
<strong papago-id="11-4">Explanation:</strong> Here is what happens with the orders:
- 10<sup papago-id="11-6">9</sup> orders of type sell with price 7 are placed. There are no buy orders, so the 10<sup papago-id="11-8">9</sup> orders are added to the backlog.
- 3 orders of type buy with price 15 are placed. They are matched with the 3 sell orders with the least price which is 7, and those 3 sell orders are removed from the backlog.
- 999999995 orders of type buy with price 5 are placed. The least price of a sell order is 7, so the 999999995 orders are added to the backlog.
- 1 order of type sell with price 5 is placed. It is matched with the buy order of the highest price, which is 5, and that buy order is removed from the backlog.
Finally, the backlog has (1000000000-3) sell orders with price 7, and (999999995-1) buy orders with price 5. So the total number of orders = 1999999991, which is equal to 999999984 % (10<sup papago-id="11-10">9</sup> + 7).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= orders.length &lt;= 10<sup>5</sup></code></li>
	<li><code>orders[i].length == 3</code></li>
	<li><code>1 &lt;= price<sub>i</sub>, amount<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>orderType<sub>i</sub></code><font> is either </font><code>0</code><font> or </font><code>1</code><font>.</font></li>
</ul></div>