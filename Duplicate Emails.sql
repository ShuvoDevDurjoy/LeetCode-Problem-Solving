# Write your MySQL query statement below
SELECT email as Email FROM (SELECT id,email,count(email) as counts FROM Person GROUP BY email) as t where counts > 1 ;
