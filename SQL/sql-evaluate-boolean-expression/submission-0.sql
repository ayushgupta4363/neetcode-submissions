-- Write your query below
select e.left_operand,
e.operator,
e.right_operand,
CASE 
   WHEN e.operator='>' AND v1.value > v2.value THEN 'true'
    WHEN e.operator='<' AND v1.value <v2.value THEN 'true'
     WHEN e.operator='=' AND v1.value = v2.value THEN 'true'
   else 'false' 
   END  as value
from expressions e
JOIN variables v1 ON v1.name=e.left_operand
JOIN variables v2 ON 
v2.name=e.right_operand;