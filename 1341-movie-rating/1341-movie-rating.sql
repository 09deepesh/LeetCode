# Write your MySQL query statement below

(select u.name as results from MovieRating as m inner join Users as u on m.user_id = u.user_id group by u.user_id,u.name order by  count(*) desc,u.name asc limit 1)

union all

(select mu.title as results from MovieRating as m inner join Movies as mu on m.movie_id  = mu.movie_id group by mu.movie_id, mu.title order by  avg(m.rating) desc, mu.title asc limit 1)