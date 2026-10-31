WITH cte AS(SELECT d.name as Department,e.name as Employee,e.salary as Salary,
DENSE_RANK() OVER(PARTITION BY d.name ORDER BY e.salary DESC) as "dr"
FROM Employee e
JOIN Department d 
ON e.departmentId=d.id)

SELECT Department,Employee,Salary
FROM cte 
WHERE dr<=3
