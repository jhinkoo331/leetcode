-- Write your MySQL query statement below

-- perf: 23, 100
-- join == inner join, while we should use left join explicitly
select Person.FirstName, Person.LastName, Address.City, Address.State
from Person left join Address on Person.PersonId = Address.PersonId