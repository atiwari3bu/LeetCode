# Write your MySQL query statement below
SELECT 
    g2.Id
FROM
    Weather g1
        INNER JOIN
    Weather g2 ON DATEDIFF(g2.RecordDate,g1.RecordDate)=1 
WHERE
    g2.Temperature>g1.Temperature    
