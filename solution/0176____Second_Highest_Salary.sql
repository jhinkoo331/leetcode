-- err, if there is no such row, it would return []
select Salary as SecondHighestSalary
from Employee order by Salary desc 
limit 1 offset 1; 

-- to handle the problem above, replace [] with null
select ifnull(
        select Salary
        from Employee order by Salary desc
        limit 1 offset 1
) as SecondHighestSalary;
