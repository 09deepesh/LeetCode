# Write your MySQL query statement below

select 
 num
from MyNumbers group by num having count(num) = 1 order by num desc LIMIT 1;