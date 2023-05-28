SELECT t1.name as Employee
FROM Employee t1, Employee t2
WHERE t1.managerid = t2.id AND t1.salary > t2.salary
