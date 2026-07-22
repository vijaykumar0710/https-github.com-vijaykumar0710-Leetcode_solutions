WITH cte AS(SELECT e.name,b.bonus
FROM Employee e
LEFT JOIN Bonus b
ON e.empId=b.empId)

SELECT name,bonus
FROM cte 
HAVING bonus<1000 || bonus IS NULL