
SELECT firstname, lastname, city, state 
FROM Person
LEFT JOIN Address
ON Person.personid = Address.personId
