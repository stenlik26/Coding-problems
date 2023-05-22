SELECT name as Customers
FROM Customers
LEFT OUTER JOIN Orders
On Customers.id = Orders.customerId
WHERE Orders.customerid is NULL
