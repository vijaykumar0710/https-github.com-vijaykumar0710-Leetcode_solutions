CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    WITH cte AS(
        SELECT salary,DENSE_RANK() over(ORDER BY salary DESC) as dr
        FROM Employee
    )
    SELECT DISTINCT MAX(salary) 
    FROM cte
    WHERE dr=N
  );
END