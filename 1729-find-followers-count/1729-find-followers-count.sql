# Write your MySQL query statement below
select 
distinct u.user_id,  count(distinct f.follower_id) as followers_count
from Followers as u join Followers as f where u.user_id = f.user_id group by f.user_id