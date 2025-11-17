# Write your MySQL query statement below

-- select class from Courses where student in (select count(student) from Courses group by class) >= 5


select class from Courses  group by class having count(student) > 5