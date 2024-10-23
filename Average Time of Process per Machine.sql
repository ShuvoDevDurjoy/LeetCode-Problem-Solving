# Write your MySQL query statement below
SELECT machine_id, ROUND(dur/counts,3) as processing_time FROM (
    SELECT machine_id, process_id, sum(duration) as dur,count(machine_id) as counts from (
    SELECT 
    machine_id, 
    process_id, 
    ROUND(
        MAX(CASE WHEN activity_type = 'end' THEN timestamp END) - 
        MIN(CASE WHEN activity_type = 'start' THEN timestamp END),3
    )AS duration
FROM 
    Activity
GROUP BY 
    machine_id, 
    process_id
) as t GROUP BY machine_id

) AS tt;
