-- Write your query below
select u.name,
COALESCE(sum(r.distance),0)as travelled_distance
from 
users u
left join 
rides r
ON u.id=r.user_id
group by u.id,u.name
order by travelled_distance DESC ,u.name