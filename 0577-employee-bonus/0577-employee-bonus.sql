SELECT e.name,b.bonus
FROM Employee e
LEFT JOIN Bonus b
ON e.empId=b.empId
HAVING b.bonus<1000 || b.bonus IS NULL