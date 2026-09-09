-- Write your query below
select employee_id,
case
 when employee_id%2!=0 AND name NOT LIKE 'M%' THEN salary 
 else 0 
 END as bonus
from employees 
order by employee_id;