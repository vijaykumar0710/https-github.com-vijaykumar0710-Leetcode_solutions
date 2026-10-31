SELECT ROUND(COUNT(a2.player_id)/COUNT(a1.player_id),2) as fraction
FROM(
    SELECT player_id,MIN(event_date) as first_login
    FROM Activity 
    GROUP BY player_id
) as a1 
LEFT JOIN Activity a2
ON a1.player_id=a2.player_id
AND DATEDIFF(a2.event_date,a1.first_login)=1