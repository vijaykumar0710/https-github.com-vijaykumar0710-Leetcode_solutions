SELECT name as Customers 
FROM Customers WHERE id NOT IN (SELECT c.id 
FROM Customers c
JOIN Orders o
ON c.id=o.customerId )