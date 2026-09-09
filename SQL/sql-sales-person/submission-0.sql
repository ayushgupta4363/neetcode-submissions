-- Write your query below
select name from sales_person 
where (sales_id,name) NOT IN(
select sp.sales_id,sp.name
from sales_person sp
LEFT JOIN orders o
ON sp.sales_id=o.sales_id
JOIN company c
ON o.com_id=c.com_id
where c.name='CRIMSON')
