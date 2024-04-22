<h2><a href="https://leetcode.com/problems/simple-bank-system/">2043. Simple Bank System</a></h2><h3>Medium</h3><hr><div><p><font papago-translate="splitted">You have been tasked with writing a program for a popular bank that will automate all its incoming transactions (transfer, deposit, and withdraw). The bank has </font><code>n</code><font papago-translate="splitted"> accounts numbered from </font><code>1</code><font papago-translate="splitted"> to </font><code>n</code><code>balance</code><font papago-translate="splitted">, with the </font><code>(i + 1)<sup>th</sup></code><font papago-translate="splitted"> account having an initial balance of </font><code>balance[i]</code><font papago-translate="splitted">.</font></p>

<p>Execute all the <strong>valid</strong> transactions. A transaction is <strong>valid</strong> if:</p>

<ul>
	<li><font papago-translate="splitted">The given account number(s) are between </font><code>1</code><font papago-translate="splitted"> and </font><code>n</code><font papago-translate="splitted">, and</font></li>
	<li>The amount of money withdrawn or transferred from is <strong>less than or equal</strong> to the balance of the account.</li>
</ul>

<p><font papago-translate="splitted">Implement the </font><code>Bank</code><font papago-translate="splitted"> class:</font></p>

<ul>
	<li><code>Bank(long[] balance)</code><code>balance</code><font papago-translate="splitted">.</font></li>
	<li><code>boolean transfer(int account1, int account2, long money)</code><font papago-translate="splitted"> Transfers </font><code>money</code><font papago-translate="splitted"> dollars from the account numbered </font><code>account1</code><font papago-translate="splitted"> to the account numbered </font><code>account2</code><font papago-translate="splitted">. Return </font><code>true</code><font papago-translate="splitted"> if the transaction was successful, </font><code>false</code><font papago-translate="splitted"> otherwise.</font></li>
	<li><code>boolean deposit(int account, long money)</code><font papago-translate="splitted"> Deposit </font><code>money</code><font papago-translate="splitted"> dollars into the account numbered </font><code>account</code><font papago-translate="splitted">. Return </font><code>true</code><font papago-translate="splitted"> if the transaction was successful, </font><code>false</code><font papago-translate="splitted"> otherwise.</font></li>
	<li><code>boolean withdraw(int account, long money)</code><font papago-translate="splitted"> Withdraw </font><code>money</code><font papago-translate="splitted"> dollars from the account numbered </font><code>account</code><font papago-translate="splitted">. Return </font><code>true</code><font papago-translate="splitted"> if the transaction was successful, </font><code>false</code><font papago-translate="splitted"> otherwise.</font></li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input</strong>
["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
<strong>Output</strong>
[null, true, true, true, false, false]

<strong>Explanation</strong>
Bank bank = new Bank([10, 100, 20, 50, 30]);
bank.withdraw(3, 10);    // return true, account 3 has a balance of $20, so it is valid to withdraw $10.
                         // Account 3 has $20 - $10 = $10.
bank.transfer(5, 1, 20); // return true, account 5 has a balance of $30, so it is valid to transfer $20.
                         // Account 5 has $30 - $20 = $10, and account 1 has $10 + $20 = $30.
bank.deposit(5, 20);     // return true, it is valid to deposit $20 to account 5.
                         // Account 5 has $10 + $20 = $30.
bank.transfer(3, 4, 15); // return false, the current balance of account 3 is $10,
                         // so it is invalid to transfer $15 from it.
bank.withdraw(10, 50);   // return false, it is invalid because account 10 does not exist.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == balance.length</code></li>
	<li><code>1 &lt;= n, account, account1, account2 &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= balance[i], money &lt;= 10<sup>12</sup></code></li>
	<li><font papago-translate="splitted">At most </font><code>10<sup>4</sup></code><font papago-translate="splitted"> calls will be made to <strong>each</strong> function </font><code>transfer</code><font papago-translate="splitted">, </font><code>deposit</code><font papago-translate="splitted">, </font><code>withdraw</code><font papago-translate="splitted">.</font></li>
</ul>
</div>