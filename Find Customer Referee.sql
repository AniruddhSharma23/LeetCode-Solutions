SELECT name
FROM Customer
WHERE IFNULL(referee_id,0)<>2;

SELECT name
FROM Customer
WHERE (referee_id != 2) or (referee_id IS NULL);