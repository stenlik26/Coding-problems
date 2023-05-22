
SELECT a.id
From Weather A, Weather B
WHERE A.recordDate = DATEADD(day, 1, B.recorddate) AND a.temperature > b.temperature
