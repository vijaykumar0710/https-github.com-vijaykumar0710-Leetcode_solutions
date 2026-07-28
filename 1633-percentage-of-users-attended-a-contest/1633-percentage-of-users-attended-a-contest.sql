SELECT r.contest_id,ROUND((COUNT(*)*100)/(SELECT COUNT(*) FROM Users),2) AS percentage
FROM Register r
GROUP BY r.contest_id
ORDER BY percentage desc,r.contest_id