-- Write your query below
select s.seller_name
from 
seller s
left join orders o
On s.seller_id=o.seller_id
group by s.seller_id
having SUM(case when EXTRACT(year from o.sale_date)=2020 THEN 1 ELSE 0 END)=0
order by s.seller_name
