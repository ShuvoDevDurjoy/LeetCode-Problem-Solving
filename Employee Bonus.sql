SELECT name, bonus
FROM (
    SELECT name, bonus
    FROM Employee
    LEFT JOIN Bonus ON Employee.empId = Bonus.empId
) AS t
WHERE t.bonus IS NULL OR t.bonus < 1000;
