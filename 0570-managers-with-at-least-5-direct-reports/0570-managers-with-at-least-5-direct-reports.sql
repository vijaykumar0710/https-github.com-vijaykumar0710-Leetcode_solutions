# Write your MySQL query statement below
WITH cte AS(SELECT e1.id,e1.name,COUNT(e1.id) AS cnt
FROM Employee e1
JOIN Employee e2
ON e1.id=e2.managerId
GROUP BY e1.id
)

SELECT name 
FROM cte
WHERE cnt>=5;