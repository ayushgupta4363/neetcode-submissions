-- Write your query below
select p.first_name,p.last_name,a.city,a.state
from person p
Left JOIN
address a
ON
p.person_id = a.person_id
