<h2><a href="https://leetcode.com/problems/apply-discount-every-n-orders/">1357. Apply Discount Every n Orders</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">There is a supermarket that is frequented by many customers. The products sold at the supermarket are represented as two parallel integer arrays </font><code>products</code><font papago-translate="splitted"> and </font><code>prices</code><font papago-translate="splitted">, where the </font><code>i<sup>th</sup></code><font papago-translate="splitted"> product has an ID of </font><code>products[i]</code><font papago-translate="splitted"> and a price of </font><code>prices[i]</code><font papago-translate="splitted">.</font></p>

<p><font papago-translate="splitted">When a customer is paying, their bill is represented as two parallel integer arrays </font><code>product</code><font papago-translate="splitted"> and </font><code>amount</code><font papago-translate="splitted">, where the </font><code>j<sup>th</sup></code><font papago-translate="splitted"> product they purchased has an ID of </font><code>product[j]</code><font papago-translate="splitted">, and </font><code>amount[j]</code><font papago-translate="splitted"> is how much of the product they bought. Their subtotal is calculated as the sum of each </font><code>amount[j] * (price of the j<sup>th</sup> product)</code><font papago-translate="splitted">.</font></p>

<p><font papago-translate="splitted">The supermarket decided to have a sale. Every </font><code>n<sup>th</sup></code><code>discount</code><font papago-translate="splitted">, where they will be given </font><code>discount</code><font papago-translate="splitted"> percent off their subtotal. More formally, if their subtotal is </font><code>bill</code><font papago-translate="splitted">, then they would actually pay </font><code>bill * ((100 - discount) / 100)</code><font papago-translate="splitted">.</font></p>

<p><font papago-translate="splitted">Implement the </font><code>Cashier</code><font papago-translate="splitted"> class:</font></p>

<ul>
	<li><code>Cashier(int n, int discount, int[] products, int[] prices)</code><font papago-translate="splitted"> Initializes the object with </font><code>n</code><font papago-translate="splitted">, the </font><code>discount</code><font papago-translate="splitted">, and the </font><code>products</code><font papago-translate="splitted"> and their </font><code>prices</code><font papago-translate="splitted">.</font></li>
	<li><code>double getBill(int[] product, int[] amount)</code><font papago-translate="splitted"> Returns the final total of the bill with the discount applied (if any). Answers within </font><code>10<sup>-5</sup></code><font papago-translate="splitted"> of the actual value will be accepted.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input</strong>
["Cashier","getBill","getBill","getBill","getBill","getBill","getBill","getBill"]
[[3,50,[1,2,3,4,5,6,7],[100,200,300,400,300,200,100]],[[1,2],[1,2]],[[3,7],[10,10]],[[1,2,3,4,5,6,7],[1,1,1,1,1,1,1]],[[4],[10]],[[7,3],[10,10]],[[7,5,3,1,6,4,2],[10,10,10,9,9,9,7]],[[2,3,5],[5,3,2]]]
<strong>Output</strong>
[null,500.0,4000.0,800.0,4000.0,4000.0,7350.0,2500.0]
<strong>Explanation</strong>
Cashier cashier = new Cashier(3,50,[1,2,3,4,5,6,7],[100,200,300,400,300,200,100]);
cashier.getBill([1,2],[1,2]);                        // return 500.0. 1<sup>st</sup> customer, no discount.
                                                     // bill = 1 * 100 + 2 * 200 = 500.
cashier.getBill([3,7],[10,10]);                      // return 4000.0. 2<sup>nd</sup> customer, no discount.
                                                     // bill = 10 * 300 + 10 * 100 = 4000.
cashier.getBill([1,2,3,4,5,6,7],[1,1,1,1,1,1,1]);    // return 800.0. 3<sup>rd</sup> customer, 50% discount.
                                                     // Original bill = 1600
                                                     // Actual bill = 1600 * ((100 - 50) / 100) = 800.
cashier.getBill([4],[10]);                           // return 4000.0. 4<sup>th</sup> customer, no discount.
cashier.getBill([7,3],[10,10]);                      // return 4000.0. 5<sup>th</sup> customer, no discount.
cashier.getBill([7,5,3,1,6,4,2],[10,10,10,9,9,9,7]); // return 7350.0. 6<sup>th</sup> customer, 50% discount.
                                                     // Original bill = 14700, but with
                                                     // Actual bill = 14700 * ((100 - 50) / 100) = 7350.
cashier.getBill([2,3,5],[5,3,2]);                    // return 2500.0.  7<sup>th</sup> customer, no discount.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= discount &lt;= 100</code></li>
	<li><code>1 &lt;= products.length &lt;= 200</code></li>
	<li><code>prices.length == products.length</code></li>
	<li><code>1 &lt;= products[i] &lt;= 200</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 1000</code></li>
	<li><font papago-translate="splitted">The elements in </font><code>products</code><font papago-translate="splitted"> are <strong>unique</strong>.</font></li>
	<li><code>1 &lt;= product.length &lt;= products.length</code></li>
	<li><code>amount.length == product.length</code></li>
	<li><code>product[j]</code><font papago-translate="splitted"> exists in </font><code>products</code><font papago-translate="splitted">.</font></li>
	<li><code>1 &lt;= amount[j] &lt;= 1000</code></li>
	<li><font papago-translate="splitted">The elements of </font><code>product</code><font papago-translate="splitted"> are <strong>unique</strong>.</font></li>
	<li><font papago-translate="splitted">At most </font><code>1000</code><font papago-translate="splitted"> calls will be made to </font><code>getBill</code><font papago-translate="splitted">.</font></li>
	<li><font papago-translate="splitted">Answers within </font><code>10<sup>-5</sup></code><font papago-translate="splitted"> of the actual value will be accepted.</font></li>
</ul>
</div>